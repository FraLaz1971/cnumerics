#include <stdio.h>
int main()
{
/*   THiS PROGRAM READS 10 NUMBERS FROM STDiN 
 *   AND PRiNTS THEiR SUM c language implementation 
 *   of exercise 3.y from Ellis,1982
 * "A structured approach to FORTRAN 77 programming"
 */
    float x[10], rsum;
    int i,nmax, ret;
    nmax=10; rsum=0;
    printf("please, enter %d numbers\n",nmax);
    printf("press enter after each of them\n");
    for (i=0; i<nmax; i++)
    {
        ret = scanf("%f",&x[i]);
        printf( "number %d  value %g\n",i,x[i]);
    }

    for (i=0; i<nmax; i++)
    {
        rsum = x[i] + rsum;
    }
    printf("The sum is %g\n", rsum);
    return 0;
}        
/* ./test23 <data/sum10.dat */

