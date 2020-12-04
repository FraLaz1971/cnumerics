#include <stdio.h>
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int main()
{
	int cur; char c1;
	int combination[3];
	float temps[] = { 97.0, 98.2, 98.6, 99.1 };
	combination[0] = 32;
	combination[1] = 17;
	combination[2] = 96;
	puts("printing temps[]");
	for (cur=0; cur<NELEMS(temps); cur++)
		printf("%f ", temps[cur]);
	puts("");
	puts("printing combination[]");
	for (cur=0; cur<NELEMS(combination); cur++)
		printf("%d ", combination[cur]);
	puts("\nplease, press ENTER");
	c1 = getchar();
	return 0;
}
