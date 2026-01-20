#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXDIM 65536

/** divide() function takes as input the dividend den and the divisor dor and returns 1 (=true)
 if dor is a perect divisor of den and 0 if not */
unsigned char divide(int den,int dor){
	int res;
	float f,q;
	const float eps=0.000001;
	q=(float)den/(float)dor;
	if (q-(den/dor)<eps) 
	  return 1;
	else 
	   return 0;
}
/** create() function takes as input a monodimensional array mulvec[] of unsigned integers and returns the
 * multiplication of all members != 0 */
int create(unsigned int *mulvec){
	unsigned int i, mul;
	mul=1;
	for (i=0; i<MAXDIM;i++){
	  if(mulvec[i]>0) mul=mul*mulvec[i];
	  /* printf("i=%u mul=%u\n",i,mul); */
	}
  return mul;
}
/** is_included() takes as input a vector ve[] and an unsigned integer elem
 and returns 1 if the element is included in the vector or 0 if not */
unsigned char is_included(unsigned int *vec,unsigned int elem){
	unsigned int i;
	for(i=0;i<MAXDIM;i++){
		if (vec[i]==elem) return 1;
	}
	return 0;
}
/** is_prime() takes as input an unsigned integer n anf gives as output
 the value 1 if n is a prime number or 0 if it is not prime */
unsigned char is_prime(unsigned int n){
  unsigned int i;
  unsigned char flag;
  flag=0;
	  for (i=2;i<=round(sqrt(n));i++){
		  if (divide(n,i)){
		    /* printf("%u is a divisor of %u\n",i,n);*/
		    flag=1;
		  }else
		    continue;
	  }
  return (!flag) ? 1: 0;
}

/** is_factor() returns 1(=true) if dor is a factor of den or 0 if it is not */
unsigned char is_factor(int den,int dor){
	int res;
	float f,q;
	const float eps=0.000001;
	q=(float)den/(float)dor;
	if ((q-(den/dor)<eps)&&is_prime(dor)) 
	  return 1;
	else 
	   return 0;
}

/**
 * \image html ./cgd_school_ad.png
   \image latex ./cgd_school_ad.eps "activity diagram of the program gcd_school" width=10cm
 ![activity diagram of the program gcd_school](cgd_school_ad.png)
 */

/** greatest common divisor (GCD) school algorithm: take common factors with smaller exponent */
int main(void){
  unsigned int n,m,i,j,k,currfac,GCD;
  unsigned char flag;
  unsigned char facflag[MAXDIM];
  unsigned int factors[2][MAXDIM];
  unsigned int expon[2][MAXDIM];
  unsigned int flags[2][MAXDIM];
  int res;

  /** - Initialize the variables */
  GCD=1;
  for(i=0;i<2;i++){
	 for(j=0;j<MAXDIM;j++){
		factors[i][j]=0;
		expon[i][j]=0;
		flags[i][j]=0;
	 }
  }

  /** - Take the 2 numbers n and m as input */
  printf("this program prints the GCD of 2 numbers\n");
  printf("enter 2 natural numberS [1,+INF) comma separated\n");
  res = scanf("%u,%u",&n,&m);
  printf("extracting factors of n:%u\n",n);

  /** - decompose n in factors */
/**
 * \image html ./factors_decomposition.png
   \image latex ./factors_decomposition.eps "decomposition in factors of a number" width=10cm
 ![decomposition in factors of a number](factors_decomposition.png)
 */
  j=0;
    while(create((unsigned int*)factors[0])!=n){
		  for (i=2;i<=n;i++){
			  if (is_factor(n,i)&&(create((unsigned int*)factors[0])*i<=n)&&(divide(n,round(pow(i,expon[0][i]+1))))){
			/*     printf("%u\n",i);*/
			     factors[0][j]=i;
			     expon[0][i]++;
				 j++;
			  }else
			    continue;
		  }
/*    printf("created(factors[0]):%d j=%u\n",create((unsigned int*)factors[0]),j); */
}
/*    printf("showing the factors\n"); */
	/** - Show factors of n each with its exponent */
    for(k=0;k<MAXDIM;k++){
      if((factors[0][k])&&(flags[0][factors[0][k]]<1)) {
		  printf("%u^%u\n",factors[0][k],expon[0][factors[0][k]]);
		  flags[0][factors[0][k]]++;
      }
  }
  /** - decompose m in factors */
  printf("extracting factors of m:%u\n",m);
    j=0;
    while(create((unsigned int*)factors[1])!=m){
		  for (i=2;i<=m;i++){
			  if (is_factor(m,i)&&(create((unsigned int*)factors[1])*i<=m)&&(divide(m,round(pow(i,expon[1][i]+1))))){
			/*    printf("%u\n",i); */
			    factors[1][j]=i;
			    expon[1][i]++;
				j++;
			  }else
			    continue;
		  }
/*    printf("created(factors[1]):%d j=%u\n",create((unsigned int*)factors[1]),j); */
  }
/*    printf("showing the factors\n"); */
	/** - Show factors of m each with its exponent */
    for(k=0;k<MAXDIM;k++){
      if((factors[1][k])&&(flags[1][factors[1][k]]<1)){
			printf("%u^%u\n",factors[1][k],expon[1][factors[1][k]]);
			flags[1][factors[1][k]]++;
		}
    }
    	/** - Select the common factors with the minimum exponent */

        currfac=2;
        while(currfac<round(fmax(n,m))){
    		if((is_included(factors[0],currfac)&&(is_included(factors[1],currfac)))) {
				if(expon[0][currfac]<expon[1][currfac]){
					GCD*=pow(currfac,expon[0][currfac]);
					/*printf("taking %u^%u\n",currfac,expon[0][currfac]);*/
				} else{
					GCD*=pow(currfac,expon[1][currfac]);
					/*printf("taking %u^%u\n",currfac,expon[1][currfac]);*/
				}
			}
			currfac++;
		}
		/** - Show GCD computed value */
    printf("GCD of %u and %u is %u\n",n,m,GCD);
  return 0; 
}
