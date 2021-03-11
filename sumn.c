/*   THiS PROGRAM READS N NUMBERS FROM STDiN 
 *   AND PRiNTS THEiR SUM in c language 
 *   inspired by fortran exercises in Ellis,1982
 *   and other books
 *   author: Francesco Lazzarotto
 *   version: 0.0.1
 *   date: 2021-03-11
 *   email: fralaz1971_at_gmail.com
 * *********************************************
 *  CHANGELOG
 * *********************************************
 * Date,         Developer,   Description_of_change
 * 2021-03-11,   fralaz1971,    first version
 * 
 */
/* maximum number of element we can read */
#define MAXS 100
#define DEBUG 0
#include <stdio.h>
int main()
{
    float x[MAXS], rsum;
    int i,nmax, ret;
    nmax=0; rsum=0;
    fprintf(stderr,"*************************************\n");
    fprintf(stderr,"*            sumn.c                 *\n");
    fprintf(stderr,"* sum n real numbers                *\n");
    fprintf(stderr,"* with n positive int. in [1:100]   *\n");
    fprintf(stderr,"*************************************\n");
    fprintf(stderr,"* the used accuracy of reals        *\n");
    fprintf(stderr,"* is 1/100000 (1E-5)                *\n");
    fprintf(stderr,"*************************************\n");
    if (DEBUG){
        fprintf(stderr,"please, enter how many numbers [1:100]\n");
        fprintf(stderr,"and press enter\n");
    }
/*The first value in input is the n= #elements to be summed*/
    ret = scanf("%d",&nmax);
    if (DEBUG){
        fprintf(stderr,"please, enter %d numbers\n",nmax);
        fprintf(stderr,"press enter after each of them\n");
    }
/* read n elements in a loop and save them in an array*/
    for (i=0; i<nmax; i++)
    {
        ret = scanf("%f",&x[i]);
        if (DEBUG)
            fprintf( stderr,"read number %d  value %10.6f\n",i+1,x[i]);
    }

/* sum all the elements of the array array*/
    for (i=0; i<nmax; i++)
    {
        rsum = x[i] + rsum;
    }
    fprintf(stderr, "The sum is %10.5f\n", rsum);
    printf("%10.5f\n", rsum);
    return 0;
}        
/* ./sumn <sum100.dat */

