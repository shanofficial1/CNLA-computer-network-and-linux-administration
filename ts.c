#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


#define PORT 12345

int main() {
    int sockfd, connfd;
    struct sockaddr_in serv, cli;
    socklen_t len = sizeof(cli);
    int numbers[10];

    // 1) Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2) Fill server address
    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = INADDR_ANY;

    // 3) Bind
    bind(sockfd, (struct sockaddr*)&serv, sizeof(serv));

    // 4) Listen
    listen(sockfd, 1);
    printf("Server waiting for connection...\n");

    // 5) Accept client
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    printf("Client connected.\n");

    // 6) Generate 10 numbers
   
    printf("Generated numbers: ");
    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 100;   // random 0–99
        printf("%d ", numbers[i]);
    }
    printf("\nSending to client...\n");

    // 7) Send array to client
    send(connfd, numbers, sizeof(numbers), 0);

    close(connfd);
    close(sockfd);
    return 0;
}
