#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swapPointers(int** p1, int** p2);

int main(void)
{
    int a = 5;
    int b = 17;

    int* pointer1 = &a;
    int* pointer2 = &b;

    printf("\n ---- Antes do SWAP ----\n");
    printf("Valor de 'a' = %d. | Valor de 'b' = %d.\n", a, b);
    printf("Valor através do ponteiro *p1 = %d. | Valor através do ponteiro *p2 = %d.\n", *pointer1, *pointer2);

    swapPointers(&pointer1, &pointer2);
    
    printf("\n ---- Depois do SWAP ----\n");
    printf("Valor de 'a' = %d. | Valor de 'b' = %d. - Ou seja, iguais\n", a, b);
    printf("Valor através do ponteiro *p1 = %d. | Valor através do ponteiro *p2 = %d. - Agora estão diferentes!\n", *pointer1, *pointer2);

    return 0;
}



void swapPointers(int** p1, int** p2)
{
    int* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}