// This program simulates FCFS algorithm
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int proc_id; //process id
    int ar_time; //arrival time
    int br_time; //burst time
    int wt_time; //wait time
    int cp_time; //completion time
    int trnarnd; //turnaround
}process;

int compare_ar_time(const void *a, const void *b)
{
    process *p1 = (process*) a;
    process *p2 = (process*) b;

    return (p1->ar_time - p2->ar_time);   
}

void calc_time(process *proc, double *av_wt_time, double *av_trnarnd, int N)
{
    proc[0].wt_time = 0;
    proc[0].cp_time = proc[0].br_time;
    proc[0].trnarnd = proc[0].br_time;
    
    for(int i=1; i<N; i++){
        proc[i].wt_time = proc[0].ar_time;
        for(int j=0; j<i; j++){
            proc[i].wt_time += proc[j].br_time;
        }
        proc[i].wt_time -= proc[i].ar_time;
    }
    for(int i=1; i<N; i++){
        proc[i].trnarnd = proc[i].wt_time + proc[i].br_time;
        proc[i].cp_time = proc[i].trnarnd + proc[i].ar_time;
    }

    for(int i=0; i<N; i++){
        *av_wt_time += proc[i].wt_time;
        *av_trnarnd += proc[i].trnarnd;
    }
    *av_wt_time /= N;
    *av_trnarnd /= N;
}

int main(int args, char *argv[])
{
    // HANDLE INPUT
    /*
    Specify input test in the specified file in the following way
    --input.ex1--
    N                           #number of processes
    ar_time_0 br_time_0         #arrival time and burst time of process 0
    ar_time_1 br_time_1         #arrival time and burst time of process 1
    ...
    ar_time_(N-1) br_time_(N-1) #arrival time and burst time of process N-1
    */
    FILE *fp;
    fp = fopen ("input.ex1", "r+");

    int N;
    fscanf(fp, "%d", &N);
    process proc[N];
    double av_wt_time=0, av_trnarnd=0;

    for(int i=0; i<N; i++){
        proc[i].proc_id = i;
        fscanf(fp, "%d %d", &proc[i].ar_time, &proc[i].br_time);
    }

    fclose(fp);
    // 

    qsort(proc, N, sizeof(process), compare_ar_time);
    calc_time(proc, &av_wt_time, &av_trnarnd, N);

    printf("\tarrival time\t burst time\t wait time\t completion time urnaround\n");
    for(int i=0; i<N; i++){
        printf("P(%d):\t%d,\t\t %d,\t\t %d,\t\t %d,\t\t %d\n",
            proc[i].proc_id, proc[i].ar_time, proc[i].br_time, 
            proc[i].wt_time, proc[i].cp_time, proc[i].trnarnd);
    }
    printf("average wating time = %lf\n", av_wt_time);
    printf("average turnaround time = %lf\n", av_trnarnd);
}