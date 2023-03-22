#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void *ptr, size_t N)
{
    if(N == 0){
        free(ptr);
        return NULL;
    }
    if(ptr == NULL){
        void* new_ptr = malloc(N);
        return new_ptr;
    }

    void* new_ptr = malloc(N);

    memcpy(new_ptr, ptr, N);

    return new_ptr;
}
 
void print_array(int *ptr, int N){
    for(int i=0; i<N; i++){
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

int main()
{
    int n1 = 10;
    int *ar = my_realloc(NULL, n1*sizeof(int));

    for(int i=0; i<n1; i++){
        ar[i] = i;
    }

    printf("Original array of size %d:\n", n1);
    print_array(ar, n1);

    int n3 = 15;
    ar = my_realloc(ar, n3*sizeof(int));
    printf("Array after reallocation to size %d:\n", n3);
    print_array(ar, n3);
    
    int n2 = 5;
    ar = my_realloc(ar, n2*sizeof(int));
    printf("Array after reallocation to size %d:\n", n2);
    print_array(ar, n2);

    my_realloc(ar, 0);
}