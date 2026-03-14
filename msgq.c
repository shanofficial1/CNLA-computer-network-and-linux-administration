#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct message{

	long mtype;
	char num[10];
};

int main()
{
	struct message msg;
	pid_t pid;
	int msgid=msgget(IPC_PRIVATE,0666 | IPC_CREAT);
	pid=fork();
	if(pid==0)
	{
		msgrcv(msgid,&msg,sizeof(msg.num),1,0);
		printf("%s",msg.num);
	}
	if(pid>0)
	{
		msg.mtype=1;
		msg.num="shan";
		msg.num[strlen(msg.num)+1]='\0';
		msgsnd(msgid,&msg,sizeof(msg.num),0);
		wait(NULL);
		msgctl(msgid,IPC_RMID,NULL);
	}
	return 0;
}
