#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sockfd,n;
    struct sockaddr_in server, client;
    socklen_t len;
    char buffer[50];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr *)&server, sizeof(server));

    len = sizeof(client);
    while(1)
   {
   memset(&buffer,0,sizeof(buffer));
   n= recvfrom(sockfd, buffer, sizeof(buffer)-1, 0,
             (struct sockaddr *)&client, &len);
   buffer[n]='\0';
    printf("Client: %s", buffer);

if(strcmp(buffer,"bye\n")==0)
{
break;
}
  
 memset(&buffer,0,sizeof(buffer));
printf("Server: ");
fgets(buffer,sizeof(buffer),stdin);

sendto(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&client, len);

if(strcmp(buffer,"bye\n")==0)
{
break;
}



 }
    close(sockfd);
    return 0;
}
