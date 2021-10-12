#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/time.h>
#include <sys/resource.h>

#define MB 1048576
#define KB 1024
#define MICRO 1e6

void print_rusage(struct rusage *res)
{
    printf("user CPU time used: %ld\n", res->ru_utime.tv_sec*MICRO+res->ru_utime.tv_usec);
    printf("system CPU time used: %ld\n", res->ru_stime.tv_sec*MICRO+res->ru_stime.tv_usec);
    printf("system CPU time used: %ld\n", res->ru_maxrss);
    printf("integral shared memory size: %ld\n", res->ru_ixrss);
    printf("integral unshared data size: %ld\n", res->ru_idrss);
    printf("integral unshared stack size: %ld\n", res->ru_isrss);
    printf("page reclaims (soft page faults): %ld\n", res->ru_minflt);
    printf("page faults (hard page faults): %ld\n", res->ru_majflt);
    printf("swaps: %ld\n", res->ru_nswap);
    printf("block input operations: %ld\n", res->ru_inblock);
    printf("block output operations: %ld\n", res->ru_oublock);
    printf("IPC messages sent: %ld\n", res->ru_msgsnd);
    printf("IPC messages received: %ld\n", res->ru_msgrcv);
    printf("signals received: %ld\n", res->ru_nsignals);
    printf("voluntary context switches: %ld\n", res->ru_nvcsw);
    printf("involuntary context switches: %ld\n", res->ru_nivcsw);
    printf("\n");
}

int main()
{
    struct rusage *res = malloc(sizeof(struct rusage));
    char *ptr;
    char flag;
    for(int i=0; i<10; i++){
        ptr = malloc(10*MB);
        memset(ptr, 0, 10*MB);
        flag = getrusage(RUSAGE_SELF, res);
        print_rusage(res);
        sleep(1);
        free(ptr);
    }    
}