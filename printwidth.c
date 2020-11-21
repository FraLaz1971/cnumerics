/* width.c -- field widths */
#include <stdio.h>
#define PAGES 931
int main(void)
{
	char c;
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("reserving 4 characters\n");
	printf("*%4d*\n", PAGES);
	printf("reserving 10 characters on the right\n");
	printf("*%10d*\n", PAGES);
	printf("reserving 10 characters on the left\n");
	printf("*%-10d*\n", PAGES);
	printf("Please press ENTER to close\n");
	c = getchar();
	return 0;
}

