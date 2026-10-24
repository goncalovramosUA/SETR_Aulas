#include <stdio.h>
#include <stdlib.h>

#define MAX_FOLDER_LEN 64
#define MAX_COMMAND_LEN 128

int main(int argc, char *argv[]){

    char* prefix = 0;
    int n = 0;
    char folderName[MAX_FOLDER_LEN];
    char command[MAX_COMMAND_LEN];

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

    for(int i = 1; i <= n; i++){
        char option;
        snprintf(folderName, MAX_FOLDER_LEN, "%s%d", prefix, i);
        printf("Do you want to remove folder \"%s\" (y/n): ", folderName);
        scanf(" %c", &option);
        if (option != 'y' && option != 'Y') {
            printf("Skipping \"%s\"...\n", folderName);
            continue;
        }
            
        snprintf(command, MAX_COMMAND_LEN-1, "rmdir \"%s\"", folderName);
        int status = system(command);
        if(status == -1){
            perror("system");
            return -1;
        }else{
            printf("\nFolder \"%s\" removed sucessfuly. \n", folderName);
        }
    }
    return 0;
}