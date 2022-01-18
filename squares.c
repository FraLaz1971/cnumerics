#include <stdio.h>
#include <stdlib.h>
/** function square() of 1 double argument, it returns the square of the input as result */
double square(double val){
  double res;
  printf("square(): computing (%g)^2 \n", val);
  res = val * val;
  return res;
}

int main(int argc, char* argv[])
{
    int i; double cur;double darg;
    printf("main(): argc=%d\n", argc);
    printf("main(): lets see what is in argv[]\n");
    if (argc>1)
    {
       for  (i = 1; i<argc; i++)
       {
          printf("main(): argv[%d]=%s\n", i, argv[i]);
 	  darg = atof(argv[i]);
          cur = square( darg );
	  printf("main(): (%g)^2 is %g\n", darg, cur );
    }
         printf("main(): over\n");
  }
  return 0;
}
