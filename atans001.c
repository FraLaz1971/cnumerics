#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define MAXDIM 1000
int main() {
    int i;
    double y[MAXDIM];
    double x[MAXDIM];
    double res_atan[MAXDIM];
    double res_atan2[MAXDIM];
    printf("#  x,   y,atan(y/x),atan2(y,x)\n");
    for(i=0;i<MAXDIM;i++){
        y[i]=MAXDIM-i*pow(-1,i);
        x[i]=i*pow(-1,i+1);;
        // atan only sees the result of the division (-1 / -1 = 1.0)
        res_atan[i] = atan(y[i]/x[i]);
        // atan2 sees both signs and knows this is the 3rd quadrant
        res_atan2[i] = atan2(y[i],x[i]);
        printf("%4.0f,%4.0f,%8.4f,%8.4f\n", x[i],y[i],res_atan[i]*180/PI,res_atan2[i]*180/PI);
    }
    return 0;
}

