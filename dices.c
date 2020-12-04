#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int rnd(int range);

void seedrnd(void);

int main()
{
	int x; unsigned char launches;
	seedrnd();
	fprintf(stderr, "Please enter the number of dice launches\n");
	if(scanf("%hhu", &launches)<=0) perror("error in reading n. of launches") ;
	for(x=0;x<launches;x++)
		printf("%i\t",rnd(6));
	return(0);
}

int rnd(int range)
{
	int r;
	r=(rand()%range)+1;
	return(r);
}

void seedrnd(void)
{
	srand((unsigned)time(NULL));
}
