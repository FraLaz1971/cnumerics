#include <stdio.h>
#include <limits.h>

int main() {

	printf("The number of bits in a byte %d\n", CHAR_BIT);

	printf("The minimum value of CHAR = %d\n", CHAR_MIN);
	printf("The maximum value of CHAR = %d\n", CHAR_MAX);
	printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
	printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
	printf("The minimum value of UNSIGNED CHAR = %d\n", 0);
	printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

	printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
	printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

	printf("The minimum value of Uns. SHORT  = %u\n",  0);
	printf("The maximum value of Uns. SHORT  = %u\n",  USHRT_MAX);

	printf("The minimum value of INT = %d\n", INT_MIN);
	printf("The maximum value of INT = %d\n", INT_MAX);

	printf("The minimum value of Uns. INT = %u\n",  0);
	printf("The maximum value of Uns. INT = %u\n",  UINT_MAX);


	printf("The minimum value of LONG = %ld\n", LONG_MIN);
	printf("The maximum value of LONG = %ld\n", LONG_MAX);

	printf("minimum value of uns. long  = %lu\n",  (unsigned long)0);
	printf("maximum value of uns. long  = %lu\n",  ULONG_MAX);

	printf("minimum value of uns. long long = %llu\n",  (unsigned long long)0);
	printf("maximum value of uns. long long = %llu\n",  ULLONG_MAX);

	printf("maximum value of long long = %llu\n",  LLONG_MIN);
	printf("maximum value of long long = %llu\n",  LLONG_MAX);

	printf("MB_LEN_MAX = %d maximum multibyte length of a character in all local languages \n", MB_LEN_MAX);
   return(0);
}

