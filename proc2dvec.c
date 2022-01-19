#include <stdio.h>
#define SIZE 5

/*
   this program reads a 2D array of EXACTLY size 5 in[i]
   and gives back a 1D array of size 5 ou[i] ,
   if (a,b) is the element  in[i]
   the corresponging output element of ou[i] = (a+b)^2
   the square of (a+b). If the read input numbers are less
   than 10, the lacking input is filled with zeros.
   It makes use of a function alpha() that implements the operation
   (a+b)^2. When you change only the operation inside
   the alpha() implementation, you don't need to change
   the main().
*/

int alpha(int num1, int num2);

int main (int argc, char *argv[]) {

   /* local variables definition and initialization  */
   int a = 0; 	  /* first input variable at step i  */
   int b = 0; 	  /* second input variable at step i */
   int res = 0;   /* exit code of the scanf()	     */
   int c = 0; 	  /* c will contain (a+b)^2 	     */
   int i = 0;	  /* i iterate on the input elements */

   /* I want to make a loop to calculate a+b 5 times  */

   for (i=0; i<SIZE; i++){
        /* c is the result of summation, i want to multiply by itself to get the square */
	fprintf(stderr, "%s: reading an integers couple ... \n", argv[0]);
	res = scanf("%d %d ", &a, &b);
    	/* i want to call the result of addition and multiplication */
	c = alpha(a,b);
	fprintf(stderr, "in[%d] = [%d,%d] --> ou[%i] = %d\n",i,a,b,i,c);
   if (i == 4) /* the exact number of 5 elements is the number i want to iterate */
   {   fprintf(stderr,"%s: good I read all the expected data, now exiting! \n ", argv[0]);
      break;
   }
     a = 0; b = 0;
   }
   return 0;
}

int alpha(int num1, int num2){
	int res = (num1+num2)*(num1+num2);
	fprintf(stderr, "alpha(%d,%d): (%d+%d)^2 --> %d\n",num1, num2, num1, num2, res);
	return res;
}
