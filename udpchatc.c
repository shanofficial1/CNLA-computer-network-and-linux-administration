#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd,n;
    struct sockaddr_in server;
    char msg[100];
   socklen_t len=sizeof(server);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
while(1){
memset(&msg,0,sizeof(msg));
   printf("Client: ");
fgets(msg,sizeof(msg),stdin);
    sendto(sockfd, msg, sizeof(msg), 0,
           (struct sockaddr *)&server, len);
if(strcmp(msg,"bye\n")==0)
{
break;
}

memset(&msg,0,sizeof(msg));

n=recvfrom(sockfd, msg, sizeof(msg) -1, 0,
           (struct sockaddr *)&server, &len);
msg[n]='\0';
printf("server: %s",msg);
if(strcmp(msg,"bye\n")==0)
{
break;
}

}
    close(sockfd);
    return 0;
}
