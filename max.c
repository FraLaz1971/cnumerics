#include <stdio.h>
#include <stdlib.h>
	/* function declaration */
#define EX_BADARGS 64
int max(int num1, int num2);

int main (int argc, char *argv[]) {
	/* local variable definition */
   int a, b, res, i=0;
   	/* calling a function to get max value between two integers */
   if (argc == 3){
      a = atoi(argv[1]); b = atoi(argv[2]);
      res = max(a,b);
      fprintf(stderr, "%s: max(%d,%d)=",argv[0],a,b);
      printf("%d\n", res);
      return 0;
  } else {
      	fprintf(stderr, "%s: gives the max among 2 integer numbers\n",argv[0]);
      	fprintf(stderr, "%s: ERROR! Wrong number of input arguments\n",argv[0]);
      	fprintf(stderr, "usage: %s <num1> <num2>\n",argv[0]);
	return EX_BADARGS;
  }
}

/* function implementation */
int max(int num1, int num2){
	if (num1 > num2){
		return num1;
	} else {
		return num2;
	}
}
