#include <stdio.h>

void swap_int(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int qs_partition(int *ar, int l, int r){
    int pivot = ar[r];
    int i = l-1;

    for(int j = l; j<=r-1; j++){
        if(ar[j] < pivot){
            i++;
            swap_int(&ar[i], &ar[j]);
        }
    }
    swap_int(&ar[i+1], &ar[r]);
    
    return (i+1); 
}

void quick_sort(int *ar, int l, int r){
    if(l < r){
        int p = qs_partition(ar, l, r);
        quick_sort(ar, l, p-1);
        quick_sort(ar, p+1, r);
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

	quick_sort(ar, 0, n-1);

	printf("Sorted array: ");
	for(int i=0; i<n; i++){
		printf("%d ", ar[i]);	
	}
	printf("\n");

	return 0;
}

