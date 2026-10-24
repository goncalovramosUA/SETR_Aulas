#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){

    execlp("ps", "ps", "aux", NULL);
    
    perror("execlp");

    return 0; 
}