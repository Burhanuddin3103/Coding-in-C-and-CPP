#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define N 4

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    socklen_t add_len = sizeof(address);
    char buffer[N] = {0};
    char response[2] = {0};
    int counter = 0;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd,(struct sockaddr*) &address, add_len);
    listen(server_fd, 1);
    new_socket = accept(server_fd,(struct sockaddr*) &address, &add_len);
    if(new_socket == -1)
    {
        perror("Error connecting to client");
        exit(EXIT_FAILURE);
    }
    for(int j = 0; j < N; j++)
        buffer[j] = '0' + counter++;
    send_again:
        printf("Sending %s\n", buffer);
        send(new_socket, buffer, strlen(buffer), 0);
        read(new_socket, response, 2);
        if(response[0] == '0')
        {
            printf("Received negative acknowledgedment\n");
            goto send_again;
        }
        else printf("Received acknowledgement %c\n", response[0]);
        return 0;
}
