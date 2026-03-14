#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main()
{
	int fd,fd1;
	char str[100]="SHAN",str1[100];
	mkfifo("unp",0666);
	mkfifo("unp1",0666);
	fd=open("unp",O_WRONLY);
	fd1=open("unp1",O_RDONLY);
	write(fd,str,sizeof(str));
	read(fd1,str1,sizeof(str1));
	printf("%s",str1);
	printf("\n");
	close(fd);
	return 0;
}
