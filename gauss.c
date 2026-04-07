#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot_i.h"

/*
 *
 It is defined by the formula a * e^-(x-b)^2/{2*c^2}  , where b is the mean
(center), c the standard deviation (width, also called the Gaussian RMS
width), and a the height
a * exp(-1*((x-b)*(x-b))/(2*c*c))

 */

void setup_gnuplot(gnuplot_ctrl *handle, double a, double b, double c);
int plot_gauss(gnuplot_ctrl *handle, double a, double b, double c);

int main(int argc, char **argv){
    double a; /* the height */
    double b; /* the mean (center) */
    double c; /* the standard deviation */
    int ires;
    gnuplot_ctrl *handle;
      /* take in input the objects table */
  if (argc < 2){
    fprintf(stderr,"usage:%s <a> <b> <c>\n",argv[0]);
    fprintf(stderr,"where b is the mean (center), c the standard deviation and a the height\n");
    return 1;
  }
  a = atof(argv[1]);
  b = atof(argv[2]);
  c = atof(argv[3]);
  handle = gnuplot_init();
  if (!handle) {
        fprintf(stderr, "Error: Gnuplot not found!\n");
        return 1;
    }
  setup_gnuplot(handle, a, b, c);
  ires = plot_gauss(handle, a, b, c);
  gnuplot_close(handle);
  printf("Execution completed\n");
    return ires;
}
/* Function to set up gnuplot parameters */
void setup_gnuplot(gnuplot_ctrl *handle, double a, double b, double c) {
    gnuplot_cmd(handle, "set termina wxt persist");
    gnuplot_cmd(handle, "set size ratio 1");
    gnuplot_cmd(handle, "set xlabel 'X'");
    gnuplot_cmd(handle, "set ylabel 'Y'");
    gnuplot_cmd(handle, "set xrange [%.2f:%.2f]", b-c*b-5, b+c*b+5);
    gnuplot_cmd(handle, "set yrange [0:%.2f]", a+a/6);
    gnuplot_cmd(handle, "set grid ytics"); // Griglia orizzontale per leggere meglio i valori
    gnuplot_cmd(handle, "set grid xtics"); // Griglia verticale per leggere meglio i valori
    gnuplot_cmd(handle, "set title 'Gauss Curve' font 'arial,14'");
}

int plot_gauss(gnuplot_ctrl *handle, double a, double b, double c){
  char cmdstring[2048];
  /* Setup for histograms */
    snprintf(cmdstring, 2047,"plot %.2f*exp(-(x-%.2f)**2/(2*%.2f**2)) title 'Gauss function'",a, b, c);
    gnuplot_cmd(handle, cmdstring);
  return 0;
}
