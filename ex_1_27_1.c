/**
 f1: 2*x - y  = 0 --> y = 2*x
 f2: x - y*(3/2) = 0 --> y*(3/2) = x --> y = x*(2/3)
 f3: -x + 2*y = 0 --> 2*y = x --> y = x/2
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot_i.h"
#define SECONDS 1
#define MAXDIM 100
int main(){
  gnuplot_ctrl *h1;
  double x1[MAXDIM],y1[MAXDIM],x2[MAXDIM],y2[MAXDIM],x3[MAXDIM],y3[MAXDIM];
  int i;
  for (i=0;i<MAXDIM;i++){
    x1[i]=0.1*(i-MAXDIM/2);x2[i]=x1[i];x3[i]=x1[i];
    y1[i]=2.0*x1[i];y2[i]=x2[i]*2.0/3.0;y3[i]=x3[i]/2.0 ;
  }
  fprintf(stderr,"*** Example of gnuplot control through C ***\n");
  h1 = gnuplot_init();
  gnuplot_cmd(h1, "set terminal pngcairo");
  gnuplot_cmd(h1, "set output \"f1.png\"");
  gnuplot_cmd(h1, "set grid");
  gnuplot_setstyle(h1, "linespoints");
  gnuplot_set_axislabel(h1, "x", "x_1");
  gnuplot_set_axislabel(h1, "y", "y_1");
  gnuplot_plot_coordinates(h1, x1, y1, MAXDIM, "2x - y = 0");
  sleep(SECONDS);
  gnuplot_resetplot(h1);
  gnuplot_cmd(h1, "set output \"f2.png\"");
  gnuplot_plot_coordinates(h1, x2, y2, MAXDIM, "x - y*(3/2) = 0");
  sleep(SECONDS);
  gnuplot_resetplot(h1);
  gnuplot_cmd(h1, "set output \"f3.png\"");
  gnuplot_plot_coordinates(h1, x3, y3, MAXDIM, "-x + 2*y = 0");
/*  gnuplot_plot_equation(h1, "sin(x)", "Sine wave"); */
  fprintf(stderr,"\n*** check generated png files ***\n");
  fprintf(stderr,"\n*** closing gnuplot handle ***\n");
  gnuplot_close(h1);
  return 0;
}
