#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "errvals.h"
/* compute x raised to the y power reading
 * input values from command line parameters
 * given after the program executable name
 */
int main(int argc, char *argv[]) {
    double x,y,p;
   if (argc != 3){
        fprintf(stderr,"%s: compute x raised to y power\n", argv[0]);
        fprintf(stderr,"usage: %s <x> <y>\n", argv[0]);
        return EX_BADARGS;
   } else {
        /* atof() convert strings to real numbers */
        x = atof(argv[1]);
        y = atof(argv[2]);
        p = pow(x, y);
        printf("The result of %g^%g is %g\n", x, y, p);
        return EXIT_SUCCESS;
   }
}

