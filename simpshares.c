#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char **argv)
{
    int cintv; /* (days) time interval after when evaluate the variation */
    int nsteps; /* number of steps to evaluate */
    float shaprice; /* value of 1 share in dollars*/
    float sharevar; /* price variation (%) of 1 share in the last time interval*/
    int i;
    fprintf(stderr, "type time interval (days) after when evaluate the variation\n");
    if (scanf("%i", &cintv) != 1)
        fprintf(stderr, "%s: error in reading time interval\n", argv[0]);
    fprintf(stderr, "%s: time interval is %d days\n", argv[0], cintv);
    fprintf(stderr, "type number of time intervals to consider\n");
    if (scanf("%i", &nsteps) != 1)
        fprintf(stderr, "%s: error in reading number of time intervals to consider\n", argv[0]);
    fprintf(stderr, "%s: the time intervals to consider are %d\n", argv[0], nsteps);
    shaprice = 100.0;
    for (i=0; i<nsteps; i++){
        fprintf(stderr, "%s: day %d, type price variation (%%)\n", argv[0], (i+1)*cintv);
        if (scanf("%f", &sharevar) != 1)
            fprintf(stderr, "%s: error in reading the shares price variation (%%)\n", argv[0]);
        fprintf(stderr, "%s: shares price variation is %.2f (%%)\n", argv[0], sharevar);
        shaprice = shaprice + 0.01*sharevar*shaprice;
    }
        
    printf("%s: after %d days, the price is %.2f$\n", argv[0], nsteps*cintv, shaprice);
	return(0);
}
