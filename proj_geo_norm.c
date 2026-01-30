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
  fprintf(cfp,"#value,unit\n");
  fprintf(cfp,"%9.6f,km\n",Req);
  fprintf(cfp,"%9.6f,km\n",Rp);
  fprintf(cfp,"%9.6f,km\n",H);
  fprintf(cfp,"%9.6f,dd\n",Lon);
  fprintf(cfp,"%9.6f,dd\n",Lat);
  fprintf(cfp,"%9.6f, \n",fm1);
  fclose(cfp);
  fprintf(stderr,"inverse flattening = %9.6f\n",Req/(Req-Rp));
  return 0;
}

int main(int argc, char **argv){
  char *cnfile, temps[16], temps1[16];
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
/*   ret = write_conf_file(); 
   return 1; */
  cnfile=argv[1];
  fprintf(stderr,"cnfile: %s\n",cnfile);
  cfp = fopen(cnfile, "r");
  ret = fscanf(cfp,"%s",temps);
  fprintf(stderr,"%s\n",temps);
  ret = fscanf(cfp,"%lf,%s",&Req,temps1);
  fprintf(stderr,"Req = %9.6f %s\n",Req,temps1);
  ret = fscanf(cfp,"%lf,%s",&Rp,temps1);
  fprintf(stderr,"Rp = %9.6f %s\n",Rp,temps1);
  ret = fscanf(cfp,"%lf,%s",&H,temps1);
  fprintf(stderr,"H = %9.6f %s\n",H,temps1);
  ret = fscanf(cfp,"%lf,%s",&Lon,temps1);
  fprintf(stderr,"Lon = %9.6f %s\n",Lon,temps1);
  ret = fscanf(cfp,"%lf,%s",&Lat,temps1);
  fprintf(stderr,"Lat = %9.6f %s\n",Lat,temps1);strcpy(temps1,"");
  ret = fscanf(cfp,"%lf,%s",&fm1,temps1);
  fprintf(stderr,"mf1 = %9.6f %s\n",fm1,temps1);
  fclose(cfp);
  return 0;
}
