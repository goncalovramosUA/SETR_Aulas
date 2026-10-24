#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    execlp("wc", "wc", "src/teste.txt", "-m", "-w", NULL);

    perror("system");
    
    return 0;
}