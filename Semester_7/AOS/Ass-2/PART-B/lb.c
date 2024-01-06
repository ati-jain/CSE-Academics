#include <stddef.h>

#include <linux/bpf.h>
#include <linux/in.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/udp.h>

#include <bpf/bpf_helpers.h>
#include <bpf/bpf_endian.h>


#define MAX_THREAD_COUNT 5

#define LB_PORT 8080
#define LB_IP 2

#define SERVER_1_PORT 6060
#define SERVER_1_IP 3

#define SERVER_2_PORT 7070
#define SERVER_2_IP 4

#define SERVER_3_PORT 9090
#define SERVER_3_IP 5                                   


// Subnet: 172.18.0.0/16
#define IP_ADDRESS(x) (unsigned int)(172 + (18 << 8) + (0 << 16) + (x << 24))


__always_inline int isPacketToHandle(void *data, void *data_end);
__always_inline __u16 iphCsum(struct iphdr *iph);
__always_inline void modifyPacket(void *data, void *data_end, int source_ip, int source_port, int dest_ip, int dest_port);
__always_inline int getFreeServer();
__always_inline int getData(void*data,void*data_end);
__always_inline void modifyUdpData(void*data,void*data_end,int val);
__always_inline int packetFromServers(void*data,void*data_end);
__always_inline int getFrontData();

// Define the map
struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(key_size, sizeof(__u32));
    __uint(value_size, sizeof(__u32));
    __uint(max_entries, 3);
} x_map SEC(".maps");


struct bpf_map_def SEC("maps") udp_queue = {
    .type        = BPF_MAP_TYPE_QUEUE,
    .value_size  = sizeof(__u32),
    .max_entries = 100,
};




SEC("xdp")
int loadBalancer(struct xdp_md*ctx){
	void *data = (void *)(long)ctx->data;
    void *data_end = (void *)(long)ctx->data_end;

    

    if(!isPacketToHandle(data, data_end)){
        return XDP_PASS;
    }


    bpf_printk("Packet To Handle!");

    int  serv = packetFromServers(data, data_end);
    if(serv!=-1){
        bpf_printk("Thread Freed in server %d\n", serv);
        int front=getFrontData();
        if(front==-1){
            return XDP_DROP;
        }
        modifyUdpData(data, data_end, front);
        int key=serv-1, *value = bpf_map_lookup_elem(&x_map, &key); if(value) (*value)++;
    }
    else{
        serv = getFreeServer();
        if(serv==-1){
            int udp_data=getData(data,data_end);
            bpf_printk("val: %d",udp_data);
            if(bpf_map_push_elem(&udp_queue, &udp_data,BPF_EXIST) != 0)
                return XDP_DROP;
            bpf_printk("pushed the element %d",udp_data);
            return XDP_DROP;
            
        }
    }
    if(serv==1) 
        modifyPacket(data, data_end, LB_IP, LB_PORT, SERVER_1_IP, SERVER_1_PORT);
    
    else if(serv==2)
        modifyPacket(data, data_end, LB_IP, LB_PORT, SERVER_2_IP, SERVER_2_PORT);

    else if(serv==3)
        modifyPacket(data, data_end, LB_IP, LB_PORT, SERVER_3_IP, SERVER_3_PORT);
    




        

    bpf_printk("Redirecting to server %d ......\n", serv);



    return XDP_TX;


}

__always_inline int getFrontData(){
     int front=-1;
     if(bpf_map_peek_elem(&udp_queue,&front)!=0)return -1;
     bpf_map_pop_elem(&udp_queue,&front);
    return front;
}



__always_inline int packetFromServers(void*data,void*data_end){
    struct ethhdr*eth = data;
    struct iphdr* iphdr = data + sizeof(struct ethhdr);
    if(data+sizeof(struct ethhdr)+sizeof(struct iphdr) > data_end){
        bpf_printk("PASS: iphdr error\n");
        return XDP_DROP;
	}

    __u32 key;
    __u32 *value;

    // check-1
    if( iphdr->saddr == IP_ADDRESS(SERVER_1_IP) ) { 
         key=0;
         value = bpf_map_lookup_elem(&x_map, &key);
         if(value){(*value)--;return 1;}
        }
    
    else if( iphdr->saddr == IP_ADDRESS(SERVER_2_IP)) {
        key=1;
        value = bpf_map_lookup_elem(&x_map, &key);
        if(value){(*value)--;return 2;}
    }

    else if(iphdr->saddr == IP_ADDRESS(SERVER_3_IP)) {
        key=2;
        value = bpf_map_lookup_elem(&x_map, &key);
        if(value){(*value)--;return 3;}
    }
    return -1;

}



__always_inline int getData(void*data,void*data_end){
    struct ethhdr*eth = data;
    struct iphdr* iphdr = data + sizeof(struct ethhdr);
    struct udphdr*udphdr = data + sizeof(struct ethhdr) + iphdr->ihl*4;
    if(data+sizeof(struct ethhdr)+sizeof(struct iphdr) > data_end){
					bpf_printk("PASS: iphdr error\n");
					return XDP_DROP;
	}
    if(data+sizeof(struct ethhdr)+iphdr->ihl*4 + sizeof(struct udphdr) > data_end ){ // This will never happen
        bpf_printk("PASS: udphdr error\n");
        return -1; 
    }

    if(data+sizeof(struct ethhdr)+iphdr->ihl*4 + sizeof(struct udphdr) + 4 > data_end){
        bpf_printk("udp_pkt errror");
        return -1;
    }
    else return *(int*)((void*)udphdr+8);
    

}

__always_inline void modifyUdpData(void*data,void*data_end,int val){
    struct ethhdr*eth = data;
    struct iphdr* iphdr = data + sizeof(struct ethhdr);
    struct udphdr*udphdr = data + sizeof(struct ethhdr) + iphdr->ihl*4;

    if(data+sizeof(struct ethhdr)+sizeof(struct iphdr) > data_end){
					bpf_printk("PASS: iphdr error\n");
					return ;
				}
    if(data+sizeof(struct ethhdr)+iphdr->ihl*4 + sizeof(struct udphdr) > data_end ){ // This will never happen
        bpf_printk("PASS: udphdr error\n");
        return; 
    }
    if(data+sizeof(struct ethhdr)+iphdr->ihl*4 + sizeof(struct udphdr) + 4 > data_end){
        bpf_printk("udp_pkt errror");
        return ;
    }
    int*udp_data=(int*)((void *)udphdr+8);
    *udp_data=val;
}

__always_inline int isFree(int serv){
    __u32 key=serv-1;
    __u32 *value;

    // check-1
    value = bpf_map_lookup_elem(&x_map, &key);
    if (value) {
        // check if thread_count <5 if so increase thread_count else check the next server
        bpf_printk("threads busy server-%d:%d", serv, *value);
        if(*value < MAX_THREAD_COUNT){
          ++(*value);
          return 1;
        }
    }
    return 0;
}


__always_inline int getFreeServer(){
    __u32 key;
    __u32 *value;

    // check server 1
    if(isFree(1)) return 1;
    // check server 2
    if(isFree(2)) return 2;
    // check server 3
    if(isFree(3)) return 3;
    

    
    return -1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 ;
}






__always_inline void modifyPacket(void *data, void *data_end, int source_ip, int source_port, int dest_ip, int dest_port){
    struct ethhdr*eth = data;
    struct iphdr* iphdr = data + sizeof(struct ethhdr);
    struct udphdr*udphdr = data + sizeof(struct ethhdr) + iphdr->ihl*4;

    if(data+sizeof(struct ethhdr)+iphdr->ihl*4 + sizeof(struct udphdr) > data_end ){ // This will never happen
        bpf_printk("PASS: udphdr error\n");
        return; 
    }
    udphdr->dest=bpf_htons(dest_port);
    udphdr->source=bpf_htons(source_port);

    iphdr->daddr=IP_ADDRESS(dest_ip);
    iphdr->saddr=IP_ADDRESS(source_ip);
    iphdr->check = iphCsum(iphdr);

    eth->h_dest[5] = dest_ip;
    eth->h_source[5] = source_ip;
}



__always_inline int isPacketToHandle(void *data, void *data_end){
    // Get Ethernet header
    struct ethhdr*eth=data;
    if(data+sizeof(struct ethhdr) > data_end){
        bpf_printk("PASS: ethhdr error\n");
        return 0;
    }
    //check if its an ipv4 packet
    if(bpf_ntohs(eth->h_proto) != ETH_P_IP){
        bpf_printk("PASS: not ipv4\n");
        return 0;
    }
    // IP header check
    struct iphdr*iphdr=data+sizeof(struct ethhdr);
    if(data+sizeof(struct ethhdr)+sizeof(struct iphdr) > data_end){
        bpf_printk("PASS: iphdr error\n");
        return 0;
    }
			
    int iphdr_size=iphdr->ihl*4;
    if(data+sizeof(struct ethhdr)+iphdr_size > data_end){
        bpf_printk("PASS: iphdr error type 2\n");
        return 0;
    }

    if(iphdr->daddr != IP_ADDRESS(LB_IP)){
        bpf_printk("PASS: Not sent to LB IP\n");
        return 0;
    }

    unsigned char protocol = iphdr->protocol;

    // check if its a UDP packet
    if(protocol != IPPROTO_UDP){
        bpf_printk("PASS: not UDP\n");
        return 0;
    }
							 
    struct udphdr*udp=data + sizeof(struct ethhdr)+ iphdr_size ;
    
    // Get UDP header
    if(data+sizeof(struct ethhdr)+iphdr_size + sizeof(struct udphdr) > data_end ){
        bpf_printk("PASS: udphdr error\n");
        return 0;
    }

    int udp_port=bpf_ntohs(udp->dest);
    // int udp_data=*(int*)(data+sizeof(struct ethhdr)+iphdr_size+8);

    if(udp_port != LB_PORT){
        bpf_printk("PASS: Port %d, Not our target!\n", udp_port);
        return 0; 
    }
		
	return 1;

}


__always_inline __u16 csum_fold_helper(__u64 csum){
    int i;
#pragma unroll
    for (i = 0; i < 4; i++)
    {
        if (csum >> 16)
            csum = (csum & 0xffff) + (csum >> 16);
    }
    return ~csum;
}


__always_inline __u16 iphCsum(struct iphdr *iph){
    iph->check = 0;
    unsigned long long csum = bpf_csum_diff(0, 0, (unsigned int *)iph, sizeof(struct iphdr), 0);
    return csum_fold_helper(csum);
}





char LICENSE[] SEC("license") = "GPL";