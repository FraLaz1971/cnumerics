#include <stdio.h>
#include <math.h>
#include <string.h>
#include "conversions.h"
/*

         Satellite S (posizione: H dal centro)
           /|
          / |
         /  |
      d /   |
       /    |
      / γ   |
     /      |
    P       |
  (punto)   |
            |
        (C: centro Terra)

    |S-C| = H ≈ 42164 km
    |P-C| = R ≈ 6369 km
    |S-P| = d ≈ 39422 km

 */
double Req;
double Rp;
/* H: Earth_centre-Satellite distance (km) */
double H;
/* angles in DD Decimal Degrees */
double Lon, tlon;
double Lat, tlat;
/* F^-1: Inverse flattening factor */
double fm1;

/* Satellite position in radians */
double rLat_sat;
double rLon_sat;

/* Satellite position in Cartesian coordinates */
double Sx, Sy, Sz;

double Gamma;

double getGamma(double rx, double ry, double rz);

int main(int argc, char **argv) {
  char *cnfile, *ptsfile, temps[32], temps1[16];
  struct Capital capitals[6];
  FILE *cfp, *ifp;
  int ret, i;
  
  if (argc < 3) {
    fprintf(stderr, "usage:%s <file.conf> <points_file.csv>\n", argv[0]);
    return 1;
  }
  
  cnfile = argv[1];
  ptsfile = argv[2];
  fprintf(stderr, "cnfile: %s\n", cnfile);
  
  cfp = fopen(cnfile, "r");
  ret = fscanf(cfp, "%s\n", temps);
  fprintf(stderr, "%s\n", temps);
  ret = fscanf(cfp, "%lf,%s", &Req, temps1);
  fprintf(stderr, "%9.6f %s\n", Req, temps1);
  ret = fscanf(cfp, "%lf,%s", &Rp, temps1);
  fprintf(stderr, "%9.6f %s\n", Rp, temps1);
  ret = fscanf(cfp, "%lf,%s", &H, temps1);
  fprintf(stderr, "%9.6f %s\n", H, temps1);
  ret = fscanf(cfp, "%lf,%s", &Lon, temps1);
  fprintf(stderr, "%9.6f %s\n", Lon, temps1);
  ret = fscanf(cfp, "%lf,%s", &Lat, temps1);
  fprintf(stderr, "%9.6f %s\n", Lat, temps1);
  strcpy(temps1, "");
  ret = fscanf(cfp, "%lf,%s", &fm1, temps1);
  fprintf(stderr, "%9.6f %s\n", fm1, temps1);
  fclose(cfp);
  
  /* Convert satellite position to radians */
  rLat_sat = ddeg2rad(Lat);
  rLon_sat = ddeg2rad(Lon);
  fprintf(stderr, "\nSatellite position (rad): Lat=%9.6f, Lon=%9.6f\n", 
          rLat_sat, rLon_sat);
  
  /* Calculate satellite Cartesian coordinates */
  Sx = H * cos(rLat_sat) * cos(rLon_sat);
  Sy = H * cos(rLat_sat) * sin(rLon_sat);
  Sz = H * sin(rLat_sat);
  fprintf(stderr, "Satellite position (km): X=%9.3f, Y=%9.3f, Z=%9.3f\n\n",
          Sx, Sy, Sz);
  
  fprintf(stderr, "points file: %s\n", ptsfile);
  ifp = fopen(ptsfile, "r");
  ret = fscanf(ifp, "%s", temps);
  fprintf(stderr, "%s\n", temps);
  
  printf("#City,Lat(deg),Lon(deg),Gamma(deg),Gamma(rad)\n");
  
  for (i = 0; i < 5; i++) {
    ret = fscanf(ifp, "%lf,%lf,%s", &tlat, &tlon, temps);
    capitals[i].Lat = tlat;
    capitals[i].Lon = tlon;
    capitals[i].city = temps;
    capitals[i].rLat = ddeg2rad(capitals[i].Lat);
    capitals[i].rLon = ddeg2rad(capitals[i].Lon);
    
    fprintf(stderr, "\nLat=%9.6f,rLat=%9.6f,Lon=%9.6f,rLon=%9.6f,City=%s\n",
            capitals[i].Lat, capitals[i].rLat,
            capitals[i].Lon, capitals[i].rLon, capitals[i].city);
    
    /* Cartesian coordinates of point on Earth (ellipsoid) */
    capitals[i].rx = Req * cos(capitals[i].rLat) * cos(capitals[i].rLon);
    capitals[i].ry = Req * cos(capitals[i].rLat) * sin(capitals[i].rLon);
    capitals[i].rz = Rp * sin(capitals[i].rLat);
    
    fprintf(stderr, "rx=%9.6f,ry=%9.6f,rz=%9.6f\n",
            capitals[i].rx, capitals[i].ry, capitals[i].rz);
    
    /* Calculate nadir angle */
    Gamma = getGamma(capitals[i].rx, capitals[i].ry, capitals[i].rz);
    
    if (Gamma >= 0) {
      fprintf(stderr, "Gamma(rad)=%lf, Gamma(deg)=%lf\n",
              Gamma, Gamma * 180.0 / M_PI);
      
      printf("%s,%.6f,%.6f,%.6f,%.6f\n",
             capitals[i].city, capitals[i].Lat, capitals[i].Lon,
             Gamma * 180.0 / M_PI, Gamma);
    } else {
      fprintf(stderr, "ERROR: Point not visible or calculation error\n");
      printf("%s,%.6f,%.6f,ERROR,ERROR\n",
             capitals[i].city, capitals[i].Lat, capitals[i].Lon);
    }
  }
  
  fclose(ifp);
  return 0;
}

/*
 * Calculate nadir angle γ using the law of cosines
 * 
 * In the triangle Satellite-Point-EarthCenter:
 *   H = distance satellite to Earth center
 *   R = distance point to Earth center
 *   d = distance satellite to point
 * 
 * By law of cosines:
 *   R² = H² + d² - 2·H·d·cos(γ)
 * 
 * Therefore:
 *   cos(γ) = (H² + d² - R²) / (2·H·d)
 */
double getGamma(double rx, double ry, double rz) {
  /* Distance of point from Earth center */
  double R = sqrt(rx*rx + ry*ry + rz*rz);
  
  /* Distance from satellite to point */
  double dx = Sx - rx;
  double dy = Sy - ry;
  double dz = Sz - rz;
  double d = sqrt(dx*dx + dy*dy + dz*dz);
  
  /* Nadir angle using law of cosines */
  double cos_gamma = (H*H + d*d - R*R) / (2.0 * H * d);
  
  /* Check for valid range */
  if (cos_gamma < -1.0 || cos_gamma > 1.0) {
    fprintf(stderr, "WARNING: cos(gamma) = %lf out of range [-1,1]\n", cos_gamma);
    return -1.0;
  }
  
  double gamma = acos(cos_gamma);
  
  /* Additional check: point should be visible (γ < arcsin(R/H)) */
  double max_gamma = asin(R / H);
  if (gamma > max_gamma) {
    fprintf(stderr, "WARNING: gamma=%.3f° exceeds horizon %.3f°\n",
            gamma*180/M_PI, max_gamma*180/M_PI);
  }
  
  return gamma;
}
