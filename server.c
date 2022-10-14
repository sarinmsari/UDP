#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
int main(int argc, char *argv[])
{
    char buff[100];
    int soc_desc;
    struct socaddr_in server, client;
    if (argc != 2)
        printf("\nInput format not correct");
    soc_desc = socket(AF_INET, SOCK_DGRAM, 0);
    if (soc_desc == -1)
        printf("\nError in socket()");
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));
    if (bind(soc_desc, (struct sockadder *)&server, sizeof(server)) < 0)
        printf("\nError in bind()!");
    printf("\nServer waiting...");
    if (recvfrom(soc_desc, buff, 100, 0, (struct sockaddr *)&server, sizeof(server)) < 0)
        printf("\nError in recvfrom()");
    printf("\nGot a datagram:%s", buff);
    return 0;
}