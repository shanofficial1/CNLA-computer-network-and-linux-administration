#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
	int num,sock;
	struct sockaddr_in server,client;
	socklen_t len=sizeof(client);

	sock=socket(AF_INET,SOCK_DGRAM,0);

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(7000);

	bind(sock,(struct sockaddr*)&server,sizeof(server));

	printf("server running ready ....\n");

	recvfrom(sock,&num,sizeof(num),0,(struct sockaddr*)&client,&len);

	for(int i=0;i<10;i++)
	{
		num=i+1;
		sendto(sock,&num,sizeof(num),0,(struct sockaddr*)&client,len);
	}
	close(sock);
	return 0;
}
