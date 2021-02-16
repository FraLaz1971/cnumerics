#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "errvals.h"
/* compute x raised to the y power reading
 * input values from command line parameters
 * given after the program executable name
 */
int main(int argc, char *argv[]) {
    double x,y,p; int ret;
    FILE *ifp;
   if (argc != 2){
        fprintf(stderr,"%s: compute x raised to y power\n", argv[0]);
        fprintf(stderr,"usage: %s <infile>\n", argv[0]);
        return EX_BADARGS;
   } else {
        /* atof() convert strings to real numbers */
        ifp = fopen(argv[1], "r");
        if (ifp != 0){
            fprintf(stderr, "%s: opened for reading file name:'%s'/pointer:%p\n", argv[0], argv[1],ifp);
            do {
                ret = fscanf(ifp,"%lf %lf", &x, &y);
                fprintf(stderr,"%s: fscanf() return value is %d\n",argv[0], ret);
                if (ret !=2){
                    if (ret == 1)
                        fprintf(stderr, "%s: only 1 input data read, expected 2\n", argv[0]);
                if (ret == -1)
                    fprintf(stderr, "%s: no (more) data to read from %s\n", argv[0], argv[1]);
                    return EX_IOERR;
                }
                fprintf(stderr,"%s: read x:%g y:%g input values\n",argv[0], x, y);
                p = pow(x, y);
                fprintf(stderr,"%s: The result of %g^%g is %g\n",argv[0], x, y, p);
                printf("%g ",p);
            } while (ret != -1);
            if (ret == -1)
                fprintf(stderr, "%s: no more data to read from %s\n", argv[0], argv[1]);
            fclose(ifp);
            return EXIT_SUCCESS;
        } else {
            fprintf(stderr, "%s: error opening file name:'%s' pointer:%p\n", argv[0], argv[1],ifp);
            fprintf(stderr, "%s: is the file name correct?\n", argv[0]);
            return EX_NOINPUT;
        }
   }
}

