#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 3000

int main() {
    int sock;
    char buffer[100];
    struct sockaddr_in server;
//    memset(&server,0,sizeof(server));
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Server address setup
    server.sin_family = AF_INET;   
    server.sin_addr.s_addr = inet_addr("127.0.0.0");
    server.sin_port = htons(PORT);

    // Connect to server
    connect(sock, (struct sockaddr*)&server, sizeof(server));

    // Send message
    send(sock, "Hello Server", 12, 0);

    // Receive reply
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Client received: %s\n", buffer);

    close(sock);
}

