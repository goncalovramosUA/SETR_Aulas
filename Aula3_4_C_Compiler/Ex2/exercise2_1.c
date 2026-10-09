#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* manageArray(int N, int M, int* min, int* max, int* average);

int main(void)
{
    // Semente para gerar números verdadeiramente aleatórios em cada execução
    srand((unsigned int)time(NULL));

    int nNumbers = 10;
    int maxNum = 100;
    int minArrayNum;
    int maxArrayNum;
    int averageNum; 

    int* listagem = manageArray(nNumbers, maxNum, &minArrayNum, &maxArrayNum, &averageNum);

    printf("Foi criado um array com %d números, entre 1 e %d.\n", nNumbers, maxNum);
    printf("Este array tem os seguintes valores: ");
    for(int i = 0; i < nNumbers; i++)
    {
        if(i < nNumbers-1){
            printf("%d, ", *(listagem + i));
        } else {
            printf("%d. \n", *(listagem + i));
        }
    }
    printf("O número mínimo foi: %d.\n", minArrayNum);
    printf("O número máximo foi: %d.\n", maxArrayNum);
    printf("A média é: %d. \n", averageNum);

    free(listagem);

    return 0;
}

int* manageArray(int N, int M, int* min, int* max, int* average)
{
    // Alocating memory
    int *array = (int *)malloc(N * sizeof(int)); //Não pode ser int array[N]; por estarmos a declarar 
                                                 //numa função e depois queremos passar para fora dela,
                                                 // Ou seja temos de criar na HEAP em vez da stack.
    if (array == NULL) {return NULL;}

    int sum = 0;
    *min = M;
    *max = 1;
    for (int i = 0; i < N; i++)
    {
        // Generating random number comprised between 1 and M
        array[i] = (rand() % M) + 1; 

        // Checking min, max, and average
        if (array[i] < *min) {*min = array[i];}
        if (array[i] > *max) {*max = array[i];}

        sum += array[i];
    }

    *average = sum/N;  

    // Returning pointer to the array
    return array;

}