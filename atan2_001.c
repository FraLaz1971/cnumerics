#include <stdio.h>
#include <math.h>
#define MAXDIM 100
int main(){
  int i;
  double x[MAXDIM],y[MAXDIM];
  i=0;x[i]=0.5;y[i]=0.5;
  printf("%5.2lf %5.2lf %7.3lf\n",x[i], y[i], atan2(x[i], y[i]));
  i=1;x[i]=-0.5;y[i]=-0.5;
  printf("%5.2lf %5.2lf %7.3lf\n",x[i], y[i], atan2(x[i], y[i]));
  i=2;x[i]=5;y[i]=5;
  printf("%5.2lf %5.2lf %7.3lf\n",x[i], y[i], atan2(x[i], y[i]));
  i=3;x[i]=10;y[i]=20;
  printf("%5.2lf %5.2lf %7.3lf\n",x[i], y[i], atan2(x[i], y[i]));
  i=4;x[i]=5;y[i]=-5;
  printf("%5.2lf %5.2lf %7.3lf\n",x[i], y[i], atan2(x[i], y[i]));
  i=5;x[i]=-10;y[i]=10;
  printf("%5.2lf %5.2lf %7.3lf\n",x[i], y[i], atan2(x[i], y[i]));
  return 0;
}
