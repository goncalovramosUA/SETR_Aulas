#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){

    pid_t pid = fork();

    if(pid < 0){
        perror("fork");
        return -1;
    }

    if(pid == 0){
        pid_t parent_pid = getppid();
        pid_t child_pid = getpid();

        printf("I'm the Child (PID = %d), my parent PID is %d.\n", child_pid, parent_pid);
        printf("Slepping for 3 seconds...\n");

        sleep(3);

        printf("Finished. Closing %d process.\n", getpid());
    }else{
        pid_t parent_pid = getpid();
        printf("I'm the Parent (PID = %d), my child PID is %d.\n", parent_pid, pid);

        int status;
        pid_t cpid = wait(&status);

        if(status == -1){
            perror("wait");
            return -1;
        }

        printf("Child (PID = %d) finished. I'm finishing now.\n", cpid);
    }

    return 0;
}