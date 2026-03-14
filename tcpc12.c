#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
	int sock,num;
	struct sockaddr_in  server;

	sock=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(7000);

	connect(sock,(struct sockaddr*)&server,sizeof(server));

	printf("Receving: \n");
	for(int i=0;i<10;i++ )
	{
		recv(sock,&num,sizeof(num),0);
		printf("%d\t",num);
	}
	close(sock);
	return 0;

}
