#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    int fd[2];
    pid_t pid;

    if( (pipe(fd)) == -1 ){
        perror("pipe not created");
        return 1;
    }
    pid=fork();
    if((pid<0)){
        perror("fork error");
        return 1;
    }
    if(pid==0){

        printf("CHILD PROCESS\n");
        close(fd[0]);

        char write_msg[] = "Hello from child process!";
        write(fd[1], write_msg, sizeof(write_msg)+1);
    }
    else{

        printf("PARENT PROCESS\n");
        close(fd[1]);

        char read_msg[100];
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Message from child: %s\n", read_msg);
    }
}