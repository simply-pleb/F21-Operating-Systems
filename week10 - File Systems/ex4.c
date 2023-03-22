#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LEN 20

int main()
{
    system("bash ex4.sh");

    char *path=malloc(20);

    DIR *dir;
    struct dirent *dr;
    if ((dir = opendir("tmp")) == NULL) {
        printf("failed to access 'tmp': No such file or directory\n");
        return 1;
    }

    // ...

    while((dr=readdir(dir)) != NULL){

    }
}