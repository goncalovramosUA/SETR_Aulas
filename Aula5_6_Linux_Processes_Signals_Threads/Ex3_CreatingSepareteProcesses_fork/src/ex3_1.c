#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){

    /* Forking process to Child/Parent. The fork returns 0 when is the child and 
    when is the Parent returns the PID of the child. */
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }


    if(pid == 0){
        pid_t parent_pid = getppid();
        pid_t child_pid = getpid();
        printf("I'm the Child (PID = %d), my parent PID is %d.\n", child_pid, parent_pid);
    }else{
        pid_t parent_pid = getpid();
        printf("I'm the Parent (PID = %d), my child PID is %d.\n", parent_pid, pid);
        
        int status;
        pid_t cpid = wait(&status);

        if (cpid == -1) {
            perror("wait");
            return 1;
        }
    }

    /* Before closing, both processes execute this line*/
    pid_t pid_finish = getpid();
    printf("Process PID %d is finishing now.\n", pid_finish);

    return 0;
}