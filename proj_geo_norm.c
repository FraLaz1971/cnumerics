#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char **argv){
  char *cnfile, temps[32], temps1[16];
  FILE *cfp;
  int ret;
  double Req;
  double Rp;
  /* H: Earth_centre-Satellite distance (km) */
  double H;
  /* angles in DD Decimal Degrees */
  double Lon;
  double Lat;
  /* F^-1: Inverse flattening factor */
  double fm1;
  if (argc<2){
    fprintf(stderr, "usage:%s <file.conf>\n",argv[0]);
    return 1;
  }
  cnfile=argv[1];
  fprintf(stderr,"cnfile: %s\n",cnfile);
  cfp = fopen(cnfile, "r");
  ret = fscanf(cfp,"%s\n",temps);
  fprintf(stderr,"%s\n",temps);
  ret = fscanf(cfp,"%lf,%s",&Req,temps1);
  fprintf(stderr,"%9.6f %s\n",Req,temps1);
  ret = fscanf(cfp,"%lf,%s",&Rp,temps1);
  fprintf(stderr,"%9.6f %s\n",Rp,temps1);
  ret = fscanf(cfp,"%lf,%s",&H,temps1);
  fprintf(stderr,"%9.6f %s\n",H,temps1);
  ret = fscanf(cfp,"%lf,%s",&Lon,temps1);
  fprintf(stderr,"%9.6f %s\n",Lon,temps1);
  ret = fscanf(cfp,"%lf,%s",&Lat,temps1);
  fprintf(stderr,"%9.6f %s\n",Lat,temps1);strcpy(temps1,"");
  ret = fscanf(cfp,"%lf,%s",&fm1,temps1);
  fprintf(stderr,"%9.6f %s\n",fm1,temps1);
  fclose(cfp);
  return 0;
}
