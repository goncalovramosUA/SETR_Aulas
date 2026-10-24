#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FOLDER_LEN 64

int main(int argc, char *argv[]){

    char* prefix = 0;
    int n = 0;
    char **cmd_args;
    int i;

    if(argc < 3){
        fprintf(stderr, "Error: Not enough parameters.\n");
        return -1;
    }

    prefix = argv[1];
    n = atoi(argv[2]);

    if (n < 1 || n > 99){
        fprintf(stderr, "Error: n must be between 1 and 99.\n");
        return -1;
    }

    cmd_args = malloc((n+2) * sizeof(char*));
    if (cmd_args == NULL) {
        perror("malloc");
        return -1;
    }

    cmd_args[0] = "mkdir";

    for(i = 1; i <= n; i++){
        cmd_args[i] = malloc(MAX_FOLDER_LEN);
        snprintf(cmd_args[i], MAX_FOLDER_LEN, "%s%d", prefix, i);
    }

    execvp("mkdir", cmd_args);
    perror("execvp");

    return -1;
}