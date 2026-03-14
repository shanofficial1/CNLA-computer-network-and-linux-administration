#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int rs;
	pid_t pid;
	if(argc!=3)
	{
		printf("Program is not running properly\n");
		printf("Please provide command to be shown below\n ./a.out <fullpath> <command>\n");
		exit(-1);
	}
	pid=fork();
	if(pid<0)
	{
		printf("Child process creation failed\n");
		exit(-1);

	}
	if(pid==0)
	{
		printf("Child process starts\n");
		rs=execl(argv[1],argv[2],NULL);
		if(rs<0)
		{
			printf("program cannot loaded successfully\n");
			exit(-1);
		}
	}
	if(pid>0)
	{
		wait(NULL);
		printf("Child process exited\n program completed\n");
	}
	return 0;
}
