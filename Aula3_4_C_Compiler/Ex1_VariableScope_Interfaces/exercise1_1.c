#include <stdio.h>
#include <stdlib.h>

#define RAND_MAX_NUM 100
#define NUM_REPS 8

void MyRand(int *value, int *ncalls);

int main(){

    int valor;
    int num_rep;

    //int i = 0;
    for (int i = 0; i < NUM_REPS; i++)
    {
        MyRand(&valor, &num_rep);
        printf("Number Generated: %d | Repetition Number: %d \n", valor, num_rep);
    }

    return 0;
}

void MyRand(int *value, int *ncalls)
{
    *value = rand() % (RAND_MAX_NUM + 1);
    (*ncalls)++;
}