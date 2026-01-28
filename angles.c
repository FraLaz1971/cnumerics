#include <stdio.h>
#include <string.h>
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


float ddeg2rad(float d);

float deg2rad(unsigned short deg, unsigned char min, unsigned char sec);

int main(int argc, char **argv){
  int i;
  struct Capital capitals[5];
  capitals[0].n=18 ;capitals[0].city="Baku";capitals[0].country="Azerbaijan";capitals[0].continent="Asia";capitals[0].Lat=40.29;capitals[0].Lon=49.56;
  capitals[1].n=75 ;capitals[1].city="Jerusalem";capitals[1].country="Palestine";capitals[1].continent="Asia";capitals[1].Lat=31.76;capitals[1].Lon=35.21;
  capitals[2].n=154;capitals[2].city="Rome";capitals[2].country="Italy";capitals[2].continent="Europe";capitals[2].Lat=41.54;capitals[2].Lon=12.29;
  capitals[3].n=174;capitals[3].city="Tallin";capitals[3].country="Estonia";capitals[3].continent="Europe";capitals[3].Lat=59.22;capitals[3].Lon=24.48;
  capitals[4].n=92 ;capitals[4].city="Lisbon";capitals[4].country="Portugal";capitals[4].continent="Europe";capitals[4].Lat=38.42;capitals[4].Lon=-09.10;
  printf("      city\tlat\tlon\n");
  printf("------------------------------\n");
  for(i=0;i<5;i++){
      printf("%10s\t%5.2f\t%5.2f\n",capitals[i].city,capitals[i].Lat,capitals[i].Lon);
  }
  printf("------------------------------\n");
  return 0;
}

float ddeg2rad(float d){
  float rad;
  rad = d*PI/180.0;
  return rad;
}

float deg2rad(unsigned short deg, unsigned char min, unsigned char sec){
  float rad;
  rad = deg+min/60.0+sec/3600.0;
  return rad;
}
/*
 * #n,Capital City,Country,Continent,Latitude,Longitude
                          x_d    180       x_r    x_d   pi
 x_d/(x_r) = 180/pi ---> ---- = ---- --->     =     * ----
                          x_r    pi                    180
 */
