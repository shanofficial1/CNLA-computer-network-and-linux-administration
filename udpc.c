#include  <stdio.h>
#include  <arpa/inet.h>
#include <unistd.h>


int main()
{
	int num,sockfd;
	struct sockaddr_in server;
	socklen_t len=sizeof(server);

	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(7000);

	sendto(sockfd,&num,sizeof(num),0,(struct sockaddr*)&server,sizeof(server));

	printf("Recieving numbers : \n");

	for(int i=0;i<10;i++)
	{
		recvfrom(sockfd,&num,sizeof(num),0,NULL,NULL);
		printf("%d\t",num);
	}
	printf("\n");
	close(sockfd);
	return 0;
}
