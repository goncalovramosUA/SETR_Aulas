#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

volatile int counter = 0;
volatile sig_atomic_t flg = 0;

void handler_usr1(int sig){
    if(sig == SIGUSR1){
        flg = 1;
        printf("[SIGUSR1] Start (SIGUSR2 blocked)...\n");
        sleep(2); // Simulating Work to watch the blocking of SIGUSR2
        printf("[SIGUSR1] End!\n");
        fflush(stdout);
    }
}

void handler_usr2(int sig){
    if(sig == SIGUSR2){
        printf("[SIGUSR2] Handled!\n"); 
        fflush(stdout);
    }
}

int main(void){
    /* Signal setup SIG_USR1 handler */
    struct sigaction sa1;
    sa1.sa_handler = handler_usr1;
    sigemptyset(&sa1.sa_mask);
    sa1.sa_flags = 0;
    sigaddset(&sa1.sa_mask, SIGUSR2); // Blocks SIGUSR2 while in handler_usr1;
    if(sigaction(SIGUSR1, &sa1, NULL) == -1){
            perror("sigaction");
        return -1;
    }

    /* Signal setup SIG_USR2 handler */
    struct sigaction sa2;
    sa2.sa_handler = handler_usr2;
    sigemptyset(&sa2.sa_mask);
    sa2.sa_flags = 0;
    sigaddset(&sa2.sa_mask, SIGUSR1); // Blocks SIGUSR1 while in handler_usr2;
    if(sigaction(SIGUSR2, &sa2, NULL) == -1){
        perror("sigaction");
        return -1;
    }
    
    pid_t pid = getpid();
    printf("\n--------------------------------------------------------------\n");
    printf("Process PID: %d\n", pid);
    printf("Command (in another terminal):\n");
    printf("   kill -SIGUSR1 %d; kill -SIGUSR2 %d : To see the blocking\n", pid, pid);
    printf("   kill -KILL %d                        : To finish the program\n", pid);
   printf("\n--------------------------------------------------------------\n");
   fflush(stdout);

    while(1){
        pause();
        if(flg) {
            counter++;
            flg = 0;
            printf("  Updated Counter: %d\n", counter);
            fflush(stdout);
        }
    }

}