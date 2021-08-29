#include <stdio.h>

void reverse_int(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    return;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    printf("a=%d b=%d\n", a, b);

    reverse_int(&a, &b);
    printf("a=%d b=%d\n", a, b);

    return 0;
}
