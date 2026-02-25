#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXD 10
int main(int argc, char **argv){
  char *datafile;
  FILE *dfp;
  double x[MAXD], ea[MAXD], er[MAXD], sum, xm;
  int i, res, dim;
  if(argc<2){
    fprintf(stderr, "usage:%s <datafile>\n",argv[0]);
    return 1;
  }
  datafile = argv[1];
  dfp = fopen(datafile, "r");
  i = 0; sum = 0;
  while(res = fscanf(dfp, "%lfm,\n", &x[i]) != -1 ){
/*    res = fscanf(dfp, "%lfm,\n", &x[i]); */
    fprintf(stderr, "read %5.2f res=%d i=%d\n", x[i], res, i);
/* compute sum */
    sum += x[i];
    i++;
  }
/* average value  */
  fclose(dfp);
  dim = i;
  xm = sum/dim;
  fprintf(stderr, "average = %5.3f\n", xm);
  for (i=0;i<dim;i++){
    /* absolute error */
    ea[i] = xm - x[i];
  fprintf(stderr, "x_i=%5.3f xm=%5.3f abs_err = %5.3f\n",x[i],xm, ea[i]);
  /* relative error */
    er[i] = fabs(ea[i])/xm;
  fprintf(stderr, "xm=%5.3f rel_err = %8.5f\n",xm, er[i]);
  /* correct number of digits */
  fprintf(stderr, "x=%g\n",x[i]);
  }
  return 0;
}
