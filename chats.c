#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sockfd, clntfd;
    struct sockaddr_in server;
    char buffer[100];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    listen(sockfd, 5);

    clntfd = accept(sockfd, NULL, NULL);

    while (1) {
        /* ---- FIX 1: CLEAR BUFFER BEFORE RECEIVING ---- */
        memset(buffer, 0, sizeof(buffer));

        /* ---- RECEIVE AND STORE BYTE COUNT ---- */
        n = recv(clntfd, buffer, sizeof(buffer) - 1, 0);

        /* ---- FIX 2: NULL TERMINATE USING recv RETURN ---- */
        buffer[n] = '\0';

        printf("Client: %s\n", buffer);

        if (strcmp(buffer, "bye\n") == 0)
            break;

        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);

        send(clntfd, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "bye\n") == 0)
            break;
    }

    close(clntfd);
    close(sockfd);
    return 0;
}
