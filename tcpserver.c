#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, clientfd;
    struct sockaddr_in server, client;
    char msg[100] = "Hello from Server";
    int len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    listen(sockfd, 1);

    len = sizeof(client);
    clientfd = accept(sockfd, (struct sockaddr*)&client, &len);

    write(clientfd, msg, strlen(msg));

    close(clientfd);
    close(sockfd);


    return 0;
}
