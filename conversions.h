#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323844
struct Capital{
  unsigned char n;
  char *city;
  char *country;
  char *continent;
  double Lat;
  double Lon;
  double rLat;
  double rLon;
  double rx;
  double ry;
  double rz;
};

struct Angle{
  unsigned short deg;
  unsigned char min;
  unsigned char sec;
};

double rad2ddeg(double rad);

int decdeg2deg (double dd, struct Angle *iangle);

double deg2decdeg(unsigned short deg, unsigned char min, unsigned char sec);

double ddeg2rad(double d);

double deg2rad(unsigned short deg, unsigned char min, unsigned char sec);


/*
 *
                          x_d    180       x_r    x_d   pi
 x_d/(x_r) = 180/pi ---> ---- = ---- --->     =     * ----
                          x_r    pi                    180

  min   100      s   min*60   min*3
  --- = --- --->   = ------ = ----- = min*0.6
   s     60           100       5
 */
