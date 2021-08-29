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

void print_right_triangle(int n){	
    for(int h=1; h<=n; h++){
    	for(int w=0; w<h; w++){
	    	printf("*");
		}
		printf("\n");
    }
}
void print_obtuse_triangle(int n){
	for(int h=1; h<=n/2+n%2; h++){
		for(int w=0; w<h; w++){
			printf("*");
		}
		printf("\n");
	}
	for(int h=n/2; h>=1; h--){
		for(int w=0; w<h; w++){
			printf("*");
		}
		printf("\n");
	}
}
void print_rectangle(int n){
    for(int h=1; h<=n; h++){
    	for(int w=1; w<=n; w++){
	    	printf("*");
		}
		printf("\n");
    }
}

int main(void){
    printf("Press 0 to get an isosceles triangle\n");
    printf("Press 1 to get a right triangle\n");
    printf("Press 2 to get an obtuse triangle\n");
    printf("Press 3 to get a rectangle triangle\n");
    int shape;
    scanf("%d", &shape);
    
    printf("what is the height of the shape?: ");
    int n; 
    scanf("%d", &n);

    switch(shape){
	case 0:
	    print_triangle(n);
	    break;
	case 1:
	    print_right_triangle(n);
	    break;
	case 2:
		print_obtuse_triangle(n);
		break;	
	case 3:
		print_rectangle(n);
		break;
	default:
		break;
	}

	return 0;
}
