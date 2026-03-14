#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    char msg[100];
    struct sockaddr_in server;
    socklen_t len = sizeof(server);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("UDP Chat Client started...\n");

    while (1) {
        printf("Client: ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0;

        sendto(sockfd, msg, strlen(msg)+1, 0,
               (struct sockaddr *)&server, len);

        if (strcmp(msg, "STOP") == 0)
            break;

        recvfrom(sockfd, msg, sizeof(msg), 0,
                 (struct sockaddr *)&server, &len);

        printf("Server: %s\n", msg);

        if (strcmp(msg, "STOP") == 0)
            break;
    }

    close(sockfd);
    return 0;
}
