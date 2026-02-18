/* This program plots a triangle on the X,Y plane with edge 1 parallel to the axes
 and then plots the same triangle rotated by an angle theta given in input by the user
 */
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141593
int main(int argc, char **argv){
  float theta,rtheta;
  char *gpfile;
  char *datafile;
  FILE *gpp,*dfp;
  if (argc < 2){
    fprintf(stderr, "usage:%s <angle (deg)>\n", argv[0]);
    return 1;
  }
  theta = atof(argv[1]); rtheta = PI*theta/180;
  gpfile = "rotated_triangle.gp";
  datafile = "triangle.dat";
  /* write the gnuplot script file */
  gpp = fopen(gpfile, "w\n");
    fprintf(gpp,"set terminal wxt persist\n");
    fprintf(gpp,"#set term pngcairo size 800,400\n");
    fprintf(gpp,"#set output '2d_rotation.png'\n");
    fprintf(gpp,"set multiplot layout 1,2\n");
    fprintf(gpp,"# Original triangle\n");
    fprintf(gpp,"set title 'Before Rotation'\n");
    fprintf(gpp,"set xrange [-2:2]\n");
    fprintf(gpp,"set yrange [-2:2]\n");
    fprintf(gpp,"set xlabel 'X Axes'\n");
    fprintf(gpp,"set ylabel 'Y Axes'\n");
    fprintf(gpp,"set size ratio 1\n");
    fprintf(gpp,"plot 'triangle.dat' with lines title 'Triangle', \\\n");
    fprintf(gpp,"'triangle.dat' with labels notitle offset 0.6,0.5 \n");
    fprintf(gpp,"set title 'After Rotation (%.1f°)'\n", theta);
    fprintf(gpp,"theta = %f\n", rtheta);
    fprintf(gpp,"s = sin(theta)\n");
    fprintf(gpp,"c = cos(theta)\n");
    fprintf(gpp,"plot 'triangle.dat' using (c*$1 - s*$2):(s*$1 + c*$2) \
with lines title 'Rotated Triangle', \\\n");
    fprintf(gpp,"'triangle.dat'using (c*$1 - s*$2):(s*$1 + c*$2):3 \
with labels offset 0.6,0.5 notitle\n");
  fclose(gpp);
    /* write the points data file */
  dfp = fopen(datafile, "w\n");
    fprintf(dfp,"-1 -1 A\n");
    fprintf(dfp," 1 -1 B\n");
    fprintf(dfp," 0  1 C\n");
    fprintf(dfp,"-1 -1\n");
  fclose(dfp);
  /* run the script */
  system("gnuplot rotated_triangle.gp\n");
  return 0;
}
