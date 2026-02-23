/**
 * (y - y_1)/(y_2 - y_1) = (x - x_1)/(x_2-x_1)
---> y = a*x + b
 * a = (y_2 - y_1)/(x_2-x_1)
   b = [y_1/(y_2 - y_1) - x_1/(x_2-x_1)]*(y_2 - y_1)
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot_i.h"
#define SECONDS 1
#define MAXDIM 100
int main(int argc , char **argv){
  gnuplot_ctrl *h1;
  double x[MAXDIM],y[MAXDIM], x1, y1, x2, y2, a, b;
  char funstring[32], cmdstring[64];
  int i;
  if (argc < 5){
    fprintf(stderr, "enter 2 points\n");
    fprintf(stderr, "usage:%s <x_1> <y_1> <x_2> <y_2>\n", argv[0]);
    return 1;
  }
  x1 = atof(argv[1]); y1 = atof(argv[2]); x2 = atof(argv[3]); y2 = atof(argv[4]);
  a = (y2 - y1)/(x2-x1);
  b = (y1/(y2 - y1) - x1/(x2-x1))*(y2 - y1);
  fprintf(stderr,"*** Example of gnuplot control through C ***\n");
  h1 = gnuplot_init();
  gnuplot_cmd(h1, "set terminal pngcairo");
  gnuplot_cmd(h1, "set output \"points001.png\"");
  gnuplot_cmd(h1, "set grid");
  gnuplot_cmd(h1, "set size square");
  gnuplot_cmd(h1, "set size ratio -1");
  gnuplot_cmd(h1, "set xtics 1");
  gnuplot_cmd(h1, "set ytics 1");
  gnuplot_setstyle(h1, "linespoints");
  gnuplot_set_axislabel(h1, "x", "x");
  gnuplot_set_axislabel(h1, "y", "y");
  for (i=0;i<MAXDIM;i++){
    x[i]=0.1*(i-MAXDIM/2);
    y[i]=a*x[i] + b;
  }
  snprintf(funstring,31,"y = %5.2f * x + %5.2f", a, b);
/*  snprintf(cmdstring,63,"set title offset 16,8 '%s' ", funstring);
  gnuplot_cmd(h1, cmdstring); */
  gnuplot_plot_coordinates(h1, x, y, MAXDIM, funstring);
  fprintf(stderr,"\n*** check generated png file ***\n");
  fprintf(stderr,"\n*** closing gnuplot handle ***\n");
  gnuplot_close(h1);
  return 0;
}
