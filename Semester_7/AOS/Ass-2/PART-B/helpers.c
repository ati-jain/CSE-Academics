#include <stddef.h>
#include <linux/bpf.h>
#include <linux/in.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_endian.h>
#include<linux/udp.h>

inline int isPacketToHandle(void *data, void *data_end, int target_port){
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
    int udp_data=*(int*)(data+sizeof(struct ethhdr)+iphdr_size+8);

    if(udp_port != target_port){
        bpf_printk("PASS: Port %d, Not our target!\n", udp_port);
        return 0; 
    }
		
	return 1;

}
