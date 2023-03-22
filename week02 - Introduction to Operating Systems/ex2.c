#include <stdio.h>
#include <string.h>

void print_reversed_string(char *string){
    for(int i=strlen(string)-1; i>=0; i--){
    	printf("%c", string[i]);
    }
}

int main(){
	char c[] = "Hello, my name is Ahmadsho";
	printf("%s\n", c);
    print_reversed_string(c);
	printf("\n");
}
