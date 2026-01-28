#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* this program prints points of a sphere of given center
 (x_0, y_0, z_0) and radius R
 x_0, y_0, z_0, R are took in input as program parameters argv[1]-argv[4]
 argv[5] is the filename of a csv file containing a list of points.
 The program should check for each point if it is on the surface of the sphere,
 included in the sphere or outside the sphere.
 */
struct Point3D{
    float x;
    float y;
    float z;
};

unsigned char is_inside(struct Point3D *p, struct Point3D *c, float r);

int main(int argc, char **argv){
    struct Point3D C, P; int i; unsigned char mret; float R;
    char *infile, temp[64]; float x,y,z;int ret2;
    char temp1[8], temp2[8], temp3[8];
    char *o1 = "outside.csv";char *o2 = "inside.csv";char *o3 = "surface.csv";
    FILE *ifp, *ofp1, *ofp2, *ofp3;
    if (argc<6){
        fprintf(stderr,"usage:%s\n <x_0> <y_0> <z_0> <R> <points.csv>\n",argv[0]);
        return 1;
    }
    C.x=atof(argv[1]);C.y=atof(argv[2]);C.z=atof(argv[3]);
    R=atof(argv[4]);
    infile = argv[5];
    /* open input file */
    ifp = fopen(infile, "r");
    ofp1 = fopen(o1, "w");
    ofp2 = fopen(o2, "w");
    ofp3 = fopen(o3, "w");
    ret2 = fscanf(ifp, "%s\n",temp);
    for(i=0;i<8;i++){
      ret2 = fscanf(ifp, "%f,%f,%f",&P.x,&P.y,&P.z);
      fprintf(stderr,"read: %4.1f %4.1f %4.1f\n",P.x,P.y,P.z);
      mret = is_inside(&P, &C, R);
      if (mret==1){
        fprintf(stderr,"point: %f,%f,%f is inside\n",P.x,P.y,P.z);
      } else if (mret==0){
        fprintf(stderr,"point: %f,%f,%f is on the surface\n",P.x,P.y,P.z);
      } else {
        fprintf(stderr,"point: %f,%f,%f is outside\n",P.x,P.y,P.z);
      }
    }
    fclose(ifp);fclose(ofp1);fclose(ofp2);fclose(ofp3);
    return 0;
}

unsigned char is_inside(struct Point3D *p, struct Point3D *c, float r){
  unsigned char ret; float v, eps=0.000001;
  v = pow((p->x - c->x),2) + pow((p->y - c->y),2) +  pow((p->z - c->z),2);
  if (abs(v-r*r)<eps){
    ret = 0;
  } else if ((v-r*r)>0){
    ret = -1;
  } else {
    ret = 1;
  }
 /* (x − x0 )^2 + (y − y0 )^2 + (z − z^0)2 ≤ R2 */
 return ret;
}
