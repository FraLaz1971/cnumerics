/* bases.c : prints 100 in decimal, octal, and hex 
thanks to Prata, S., 2004 'C Primer plus' */
#include <stdio.h>
int main(void)
{
	int x = 100;
	printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
	printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
	printf("Please press ENTER");
	getchar();
	return 0;
}

