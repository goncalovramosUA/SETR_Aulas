#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

void *thread(void *arg){
    int name = *(int *)arg;
    sigset_t set;
    int sig;

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);

    if(sigwait(&set, &sig) == 0){
        if (sig == SIGUSR1) {
            printf("[Thread %d] Signal Received: SIGUSR1\n", name);
        }
    }
    pthread_exit(NULL);
}

int main(void){

    pthread_t tid1;
    pthread_t tid2;
    int t_name1 = 1;
    int t_name2 = 2;
    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    pthread_sigmask(SIG_BLOCK, &set, NULL);

    printf("[Main Thread] Creating two threads named 1 and 2.\n");
    pthread_create(&tid1, NULL, &thread, &t_name1);
    pthread_create(&tid2, NULL, &thread, &t_name2);
    sleep(1);

    printf("[Main Thread] Sending signal to the thread 1\n");
    pthread_kill(tid1, SIGUSR1);
    sleep(1);
    printf("[Main Thread] Sending signal to the thread 2\n");
    pthread_kill(tid2, SIGUSR1);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("[Main Thread] Both threads are finished, exiting.\n");

    return 0;
}