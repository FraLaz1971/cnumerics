#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv){
	if (argc != 4){
		puts("displays \"x, cos(x)\" please enter the interval limits");
		printf("%s <lowerer_limit> <upper_limit> <step>\n", argv[0]);
		return(1);
	} else {
        double cur, lower, upper, step, val, fval; const char *txtl, *txtu, *txts;
		txtl=argv[1]; txtu=argv[2]; txts=argv[3];
		lower=atof(txtl); upper=atof(txtu);step=atof(txts);
		fprintf(stderr, "we'll display reals in the following interval/step:");
		fprintf(stderr, "[%g, %g] / step=%g\n", lower, upper, step);
		for (cur=lower; cur<=upper; cur=cur+step){
            val=cur; fval=cos(val);
			printf("%g %g\n",val,fval);
		}
	}
	return(0);
}
