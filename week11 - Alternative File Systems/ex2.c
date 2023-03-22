#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *d;
    struct dirent *dr;
    
    d = opendir("/");
    if(d != NULL){
        while((dr=readdir(d)) != NULL){
            printf("%s\n", dr->d_name);
        }
        closedir(d);
    }
    
    return 0;
}