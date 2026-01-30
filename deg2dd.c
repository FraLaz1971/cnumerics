#include <stdio.h>
#include <stdlib.h>
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
  float dd;
  struct Angle angle, angle2;
  if (argc<4){
    fprintf(stderr,"usage:%s <deg> <min> <sec>\n", argv[0]);
    return 1;
  }
  angle.deg=atof(argv[1]);angle.min=atof(argv[2]);angle.sec=atof(argv[3]);
  printf("The angle is %d degrees %d minutes and %d seconds\n",angle.deg,angle.min,angle.sec);
  dd = deg2decdeg(angle.deg,angle.min,angle.sec);
  printf("The angle in decimal degrees is %9.6f\n",dd);
  mret=decdeg2deg (dd, &angle2);
  printf("back in degrees %d degrees %d minutes and %d seconds\n",angle2.deg,angle2.min,angle2.sec);
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
