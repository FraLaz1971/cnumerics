#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265
/* #n,Capital City,Country,Continent,Latitude,Longitude */
struct Capital{
  unsigned char n;
  char *city;
  char *country;
  char *continent;
  float Lat;
  float Lon;
};

struct Angle{
  unsigned short deg;
  unsigned char min;
  unsigned char sec;
};

int decdeg2deg (float dd, struct Angle *iangle);

float deg2decdeg(unsigned short deg, unsigned char min, unsigned char sec);

float ddeg2rad(float d);

float deg2rad(unsigned short deg, unsigned char min, unsigned char sec);

int main(int argc, char **argv){
  int i, mret;
  char *outfile="few_capitals.csv";
  FILE *ofp;
  struct Angle angle;
  struct Capital capitals[5];
  capitals[0].n=18 ;capitals[0].city="Baku";capitals[0].country="Azerbaijan";capitals[0].continent="Asia";capitals[0].Lat=40.366943;capitals[0].Lon=49.84;
  capitals[1].n=75 ;capitals[1].city="Jerusalem";capitals[1].country="Palestine";capitals[1].continent="Asia";capitals[1].Lat=31.7767;capitals[1].Lon=35.236946;
  capitals[2].n=154;capitals[2].city="Rome";capitals[2].country="Italy";capitals[2].continent="Europe";capitals[2].Lat=41.8992;capitals[2].Lon=12.511666;
  capitals[3].n=174;capitals[3].city="Tallin";capitals[3].country="Estonia";capitals[3].continent="Europe";capitals[3].Lat=59.437222;capitals[3].Lon=24.745277;
  capitals[4].n=92 ;capitals[4].city="Lisbon";capitals[4].country="Portugal";capitals[4].continent="Europe";capitals[4].Lat=38.728054;capitals[4].Lon=-9.15;
  printf("      city\tlat\tlon\n");
  printf("------------------------------\n");
  ofp=fopen(outfile, "w");
  fprintf(ofp,"#city,  Lat,  Lon\n");
  for(i=0;i<5;i++){
      printf("%10s\t%5.2f\t%5.2f\n",capitals[i].city,capitals[i].Lat,capitals[i].Lon);
      fprintf(ofp,"%10s,%9.6f,%9.6f\n",capitals[i].city,capitals[i].Lat,capitals[i].Lon);
  }
  printf("------------------------------\n");
  fclose(ofp);
  printf("The Latitude of %s is %4.2f (angle with decimals)\n",capitals[2].city,capitals[2].Lat);
  mret = decdeg2deg(capitals[2].Lat, &angle);
  printf("Or better is %d degrees %d minutes and %d seconds\n",angle.deg,angle.min,angle.sec);
  printf("back in decimal degrees is %5.2f\n",deg2decdeg(angle.deg,angle.min,angle.sec));
  return 0;
}

float ddeg2rad(float d){
  float rad;
  rad = d*PI/180.0;
  return rad;
}

float deg2decdeg(unsigned short deg, unsigned char min, unsigned char sec){
  float dd;
  dd = deg+min/60.0+sec/3600.0;
  return dd;
}

int decdeg2deg (float dd, struct Angle *iangle) {
  int ret=0; float tf;
  iangle->deg=(int)dd;
  tf = (dd-iangle->deg)*60.0;
  iangle->min=(int)tf;
  tf = tf - iangle->min;
  iangle->sec=round(tf*60.0);
  return ret;
}


/*
 * #n,Capital City,Country,Continent,Latitude,Longitude
                          x_d    180       x_r    x_d   pi
 x_d/(x_r) = 180/pi ---> ---- = ---- --->     =     * ----
                          x_r    pi                    180

  min   100      s   min*60   min*3
  --- = --- --->   = ------ = ----- = min*0.6
   s     60           100       5
 */
