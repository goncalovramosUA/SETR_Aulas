#include <stdio.h>
#include <stdlib.h>

int main(void){

    int status = system("ps aux");
    if (status == -1){
        perror("system");
        return -1;
    }
    return 0; 
}