/* floaterr.c--demonstrates round-off error 
from Prata, 2004 'c primer plus' */
#include <stdio.h>
int main(void){
	float a,b;
	float c,d;
	b = 2.0e20 + 1.0;
	a = b - 2.0e20;
	printf("%f \n", a);
	printf("this showed a round-off error \n");
	printf("now a correct operation\n");
	d = 2.0e4 + 1.0;
	c = d - 2.0e4;
	printf("%f \n", c);
	return 0;
}
