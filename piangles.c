#include <stdio.h>
#include <math.h>
const double pi=4*atan(1);
double dd2rad(double d){
  return d*pi/180.0;
}
double rad2dd(double r){
  return r*180/pi;
}
int main(){
  int i; char *pimul[16];
  float x[100],y1[100],y2[100];
  fprintf(stderr, "pi   =%9.6f\n", pi);
  fprintf(stderr, "pi/2 = %6.4f = %5.2f deg\n", pi/2,rad2dd(pi/2));
  fprintf(stderr, "pi/3 = %6.4f = %5.2f deg\n", pi/3,rad2dd(pi/3));
  fprintf(stderr, "pi/4 = %6.4f = %5.2f deg\n", pi/4,rad2dd(pi/4));
  fprintf(stderr, "pi/6 = %6.4f = %5.2f deg\n", pi/6,rad2dd(pi/6));
  fprintf(stderr,"\n");
  fprintf(stderr, "sin(0)    = %6.4f  cos(0) =  %6.4f\n", sin(0), cos(0));
  fprintf(stderr, "sin(pi)   = %6.4f cos(pi) =  %6.4f\n", sin(pi), cos(pi));
  fprintf(stderr, "sin(pi/2) = %6.4f cos(pi/2) = %6.4f\n", sin(pi/2),cos(pi/2));
  fprintf(stderr, "sin(pi/3) = %6.4f cos(pi/3) = %6.4f\n", sin(pi/3),cos(pi/3));
  fprintf(stderr, "sin(pi/4) = %6.4f cos(pi/4) = %6.4f\n", sin(pi/4),cos(pi/4));
  fprintf(stderr, "sin(pi/6) = %6.4f cos(pi/6) = %6.4f\n", sin(pi/6),cos(pi/6));

  x[0]=0;x[1]=pi/6;x[2]=pi/4;x[3]=pi/3;x[4]=pi/2;
  x[5]=pi*2/3;x[6]=pi*3/4;x[7]=pi*5/6;x[8]=pi;x[9]=pi*7/6;
  x[10]=pi*5/4;x[11]=pi*3/2;x[12]=pi*5/3;x[13]=pi*7/4;x[14]=pi*11/6;x[15]=2*pi;
  pimul[0]="pi*0";pimul[1]="pi/6";pimul[2]="pi/4";pimul[3]="pi/3";pimul[4]="pi/2";
  pimul[5]="pi*2/3";pimul[6]="pi*3/4";pimul[7]="pi*5/6";pimul[8]="pi";pimul[9]="pi*7/6";
  pimul[10]="pi*5/4";pimul[11]="pi*3/2";pimul[12]="pi*5/3";pimul[13]="pi*7/4";pimul[14]="pi*11/16";pimul[15]="2*pi";
  printf("#p*n,a(rad),a(deg),sin(),cos()\n");
  for (i=0;i<16;i++){
    y1[i]=sin(x[i]);
    y2[i]=cos(x[i]);
    printf("%s,%6.4f,%6.4f,%6.4f,%6.4f\n",pimul[i],x[i],rad2dd(x[i]),y1[i],y2[i]);
  }
  return 0;
}
