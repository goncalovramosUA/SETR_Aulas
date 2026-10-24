#include <stdio.h>
#include <stdlib.h>

int main(void){

    int stauts = system("wc src/teste.txt -m -w");
    if(stauts == -1){
        perror("system");
        return -1;
    }

    return 0;
}