#include <stdio.h>
#include <math.h>
/* this program gives all the prime numbers between 1 and n*/
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
int main(void){
  unsigned int n,i,j;
  unsigned char flag;
  int res;
  printf("this program prints all the first n prime numbers\n");
  printf("enter 1 natural number [2,+INF)\n");
  res = scanf("%u",&n);
  for(j=2;j<=n;j++){
	  flag=0;
		  for (i=2;i<=round(sqrt(j));i++){
			  if (divide(j,i)){
			    /*printf("%u is a divisor of %u\n",i,j);*/
			    flag=1;
			  }else
			    continue;
		  }
	  if (!flag) printf("%u\n",j);
	  }
  return 0; 
}
