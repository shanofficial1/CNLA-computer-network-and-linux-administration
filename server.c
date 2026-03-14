#include <stdio.h>          // printf
#include <stdlib.h>         // exit
#include <unistd.h>         // close
#include <string.h>         // memset
#include <sys/socket.h>     // socket, bind, listen, accept, send
#include <netinet/in.h>     // sockaddr_in

#define PORT 5000

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    int i;

    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    // 2. Set address details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 3. Bind socket to port
    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // 4. Listen for client
    listen(server_fd, 1);
    printf("Server waiting...\n");

    // 5. Accept client connection
    client_fd = accept(server_fd, NULL, NULL);
    printf("Client connected\n");

    // 6. Send numbers 1 to 10
    for (i = 1; i <= 10; i++) {
        send(client_fd, &i, sizeof(i), 0);
    }

    // 7. Close sockets
    close(client_fd);
    close(server_fd);

    return 0;
}
