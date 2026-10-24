#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FOLDER_LEN 64

int main(int argc, char *argv[]){

    char* prefix = 0;
    int n = 0;
    int count = 1;
    char **cmd_args;

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

    cmd_args = malloc((n+2) * sizeof(char *));
    if (cmd_args == NULL) {
        perror("malloc");
        return -1;
    }
    cmd_args[0] = "rmdir";

    for (int i = 1; i <= n; i++) {
        char tempFolder[MAX_FOLDER_LEN];
        char opt;

        snprintf(tempFolder, sizeof(tempFolder), "%s%d", prefix, i);

        printf("Do you want to remove folder \"%s\" (y/n): ", tempFolder);
        scanf(" %c", &opt);
        
        if (opt == 'y' || opt == 'Y') {
            cmd_args[count] = malloc(MAX_FOLDER_LEN);
            snprintf(cmd_args[count], MAX_FOLDER_LEN, "%s", tempFolder);
            count++;
        } else {
            printf("Skipping \"%s\"...\n", tempFolder);
        }
    }

    if (count == 1) {
        printf("No folders selected to remove.\n");
        free(cmd_args);
        return 0;
    }
    cmd_args[count] = NULL;

    execvp("rmdir", cmd_args);
    perror("system");

    return 0;
}