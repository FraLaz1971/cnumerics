#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h> 
#include <math.h>
int main(void)
{
    char c;
    printf("The number of bits in a byte %d\n", CHAR_BIT);
    printf("Size of float is %ld BYTES\n", sizeof(float)); 
    printf("Size of double is %ld BYTES\n", sizeof(double)); 
    printf("Size of long double is %ld BYTES\n", sizeof(long double)); 
    puts("");
    printf("FLT_RADIX    = %d\n", FLT_RADIX);
    printf("DECIMAL_DIG  = %d\n", DECIMAL_DIG);
    printf("FLT_MIN      = %e\n", FLT_MIN);
    printf("FLT_MAX      = %e\n", FLT_MAX);
    printf("FLT_EPSILON  = %e\n", FLT_EPSILON);
    printf("FLT_DIG      = %d\n", FLT_DIG);
    printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG);
    printf("FLT_MIN_EXP  = %d\n",  FLT_MIN_EXP);
    printf("FLT_MIN_10_EXP  = %d\n",  FLT_MIN_10_EXP);
    printf("FLT_MAX_EXP     = %d\n",  FLT_MAX_EXP);
    printf("FLT_MAX_10_EXP  = %d\n",  FLT_MAX_10_EXP);
    printf("FLT_ROUNDS      = %d\n",  FLT_ROUNDS);
    printf("FLT_EVAL_METHOD = %d\n",  FLT_EVAL_METHOD);
    puts("");
    printf("DBL_MIN      = %e\n", DBL_MIN);
    printf("DBL_MAX      = %e\n", DBL_MAX);
    printf("DBL_EPSILON  = %e\n", DBL_EPSILON);
    printf("DBL_DIG      = %d\n", DBL_DIG);
    printf("DBL_MANT_DIG = %d\n", DBL_MANT_DIG);
    printf("DBL_MIN_EXP  = %d\n",  DBL_MIN_EXP);
    printf("DBL_MIN_10_EXP  = %d\n",  DBL_MIN_10_EXP);
    printf("DBL_MAX_EXP     = %d\n",  DBL_MAX_EXP);
    printf("DBL_MAX_10_EXP  = %d\n",  DBL_MAX_10_EXP);
    puts("");
    printf("LDBL_MIN      = %Le\n", LDBL_MIN);
    printf("LDBL_MAX      = %Le\n", LDBL_MAX);
    printf("LDBL_EPSILON  = %Le\n", LDBL_EPSILON);
    printf("LDBL_DIG      = %d\n", LDBL_DIG);
    printf("LDBL_MANT_DIG = %d\n", DBL_MANT_DIG);
    printf("LDBL_MIN_EXP  = %d\n",  DBL_MIN_EXP);
    printf("LDBL_MIN_10_EXP  = %d\n",  LDBL_MIN_10_EXP);
    printf("LDBL_MAX_EXP     = %d\n",  LDBL_MAX_EXP);
    printf("LDBL_MAX_10_EXP  = %d\n",  LDBL_MAX_10_EXP);
    printf("Please press ENTER");
    c = getchar();
    return(0);
}
