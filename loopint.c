#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
	if (argc != 3){
		puts("please enter the interval limits");
		printf("%s <lower_limit> <upper_limit>\n", argv[0]);
		return(1);
	} else {
		int low, upper, cur; const char *txtl; const char * txtu;
		txtl=argv[1]; txtu=argv[2];
		low=atoi(txtl); upper=atoi(txtu);
		fprintf(stderr, "we'll display integers in the following interval:");
		fprintf(stderr, "[%d, %d]\n", low, upper);
		for (cur=low; cur<=upper; cur++){
			printf("%d\n",cur);
		}
	}
	return(0);
}
