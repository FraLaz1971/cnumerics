#include <stdio.h>
int main()
{
/*   THIS PROGRAM READS 10 NUMBERS FROM STDIN 
 *   AND PRINTS THEIR SUM c language implementation 
 *   of exercise 3.y from Ellis,1982
 * "A structured approach to FORTRAN 77 programming"
 */
    float X[10], RSUM;
    int I,NMAX, ret;
    NMAX=10; RSUM=0;
    printf("please, enter %d numbers\n",NMAX);
    printf("press enter after each of them\n");
    for (I=0; I<NMAX; I++)
    {
        ret = scanf("%f",&X[I]);
        printf( "number %d  value %g\n",I,X[I]);
    }

    for (I=0; I<NMAX; I++)
    {
        RSUM = X [I] + RSUM;
    }
    printf("The sum is %g\n", RSUM);
    return 0;
}        
/* ./test23 <data/sum10.dat */

