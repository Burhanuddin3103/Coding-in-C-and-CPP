#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define N 4

void try(int val)
{
    if(val == -1)
    {
        perror("Something went wrong");
        exit(EXIT_FAILURE);
    }
}

void main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    char buffer[N] = {0};
    char ack;
    char response[5] = {0};
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) == -1)
    {
        perror("Invalid IP value");
        exit(EXIT_FAILURE);
    }
    if(connect(sock,(struct sockaddr*) &address, sizeof(address)))
    {
        perror("Error connecting to client");
        exit(EXIT_FAILURE);
    }
    while(ack != 'y')
    {
        int val = read(sock, buffer, N);
        printf("\nReceived %s\n", buffer);
        printf("Send acknowledgement? [y/n]: ");
        scanf("%s", response);
        ack = response[0];
        memset(response, 0, sizeof(response));
        if(ack == 'y')
            sprintf(response, "%d", val);
        else
            sprintf(response, "%d", 0);
        send(sock, response, strlen(response), 0);
    }
}
