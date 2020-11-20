#include <stdio.h>
int main(void)
{
	char c;
	unsigned int un = 3000000000; 	/* system with 32-bit int */
	short end = 200; 		/* and 16-bit short */
	long big = 65537;
	long long verybig = 12345678908642;
	printf("size in BYTES of unsigned int variable 'un' is %d\n", sizeof(un));
	printf("size in BYTES of short int variable 'end' is %d\n", sizeof(end));
	printf("size in BYTES of long int variable 'big' is %d\n", sizeof(big));
	printf("size in BYTES of long long variable 'verybig' is %d\n", sizeof(verybig));
	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig = %lld , is it equal to %ld ?\n", verybig, verybig);
	printf("Please press ENTER");
        c = getchar();

	return 0;
}
