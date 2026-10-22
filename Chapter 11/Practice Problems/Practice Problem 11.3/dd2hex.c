#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_HEX_LENGTH 8

int main (int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./dd2hex <dotted-decimal IP>\n");
        return 0;
    }

    in_addr_t ip_value = inet_addr(argv[1]);

    if (ip_value == -1) {
        printf("Invalid dotted-decimal IP address: %s\n", argv[1]);
        printf("Example: ./dd2hex 128.2.194.242\n");
        return 0;
    }

    unsigned long int host_ip = ntohl(ip_value);
    printf("Hexadecimal IP address: 0x%lx\n", host_ip);

    return 1;
}