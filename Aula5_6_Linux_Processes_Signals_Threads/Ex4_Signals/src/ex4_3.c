#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t flg_rst = 0;
volatile sig_atomic_t flg_susp = 0;

void handler(int sig){
    if (sig == SIGINT)  flg_rst = 1;
    if (sig == SIGHUP)  flg_susp = 1;
    if (sig == SIGCONT) flg_susp = 0;
}

int main(void){

    int counter = 0;

    struct sigaction sa_ign;
    sa_ign.sa_handler = SIG_IGN;
    sigemptyset(&sa_ign.sa_mask);
    sa_ign.sa_flags = 0;

    for(int i = 1; i<NSIG; i++){
        if(i == SIGKILL || i == SIGSTOP) continue;
        if(i == SIGINT || i == SIGHUP || i == SIGCONT) continue;
        sigaction(i, &sa_ign, NULL);
    }

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);

    pid_t pid = getpid();
    printf("--------------------------------------------------\n");
    printf("Timer PID: %d.\n", pid);
    printf("Timer Controls:\n");
    printf("   kill -SIGINT %d  : Reset Timer\n", pid);
    printf("   kill -SIGHUP %d  : Stop Timer\n", pid);
    printf("   kill -SIGCONT %d : Resume Timer\n", pid);
    printf("   kill -KILL %d    : Quit Timer Program\n", pid);
    printf("\nNote: Open another window to write the commands.\n");
    printf("--------------------------------------------------\n");
    fflush(stdout);

    while(1){
        printf("Elapsed: %d seconds\n", counter);
        fflush(stdout);
        if(!flg_susp) counter++;
        if(flg_rst){
            counter = 0;
            flg_rst = 0;
        }
        sleep(1);
    }
}