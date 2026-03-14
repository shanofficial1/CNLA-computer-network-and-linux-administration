#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	pid_t pid;
	int fd1[2],fd2[2];
	char buf1[100]="Hello mam",buf2[100];

	if(pipe(fd1) <0 || pipe(fd2)<0)
	{
		printf("Pipes creation failed\n");
		return -1;
	}
	pid=fork();
	if(pid<0)
	{
		printf("Process creation failed");
		return -1;
	}
	if(pid==0)
	{	
		char buf[100];
		close(fd1[1]);
		close(fd2[0]);
		read(fd1[0],buf,sizeof(buf));
		printf(" child read : %s\n",buf);
		write(fd2[1],buf,strlen(buf)+1);
		printf("child write : %s\n",buf);
		close(fd1[0]);
		close(fd2[1]);
		
	}
	if(pid>0)
	{
		close(fd1[0]);
		close(fd2[1]);
		write(fd1[1],buf1,strlen(buf1)+1);
		printf("parent write : %s\n",buf1);
		wait(NULL);
		read(fd2[0],buf2,sizeof(buf2));
		printf("parent read : %s\n",buf2);
		close(fd1[1]);
		close(fd2[0]);
	}
	return 0;
}
