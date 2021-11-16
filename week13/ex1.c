#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N_RES 3
#define N_PROC 5

struct running_proc{
    bool done;
    int cur[N_RES];
    int req[N_RES];
};

bool input(int *exstng, int *avlbl, struct running_proc *proc){
    FILE *fp = fopen("input.txt", "r");
    
    if(fp == NULL){
        printf("No input file found!");
        return 1;
    }

    for(int i=0; i<N_RES; i++){
        fscanf(fp, "%d", &exstng[i]);
    }

    for(int i=0; i<N_RES; i++){
        fscanf(fp, "%d", &avlbl[i]);
    }


    for(int i=0; i<N_PROC; i++){
        for(int j=0; j<N_RES; j++){
            fscanf(fp, "%d", &proc[i].cur[j]);
        }
    }

    for(int i=0; i<N_PROC; i++){
        for(int j=0; j<N_RES; j++){
            fscanf(fp, "%d", &proc[i].req[j]);
        }
    }

    fclose(fp);
    
    for(int i=0; i<N_PROC; i++){
        proc[i].done = false;
    }
}

int find_proc(int *avlbl, struct running_proc *proc){
    for(int i=0; i<N_PROC; i++){
        if(proc[i].done){
            // printf("[%d]\n", i);
            continue;
        }
        bool proc_fits=true;
        
        for(int j=0; j<N_RES; j++){
            if(proc[i].req[j] > avlbl[j]){
                // printf("[%d] %d > %d\n", i, proc[i].req[j], avlbl[j]);
                proc_fits = false;
                break;
            }
        }

        if(proc_fits == true){
            for(int j=0; j<N_RES; j++){
                // proc[i].cur[j] += proc[i].req[j];
                proc[i].req[j] = 0;
            }
            return i;
        }
    }

    return -1;
}
void termnt_proc(int *exstng, int *avlbl, struct running_proc *proc, int id){
    proc[id].done = true;
    // printf("[%d]\n", id);
    for(int i=0; i<N_RES; i++){
        avlbl[i] += proc[id].cur[i];
        proc[id].cur[i] = 0;
    }
}

int main()
{
    int exstng[N_RES];
    int avlbl[N_RES];
    struct running_proc proc[N_PROC];
    
    bool input_status = input(exstng, avlbl, proc);

    if(input_status == 1){
        return 1;
    }

    int cnt=0;
    while(cnt < N_PROC){
        int p = find_proc(avlbl, proc);
        if(p == -1){
            printf("Deadlock was detected! The following processes are deadlocked:\n");
            for(int i=0; i<N_PROC; i++){
                if(!proc[i].done){
                    printf("%d ", i);
                }
            }
            printf("\n");
            for(int i=0; i<N_RES; i++){
                printf("%d ", avlbl[i]);
            }
            return 1;
        }
        termnt_proc(exstng, avlbl, proc, p);
        printf("Proccess %d was terminated\n", p);
        cnt++;
    }

    printf("No deadlock was detected.\n");
    return 0;
}