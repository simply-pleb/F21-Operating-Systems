#include <stdio.h>

void swap_int(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int *ar, int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1; j++){
			if(ar[j] > ar[j+1]){
				swap_int(&ar[j], &ar[j+1]);
			}
		}
	}
}

int main(){
	int ar[] = {3, 8, 9, 1, 2, 6, 5, 4, 7};
	int n = sizeof(ar)/sizeof(int);	

	printf("Initial array: ");
	for(int i=0; i<n; i++){
		printf("%d ", ar[i]);	
	}
	printf("\n");	

	bubble_sort(ar, n);

	printf("Sorted array: ");
	for(int i=0; i<n; i++){
		printf("%d ", ar[i]);	
	}
	printf("\n");

	return 0;
}

