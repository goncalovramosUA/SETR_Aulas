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

    /* When we call the syscall fork() the system separtes this code into 2 programas that run
        simultaneously. So to separate tasks from each others, the usual code is to do it with
        a if statement where we check the pid num.*/
    if(pid == 0){
        /* Child */
        pid_t parent_pid = getppid();
        pid_t child_pid = getpid();
        printf("I'm the Child (PID = %d), my parent PID is %d.\n", child_pid, parent_pid);
    }else{
        /* Parent */

        /* pid -> Child PID*/
        pid_t parent_pid = getpid();
        printf("I'm the Parent (PID = %d), my child PID is %d.\n", parent_pid, pid);
        
        /* The parent should always wait for the Child to finish in order to not have zombie
            processes. So the wait() function is blocking until the child finishes the program.
            The status variable is currently not being used, but we passed in the wait() 
            function argument (as a pointer) it is returned a termination code. */
        int status;
        pid_t cpid = wait(&status);
        if (cpid == -1) {
            perror("wait");
            return 1;
        }
    }

    /* Because there is no exit(0); or return 0; in the child part of the if statement, before
        closing, both processes execute this line. */
    pid_t pid_finish = getpid();
    printf("Process PID %d is finishing now.\n", pid_finish);

    return 0;
}