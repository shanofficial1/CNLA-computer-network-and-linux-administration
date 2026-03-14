#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>


int  main()
{
	int sockfd,clfd,num;
	struct sockaddr_in  server ,client;
	socklen_t  len=sizeof(client);

	sockfd=socket(AF_INET,SOCK_STREAM,0);

	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_family=AF_INET;
	server.sin_port=htons(7000);


	bind(sockfd,(struct sockaddr*)&server,sizeof(server));

	listen(sockfd,5);
	printf("Server is runnning\n");
while(1){
	clfd=accept(sockfd,(struct sockaddr*)&client,&len);
	printf("Connwected\n");
	for(int i=1;i<=10;i++)
	{
		num=i;
		send(clfd,&num,sizeof(num),0);
	}
	printf("sented\n");}
	close(clfd);
	close(sockfd);
	return 0;
}



