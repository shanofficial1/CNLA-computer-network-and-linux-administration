#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5000

int main() {
    int server_fd, new_sock;
    char buffer[100];
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);

//    memset(&server,0,sizeof(server));
  //  memset(&client,0,sizeof(client));
    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Server address setup
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind socket to PORT
    bind(server_fd, (struct sockaddr*)&server, sizeof(server));

    // Listen for connection
    listen(server_fd, 1);
    printf("Server waiting...\n");

    // Accept client
    new_sock = accept(server_fd, (struct sockaddr*)&client, &client_len);
    printf("Client connected.\n");

    // Receive message
    recv(new_sock, buffer, sizeof(buffer), 0);
    printf("Server received: %s\n", buffer);

    // Send reply
    send(new_sock, "Hello from Server", 18, 0);

    close(new_sock);
    close(server_fd);
}
