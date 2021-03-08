#include <stdio.h>
#define NMAX 4
/*   THiS PROGRAM READS 10 NUMBERS FROM STDiN 
 *   AND PRiNTS THEiR SUM c language implementation 
 *   of exercise 2.8 from Ellis,1982
 * "A structured approach to FORTRAN 77 programming"
 * write a program that reads 4 input numbers and gives
 * as output the sum of the first 2 and the sum of the last tow
 */
int main()
{
    float x[NMAX], rsum1, rsum2;
    int i, ret;
    rsum1=0;rsum2=0;
    printf("please, enter %d numbers\n",NMAX);
    printf("separated by space\n");
    printf("please, enter the first 2 numbers\n");
    ret = scanf("%f %f",&x[0],&x[1] );
    printf( "read %d numbers, values: %g %g\n",ret,x[0],x[1] );
    rsum1 = x[0] + x[1];
    printf("please, enter the second 2 numbers\n");
    ret = scanf("%f %f",&x[2],&x[3] );
    printf( "read %d numbers, values: %g %g\n",ret,x[2],x[3] );
    rsum2 = x[2] + x[3];
    printf("The sum of first couple is %10.5g\n", rsum1);
    printf("The sum of second couple is %10.5g\n", rsum2);
    return 0;
}        
/* ./sum4co (interactive)
 * ./sum4co < sum4co.dat */

