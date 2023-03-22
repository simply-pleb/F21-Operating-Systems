#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MB 1048576
#define KB 1024


int main()
{
    char *ptr;
    for(int i=0; i<10; i++){
        ptr = malloc(10*MB);
        memset(ptr, 0, 10*MB);
        sleep(1);
        free(ptr);
    }
}