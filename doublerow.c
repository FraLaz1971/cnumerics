#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
/* this program reads an array and prints out it's double as a row vector */
int main(int argc, char **argv){
/* low stores the lower index of the vector, upper store the higher index of the vector, 
cur is the current vector element processed, re it is the integer value of the input string read
dre it is the dubbed value to print in output res it is the return value of the main() function */
	int low, upper, cur, re, dre, res;
	char vre[20]; /* store the current input element as string */
	char txts[20]; /* stores the input size as a string */
if (argc != 2){ /* if n. of input parameters is not 2 (program name + size) ends and return 1 (== failure) */
                puts("please enter input parameters");
                printf("%s array_size < filename\n", argv[0]);
                return(1);
        } else { /* if you got only the size in input */
	strcpy(txts,argv[1]); /* txts takes the size input string value */
	upper=atoi(txts)-1; /* upper takes the maximum index of the vector elements to be processed */
	low=0;res=0;
#if defined(DEBUG) && (DEBUG==1)
	fprintf(stderr, "%s.main() you entered %d parameter(s)\n", argv[0], argc);
	fprintf(stderr, "%s.main() doubling a vector read from stdout \n", argv[0]);
	fprintf(stderr, "%s.main() reading a %s elements 1D array \n", argv[0], txts);
#endif
	for (cur=low; cur<=upper; cur++){ /* do this for all vector indexes < upper*/
			res=scanf("%s", vre); /* read string element from stdin */
			re=atoi(vre); /* convert string to integer var. re */
			dre=re*2; /* assign the dubbed value to int var dre */
			printf("%d ",dre); /* print the dubbed element value on the stdout */
    } /* end of for loop on vector elements */
  puts(""); /* go to new line */
} /* and of if number of input parameters is correct */
	return(res); /* return 0 (== success) */

}
