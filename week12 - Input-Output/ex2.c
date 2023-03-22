#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>


int main(void){
    char* kbrd = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";

    int fd = open(kbrd, 0);
    if (fd < 0){
        printf("Try to run with super user permission.\n");
        return 1;
    }

    struct input_event evnt;
    while(1){
        size_t b = read(fd, &evnt, sizeof(evnt));
        if(evnt.type==EV_KEY){
            if(evnt.value==1){
                printf("PRESSED %x (%d)\n", evnt.code, evnt.code);
            }
            else if(evnt.value==0){
                printf("RELEASED %x (%d)\n", evnt.code, evnt.code);
            }
        }
    }

    return 0;
}