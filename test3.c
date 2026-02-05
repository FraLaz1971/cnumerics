#include <stdio.h>
#include <math.h>
#define MAXDIM 100
int main(){
  double x;
  int i;
  const double pi=4*atan(1);
/*    printf("%8.2f %8.2f\n",-1.568,tan(-1.569));
    printf("%8.2f %8.2f\n",-1.568,tan(-1.568));
    printf("%8.2f %8.2f\n",-1.565,tan(-1.565));
    printf("%8.2f %8.2f\n",-1.56,tan(-1.56));
    printf("%8.2f %8.2f\n",-1.55,tan(-1.55));*/
  for(i=1;i<MAXDIM;i++){
    x=pi*i/MAXDIM-pi*0.5;
    printf("%8.2f %8.2f\n",x,tan(x));
  }
/*    printf("%8.2f %8.2f\n",1.55,tan(1.55));
    printf("%8.2f %8.2f\n",1.56,tan(1.56));
    printf("%8.2f %8.2f\n",1.565,tan(1.565));
    printf("%8.2f %8.2f\n",1.568,tan(1.568));
    printf("%8.2f %8.2f\n",1.569,tan(1.569));*/
  return 0;
}
