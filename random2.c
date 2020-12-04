#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rndr(int, int);
void seedrnd(void);

int main()
{
	int x; int min; int max, ret;
	fprintf(stderr,"Remember that RAND_MAX = %u\n", RAND_MAX);
	fprintf(stderr,"Behold! 100 Random Numbers!");
	fprintf(stderr,"please enter the range min\n");
	if(scanf("%i", &min)<=0) fprintf(stderr, "problem acquiring min value\n");
	printf("please enter the range max\n");
	if(scanf("%i", &max)<=0) fprintf(stderr, "problem acquiring max value\n");
	seedrnd();
	for(x=0;x<100;x++)
		printf("%d\t",rndr(min, max));
	return 0;
}

int rndr(int mmin, int mmax)
{
	float r; float fr;
	r=rand(); fr = mmin+mmax*(r/RAND_MAX);

	return((int)fr);

}

void seedrnd(void){
	srand((unsigned)time(NULL));
}
