#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define file  "myfifo"
int main()
{
	pid_t pid;
	int num,fd;
	mkfifo(file,0666);
	pid=fork();
	if(pid==0)
	{
		fd=open(file,O_RDONLY);
		printf("Odd numbers : \n");
		for(int i=0;i<10;i++)
		{
			read(fd,&num,sizeof(num));
			if(num%2!=0)
			{
				printf("%d \t",num);
			}
		}
		close(fd);
	}
	if(pid>0)
	{
		fd=open(file,O_WRONLY);
		for(int i=1;i<=10;i++)
		{
			write(fd,&i,sizeof(i));
		}
		close(fd);
	}
	return 0;
}
