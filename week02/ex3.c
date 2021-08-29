#include <stdio.h>

void print_triangle(int n){
    for(int h=1; h<=n; h++){
    	for(int w=0; w<n-h; w++){
	    printf(" ");
	}
    	for(int w=0; w<2*h-1; w++){
	    printf("*");
	}
    	for(int w=0; w<n-h; w++){
	    printf(" ");
	}
	printf("\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);

    print_triangle(n);
}
