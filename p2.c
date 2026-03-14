#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
	pid_t pid;
	int p[2],c[2],num;
	pipe(p);
	pipe(c);
	pid=fork();

	if(pid==0)
	{
		close(p[1]);
		close(c[0]);
		for(int i=0;i<10;i++)
		{
			read(p[0],&num,sizeof(num));
			if(num%2==0){
				write(c[1],&num,sizeof(num));}
		}
		close(c[1]);
		close(p[0]);
	}
	if(pid>0)
	{
		close(p[0]);
		close(c[1]);
		for(int i=0;i<10;i++)
		{
			write(p[1],&i,sizeof(i));
		}
		printf("[ PARENT ]: PRINTING EVEN NUMBER\n");
		for(int i=0;i<5;i++)
		{
			read(c[0],&num,sizeof(num));
			printf("%d \t",num);
		}
		close(c[0]);
		close(p[1]);
	}
return 0;
}
