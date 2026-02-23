/**
x y
-2 5
-1 7
0 9
1 11
2 13
3 15
4 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot_i.h"
#define SECONDS 1
#define MAXDIM 7
int main(){
  gnuplot_ctrl *h1;
  double x1[MAXDIM],y1[MAXDIM];
  x1[0] = -2; y1[0] = 5;
  x1[1] = -1; y1[1] =7;
  x1[2] = 0; y1[2] =9;
  x1[3] = 1; y1[3] =11;
  x1[4] = 2; y1[4] =13;
  x1[5] = 3; y1[5] =15;
  x1[6] = 4; y1[6] =17;

  fprintf(stderr,"*** Example of gnuplot control through C ***\n");
  h1 = gnuplot_init();
  gnuplot_cmd(h1, "set terminal pngcairo");
  gnuplot_cmd(h1, "set output \"points001.png\"");
  gnuplot_cmd(h1, "set grid");
  gnuplot_cmd(h1, "set size ratio -1");
  gnuplot_cmd(h1, "set xtics -2, 1, 4");
  gnuplot_cmd(h1, "set ytics 5, 1, 17");
  gnuplot_setstyle(h1, "linespoints");
  gnuplot_set_axislabel(h1, "x", "x");
  gnuplot_set_axislabel(h1, "y", "y");
  gnuplot_plot_coordinates(h1, x1, y1, MAXDIM, "odd points");
  fprintf(stderr,"\n*** check generated png file ***\n");
  fprintf(stderr,"\n*** closing gnuplot handle ***\n");
  gnuplot_close(h1);
  return 0;
}
