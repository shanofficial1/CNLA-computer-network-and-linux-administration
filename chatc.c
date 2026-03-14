#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in server;
    char buffer[100];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(sockfd, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "bye\n") == 0)
            break;

        /* ---- FIX 1: CLEAR BUFFER BEFORE RECEIVING ---- */
        memset(buffer, 0, sizeof(buffer));

        /* ---- RECEIVE AND STORE BYTE COUNT ---- */
        n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);

        /* ---- FIX 2: NULL TERMINATE USING recv RETURN ---- */
        buffer[n] = '\0';

        printf("Server: %s\n", buffer);

        if (strcmp(buffer, "bye\n") == 0)
            break;
    }

    close(sockfd);
    return 0;
}
