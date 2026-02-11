#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "conversions.h"


double rad2ddeg(double rad){
  double d;
  d = rad*180.0/PI;
  return rad;
}


double ddeg2rad(double d){
  double rad;
  rad = d*PI/180.0;
  return rad;
}

double deg2decdeg(unsigned short deg, unsigned char min, unsigned char sec){
  double dd;
  dd = deg+min/60.0+sec/3600.0;
  return dd;
}

int decdeg2deg (double dd, struct Angle *iangle) {
  int ret=0; double tf;
  iangle->deg=(int)dd;
  tf = (dd-iangle->deg)*60.0;
  iangle->min=(int)tf;
  tf = tf - iangle->min;
  iangle->sec=round(tf*60.0);
  return ret;
}


/*
                          x_d    180       x_r    x_d   pi
 x_d/(x_r) = 180/pi ---> ---- = ---- --->     =     * ----
                          x_r    pi                    180

  min   100      s   min*60   min*3
  --- = --- --->   = ------ = ----- = min*0.6
   s     60           100       5
 */
