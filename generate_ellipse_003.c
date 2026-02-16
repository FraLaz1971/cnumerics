#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point center;
    double a;  // semi-major axis
    double b;  // semi-minor axis
    double c;  // semi-focal distance
    double theta;  // rotation angle in radians
} Ellipse;

// Convert degrees to radians
double to_radians(double degrees) {
    return degrees * PI / 180.0;
}

// Convert radians to degrees
double to_degrees(double radians) {
    return radians * 180.0 / PI;
}

int main(int argc, char **argv){
  Ellipse ellipse1;
  char *focifile, *gpfile, *pointsfile;
  FILE *ffp, *gfp, *pfp;
  Point O,P,Q,F1,F2;
  if(argc<6){
    fprintf(stderr,"usage:%s <xc> <yc> <a> <b> <theta>\n", argv[0]);
    return 1;
  }
  O.x = atof(argv[1]);O.y = atof(argv[2]);
  ellipse1.a = atof(argv[3]); ellipse1.b = atof(argv[4]);
  ellipse1.theta = atof(argv[5]);
  ellipse1.c = sqrt(ellipse1.a*ellipse1.a+ellipse1.b*ellipse1.b);
  gpfile = "ellipse003.gp";
  /* write gnuplot script */
  gfp = fopen(gpfile, "w\n");
  fprintf(gfp,"set terminal wxt persist\n");
  fprintf(gfp,"#set terminal pngcairo\n");
  fprintf(gfp,"#set output 'ellipse003.png'\n");
  fprintf(gfp,"set parametric\n");
  fprintf(gfp,"set trange [0:2*pi]\n");
  fprintf(gfp,"set samples 500\n");
  fprintf(gfp,"set size ratio -1\n");
  fprintf(gfp,"set grid\n");
  fprintf(gfp,"x0 = %lf\n", O.x);
  fprintf(gfp,"y0 = %lf\n", O.y);
  fprintf(gfp,"a = %lf\n", ellipse1.a);
  fprintf(gfp,"b = %lf\n", ellipse1.b);
  fprintf(gfp,"c = sqrt(a**2-b**2)\n");
  fprintf(gfp,"e = c/a\n");
  fprintf(gfp,"print 'e=',e\n");
  fprintf(gfp,"# because a is semiaxes major\n");
  fprintf(gfp,"# 3. parametric function for the ellipse circumference\n");
  fprintf(gfp,"x(t) = x0 + a*cos(t)\n");
  fprintf(gfp,"y(t) = y0 + b*sin(t)\n");
  fprintf(gfp,"# 5. Definizione degli Assi (vettori che partono dal centro)\n");
  fprintf(gfp,"# Major Axes (along a)\n");
  fprintf(gfp,"set arrow from x0 - a, y0 to x0 + a, y0 nohead lc rgb 'blue' dt 2\n");
  fprintf(gfp,"# Minor Axes (along b)\n");
  fprintf(gfp,"set arrow from x0, y0-b to x0,y0+b nohead lc rgb 'red' dt 2\n");

  fprintf(gfp,"set xrange [x0-a-2 : x0+a+2]\n");
  fprintf(gfp,"set yrange [y0-b-2 : y0+b+2]\n");
  fprintf(gfp,"set xtics x0-a-2,1,x0+a+2\n");
  fprintf(gfp,"set ytics y0-b-2,1,y0+b+2\n");
  fprintf(gfp,"plot x(t), y(t) with lines title 'Ellipse O(%.0f,%.0f) a=%.0f,b=%.0f' lw 2, \\\n", O.x,O.y,ellipse1.a,ellipse1.b);
  fprintf(gfp,"'foci003.csv' with points pt 7 notitle, \\\n");
  fprintf(gfp,"'foci003.csv' using 1:2:3 with labels offset 0.50,0.50 font 'arial,14' notitle, \\\n");  fprintf(gfp,"'ellipse_points003.csv' with points pt 7 notitle, \\\n");
  fprintf(gfp,"'ellipse_points003.csv' using 1:2:3 with labels offset 0.50,0.50 font 'arial,14' notitle\n");
  fclose(gfp);
/* write foci file */
  focifile = "foci003.dat";
  /* write gnuplot script */
  ffp = fopen(focifile, "w\n");
  fprintf(ffp,"#x y label\n");
  fprintf(ffp,"%.1f+c %.1f F2\n",O.x, O.y);
  fprintf(ffp,"%.1f-c %.1f F1\n",O.x, O.y);
  fclose(ffp);
  pointsfile = "ellipse_points003.csv";
  pfp = fopen(pointsfile, "w\n");
  fprintf(pfp,"#x y label\n");
  fprintf(pfp,"%.1f %.1f O\n", O.x,O.y);
  fprintf(pfp,"%.1f %.1f (%.1f-a,%.1f)\n",O.x-ellipse1.a,O.y,O.x,O.y);
  fprintf(pfp,"%.1f %.1f (%.1f+a,%.1f)\n",O.x+ellipse1.a,O.y,O.x,O.y);
  fprintf(pfp,"%.1f %.1f (%.1f,%.1f-b)\n",O.x,O.y-ellipse1.b,O.x,O.y);
  fprintf(pfp,"%.1f %.1f (%.1f,%.1f+b)\n",O.x,O.y+ellipse1.b,O.x,O.y);
  fprintf(pfp,"7.656848 6.121318,P\n");
  fprintf(pfp,"4.809 6.809 Q\n");

  fclose(pfp);
/* launch gnuplot script */
system("gnuplot ellipse003.gp");
  return 0;
}
