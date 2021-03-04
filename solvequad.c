/* PROGRAM solvequad.c adapted from fortran
* This program reads the coefficients of a quadratic equation of
* the form
* A * X**2 + B * X + C = 0,
* and solves for the roots of the equation (FORTRAN 77 style).
* Get the coefficients of the quadratic equation. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
        float A,B,C,Discr; int ret;
        printf("Computing solutions for\n");
        printf("Equation A * X^2 + B * X + C\n");
do {
        printf("Enter the coefficients A B and C:\n");
        printf("(with A not eq. to 0) :");
	    ret = scanf("%f %f %f", &A, &B, &C);
/* if A > 0 continue */
        if (sqrt((A - 0)*(A - 0)) >= 0.000001) break;
        printf("Illegal value for coeff. A\n");
        printf("A = %2.9g\n", A - 0);
} while (sqrt((A - 0)*(A - 0)) < 0.0000001);  
/* request input until A is > 0 */
	    
/*
* Echo the coefficients to make sure they are entered correctly.
*/
	printf("The coefficients are: %10.4g %10.4g %10.4g\n", A, B, C);
/*
* Check the discriminant and calculate its roots.
*/
    Discr = pow(B,2) - 4.*A*C;
	printf("Discriminant (= B^2 - 4.*A*C) is %g\n", Discr);
	if ( Discr  <  0) {
		printf("This equation has complex roots:\n");
		printf("X_1 = %g +i *%g\n", -B/(2.*A), sqrt(abs(Discr))/(2.*A) );
		printf("X_2 = %g -i *%g\n", -B/(2.*A), sqrt(abs(Discr))/(2.*A) );
    } else if ( sqrt((pow(B,2) - 4.*A*C - 0)*(pow(B,2) - 4.*A*C - 0)) < 0.0000001) {
            printf("Equation with single repeated real root:\n");
            printf("X_1 = X_2 =  %g\n", -B/(2.*A) );
    } else {
		printf("Equation with two distinct real roots:\n");
		printf("X_1 =%g\n", (-B + sqrt(abs(Discr)))/(2.*A));
		printf("X_2 =%g\n", (-B - sqrt(abs(Discr)))/(2.*A));
	}
/* * */
    return 0;
}
