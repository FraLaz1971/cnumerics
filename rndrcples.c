#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double rndr(int, int);
void seedrnd(void);

int main()
{
	int x; int min; int max, n, ret;
	fprintf(stderr,"Remember that RAND_MAX = %u\n", RAND_MAX);
	fprintf(stderr,"please enter the range min\n");
	if(scanf("%i", &min)<=0) 
        fprintf(stderr, "problem acquiring min value\n");
    else
        fprintf(stderr, "selected min value: %i\n", min);        
	fprintf(stderr,"please enter the range max\n");
	if(scanf("%i", &max)<=0) 
        fprintf(stderr, "problem acquiring max value\n");
    else
        fprintf(stderr, "selected max value: %i\n", max);        
	fprintf(stderr,"please enter the number of couples to generate\n");
	if(scanf("%i", &n)<=0) 
        fprintf(stderr, "problem acquiring the number of couples\n");
    else
        fprintf(stderr, "selected n of couples: %i\n", n);        
    fprintf(stderr,"Behold! %i Random Numbers!\n",n*2);
	seedrnd();
	for(x=0;x<n;x++)
		printf("%lf %lf\t",rndr(min, max), rndr(min, max));
    puts("");
	return 0;
}

double rndr(int mmin, int mmax)
{
	float r; double fr;
	r=rand(); fr = mmin+mmax*(r/RAND_MAX);
	return fr;

}

void seedrnd(void){
	srand((unsigned)time(NULL));
}
