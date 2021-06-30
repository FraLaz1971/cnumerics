/* this program is perfect */
#include <stdio.h>
int main(void) {
	int cows, legs, ret;
	printf("How many cow legs did you count?\n");
	ret = scanf("%d", &legs);
	#ifdef DEBUG
	fprintf(stderr, "scanf() return value is %d \n", ret);
	#endif
	cows = legs / 4;
	printf("That implies there are %d cows.\n", cows);
	return 0;
}

