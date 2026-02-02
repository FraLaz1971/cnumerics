#include <stdio.h>
#include <math.h>
#include <string.h>
#include "conversions.h"
  double Req;
  double Rp;
  /* H: Earth_centre-Satellite distance (km) */
  double H;
  /* angles in DD Decimal Degrees */
  double Lon_sat,tlon;
  double Lat_sat,tlat;
  /* F^-1: Inverse flattening factor */
  double fm1;
  double S1,S2,S3,Gamma;

double getS1(double rx,double ry,double rz);
double getS2(double rx,double ry,double rz);
double getS3(double rx,double ry,double rz);
double getGamma();

int main(int argc, char **argv){
  char *cnfile, *ptsfile,temps[32], temps1[16];
  struct Capital capitals[6];
  FILE *cfp,*ifp;
  int ret, i;
  if (argc<3){
    fprintf(stderr, "usage:%s <file.conf> <points_file.csv>\n",argv[0]);
    return 1;
  }
  cnfile=argv[1];
  ptsfile=argv[2];
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
  ret = fscanf(cfp,"%lf,%s",&Lon_sat,temps1);
  fprintf(stderr,"%9.6f %s\n",Lon_sat,temps1);
  ret = fscanf(cfp,"%lf,%s",&Lat_sat,temps1);
  fprintf(stderr,"%9.6f %s\n",Lat_sat,temps1);strcpy(temps1,"");
  ret = fscanf(cfp,"%lf,%s",&fm1,temps1);
  fprintf(stderr,"%9.6f %s\n",fm1,temps1);
  fclose(cfp);
   /* (Latitude φ, Longitude λ)
   rx = Req*cos(Lat)*cos(Lon)
   ry = Req*cos(Lat)*sin(Lon)
   rz = Rp*sin(Lat)
   */
  fprintf(stderr,"points file: %s\n",ptsfile);
  ifp = fopen(ptsfile, "r");
  ret = fscanf(ifp,"%s",temps);
  fprintf(stderr,"%s\n",temps);
  for(i=0;i<5;i++){
    ret = fscanf(ifp,"%lf,%lf,%s",&tlat,&tlon,temps);
    capitals[i].Lat=tlat; capitals[i].Lon=tlon;capitals[i].city=temps;
    capitals[i].rLat=ddeg2rad(capitals[i].Lat);capitals[i].rLon=ddeg2rad(capitals[i].Lon);
    fprintf(stderr,"Lat=%9.6f,rLat=%9.6f,Lon=%9.6f,rLon=%9.6f,City=%s\n",capitals[i].Lat,capitals[i].rLat, \
    capitals[i].Lon,capitals[i].rLon,capitals[i].city);
    capitals[i].rx=Req*cos(capitals[i].rLat)*cos(capitals[i].rLon);
    capitals[i].ry=Req*cos(capitals[i].rLat)*sin(capitals[i].rLon);
    capitals[i].rz=Rp*sin(capitals[i].rLat);
    fprintf(stderr,"rx=%9.6f,ry=%9.6f,rz=%9.6f\n",capitals[i].rx,capitals[i].ry,capitals[i].rz);
    S1=getS1(capitals[i].rx,capitals[i].ry,capitals[i].rz);
    S2=getS2(capitals[i].rx,capitals[i].ry,capitals[i].rz);
    S3=getS3(capitals[i].rx,capitals[i].ry,capitals[i].rz);
    Gamma=getGamma();
    fprintf(stderr,"S1=%lf,S2=%lf,S3=%lf,Gamma=%lf\n",S1,S2,S3,Gamma);
  }
  fclose(ifp);
  return 0;
}
/*
The projection maps the sub-satellite point to the center (0, 0) and the edges of the Earth to the limits defined by the distance of the satellite. These formulas first calculate the 3D Cartesian coordinates (rx, ry, rz) of the point on the Earth's surface, and then project them into plane coordinates (x, y).
*/
double getS1(double rx,double ry,double rz){
  return H-(rx*cos(ddeg2rad(Lat_sat))*cos(ddeg2rad(Lon_sat))+ry*cos(ddeg2rad(Lat_sat))*sin(ddeg2rad(Lon_sat))+rz*sin(ddeg2rad(Lat_sat)));
/*\(S_{1}=H-(r_{x}\cos (\phi _{0})\cos (\lambda _{0})+r_{y}\cos (\phi _{0})\sin (\lambda _{0})+r_{z}\sin (\phi _{0}))\)*/
}
double getS2(double rx,double ry,double rz){
  return rx*rx + ry*ry + rz*rz;
}
double getS3(double rx,double ry,double rz){
 return pow((H*cos(ddeg2rad(Lat_sat))*cos(ddeg2rad(Lon_sat))-rx),2)+pow((H*cos(ddeg2rad(Lat_sat))*sin(ddeg2rad(Lon_sat))-ry),2)+pow((H*sin(ddeg2rad(Lat_sat))-rz ),2);
}

double getGamma(){
  return atan(sqrt(S2-S1*S1)/S1);
}
