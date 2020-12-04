#include <stdlib.h>
#include <stdio.h>

int rnd(void);

int main()
{
	int x;
	printf("Remember that RAND_MAX = %u\n", RAND_MAX);
	puts("Behold! 100 Random Numbers!");
	for(x=0;x<100;x++)
		printf("%d\t",rnd());
	return 0;
}

int rnd(void)
{
	int r;
	r=rand();
	return(r);
}

