#include <stdio.h>
#include <math.h>
#define MAXDIM 1024
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
unsigned char is_included(unsigned int *vec,unsigned int elem){
	unsigned int i;
	for(i=0;i<MAXDIM;i++){
		if (vec[i]==elem) return 1;
	}
	return 0;
}
int main(void){
  unsigned int n,m,i,j,result;
  unsigned int divisors[2][MAXDIM];
  int res;
  for(i=0;i<2;i++){
	 for(j=0;j<MAXDIM;j++)
		divisors[i][j]=0;
  }
  printf("this program prints the GCD of 2 numbers\n");
  printf("enter 2 natural numberS [1,+INF) comma separated\n");
  res = scanf("%u,%u",&n,&m);
      j=0;
	  for (i=1;i<=n;i++){
		  if (divide(n,i)){
		    /*printf("%u is a divisor of %u\n",i,n);*/
		    divisors[0][j++]=i;
		  }else
		    continue;
	  }
      j=0;
	  for (i=1;i<=m;i++){
		  if (divide(m,i)){
		    /*printf("%u is a divisor of %u\n",i,m);*/
		    divisors[1][j++]=i;
		  }else
		    continue;
	  }
  /*
  for(i=0;i<2;i++){
	 for(j=0;j<MAXDIM;j++){
	    if (divisors[i][j]!=0)
		  printf("i:%u,j:%u-->%u\n",i,j,(divisors[i][j]));
	 }
  }*/
	  for(i=0;i<MAXDIM;i++){
		  if (is_included((unsigned int*)&divisors[1],divisors[0][i])&&(divisors[0][i]!=0)){
				/*printf("%u: %u is a common divisor\n",i,divisors[0][i]);*/
				result=divisors[0][i];
		  }
	  }
	  printf("The GCD of %u and %u is %u\n",n,m,result);
  return 0;
}
