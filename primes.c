#include <stdio.h>
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
int main(void){
  unsigned int n,i;
  unsigned char flag;
  int res;
  printf("this program tells you if n is a prime number\n");
  printf("enter 1 natural number [1,+INF)\n");
  res = scanf("%u",&n);
  flag=0;
	  for (i=2;i<=round(sqrt(n));i++){
		  if (divide(n,i)){
		    printf("%u is a divisor of %u\n",i,n);
		    flag=1;
		  }else
		    continue;
	  }
  if ((!flag)||(n==1)) 
	printf("%u is a prime number\n",n);
  else 
	printf("%u is NOT a prime number\n",n);
  return 0;
}
