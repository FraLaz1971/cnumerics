#include <stdio.h>
#include <stdlib.h>
/* this program reads an array and prints out it's double */
int main(int argc, char **argv){
	int low, upper, cur, re, dre, res;
	char vre[20];
if (argc != 2){
                puts("please enter input parameters");
                printf("%s array_size < filename\n", argv[0]);
                return(1);
        } else {
	const char *txts=(const char *) argv[1];
	fprintf(stderr, "%s.main() you entered %d parameter(s)\n", argv[0], argc);
	fprintf(stderr, "%s.main() doubling a vector read from stdout \n", argv[0]);
	fprintf(stderr, "%s.main() reading a %s elements 1D array \n", argv[0], txts);
	/* txtl=argv[1]; txtu=argv[2]; */
	txts=argv[1]; //txtu=argv[2];
	/* low=atoi(txtl); upper=atoi(txtu); */
	upper=atoi(txts)-1;
	low=0;res=0;
	for (cur=low; cur<=upper; cur++){
			res=scanf("%s", vre);
			re=atoi(vre);
			dre=re*2;
			printf("%d\n",dre);
    }
}
	return(res);
    
}
