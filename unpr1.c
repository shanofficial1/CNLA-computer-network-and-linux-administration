#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include  <unistd.h>
#include <fcntl.h>
int main()
{
	int fd1,fd,num;
	mkfifo("unp",0666);
	mkfifo("unp1",0666);
	fd=open("unp",O_RDONLY);
	fd1=open("unp1",O_WRONLY);
	for(int i=1;i<=10;i++)
	{
		read(fd,&num,sizeof(num));
		if(num%2!=0)
		{
			write(fd1,&num,sizeof(num));
		}
	}
	printf("\n");
	close(fd);
	close(fd1);
	return 0;
}

