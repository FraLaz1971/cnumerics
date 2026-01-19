#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv){
        double cur, lower, upper, step, val, fval; const char *txtl, *txtu, *txts;
	if (argc != 4){
		puts("displays \"x, x^2\" please enter the interval limits");
		printf("%s <lower_limit> <upper_limit> <step>\n", argv[0]);
		return(1);
	} else {
		txtl=argv[1]; txtu=argv[2]; txts=argv[3];
		lower=atof(txtl); upper=atof(txtu);step=atof(txts);
		fprintf(stderr, "we'll display reals in the following interval/step:");
		fprintf(stderr, "[%g, %g] / step=%g\n", lower, upper, step);
		for (cur=lower; cur<=upper; cur=cur+step){
            val=cur; fval=val*val;
			printf("%g %g\n",val,fval);
		}
	}
	return(0);
}
