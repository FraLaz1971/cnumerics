/** function usage example
    when main() returns 1 you got an error
    instructions are provided in order to avoid errors
    when main() returns 2 you got a warning
*/
#include <stdio.h>
#include <stdlib.h>
/** function alpha() of 2 integer arguments, it returns an integer as result */
int alpha(int val1, int val2){
  int res;
  res = 4 + (val1 * val2);
  return res;
}

int main(int argc, char **argv){
	int opand1 = 0, opand2 = 0, res = 0;
	int retval = 0;
	if (argc < 3){
		fprintf(stderr,"%s: ERROR, too few program arguments!\n", argv[0]);
        fprintf(stderr,"usage: %s <operand1> <operand2>\n", argv[0]);
        fprintf(stderr,"%s: <operand1> and <operand2> are expected to be integer numbers\n", argv[0]);
		return 1;
	}
	if (argc > 3){
		fprintf(stderr,"%s: WARNING, too many program arguments\n", argv[0]);
		fprintf(stderr,"usage: %s <operand1> <operand2>\n", argv[0]);
		fprintf(stderr,"%s: you gave %d command line arguments to %s\n", argv[0], argc-1, argv[0]);
		fprintf(stderr,"%s: arguments after the 2nd will be ignored\n", argv[0]);
		retval = 2;
	}
	opand1 = atoi(argv[1]); opand2 = atoi(argv[2]);
	fprintf(stderr, "%s: testing the use of a function\n", argv[0]);
	res = alpha(opand1, opand2);
	fprintf(stderr, "%s: the result of alpha(%d, %d) is %d\n", argv[0], opand1, opand2, res);
	printf("%d ", res);
	return retval;
}
