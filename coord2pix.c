#include <stdio.h>
#include <stdlib.h>
#include "conversions.h"
int main(int argc, char **argv){
    FILE *ifp;
    char *ifname, city[64][10], temp[64];
    int ret,i;
    double Lat[10], Lon[10];
    if(argc<2){
      fprintf(stderr, "usage:%s <points_file.csv>\n", argv[0]);
      return 1;
    }
    ifname = argv[1];
    ifp=fopen(ifname, "r");
    ret=fscanf(ifp, "%s",temp);
    fprintf(stderr,"%s\n",temp);
    i=0;
    while(fscanf(ifp, "%lf,%lf,%s",&Lat[i],&Lon[i],city[i])!=EOF){
      fprintf(stderr,"%d City=%s Lat=%lf Lon=%lf\n",i,city[i],Lat[i],Lon[i]);
      i++;
    }
    fclose(ifp);
    return 0;
}
