#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323844
#define MAXDIM 100
int main(int argc, char **argv){
     int i;
     float frac;
     double x[MAXDIM],y[MAXDIM];
     if (argc<2){
       fprintf(stderr,"usage:%s <n>\n", argv[0]);
       return 1;
     }
     frac = atof(argv[1]);
     for(i=0;i<MAXDIM;i++){
       x[i]=i*PI/frac-(MAXDIM/2)*PI/frac;
       y[i]=cos(x[i]);
       printf("%6.3f\t%6.3f\n",x[i],y[i]);
     }
     return 0;
}
