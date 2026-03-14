#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    char msg[100];
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    printf("UDP Chat Server started...\n");

    while (1) {
        recvfrom(sockfd, msg, sizeof(msg), 0,
                 (struct sockaddr *)&client, &len);

        printf("Client: %s\n", msg);

        if (strcmp(msg, "STOP") == 0)
            break;

        printf("Server: ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = 0;

        sendto(sockfd, msg, strlen(msg)+1, 0,
               (struct sockaddr *)&client, len);

        if (strcmp(msg, "STOP") == 0)
            break;
    }

    close(sockfd);
    return 0;
}
