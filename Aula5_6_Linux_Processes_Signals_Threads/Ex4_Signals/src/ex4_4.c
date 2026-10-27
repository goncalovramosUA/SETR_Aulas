#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

volatile sig_atomic_t sig_rec = 0;

void handler(int sig){
    if(sig == SIGUSR1){
        printf("[Child]: Recieved SIG_USR1. \n");
        fflush(stdout);
        sig_rec = 1;
    }
}

int main(void){

    /* Signal setup handler */
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if(sigaction(SIGUSR1, &sa, NULL) == -1){
        perror("sigaction");
        return -1;
    }

    /* Fork the process - Creating Parent and CHild*/
    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        return -1;
    }

    if(pid == 0){
        // Child
        pid_t child_pid = getpid();
        int counter = 0;
        while(counter < 10){
            pause;
            if(sig_rec){
                counter++;
                sig_rec = 0;
            }
        }
        printf("[Child - PID %d]: Program terminated\n", child_pid);
        exit(0);
    }else{
        // Parent
        pid_t parent_pid = getpid();
        for(int i = 0; i < 10; i++){
            sleep(1);
            kill(pid, SIGUSR1);
            printf("[PARENT - PID %d]: Sent Signal SIG_USR1 to process %d (%d/10)\n", parent_pid, pid, i+1);
            fflush(stdout);
        }

        int status;
        pid_t cpid = wait(&status);
        if(status == -1){
            perror("wait");
            return -1;
        }

        printf("[PARENT - PID %d]: Program terminated\n", parent_pid);
    }
}