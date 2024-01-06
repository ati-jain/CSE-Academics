#include <bpf/libbpf.h>
#include <bpf/bpf.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/if_link.h>
#include <net/if.h>

int main(int argc, char **argv) {
    struct bpf_object *obj;

    int prog_fd, ifindex, x_map_fd;

    if (argc != 2) {
        printf("Usage: %s <ifname>\n", argv[0]);
        return 1;
    }

    ifindex = if_nametoindex(argv[1]);
    if (!ifindex) {
        perror("if_nametoindex");
        return 1;
    }

    if (bpf_prog_load("packet_filter.o", BPF_PROG_TYPE_XDP, &obj, &prog_fd)) {
        fprintf(stderr, "Error loading XDP program\n");
        return 1;
    }





    // Attach the XDP program to the network interface with XDP_FLAGS_SKB_MODE
    if (bpf_set_link_xdp_fd(ifindex, prog_fd, XDP_FLAGS_SKB_MODE) < 0) {
        fprintf(stderr, "Error attaching XDP program\n");
        bpf_object__close(obj);
        return 1;
    }

    printf("XDP program loaded and attached\n");

    // [Further code to interact with the map, if necessary]

    // Keep the program running, or add some mechanism to wait for a condition to detach the program
    // sleep(10); // Example: Keep the program attached for 10 seconds

    // Detach the XDP program
    // bpf_set_link_xdp_fd(ifindex, -1, XDP_FLAGS_UPDATE_IF_NOEXIST);
    // printf("XDP program detached\n");

    // Close the eBPF object
    bpf_object__close(obj);

    return 0;
}
