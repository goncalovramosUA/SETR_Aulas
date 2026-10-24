#include <stdio.h>
#include <stdlib.h>

#define MAX_FOLDER_LEN 64
#define MAX_COMMAND_LEN 128

int main(int argc, char *argv[]){

    char* prefix = 0;
    int n = 0;
    char folderName[MAX_FOLDER_LEN];
    char command[MAX_COMMAND_LEN];
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

    for(i = 1; i <= n; i++){
        snprintf(folderName, MAX_FOLDER_LEN, "%s%d", prefix, i);
        snprintf(command, MAX_COMMAND_LEN-1, "mkdir \"%s\"", folderName);
        int status = system(command);
        if(status == -1){
            perror("system");
            return -1;
        }else{
            printf("Folder \"%s\"\n created sucessfuly", folderName);
        }
    }
    return 0;
}