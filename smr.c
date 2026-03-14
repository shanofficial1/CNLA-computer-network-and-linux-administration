#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int shmid,*arr;
	pid_t pid;

	shmid=shmget(IPC_PRIVATE,10*sizeof(int),0666|IPC_CREAT);

	pid=fork();

	if(pid==0)
	{
		arr=(int *)shmat(shmid,NULL,0);
		printf("[child] : reading from shm");
		for(int i=0;i<10;i++)
		{
			printf("%d\t",arr[i]*2);
		}
		printf("\n");
		shmdt(arr);
	}
	if(pid>0)
	{
		arr=(int *)shmat(shmid,NULL,0);
		printf("[parent]: writing into shm");
		for(int i=0;i<10;i++)
		{
			arr[i]=i+1;
		}
		wait(NULL);
		shmdt(arr);
		shmctl(shmid,IPC_RMID,NULL);
	}
	return 0;
}
