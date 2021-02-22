#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
    /* x^2 + y^2 + a*x + b*y + c = 0 
     * a+2b+c=−5 --> a+2*b+b+1 = -5 --> a+3b=-4 -->a=1-3*b --> 1 = 1-b--> b=0 
     * b−c=−1    --> c=b+1  --> c=1
     * a−b−c=2​   --> a-b-b-1=2 --> a-2*b=1 -->2*b = a+1 --> a=-1
     */

/* global variables */

struct Circle {
    double x1, y1; 
    double x2, y2; 
    double x3, y3; 
    double a, b, c;    
    double radius;
    double x_c,y_c; /* centre coordinates */
} circle;  

struct Run {
    int  argc; 
    char** argv; 
} run;  


typedef struct Circle Circle;
typedef struct Run Run;

int read_input(char ** margv, Circle *circ);
int show_output(char ** margv, Circle *circ);
int show_matrix(char ** margv, Circle *circ);
int set_run_par(int margc, char ** margv);
void estarline(void);
int dump_circle(int npts);

/* global structure */
Run run;
/* P1(0,2) P2(2,4) P3(1,0) */
int main(int argc, char **argv){
    int mret; Circle mycirc; 
    set_run_par(argc, argv);
    mret = read_input(argv, &mycirc);
    mret = show_output(argv, &mycirc);
    mret = show_matrix(argv, &mycirc);
    //double e1,e2,e3;
    /* compute the equation system */
    // e1 = x1*x1+y1*y1
    return 0;
} 

int read_input(char ** margv, Circle *circ){
    int ret;
    estarline();
    fprintf(stderr, "%s: please, enter first point  P1: x1 y1 separated by space:\n", margv[0]);
    ret = scanf("%lf %lf", &circ->x1, &circ->y1);
    fprintf(stderr,"%s: you entered P1(%g,%g)\n", margv[0], circ->x1, circ->y1);
    fprintf(stderr, "%s: please, enter second point P2: x2 y2 separated by space:\n", margv[0]);
    ret = scanf("%lf %lf", &circ->x2, &circ->y2);
    fprintf(stderr,"%s: you entered P2(%g,%g)\n", margv[0], circ->x2, circ->y2);
    fprintf(stderr, "%s: please, enter third point  P3: x3 y3 separated by space:\n", margv[0]);
    ret = scanf("%lf %lf", &circ->x3, &circ->y3);
    fprintf(stderr,"%s: you entered P3(%g,%g)\n", margv[0], circ->x3, circ->y3);
    estarline();
    /* compute the equation system */
    // e1 = x1*x1+y1*y1
    return 0;    
}

int show_output(char ** margv, Circle *circ){    
    estarline();
    fprintf(stderr,"%s: %g+%g+a*%g+b*%g+c = 0\n", margv[0], circ->x1*circ->x1, circ->y1*circ->y1, circ->x1, circ->y1);
    fprintf(stderr,"%s: %g+%g+a*%g+b*%g+c = 0\n", margv[0], circ->x2*circ->x2, circ->y2*circ->y2, circ->x2, circ->y2);
    fprintf(stderr,"%s: %g+%g+a*%g+b*%g+c = 0\n", margv[0], circ->x3*circ->x3, circ->y3*circ->y3, circ->x3, circ->y3);
    estarline();
    return 0;
}

void estarline(void){
    fprintf(stderr,"**********************************\n");
}

int show_equations(char ** margv, Circle *circ){    
    estarline();
    fprintf(stderr,"%s: %g+%g+a*%g+b*%g+c = 0\n", margv[0], circ->x1*circ->x1, circ->y1*circ->y1, circ->x1, circ->y1);
    fprintf(stderr,"%s: %g+%g+a*%g+b*%g+c = 0\n", margv[0], circ->x2*circ->x2, circ->y2*circ->y2, circ->x2, circ->y2);
    fprintf(stderr,"%s: %g+%g+a*%g+b*%g+c = 0\n", margv[0], circ->x3*circ->x3, circ->y3*circ->y3, circ->x3, circ->y3);
    estarline();
    return 0;
}

int show_matrix(char ** margv, Circle *circ){    
    estarline();
    fprintf(stderr,"%s: (%2g %2g 1) (a) = (%2g)\n", margv[0], circ->x1, circ->y1, -1*(circ->x1*circ->x1+circ->y1*circ->y1));
    fprintf(stderr,"%s: (%2g %2g 1) (b) = (%2g)\n", margv[0], circ->x2, circ->y2, -1*(circ->x2*circ->x2+circ->y2*circ->y2));
    fprintf(stderr,"%s: (%2g %2g 1) (c) = (%2g)\n", margv[0], circ->x3, circ->y3, -1*(circ->x3*circ->x3 + circ->y3*circ->y3));
    estarline();
    return 0;
}

int set_run_par(int margc, char ** margv){
    run.argc = margc;
    run.argv = margv;
    int count;
    for(count=0; count<=run.argc; count++){
            fprintf(stderr,"%s: run.argv[%i] = %s\n",run.argv[0], count, run.argv[count]);
    }
    return 0;
}


int dump_circle(int npts)
{
    int count;
    for(count=0; count<=npts; count++){
            fprintf(stderr,"%s %i %s\n",run.argv[0], count, run.argv[count]);
    }
        return 0;
}
