#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
    pid_t parnt_proc = getpid();
    pid_t chld_proc = fork();

    wait(NULL);
    
    int n=42;
    if(getpid() == parnt_proc){
        printf("Hello from parent [%d - %d]\n", parnt_proc, n);
    }
    else{
        printf("Hello from child [%d - %d]\n", chld_proc, n);
    }

    return EXIT_SUCCESS;
}