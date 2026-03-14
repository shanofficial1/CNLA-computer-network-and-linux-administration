#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include  <unistd.h>
#include <fcntl.h>
int main()
{
	int fd1,fd;
	char str[100];
	mkfifo("unp",0666);
	mkfifo("unp1",0666);
	fd=open("unp",O_RDONLY);
	fd1=open("unp1",O_WRONLY);
	read(fd,str,sizeof(str));
	write(fd1,str,sizeof(str));
	printf("\n");
	close(fd);
	close(fd1);
	return 0;
}

