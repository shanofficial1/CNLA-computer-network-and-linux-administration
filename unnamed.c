#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	int fd[2];
	char str[100]="Hello Pipe",str1[100];
	pid_t pid;
	if(pipe(fd)<0)
	{
		printf("Pipe creation failed");
		return -1;
	}
	pid=fork();
	if(pid<0)
	{
		printf("Fork failed");
		return -1;
	}
	if(pid==0)
	{
		printf("Child process start");
		close(fd[0]);
		write(fd[1],str,strlen(str)+1);
		close(fd[1]);
	}
	if(pid>0)
	{
		wait(NULL);
		close(fd[1]);
		printf("Parent process");
		read(fd[0],str1,sizeof(str1));
		printf("parent : %s :",str1);
		close(fd[0]);
	}
	return 0;
}
