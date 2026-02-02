#include <stdio.h>
#include <math.h>
#include <string.h>
#include "conversions.h"

double Req;
double Rp;
/* H: Earth_centre-Satellite distance (km) */
double H;
/* angles in DD Decimal Degrees
 * Lon_sat = longitude of the satellite projected on Earth surface
 * Lat_sat = latitude of the satellite projected on Earth surface
 */
double Lon_sat, tlon;
double Lat_sat, tlat;
/* F^-1: Inverse flattening factor */
double fm1;

/* Satellite position in radians */
double rLat_sat;
double rLon_sat;

double S1, S2, Gamma;

double getS1(double rx, double ry, double rz);
double getS2(double rx, double ry, double rz);
double getGamma();

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
  ret = fscanf(cfp, "%lf,%s", &Lon_sat, temps1);
  fprintf(stderr, "%9.6f %s\n", Lon_sat, temps1);
  ret = fscanf(cfp, "%lf,%s", &Lat_sat, temps1);
  fprintf(stderr, "%9.6f %s\n", Lat_sat, temps1);
  strcpy(temps1, "");
  ret = fscanf(cfp, "%lf,%s", &fm1, temps1);
  fprintf(stderr, "%9.6f %s\n", fm1, temps1);
  fclose(cfp);
  
  /*Conversione coordinate satellite in radianti */
  rLat_sat = ddeg2rad(Lat_sat);
  rLon_sat = ddeg2rad(Lon_sat);
  fprintf(stderr, "\nSatellite position (rad): Lat=%9.6f, Lon=%9.6f\n", 
          rLat_sat, rLon_sat);
  
  fprintf(stderr, "\npoints file: %s\n", ptsfile);
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
    
    /* Coordinate cartesiane del punto sulla Terra (ellissoide) */
    capitals[i].rx = Req * cos(capitals[i].rLat) * cos(capitals[i].rLon);
    capitals[i].ry = Req * cos(capitals[i].rLat) * sin(capitals[i].rLon);
    capitals[i].rz = Rp * sin(capitals[i].rLat);
    
    fprintf(stderr, "rx=%9.6f,ry=%9.6f,rz=%9.6f\n",
            capitals[i].rx, capitals[i].ry, capitals[i].rz);
    
    S1 = getS1(capitals[i].rx, capitals[i].ry, capitals[i].rz);
    S2 = getS2(capitals[i].rx, capitals[i].ry, capitals[i].rz);
    Gamma = getGamma();
    
    fprintf(stderr, "S1=%lf,S2=%lf,Gamma(rad)=%lf,Gamma(deg)=%lf\n",
            S1, S2, Gamma, Gamma * 180.0 / PI);
    
    printf("%s,%.6f,%.6f,%.6f,%.6f\n",
           capitals[i].city, capitals[i].Lat, capitals[i].Lon,
           Gamma * 180.0 / PI, Gamma);
  }
  
  fclose(ifp);
  return 0;
}

/*
 * S1: Distanza lungo la direzione nadir
 * Prodotto scalare tra vettore posizione punto e versore nadir
 */
double getS1(double rx, double ry, double rz) {
  /* rLat_sat e rLon_sat (in radianti) */
  return H - (rx * cos(rLat_sat) * cos(rLon_sat) +
              ry * cos(rLat_sat) * sin(rLon_sat) +
              rz * sin(rLat_sat));
}

/*
 * S2: Quadrato della distanza del punto dal centro Terra
 */
double getS2(double rx, double ry, double rz) {
  return rx * rx + ry * ry + rz * rz;
}

/*
 * Gamma: Angolo nadir in radianti
 * Formula: gamma = arctan(sqrt(S2 - S1^2) / S1)
 */
double getGamma() {
  double discriminant = S2 - S1 * S1;
  
  if (discriminant < 0) {
    fprintf(stderr, "WARNING: discriminant < 0 (=%9.6f), punto non visibile!\n",discriminant);
    exit(-1);
  }
  
  if (S1 <= 0) {
    fprintf(stderr, "WARNING: S1 <= 0 (=%9.6f), geometria non valida!\n",S1);
    exit(-1);
  }
  
  return atan(sqrt(discriminant) / S1);
}
