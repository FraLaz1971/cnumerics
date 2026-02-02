#include <stdio.h>
#include <math.h>
double pi=4*atan(1);
double dd2rad(double d){
  return d*pi/180.0;
}
double rad2dd(double r){
  return r*180/pi;
}
int main(){
  int i; char *pimul[10];
  float x[100],y1[100],y2[100];
  printf( "pi   =%9.6f\n", pi);
  printf( "pi/2 = %6.4f = %5.2f deg\n", pi/2,rad2dd(pi/2));
  printf( "pi/3 = %6.4f = %5.2f deg\n", pi/3,rad2dd(pi/3));
  printf( "pi/4 = %6.4f = %5.2f deg\n", pi/4,rad2dd(pi/4));
  printf( "pi/6 = %6.4f = %5.2f deg\n", pi/6,rad2dd(pi/6));
  puts("");
  printf( "sin(0)    = %6.4f  cos(0) =  %6.4f\n", sin(0), cos(0));
  printf( "sin(pi)   = %6.4f cos(pi) =  %6.4f\n", sin(pi), cos(pi));
  printf( "sin(pi/2) = %6.4f cos(pi/2) = %6.4f\n", sin(pi/2),cos(pi/2));
  printf( "sin(pi/3) = %6.4f cos(pi/3) = %6.4f\n", sin(pi/3),cos(pi/3));
  printf( "sin(pi/4) = %6.4f cos(pi/4) = %6.4f\n", sin(pi/4),cos(pi/4));
  printf( "sin(pi/6) = %6.4f cos(pi/6) = %6.4f\n", sin(pi/6),cos(pi/6));

  x[0]=0;x[1]=pi/6;x[2]=pi/4;x[3]=pi/3;x[4]=pi/2;
  x[5]=pi;x[6]=pi+pi/6;x[7]=pi*5/4;x[8]=pi*3/2;x[9]=2*pi;
  pimul[0]="pi*0";pimul[1]="pi/6";pimul[2]="pi/4";pimul[3]="pi/3";pimul[4]="pi/2";
  pimul[5]="pi";pimul[6]="pi*7/6";pimul[7]="pi*3/4";pimul[8]="pi*3/2";pimul[9]="2pi";
  printf("p*n,a(rad),a(deg),sin(),cos()\n");
  for (i=0;i<10;i++){
    y1[i]=sin(x[i]);y2[i]=cos(x[i]);
    printf("%s,%6.4f,%6.4f,%6.4f,%6.4f\n",pimul[i],x[i],rad2dd(x[i]),y1[i],y2[i]);
  }
  return 0;
}
