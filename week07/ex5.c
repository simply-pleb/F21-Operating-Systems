#include <stdio.h>

int main() {
    
    char **s;
    char foo[] = "Hello World";
    
    s = &foo;
    printf("s is %s\n",s);
    
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    
    return (0);
    
    // Below is an alternative solution, which looks more corrent, 
    // but it adds new lines of code

    // char **s;
    // char foo[] = "Hello World";
    
    // char *ptr = &foo;

    // s = &ptr;
    // // printf("%p\n", foo);
    // // printf("%p\n", &foo);
    // // printf("%c\n", *foo);
    // printf("s is %s\n", *s);
    
    // s[0] = foo;
    // printf("s[0] is %s\n", s[0]);
    
    // return (0);
}