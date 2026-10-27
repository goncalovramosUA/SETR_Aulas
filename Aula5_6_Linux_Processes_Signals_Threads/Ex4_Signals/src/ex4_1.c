#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig){
    /* O número na função write é o número de caracteres na string de argumento
       da função, sem contar com o /0. 
       É válido colocar nesse campo: sizeof("String Exemplo\n")-1 */
    if (sig == SIGINT)  write(STDOUT_FILENO, "Recebido SIGINT\n", 16);
    if (sig == SIGHUP)  write(STDOUT_FILENO, "Recebido SIGHUP\n", 16);
    if (sig == SIGUSR1) write(STDOUT_FILENO, "Recebido SIGUSR1\n", 17);
    if (sig == SIGCONT) write(STDOUT_FILENO, "Recebido SIGCONT\n", 17);
}

int main(void){

    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    pid_t pid = getpid();
    printf("Program PID: %d.\n", pid);
    fflush(stdout);

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGHUP, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);

    while(1){
        pause();
    }
}

/* To send a signal to the program we need to write in the terminal
    the following commands:
        $kill -USR1 PID : Sends the SIGUSR1 
        $kill -KILL PID : Terminates a process */