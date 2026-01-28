#include <stdio.h>
#include <math.h>
int main(void){
  unsigned int on,om,n,m,q,r,temp,result;
  int res;
  printf("this program prints the GCD of 2 numbers\n");
  do {
    printf("enter 2 natural numberS [1,+INF) comma separated\n");
    res = scanf("%u,%u",&on,&om);
  } while((on==0)||(om==0));
  n=on;m=om;
  if(n<m){
	  temp=n;
	  n=m;
	  m=temp;
  }
/*  printf("computing the GCD of %u and %u\n", n,m); */
  if(n==m) {
    result=n;
  } else {
	while(r!=0){
	    q=n/m; r=n%m;
/*		printf("n:%u m:%u q:%u r:%u m*q+r:%u\n",n,m,q,r,m*q+r); */
	    if(r==0){
			result=m;
		} else {
			n=m;
			m=r;
		}
	 }
  } 
  printf("The GCD of %u and %u is %u\n",on,om,result);
  return 0;
}
