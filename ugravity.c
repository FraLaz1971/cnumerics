#include <stdio.h>
#include <math.h>
int main() {
	double ugravity;
	ugravity = 6.67/pow(10,-11);
	printf("gravity = %g\n", ugravity);
	printf("gravity (2 digit precision) = %f\n", ugravity);
	return 0;
}
