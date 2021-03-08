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
    printf("please, enter a temperature value (F deg.)\n");
    printf("and then enter\n");
    ret = scanf("%f",&fa );
    ce = 5.0*(fa - 32)/9.0;
    printf("%g F deg. is %g C deg.\n", fa, ce);
    return 0;
}        
/* on posix terminal
./f2c
>>please, enter a temperature value (F deg.)
>>and then enter
or
./f2c <<< "24.8"

24.8 F deg. is -4 C deg.

*/
