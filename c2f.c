#include <stdio.h>
/*   THiS PROGRAM READS 10 NUMBERS FROM STDiN 
 *   AND PRiNTS THEiR SUM c language implementation 
 *   of exercise 2.8 from Ellis,1982
 * "A structured approach to FORTRAN 77 programming"
 * write a program that reads 4 input numbers and gives
 * as output the sum of the first 2 and the sum of the last tow
 */
int main()
{
    float ce, fa;
    int ret;
    printf("please, enter a temperature value (C deg.)\n");
    printf("and then enter\n");
    ret = scanf("%f",&ce );
    fa = 9.0*ce/5.0+32.0; 
    printf("%g C deg. is %g F deg.\n", ce, fa);
    return 0;
}        
/* on posix terminal
 * ./c2f
or (example)
./c2f <<< "0"
*/
