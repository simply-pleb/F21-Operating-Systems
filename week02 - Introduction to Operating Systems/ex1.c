#include <stdio.h>
#include <float.h>
#include <limits.h>

int i;
float f;
double lf;

int main(){
    i = INT_MAX;
    f = FLT_MAX;
    lf = DBL_MAX;

    printf("Int max: %d \nFloat max: %f \nDouble max: %lf\n", i, f, lf);

    return 0;
}
