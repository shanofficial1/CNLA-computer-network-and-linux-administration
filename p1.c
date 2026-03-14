#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main()
{
	pid_t pid;
	int num,i,fd[2];
	char str[100]="shan",str1[100];
	pipe(fd);
	pid=fork();
	if(pid==0)
	{
		close(fd[1]);
		printf("[ Child ]: recieving  :");
			read(fd[0],&str1,sizeof(str1));
			printf("reacined :%s \n",str1);
		close(fd[0]);
	}
	if(pid>0)
	{
		close(fd[0]);
		write(fd[1],str,strlen(str)+1);
		printf("[ Parent ]:%s \n",str);
		close(fd[1]);
	}
	return 0;
}
