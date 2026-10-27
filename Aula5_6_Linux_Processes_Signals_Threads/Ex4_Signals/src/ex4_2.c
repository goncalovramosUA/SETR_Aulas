#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t flg_rst = 0;  /* Utiliza-se sig_atomic_t porque é mais rápido. */
volatile sig_atomic_t flg_susp = 0; /* 1 = true; 0 = false */

void handler(int sig){
    if (sig == SIGINT)  flg_rst = 1;
    if (sig == SIGHUP)  flg_susp = 1;
    if (sig == SIGCONT) flg_susp = 0;
}

int main(void){

    int counter = 0;

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    pid_t pid = getpid();
    printf("Program PID: %d.\n", pid);
    fflush(stdout);

    sigaction(SIGINT, &sa, NULL); 
    sigaction(SIGHUP, &sa, NULL); 
    sigaction(SIGCONT, &sa, NULL); 

    while(1){
        printf("Counter (in seconds): %d.\n", counter);
        if(!flg_susp) counter++;
        if(flg_rst){
            counter = 0;
            flg_rst = 0;
        }
        sleep(1);
    }
}

/* Commands in terminal: 
        kill -INT PID (resets the counter)
        kill -HUP PID (stops the counter)
        kill -CONT PID (resumes the counter)*/