#include <stdio.h>
#include <stdlib.h>


#define QUANTUM 2

typedef struct{
    int proc_id; //process id
    int ar_time; //arrival time
    int br_time; //burst time
    int wt_time; //wait time
    int cp_time; //completion time
    int trnarnd; //turnaround
}process;

struct proc_node{
	process val;
	struct proc_node *next;
}proc_node;

typedef struct{
	struct proc_node *head;
}proc_list;

void proc_list_insert(proc_list list, process val)
{ 
    struct proc_node *prev = list.head;
	while(prev->next != NULL){
		prev = prev->next;
	}

    struct proc_node *cur = malloc(sizeof(struct proc_node));
    prev->next = cur;
    cur->val = val;  
}

int compare_ar_time(const void *a, const void *b)
{
    process *p1 = (process*) a;
    process *p2 = (process*) b;

    return (p1->ar_time - p2->ar_time);   
}

void round_robin(process *proc, int N, proc_list list)
{
    int queue_token[N];
    int preempt_time[N];

    for(int i=0; i<N; i++){
        queue_token[proc[i].proc_id] = 0;
        preempt_time[proc[i].proc_id] = proc[i].ar_time;
    }

    // proc_list queue;
    // struct proc_node *queue_head = malloc(sizeof(struct proc_node));

    int cnt_done=0, cnt_done_prev=0, cnt_served=0;
    int queue_round=0; // queue round is increment when all ready proc were preempted or blocked.
    int cur_time=0;
    while(cnt_done < N){
        int time_inter = QUANTUM;
        short int flag = 0;
        if(cnt_served == N-cnt_done_prev){
            cnt_done_prev = cnt_done;
            cnt_served = 0;
            queue_round ++;
        }
        for(int i=0; i<N; i++){
            if(proc[i].ar_time <= cur_time && proc[i].br_time>0){
                if(queue_token[proc[i].proc_id] > queue_round){
                    continue;
                }
                proc[i].br_time -= QUANTUM;
                if(proc[i].br_time<=0){ // check if the process is done
                    time_inter += proc[i].br_time;
                    proc[i].br_time = 0;
                    cnt_done ++;
                }
                
                int br_prev = proc[i].br_time; // save the value of burst time
                
                proc[i].br_time = time_inter; // make the burst time temporarily equal to the quntum, in order to memorize the instance
                proc[i].wt_time = cur_time - preempt_time[proc[i].proc_id]; //calculate the wait time based on preemptions
                preempt_time[proc[i].proc_id] = cur_time + time_inter; //calculate preemption time
                
                proc_list_insert(list, proc[i]); // memoate the instance 
                proc[i].br_time = br_prev; // give the previous value of burst time

                queue_token[proc[i].proc_id] = queue_round+1; // increment the token so this process can be processed only 
                                                              // after all other ready processes of this round were processed
                cnt_served++;
                break;
            }
        }
        cur_time += time_inter; 
    }
}

void calc_time(proc_list list, double *av_wt_time, double *av_trnarnd, int N)
{
    
    // struct proc_node *node;
    // node = proc->head->next;

    // while(node != NULL){
    //     printf("%d %d\n", node->val.proc_id, node->val.br_time);
    //     node = node->next;
    // }

    list.head->val.wt_time = 0;
    list.head->val.cp_time = list.head->val.br_time;
    list.head->val.trnarnd = list.head->val.br_time;
    
    struct proc_node *cur;
    cur = list.head->next;

    cur = list.head->next;
    while(cur != NULL){
        cur->val.trnarnd = cur->val.wt_time + cur->val.br_time;
        cur->val.cp_time = cur->val.trnarnd + cur->val.ar_time;
        
        cur = cur->next;
    }
    
    cur = list.head->next;
    while(cur != NULL){
        *av_wt_time += cur->val.wt_time;
        *av_trnarnd += cur->val.trnarnd;
        
        cur = cur->next;
    }

    printf("%d", N);
    *av_wt_time /= N;
    *av_trnarnd /= N;
}

int main()
{
    // HANDLE INPUT
    /*
    Specify input test in the specified file in the following way
    --input.ex3--
    N                           #number of processes
    ar_time_0 br_time_0         #arrival time and burst time of process 0
    ar_time_1 br_time_1         #arrival time and burst time of process 1
    ...
    ar_time_(N-1) br_time_(N-1) #arrival time and burst time of process N-1
    */
    FILE *fp;
    fp = fopen ("input.ex3", "r+");

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

    proc_list list;
    struct proc_node *head = malloc(sizeof(struct proc_node));
    list.head = head;


    qsort(proc, N, sizeof(process), compare_ar_time);
    round_robin(proc, N, list);
    calc_time(list, &av_wt_time, &av_trnarnd, N);


    printf("Quantum size is: %d\n", QUANTUM);
    printf("\tarrival time\t burst time\t wait time\t completion time turnaround\n");
    struct proc_node *cur;
    cur = list.head->next;
    while(cur != NULL){
        printf("P(%d):\t%d,\t\t %d,\t\t %d,\t\t %d,\t\t %d\n",
            cur->val.proc_id, cur->val.ar_time, cur->val.br_time, 
            cur->val.wt_time, cur->val.cp_time, cur->val.trnarnd);
        cur = cur->next;
    }
    printf("average wating time = %lf\n", av_wt_time);
    printf("average turnaround time = %lf\n", av_trnarnd);
}