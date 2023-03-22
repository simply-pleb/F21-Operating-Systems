#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main(int argc, char *argv[])
{  
    int n;
    if(argc == 1){
        n = 3; 
    }
    else{
        n = atoi(argv[1]);
        if(n==0){
            n = 3;
        }
    }

    pid_t parnt_proc = getpid();
    for(int i=0; i<n; i++){
        pid_t chld_proc = fork();
    }
    sleep(5);

    // if(parnt_proc == getpid()){
        // char *command = malloc(sizeof(char)*18);
        // strcat(command, "pstree ");
        
        // char *buffer = malloc(sizeof(char)*10);
        // sprintf(buffer, "%d", getpid());

        // strcat(command, buffer);

        // system(command);
    // }

    return EXIT_SUCCESS;
}