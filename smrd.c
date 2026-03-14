#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <ctype.h>
int main()
{
	int shmid;
	char *arr;

	shmid=shmget(1235,10*sizeof(int),0666);

	arr=(char *)shmat(shmid,NULL,0);
	printf("Reading from shm\n");
	int i=0;
	while(arr[i]!='\0')
	{
		if(arr[i] >='a' && arr[i]<='z')
		{
			arr[i]=toupper(arr[i]);
		}
		i++;
	}
	printf("Uppercase : %s",arr);
	shmdt(arr);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
