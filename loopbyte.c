/* this program print numbers in the given interval 
using an unsigned char (8 bit) variable */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
	if (argc != 3){
		puts("please enter positive number for interval limits");
		printf("%s <lower_limit> <upper_limit>\n", argv[0]);
		return(1);
	} else {
		unsigned char low, upper; int cur; const char *txtl; const char * txtu;
		txtl=argv[1]; txtu=argv[2];
		low=atoi(txtl); upper=atoi(txtu);
		if ( (low < 0) || (upper < 0) ) {
			fprintf(stderr, "please enter numbers > 0\n");
			return 1;
		}
		fprintf(stderr, "we'll display integers in the following interval:");
		fprintf(stderr, "[%d, %d]\n", low, upper);
		for (cur=low; cur<=upper; cur++){
			printf("%d\n",cur);
		}
	}
	return(0);
}
