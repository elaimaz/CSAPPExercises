#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_HEX_LENGTH 8

int main (int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./hex2dd <hexadecimal number>\n");
        return 0;
    }

    char *hex_str = argv[1];
    
    if ((strncmp(argv[1], "0x", 2) == 0) || (strncmp(argv[1], "0X", 2) == 0)) {
        hex_str = argv[1] + 2;
    }

    if (strnlen(hex_str, MAX_HEX_LENGTH) != 8) {
        printf("Error: Input must be exactly 8 characters long.\n");
        printf("Example: ./hex2dd 0xffffffff\n");
        printf("Or: ./hex2dd 00000000\n");
        return 0;
    }

    long hex_value = strtol(hex_str, NULL, 16);

    in_addr_t address_value = htonl(hex_value);

    struct in_addr ip_addr;
    ip_addr.s_addr = address_value;

    char *ip_address_string = inet_ntoa(ip_addr);
    printf("IP Address: %s\n", ip_address_string);

    return 1;
}