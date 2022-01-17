#include <stdio.h>                                                                                           
#include <stdlib.h>                                                                                          
/** function alpha() of 2 integer arguments, it returns an integer as result */                              
double alpha(double val1, double val2){
  double res;
  printf("alpha(): executing 4 + (%g * %g)\n", val1, val2);
  res = 4 + (val1 * val2);
  return res;
}

int main(int argc, char* argv[])
{
    int i; double cur=0.0;
    printf("main(): argc=%d\n", argc);
    printf("main(): lets see what is in argv[]\n");
    if (argc>1)
    {
       cur = atof(argv[1]);
       for  (i = 1; i<argc; i++)
       {
          printf("main(): argv[%d]=%s\n", i, argv[i]);
          cur = alpha( cur, atof(argv[i]) );
	  printf("main(): cur = %g\n", cur);
    }
    printf("main(): Total = %g\n", cur);
  }
  return 0;
}

