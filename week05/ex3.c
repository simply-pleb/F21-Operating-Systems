#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 100
#define RAND_RANGE 1000

typedef struct 
{
    pthread_t thread_id;
    // int val;
}thread_info;


int buffer[BUF_SIZE];
int N;
int producer_sleeping, consumer_sleeping; 

void* produce(void* args){
    thread_info* th_info = (thread_info*) args;
    th_info->thread_id = pthread_self();

    int val;

    while(1){
        if(producer_sleeping){
            continue;
        }

        val = rand()%RAND_RANGE+1;
        
        if(N < BUF_SIZE){
            buffer[N] = val;
            printf("Wrote %d at position %d.\n", buffer[N], N);
            N++;
            consumer_sleeping = 0;
        }
        else{
            producer_sleeping = 1;
            printf("Failed to write, buffer is full.\n");
        }
    }
    
}

void* consume(void* args){
    thread_info* th_info = (thread_info*) args;
    th_info->thread_id = pthread_self();

    while(1){
        if(consumer_sleeping){
            continue;
        }
        if(N > 0){
            N--;    
            printf("Read %d at position %d.\n", buffer[N], N);
            producer_sleeping = 0;
        }
        else{
            consumer_sleeping = 1;
            printf("Failed to read, buffer is empty.\n");
        }
    }
}

int main()
{
    srand(time(NULL));
    
    thread_info th_info[2];
    
    producer_sleeping = 0;
    consumer_sleeping = 1;

    pthread_create(&th_info[0].thread_id, NULL, &produce, &th_info[0]);
    pthread_create(&th_info[1].thread_id, NULL, &consume, &th_info[1]);

    pthread_join(th_info[0].thread_id, NULL);
    pthread_join(th_info[1].thread_id, NULL);
    

    exit(EXIT_SUCCESS);
}