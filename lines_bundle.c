#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double x, y;
} Point;


int main(int argc, char **argv){
    Point C;
    int i;
    double m,m_min,m_max,m_step;
    char *datafile = "lines_bundle.dat";
    char *gpfile = "lines_bundle.gp";
    FILE *ofp,*gfp;
    if(argc<4){
        fprintf(stderr,"usage:%s <m_min> <m_max> <m_step>\n",argv[0]);
        return 1;
    }
    m_min = atof(argv[1]);m_max = atof(argv[2]);m_step = atof(argv[3]);
    /* lines bundle with center x0,y0
     * y-y0 = m*(x-x0)
     * y = y0 + m*(x-x0)
     */
    fprintf(stderr,"Enter 2 real numbers separated by space\n");
    scanf("%lf %lf", &(C.x),&(C.y));
    fprintf(stderr,"You entered point C(%.2f,%.2f)\n",C.x,C.y);
    ofp = fopen(datafile, "w");
    for(m=m_min;m<=m_max;m=m+m_step){
        for(i=(int)-C.x; i<(int)C.x+100; i++){
          fprintf(ofp,"%lf %lf\n", (double)i-50.0,C.y+m*(i-50.0-C.x));
        }
        fprintf(ofp,"\n");
    }
    fclose(ofp);
    gfp = fopen(gpfile, "w");
    fprintf(gfp,"set terminal wxt persist\n");
    fprintf(gfp,"set size square\n");
    fprintf(gfp,"set xrange [%f:%f]\n",-50-C.x,50+C.x);
    fprintf(gfp,"plot 'lines_bundle.dat' with linespoints\n");
    fclose(gfp);
    system("gnuplot lines_bundle.gp");
    return 0;
}
