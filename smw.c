#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	int shmid;
	char *arr;


	shmid=shmget(1235,10*sizeof(int),0666| IPC_CREAT);

	arr=(char *)shmat(shmid,NULL,0);

	printf("Writing from shm: ");

	fgets(arr,100,stdin);
	printf("writer Sented\n");
	printf("\n");
	shmdt(arr);
	return 0;
}

