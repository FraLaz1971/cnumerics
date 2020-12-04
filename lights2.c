#include <stdio.h>
#include <math.h>
#define SQRT 251
#define TOOTH 253
#define EU 128
int main()
{
	double	lights;
	lights=sqrt(256); /* square root of 256 */
	printf("Milton, I got your %0.f%c lights.\n", lights,TOOTH);
	printf("Milton, I got your %c%0.f = %c\n", SQRT, 256, lights);
	printf("Milton, I payed it %0.f%c\n", lights, EU);
	return(0);
}
