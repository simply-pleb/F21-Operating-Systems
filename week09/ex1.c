#include <stdio.h>
#include <string.h>


#define CNT_MAX 500
#define EIGHTH_BIT 128
#define min(a, b) a<b?a:b

const int M = 1e4+5;
// const int N = 1e2+5;

struct virtual_page{
    int page_frame;
    int age_counter;
    char loaded;
};

int global_cnt_used_frames=0;

int evict_least_used(struct virtual_page *vp){
    int mn=CNT_MAX;
    int idx=-1;
    
    for(int i=1; i<=M; i++){
        // if(vp[i].loaded){
        //     printf("Ev: %d loaded\n", i);
        // }
        if(vp[i].loaded && mn > vp[i].age_counter){
            mn = vp[i].age_counter;
            idx = i;
        }
    }

    if(idx != -1){
        // printf("cnt=%d ", vp[idx].age_counter);
        vp[idx].age_counter = 0;
        vp[idx].loaded = 0;
        global_cnt_used_frames --;
    }

    return idx;
}

void incr_clock_cnt(struct virtual_page *vp, int cnt){
    for(int t=0; t<cnt; t++){
        for(int i=1; i<=M; i++){
            // printf("CL: %d{%d} -> %d\n", i, vp[i].loaded, vp[i].age_counter);
            if(vp[i].loaded){
                if(vp[i].age_counter == 0){
                    vp[i].loaded = 0;
                    global_cnt_used_frames --;
                    // printf("CL: out %d\n", i);
                }
                else{
                    vp[i].age_counter >>= 1;
                }
            }
        }
    }
}

void load_to_frame(struct virtual_page *vp, int idx, int N_frames){
    if(global_cnt_used_frames >= N_frames){
        int lu;
        lu = evict_least_used(vp);
        vp[idx].page_frame = vp[lu].page_frame; 
        // printf("LU: %d --> %d\n", lu, idx);
    }
    else{
        vp[idx].page_frame = global_cnt_used_frames;
    }

    vp[idx].loaded = 1;
    global_cnt_used_frames ++;
}

int main()
{
    // printf("%d\n", (0^(EIGHTH_BIT)>>1)^EIGHTH_BIT);
    int n, m;
    scanf("%d %d", &n, &m);

    struct virtual_page vp[M];     
    int t[m+10], a[m+10], log[m+10];

    memset(vp, 0, sizeof(vp));

    for(int i=0; i<m; i++){
        scanf("%d %d", &t[i], &a[i]);
    }

    int cnt_hit=0, cnt_miss=0;
    int t_cur, t_prev=t[0];

    int cnt=0;
    for(int i=0; i<m; i++){
        t_cur=t[i];
        incr_clock_cnt(vp, t_cur-t_prev-1);
        if(t_cur-t_prev){
            cnt += t_cur-t_prev-1;
        }
        if(t[i+1]-t_cur>0){
            incr_clock_cnt(vp, 1);
            cnt ++;
        }

        if(vp[a[i] ].loaded == 0){
            cnt_miss++;
            log[i] = 0;
            load_to_frame(vp, a[i], n);
        }
        else{
            cnt_hit++;
            log[i] = 1;
        }
        
        if((vp[a[i]].age_counter^EIGHTH_BIT) > vp[a[i]].age_counter){
            vp[a[i]].age_counter ^= EIGHTH_BIT;
        }
        t_prev = t_cur;
        // printf("L: %d, cnt=%d\n", a[i], vp[a[i]].age_counter);
        // vp[a[i]].loaded = 1;
    }
    // printf("%d\n", cnt);

    for(int i=0; i<m; i++){
        printf("%d\n", log[i]);
    }

    double r = (double)cnt_hit/cnt_miss;
    printf("%lf\n", r);
}