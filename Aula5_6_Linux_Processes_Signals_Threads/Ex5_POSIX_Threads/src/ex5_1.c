#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void* thread1(void *arg){
    printf("[Thread 1] Starting.\n");
    sleep(1);
    printf("[Thread 1] Finishing.\n");
    pthread_exit((void *) 1);
}

void* thread2(void *arg){
    printf("[Thread 2] Starting.\n");
    sleep(1);
    printf("[Thread 2] Finishing.\n");
    pthread_exit((void *) 2);
}

int main(void){

    printf("[Main Thread] Creating two threads named 1 and 2.\n");

    /* Creating Thread 1 & 2 */
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, &thread1, NULL);
    pthread_create(&tid2, NULL, &thread2, NULL);
    
    /* Waiting for both threads to finish */
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("[Main Thread] Both threads are finished, exiting.\n");

    return 0;
}