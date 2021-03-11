#include <stdio.h>
#include <math.h>
int main(){
/* length units */
	const double A1=1.0E-8;
	const double AU1=1.495E8;
	const double LY1=9.46E+12;
	const double PCLY1=3.26;
	const double PCKM1=3.087E+13;
	const double LSKMS=299.791;
	printf("1 Angstrom\t= %G cm\n",A1);
	printf("1 Astr.Unit(AU)\t= %G km\n",AU1);
	printf("1 LightSpeed\t= %G km/s\n",LSKMS);
	printf("1 LightYear\t= %G km\n",LY1);
	printf("1 Parsec(pc)\t= %G LY\n",PCLY1);
	printf("1 Parsec(pc)\t= %G km\n",PCKM1);
	printf("1 kpc\t\t= %G pc\n", 1000.0);
	printf("1 Mpc\t\t= %G pc\n", 1000000.0);
	return 0;
}
