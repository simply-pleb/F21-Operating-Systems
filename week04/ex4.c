#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define WAIT_TIME 10000

int number_of_bg_proc;

void run(pid_t parnt_proc)
{
	char *command = malloc(100*sizeof(char));
	
	printf("\\: ");
	fgets(command, 10000, stdin);
	char *token = strtok(command, " ");

	char *argv[100];
	
	int argc=0;
	while(token != NULL){
		for(int i=0; i<100; i++){
			if(token[i] == '\n'){
				token[i] = (char)(0);
			}
			if(token[i] == (char)(0)){
				break;
			}
		}
		
		argv[argc] = malloc(100*sizeof(char));
		argv[argc] = token;
      	token = strtok(NULL, " ");
		argc++;
	}
	argv[argc] = malloc(100*sizeof(char));
	argv[argc] = NULL;
	argc++;
	
	if(argv[argc-2][0] == '&'){
		argv[argc-2] = NULL;
		argc--;
	}

	pid_t chld_proc = fork();

	if(parnt_proc != getpid()){
		int status = execvp(argv[0], argv);
		if(status){
			exit(0);
		}
	}
}

int main()
{
    pid_t parnt_proc = getpid();

	while(1){
		run(parnt_proc);
		#ifdef WIN32
			printf("please run on unix.\n");
			for(int i=0; i<WAIT_TIME; i++);
		#else
			usleep(WAIT_TIME);
		#endif
	}
}