#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main()
{
	int num,num1,fd,fd1;
	mkfifo("unp",0666);
	mkfifo("unp1",0666);
	fd=open("unp",O_WRONLY);
	fd1=open("unp1",O_RDONLY);
	for(int i=1;i<=10;i++)
	{
		write(fd,&i,sizeof(i));
	}
	for(int i=1;i<=5;i++)
	{
		read(fd1,&num1,sizeof(num1));
		printf("%d\t",num1);
	}
	printf("\n");
	close(fd);
	return 0;
}
