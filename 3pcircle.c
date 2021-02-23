#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
    /* x^2 + y^2 + a*x + b*y + c = 0 
     * a+2b+c=−5 --> a+2*b+b+1 = -5 --> a+3b=-4 -->a=1-3*b --> 1 = 1-b--> b=0 
     * b−c=−1    --> c=b+1  --> c=1
     * a−b−c=2​   --> a-b-b-1=2 --> a-2*b=1 -->2*b = a+1 --> a=-1
     */

/* global variables */

struct Array2x2 {
    double a, b; 
    double c, d; 
} a2x2;  

struct Array3x3 {
    double d_1, e_1, f_1; 
    double d_2, e_2, f_2; 
    double d_3, e_3, f_3; 
} a3x3;  

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
typedef struct Array2x2 Array2x2;
typedef struct Array3x3 Array3x3;

int read_input(char ** margv, Circle *circ);
int show_system(char ** margv, Circle *circ);
int show_matrix(char ** margv, Circle *circ);
int set_run_par(int margc, char ** margv);
void estarline(void);
int dump_circle(int npts);
/* functions related to 2x2 arrays */

/* set the values in data to the Array fields*/
int set_Array2x2_data(Array2x2 *a2x2, double *data);
/* gives the determinant of the given matrix */
double detA2x2(Array2x2 *a2x2);
int show_Array2x2(Array2x2 *a2x2);
int show_Array2x2_system(Array2x2 *a2x2, double *v);
int dump_Array2x2(Array2x2 *a2x2);
/* given the linear system of 2 equations and 2 unknown variables 
 * a2x2 --> coefficient array;
 * v --> known terms array
 saves the solution as sol[0], sol[1] */
int get_2x2_solution(Array2x2 *a2x2, double *v, double *sol);
/* functions related to 3x3 arrays */
/* set the values in data to the Array fields*/
int set_Array3x3_data(Array3x3 *a3x3, double *data);
double detA3x3(Array3x3 *a3x3);
int show_Array3x3(Array3x3 *a3x3);
int show_Array3x3_system(Array3x3 *a3x3, double *w);
int dump_Array3x3(Array3x3 *a3x3);

/* given the linear system of 3 equations and 3 unknown variables 
 * a3x3 --> coefficients array;
 * v    --> known terms array
 saves the solution in sol[0], sol[1], sol[2] */
int get_3x3_solution(Array3x3 *a3x3, double *v, double *sol);

/* global structure */
Run run;
/* global temp variables */
double dres;
/* first example: P1(0,2) P2(2,4) P3(1,0) */
int main(int argc, char **argv){
    /* variable definition */
    int mret; Circle mycirc; 
    /* data for the 2x2 equations system */
    Array2x2 a22, a22s1, a22s2; double e1_2x2[4];
    /* determinants for matrix, sol1, sol2*/
    double da2, d2s[2];
    double v[2]; /*known terms array size=2 */
    /* data for the 3x3 equations system */
    Array3x3 a33; double e1_3x3[9];
    double w[3]; /*known terms array size=3 */
    /* determinants for matrix, sol1, sol2, sol3*/
    double da3, d3s[3];

    /* computing steps */
    set_run_par(argc, argv);
    mret = read_input(argv, &mycirc);
    mret = show_system(argv, &mycirc);
    mret = show_matrix(argv, &mycirc);
    /* 2x2 array example */
    /* assign values to 2x2 matrix */
    e1_2x2[0]= 2;e1_2x2[1]=-1;
    e1_2x2[2]= 1;e1_2x2[3]= 3;  
    /* show the array content on stderr */
    mret = set_Array2x2_data(&a22, (double *)&e1_2x2);
    fprintf(stderr,"%s: showing content of 2x2 array a22 \n",run.argv[0]);
    /* show the array determinant on stderr */
    mret = show_Array2x2(&a22);
    da2 = detA2x2(&a22);
    fprintf(stderr,"%s: det(a22) is %g\n",run.argv[0], da2);
    if (da2 == 0 ){ 
        fprintf(stderr,"%s: the equation system (a2) (v) cannot be solved \n",run.argv[0]);
    } else{
        fprintf(stderr,"%s: the value of x is %g\n",run.argv[0], d2s[0]);
        fprintf(stderr,"%s: the value of y is %g\n",run.argv[0], d2s[1]);
    }
    /* 3x3 array example */
    /* assign values to 3x3 matrix */
    e1_3x3[0]= 2;e1_3x3[1]= 1;e1_3x3[2]= 1;
    e1_3x3[3]= 4;e1_3x3[4]=-1;e1_3x3[5]= 1;
    e1_3x3[6]=-1;e1_3x3[7]= 1;e1_3x3[8]= 2;

    mret = set_Array3x3_data(&a33, (double *)&e1_3x3);
    /* show the array content on stderr */
    fprintf(stderr,"%s: showing content of 3x3 array a33 \n",run.argv[0]);
    mret = show_Array3x3(&a33);
    da3 = detA3x3(&a33);
    fprintf(stderr,"%s: det(a33) is %g\n",run.argv[0], da3);
    if (da3 == 0 ){ 
        fprintf(stderr,"%s: the equation system (a3) (w) cannot be solved \n",run.argv[0]);
    } else{
        fprintf(stderr,"%s: the value of a is %g\n",run.argv[0], d3s[0]);
        fprintf(stderr,"%s: the value of b is %g\n",run.argv[0], d3s[1]);
        fprintf(stderr,"%s: the value of c is %g\n",run.argv[0], d3s[2]);
    }

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

int show_system(char ** margv, Circle *circ){    
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
    fprintf(stderr,"%s: (%2g %2g  1 ) (a) = (%2g)\n", margv[0], circ->x1, circ->y1, -1*(circ->x1*circ->x1+circ->y1*circ->y1));
    fprintf(stderr,"%s: (%2g %2g  1 ) (b) = (%2g)\n", margv[0], circ->x2, circ->y2, -1*(circ->x2*circ->x2+circ->y2*circ->y2));
    fprintf(stderr,"%s: (%2g %2g  1 ) (c) = (%2g)\n", margv[0], circ->x3, circ->y3, -1*(circ->x3*circ->x3 + circ->y3*circ->y3));
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

int set_Array2x2_data(Array2x2 *a2x2, double *data){
    a2x2->a = data[0];a2x2->b = data[1];
    a2x2->c = data[2];a2x2->d = data[3];
    return 0;
}

double detA2x2(Array2x2 *a2x2){
        return a2x2->a * a2x2->d - a2x2->b*a2x2->c;
}


int show_Array2x2(Array2x2 *a2x2){
    estarline();
    fprintf(stderr,"%s: (%2g %2g )\n",run.argv[0], a2x2->a, a2x2->b);
    fprintf(stderr,"%s: (%2g %2g )\n",run.argv[0], a2x2->c, a2x2->d);
    estarline();
    return 0;
}



int dump_Array2x2(Array2x2 *a2x2){
    return 0;
}

int set_Array3x3_data(Array3x3 *a3x3, double *data){
    a3x3->d_1 = data[0];a3x3->e_1 = data[1];a3x3->f_1 = data[2];
    a3x3->d_2 = data[3];a3x3->e_2 = data[4];a3x3->f_2 = data[5];
    a3x3->d_3 = data[6];a3x3->e_3 = data[7];a3x3->f_3 = data[8];
    return 0;
}


double detA3x3(Array3x3 *a3x3){
        dres = a3x3->d_1 * a3x3->e_2 * a3x3->f_3 + \
               a3x3->e_1 * a3x3->f_2 * a3x3->d_3 + \
               a3x3->f_1 * a3x3->d_2 * a3x3->e_3 - \
               a3x3->f_1 * a3x3->e_2 * a3x3->d_3 - \
               a3x3->e_1 * a3x3->d_2 * a3x3->f_3 - \
               a3x3->d_1 * a3x3->f_2 * a3x3->e_3;
               return dres;
}

int show_Array3x3(Array3x3 *a3x3){
    estarline();
    fprintf(stderr,"%s (%2g %2g %2g )\n",run.argv[0], a3x3->d_1, a3x3->e_1, a3x3->f_1);
    fprintf(stderr,"%s (%2g %2g %2g )\n",run.argv[0], a3x3->d_2, a3x3->e_2, a3x3->f_2);
    fprintf(stderr,"%s (%2g %2g %2g )\n",run.argv[0], a3x3->d_3, a3x3->e_3, a3x3->f_3);
    estarline();
    return 0;
}
