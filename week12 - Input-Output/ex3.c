#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>

#define NUM_OF_KEYS 256

/*
P(25) + E(18) = "I passed the Exam!"
C(46) + A(30) + P(25) = "Get some cappuccino!"
G(34) + L(38) + H(35) = "Good luck and have fun!"
*/

void check_kbrd_comb_PE(int *key_status){
    int no_other_key=1;
    for(int i=0; i<NUM_OF_KEYS; i++){
        if(i==25 || i==18){
            continue;
        }
        if(key_status[i]==2){
            no_other_key=0;
        }
    }
    
    if(no_other_key && key_status[25]==2 && key_status[18]==2){
        printf("I passed the Exam!\n");
    }
}
void check_kbrd_comb_CAP(int *key_status){
    int no_other_key=1;
    for(int i=0; i<NUM_OF_KEYS; i++){
        if(i==46 || i==30 || i==25){
            continue;
        }
        if(key_status[i]==2){
            no_other_key=0;
        }
    }

    if(no_other_key && key_status[46]==2 && key_status[30]==2 && key_status[25]==2){
        printf("Get some cappuccino!\n");
    }
}
void check_kbrd_comb_GLHF(int *key_status){
    int no_other_key=1;
    for(int i=0; i<NUM_OF_KEYS; i++){
        if(i==34 || i==38 || i==35 || i==33){
            continue;
        }
        if(key_status[i]==2){
            no_other_key=0;
        }
    }

    if(no_other_key && key_status[34]==2 && key_status[38]==2 && key_status[35]==2){
        printf("Good luck and have fun!\n");
    }
}

int main(){
    printf("P + E = \"I passed the Exam!\"\n\
C + A + P = \"Get some cappuccino!\"\n\
G + L + H = \"Good luck and have fun!\"\n");

    char* kbrd = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";

    int fd = open(kbrd, 0);
    if (fd < 0){
        printf("Try to run with super user permission.\n");
        return 1;
    }

    int key_status[NUM_OF_KEYS];

    struct input_event evnt;
    while(1){
        size_t b = read(fd, &evnt, sizeof(evnt));
        if(evnt.type==EV_KEY){
            key_status[evnt.code]=evnt.value;

            check_kbrd_comb_CAP(key_status);
            check_kbrd_comb_PE(key_status);
            check_kbrd_comb_GLHF(key_status);
        }
    }

    return 0;
}