#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
	pid_t pid;
	int p,c,num;
	char str[100]="shan",str1[100],str2[100];
	mkfifo("file1",0666);
	mkfifo("file2",0666);

	pid=fork();

	if(pid==0)
	{
		p=open("file1",O_RDONLY);
		c=open("file2",O_WRONLY);
		read(p,str1,sizeof(str1));
		write(c,str1,strlen(str1)+1);
		close(c);
		close(p);
	}
	if(pid>0)
	{
		p=open("file1",O_WRONLY);
		c=open("file2",O_RDONLY);
		write(p,str,sizeof(str));
		read(c,str2,sizeof(str2));
		printf("%s \t",str2);
		close(c);
		close(p);
	}
}
