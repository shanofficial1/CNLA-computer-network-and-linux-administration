#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345

int main() {
    int sockfd;
    struct sockaddr_in serv;
    int numbers[10];

    // 1) Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2) Fill server address
    serv.sin_family = AF_INET;
    serv.sin_port = htons(PORT);
    serv.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    // 3) Connect to server
    connect(sockfd, (struct sockaddr*)&serv, sizeof(serv));

    // 4) Receive 10 numbers
    recv(sockfd, numbers, sizeof(numbers), 0);

    printf("Received numbers. Odd numbers are:\n");

    // 5) Display odd numbers
    for (int i = 0; i < 10; i++) {
        if (numbers[i] % 2 == 1) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    close(sockfd);
    return 0;
}
