/*   ThiS PROGRAM reads N numbers from stdin
 *   AND PRiNTS statistics, implemented in c language
 *   inspired by fortran exercises in Ellis,1982
 *   and other books. First number in input is the
 *   number of samples to be read. 
 *   author: Francesco Lazzarotto
 *   version: 0.0.2
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
#include <math.h>
int main()
{
    float x[MAXS];
    double rsum, avg, qsum, var1, var2, stdev1, stdev2;
    float emin, emax;
    int i, nmax, ret;
    nmax=0; rsum=0.0; avg=0.0; qsum=0.0, emin=0.0, emax=0.0;
    var1=0.0;var2=0.0;stdev1=0.0;stdev2=0.0;
    fprintf(stderr,"*************************************\n");
    fprintf(stderr,"*            statsn.c               *\n");
    fprintf(stderr,"* sum and average of n real numbers *\n");
    fprintf(stderr,"* with n int. in [1:100]            *\n");
    fprintf(stderr,"*************************************\n");
    fprintf(stderr,"* the used accuracy of reals        *\n");
    fprintf(stderr,"* is  1/100000 (1E-5)               *\n");
    fprintf(stderr,"*************************************\n");
    if (DEBUG){
        fprintf(stderr,"please, enter how many numbers [1:100]\n");
        fprintf(stderr,"and press enter\n");
    }
/*The first value in input is\tthe n= #elements to be summed*/
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
/* */
    fprintf(stderr, "The n. of samples is\t\t%d\n", nmax);
    printf("% 4d\n", nmax);
/* sum all the elements of the array array*/
    for (i=0; i<nmax; i++)
    {
        rsum = x[i] + rsum;
    }
    fprintf(stderr, "The sum is\t\t%10.5f\n", rsum);
    printf("%10.5f\n", rsum);
/* compute the aritmetic average */
    avg = rsum/nmax;
/* compute the variance */
    fprintf(stderr, "The average is\t\t%10.5f\n", avg);
    printf("%10.5f\n", avg);
    for (i=0; i<nmax; i++)
    {
        qsum = qsum + ((x[i] - avg)*(x[i] - avg));
    }
    var1 = qsum/nmax;
    fprintf(stderr, "The var_n is\t\t%10.5f\n", var1);
    printf("%10.5f\n", var1);
    var2 = qsum/(nmax-1);
    fprintf(stderr, "The var_n-1 is\t\t%10.5f\n", var2);
    printf("%10.5f\n", var2);
    stdev1 = sqrt(var1);
    fprintf(stderr, "The std.dev_n is\t%10.5f\n", stdev1);
    printf("%10.5f\n", stdev1);
    stdev2 = sqrt(var2);
    fprintf(stderr, "The std.dev_n-1 is\t%10.5f\n", stdev2);
    printf("%10.5f\n", stdev2);
    fprintf(stderr,"*************************************\n");
    fprintf(stderr,"* End of run. Bye.                  *\n");
    fprintf(stderr,"*************************************\n");
    return 0;
}
/*
* on linux/mac/mingw
* to compile 
make
* to run
./statsn <statsn.dat
* to read only info log and save output on file
./statsn <statsn.dat >out.csv
* to save info on log file and get output on stdin (terminal)
./statsn <statsn.dat 2>err.log
on MS win using MSVC compiler
*to compile
cl statsn.c /link
*to run
statsn < statsn.dat
*/

