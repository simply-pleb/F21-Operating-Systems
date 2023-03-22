#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <unistd.h>

// the first word from string s2 gets copied into the string s1
void put_first_word(char *s1, char *s2){
	// s1 = "";

	int i=0;
	while(1){
		if(s2[i] == ' ' || s2[i] == '\t' || s2[i] == '\n' || s2[i] == '\0'){
			break;
		}
		// printf("%c", *(s2+i));
		s1[i] = s2[i];
		i++;
	}
}

void run()
{
	char *command = malloc(100*sizeof(char));
	char *command_short = malloc(100*sizeof(char));
	printf("$ ");
	fgets(command, 100, stdin);

	put_first_word(command_short, command);

	// printf("%s", command_short);
	system(command_short);
}

int main()
{
	while(1){
		run();
	}
}
