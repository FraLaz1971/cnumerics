#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int create(unsigned int *mulvec){
	unsigned int i, mul;
	mul=1;
	for (i=0; i<1024;i++){
	  if(mulvec[i]>0) mul=mul*mulvec[i];
	  /* printf("i=%u mul=%u\n",i,mul); */
	}
  return mul;
}
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

/* this program gives the factorization of n*/
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

int main(void){
  unsigned int n,i,j,k,*factors;
  unsigned char flag;
  int res;
  factors = calloc(1024,sizeof(unsigned int));
  printf("enter 1 natural number [1,+INF)\n");
  res = scanf("%u",&n);
    j=0;
    while(create(factors)<n){
	      flag=0;
		  for (i=2;i<=n;i++){
			  if (is_factor(n,i)&&(create(factors)*i<=n)){
			     printf("%u\n",i);
			    factors[j++]=i;
			    flag=1;
			  }else
			    continue;
		  }
    /*printf("created:%d\n",create(factors));
    for(k=0;k<1024;k++)
      if(factors[k]) printf("factors[%u]=%u\n",k,factors[k]);*/
  }
  return 0; 
}
