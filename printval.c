/* prntval.c -- finding printf()'s return value */
#include <stdio.h>
#include "utility.h"
void PAUSE();
int main(void)
{
	int bph2o = 212;
	int rv;
	rv = printf("%.2f deg.C is water's boiling point.\n", f2c(bph2o));
	rv = printf("%i deg.F is water's boiling point.\n", bph2o);
	printf("The printf() function printed %d characters.\n",rv);
	PAUSE();
	puts("Bye.");
	return 0;
}
