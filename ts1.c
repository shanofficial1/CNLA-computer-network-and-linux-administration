#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sockfd, clntfd;
    struct sockaddr_in server;
    char buffer[50];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    listen(sockfd, 5);

    clntfd = accept(sockfd, NULL, NULL);

    read(clntfd, buffer, sizeof(buffer));
    printf("Message received: %s\n", buffer);

    close(clntfd);
    close(sockfd);

    return 0;
}
