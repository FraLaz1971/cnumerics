#include <stdio.h>
#include <string.h>
int main() {
	/*  Float is a datatype which is used to represent the floating point numbers. 
	It is a 32-bit IEEE 754 single precision floating point number 
	( 1-bit for the sign, 8-bit for exponent, 23*-bit for the value. 
	It has 6 decimal digits of precision. 
	thanks to https://www.tutorialspoint.com/float-and-double-in-c	*/
   char c;
   float fx = 10.327;
   int fy = 28;
   float x = 10.3274669;
   double y = 4244.546234677169;
   int z = 28;
   printf("The float value : %f\n", fx);
   printf("The sum of float and int variable : %f\n", (fx+fy));

	/* Double is also a datatype which is used to represent the floating point numbers. 
	It is a 64-bit IEEE 754 double precision floating point number for the value. 
	It has 15 decimal digits of precision.*/


   printf("The float value : %f\n", x);
   printf("The double value : %4.11f\n", y);
   printf("The sum of float, double and int variable : %f\n", (x+y+z));
   printf("Please press ENTER");
   c = getchar();

   return 0;
}

