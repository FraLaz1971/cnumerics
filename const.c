#include <stdio.h>

int main(){
	char c;
	const double notchange = 10/3.0;
	printf("notchange is %f\n", notchange);
/* if you uncomment the following you will get an error */
/*	notchange = 7/3.0; */

        printf("Please press ENTER");
        c = getchar();
	return 0;
}


