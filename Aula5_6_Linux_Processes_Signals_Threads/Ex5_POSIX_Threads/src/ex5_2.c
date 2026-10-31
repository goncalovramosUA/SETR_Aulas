#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TIME 10

volatile int counter = 0;
volatile int flg_updated = 0;

void* thread_counter(void *arg){
    while(counter < MAX_TIME){
        sleep(1);
        counter++;
        flg_updated = 1;
    } 
    pthread_exit(NULL);
}

void* thread_print(void *arg){

    while (1) {
        if (flg_updated) {
            printf("[Thread Print] Counter is at: %d\n", counter);
            flg_updated = 0;

            if (counter >= MAX_TIME) break;
        }
    }

    pthread_exit(NULL);
}

int main(void){

    printf("[Main Thread] Creating the threads to count 10 seconds.\n");
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, &thread_counter, NULL);
    pthread_create(&tid2, NULL, &thread_print, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    printf("Counter is finished.\n");

    return 0;
}