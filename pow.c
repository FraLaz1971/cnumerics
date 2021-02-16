#include <stdio.h>
#include <math.h>
/* calculating x raised to the y power
x and y values are hardcoded in the source */
int main() {
   double x = 5.5;
   double y = 4.0;
   double p;
   p = pow(x, y);
   printf("The value : %lf\n", p);
   return 0;
}

