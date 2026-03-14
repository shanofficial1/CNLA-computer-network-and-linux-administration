#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000

int main() {
    int sock_fd, num;
    struct sockaddr_in server_addr;

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Odd numbers:\n");

    // Receive and print odd numbers
    for (int i = 0; i < 10; i++) {
        recv(sock_fd, &num, sizeof(num), 0);
        if (num % 2 != 0)
            printf("%d ", num);
    }

    close(sock_fd);
    return 0;
}
