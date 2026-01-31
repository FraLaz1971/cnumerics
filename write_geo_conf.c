#include <stdio.h>
#include <math.h>
#include <string.h>
int write_conf_file(){
  /* distances are in km */
  double Req = 6378.137;
  double Rp = 6356.7523;
  /* H: Earth_centre-Satellite distance (km) */
  double H =  42164.0;
  /* angles in DD Decimal Degrees */
  double Lon = 0.0;
  double Lat = 0.0;
  /* F^-1: Inverse flattening factor */
  double fm1 =  298.257223563;
  char *cnfile = "geonorm001.conf";
  FILE *cfp;
  cfp = fopen(cnfile, "w");
/*  fprintf(cfp,""); */
  fprintf(cfp,"#value,measure(unit)\n");
  fprintf(cfp,"%9.6f,Req(km)\n",Req);
  fprintf(cfp,"%9.6f,Rp(km)\n",Rp);
  fprintf(cfp,"%9.6f,H(km)\n",H);
  fprintf(cfp,"%9.6f,Lon(dd)\n",Lon);
  fprintf(cfp,"%9.6f,Lat(dd)\n",Lat);
  fprintf(cfp,"%9.6f,fm1\n",fm1);
  fclose(cfp);
  fprintf(stderr,"inverse flattening = %9.6f\n",Req/(Req-Rp));
  return 0;
}

int main(void){
  int ret;
  ret = write_conf_file();
  return 0;
}
