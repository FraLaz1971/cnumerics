/* This program converts the value of an angle from degrees to radians */
#include <stdio.h>
int main ()
{
   float Pi =  3.14159265; int ret;
   float degrees, radians;
   printf("Value of the angle in degrees?");
   ret = scanf("%f", &degrees); 
   radians = Pi*degrees/180.;
   printf("\n%g degrees = %g radians.\n", degrees, radians);
   return 0;
}

