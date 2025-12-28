#include "SDL_net.h"

#include "vmsock.h"

#include "thread.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SDLNet_Init(void) {}

vm_soc_dns_result dns;

int d_callback(vm_soc_dns_result* d) {
    dns = *d;
    dns.num = 4;
    thread_next();
    return 0;
}

int SDLNet_ResolveHost(IPaddress *address, const char *host, Uint16 port)
{
    if (!address)
        return -1;

    address->port = port;

    if (host) {
        dns.num = 0;
        dns.error_cause = 0;

        int u = vm_soc_get_host_by_name(1, host, &dns, d_callback);

        if (u == VM_E_SOC_SUCCESS) {
            memcpy(&address->host, dns.address, 4);
            return 0;
        }
        else if (u == VM_E_SOC_WOULDBLOCK){
            cprintf("Resolving %s...", host);
            flush_layer();
            while (!dns.num)
                thread_next();
            cprintf("done!\n");
            memcpy(&address->host, dns.address, 4);
            return 0;
        } else
            return -1;


    } else {
        address->host = INADDR_ANY;
        return 0;
    }
}

static void udp_callback(VMINT hdl, VMINT event) {}

UDPsocket SDLNet_UDP_Open(Uint16 port) {
    if (port ==0)
        port = rand()%1000; // todo fix

    int handle = vm_udp_create(port, 1, udp_callback, 0);
    if (handle >= 0)
        return (UDPsocket)(handle + 1);
    else
        return 0;
}

UDPpacket* SDLNet_AllocPacket(int size) {
    UDPpacket* pack = SDL_malloc(sizeof(UDPpacket));
    pack->maxlen = size;
    pack->data = SDL_malloc(size);
    return pack;
}

vm_sockaddr_struct* IP_to_MRE(IPaddress ip) {
    static vm_sockaddr_struct addr = {0};
    addr.port = ip.port;
    addr.addr_len = 4;
    memcpy(addr.addr, &ip.host, 4);
    return &addr;
}

IPaddress MRE_to_IP(vm_sockaddr_struct addr) {
    IPaddress ip;
    ip.port = addr.port;
    memcpy(&ip.host, addr.addr, 4);
    return ip;
}

int SDLNet_UDP_Send(UDPsocket sock, int channel, UDPpacket *packet) {
    int ret = vm_udp_sendto(((int)sock)-1, packet->data, packet->len, IP_to_MRE(packet->address));

    return ret >= 0;
}

int SDLNet_UDP_Recv(UDPsocket sock, UDPpacket *packet) {
    static vm_sockaddr_struct addr = {0};
    int ret = vm_udp_recvfrom(((int)sock)-1, packet->data, packet->maxlen, &addr);

    if (ret > 0) {
        packet->len = ret;
        packet->address = MRE_to_IP(addr);
        return 1;
    }else if (ret == 0)
        return 0;
    else
        return -1;
}

const char* SDLNet_GetError(void) {
    return "";
}
