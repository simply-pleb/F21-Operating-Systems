#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Give the length of the array: ");
    
    int N;
    scanf("%d", &N);

    int *ar = (int*) malloc(N*sizeof(int));

    for(int i=0; i<N; i++){
        ar[i] = i;
    }

    for(int i=0; i<N; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");

    free(ar);
}