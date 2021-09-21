#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct{
    pthread_t thread_id;
    char* text;
    int thread_num;
} thread_info;

int global_thread_cnt;

void* job(void* args){
    thread_info* th_info = (thread_info*)args;  
    
    th_info->thread_id = pthread_self();
    th_info->thread_num = ++global_thread_cnt;
    th_info->text = malloc(sizeof(char)*100);
    sprintf(th_info->text, "Hello from thread #%d with ID=%lu", th_info->thread_num, th_info->thread_id); 

    puts(th_info->text);
    // printf("%s", *(th_info->text));
}

int main(int argc, char *argv[])
{

    int N;
    if(argc > 1){
        N = atoi(argv[1]);
        if(N<=0){
            N = 5;
        }
    }
    else{
        N = 5;
    }

    printf("N = %d\n", N);
    
    pthread_t thread_id[N];
    thread_info th_info[N];

    pthread_t x = pthread_self();
    printf("Hello from main thread %lu\n", x);
    
    for(int i=0; i<N; i++){
        pthread_create(&thread_id[i], NULL, &job, &th_info[i]);
    }
    for(int i=0; i<N; i++){
        pthread_join(thread_id[i], NULL);
    }

    exit(EXIT_SUCCESS);
}
