#include <stdio.h>
#include <limits.h>

int main() {

   printf("The number of bits in a byte %d\n", CHAR_BIT);

   printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
   printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
   printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

   printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
   printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);

   printf("The minimum value of INT = %d\n", INT_MIN);
   printf("The maximum value of INT = %d\n", INT_MAX);

   printf("The minimum value of CHAR = %d\n", CHAR_MIN);
   printf("The maximum value of CHAR = %d\n", CHAR_MAX);

   printf("The minimum value of LONG = %ld\n", LONG_MIN);
   printf("The maximum value of LONG = %ld\n", LONG_MAX);

printf("CHAR_BIT   = %d\n", CHAR_BIT);
    printf("MB_LEN_MAX = %d\n", MB_LEN_MAX);
    printf("\n");
 
    printf("CHAR_MIN   = %+d\n", CHAR_MIN);
    printf("CHAR_MAX   = %+d\n", CHAR_MAX);
    printf("SCHAR_MIN  = %+d\n", SCHAR_MIN);
    printf("SCHAR_MAX  = %+d\n", SCHAR_MAX);
    printf("UCHAR_MAX  = %u\n",  UCHAR_MAX);
    printf("\n");
 
    printf("SHRT_MIN   = %+d\n", SHRT_MIN);
    printf("SHRT_MAX   = %+d\n", SHRT_MAX);
    printf("USHRT_MAX  = %u\n",  USHRT_MAX);
    printf("\n");
 
    printf("INT_MIN    = %+d\n", INT_MIN);
    printf("INT_MAX    = %+d\n", INT_MAX);
    printf("UINT_MAX   = %u\n",  UINT_MAX);
    printf("\n");
 
    printf("LONG_MIN   = %+ld\n", LONG_MIN);
    printf("LONG_MAX   = %+ld\n", LONG_MAX);
    printf("ULONG_MAX  = %lu\n",  ULONG_MAX);
    printf("\n");
 
  
   return(0);
}

