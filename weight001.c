#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gnuplot_i.h"

#define DIM 1024
#define NPOINTS 50
#define DEBUG 0

typedef struct SkyObject {
  char object[64];
  double resp_e;
  double force;
} SkyObject;

int set_row(char *surf, double ust, double udy, SkyObject *so, int addr);
int show_table(SkyObject *so, int dim);
int plot_weight(SkyObject *so, int dim, gnuplot_ctrl *handle,char *ifname);
void setup_gnuplot(gnuplot_ctrl *handle);
int plot_weight2(SkyObject *so, int dim, gnuplot_ctrl *handle,char *ifname);
void setup_gnuplot2(gnuplot_ctrl *handle);
int sort_table(SkyObject *so, int dim);
int create_datafile(SkyObject *so, int dim,char *ofname);
int sort(SkyObject *so, int dim);

int main(int argc, char **argv){
  gnuplot_ctrl *handle;
  char *output_file = "objects_weight_re.png";
  char *sorted_file = "sorted_objects.csv";
  FILE *ifp;
  int llen=DIM, fc, i, dim, ires;
  char line[DIM],*field;
  char *ifname,*res;
  SkyObject so[NPOINTS];
  /* take in input the objects table */
  if (argc < 2){
    fprintf(stderr,"usage:%s <obj.file>\n",argv[0]);
    return 1;
  }
  ifname=argv[1];
  ifp = fopen(ifname,"r");
  if (!ifp) {
        perror("Error opening file");
        return 1;
  }
  /* jump the intestation */
  res = fgets(line,llen,ifp);
  i=0;
  while(fgets(line,llen,ifp)){
    field=strtok(line,",");
    fc=0;
    while(field!=NULL){
      if (fc==0){
              strcpy(so[i].object,field);
      } else if (fc==1){
              so[i].resp_e = atof(field);
      } else if (fc == 2) {
                so[i].force = (strstr(field, "nan")) ? -1.0 : atof(field); // basic nan handling
      } else {
              fprintf(stderr, "unexpected field\n");
      }
      field=strtok(NULL,",");
      fc++;
   }
   fprintf(stderr,"\n");
   i++;
  }
  fclose(ifp);
  dim = i;
  ires = show_table(so, dim);
  fprintf(stderr,"*** Weight Force in the Solar System ***\n");
  handle = gnuplot_init();
  if (!handle) {
        fprintf(stderr, "Error: Gnuplot not found!\n");
        return 1;
    }
  fprintf(stderr,"Creating png file: %s\n", output_file);
  ires = sort_table(so, dim);
  ires = create_datafile(so, dim, sorted_file);
  gnuplot_cmd(handle, "set terminal png size 1000,600");
  gnuplot_cmd(handle, "set output '%s'", output_file);
  setup_gnuplot(handle);
  ires = plot_weight(so, dim, handle, sorted_file);
  gnuplot_cmd(handle, "reset");
  gnuplot_cmd(handle, "set terminal png size 1000,600");
  output_file = (char *)malloc(64*sizeof(char));
  strcpy(output_file,"objects_weight.png");
  fprintf(stderr,"Creating png file: %s\n", output_file);
  gnuplot_cmd(handle, "set output '%s'", output_file);
  setup_gnuplot2(handle);
  ires = plot_weight2(so, dim, handle, sorted_file);

  /*
  ires = sort_table(so, dim);
  ires = create_datafile(so, dim, sorted_file);
  ires = plot_weight(so, dim, handle, sorted_file);*/
  gnuplot_close(handle);
  printf("Execution completed check %s\n", output_file);
  free(output_file);
  return 0;
}
int show_table(SkyObject *so, int dim){
  int i;
  fprintf(stderr,"__________________________\n");
  fprintf(stderr,"|  object| resp2E|   n/m |\n");
  fprintf(stderr,"|------------------------|\n");
  for(i=0;i<dim;i++){
        fprintf(stderr,"|%8s|%7.4lf|%7.3lf|\n",so[i].object, so[i].resp_e, so[i].force);
  fprintf(stderr,"--------------------------\n");
  }
  return 0;
}

/* Function to set up gnuplot parameters */
void setup_gnuplot(gnuplot_ctrl *handle) {
    gnuplot_cmd(handle, "set datafile separator ','");
    gnuplot_cmd(handle, "set size ratio 0.5");
    gnuplot_cmd(handle, "set xrange [0:10]");
    gnuplot_cmd(handle, "set yrange [0:30]");
    /* Margine inferiore aumentato per far stare le scritte inclinate */
    gnuplot_cmd(handle, "set bmargin 10");
    /* Labels X axes: rotated, right allineated and font 10 */
    gnuplot_cmd(handle, "set xtics rotate by -45 font 'arial,10' offset -1,-0.5");
    gnuplot_cmd(handle, "set ylabel 'Weight Force' font 'arial,12'");
    gnuplot_cmd(handle, "set grid ytics"); // Griglia orizzontale per leggere meglio i valori
    gnuplot_cmd(handle, "set xlabel 'Solar Systen Object'");
    gnuplot_cmd(handle, "set title 'Gravity on Solar System Objects' font 'arial,14'");
}

/* Function to set up gnuplot parameters */
void setup_gnuplot2(gnuplot_ctrl *handle) {
    gnuplot_cmd(handle, "set datafile separator ','");
    gnuplot_cmd(handle, "set size ratio 0.5");
    gnuplot_cmd(handle, "set xrange [0:10]");
    gnuplot_cmd(handle, "set yrange [0:275]");
    /* Margine inferiore aumentato per far stare le scritte inclinate */
    gnuplot_cmd(handle, "set bmargin 10");
    /* Labels X axes: rotated, right allineated and font 10 */
    gnuplot_cmd(handle, "set xtics rotate by -45 font 'arial,10' offset -1,-0.5");
    gnuplot_cmd(handle, "set ylabel 'Weight Force (N/m)' font 'arial,12'");
    gnuplot_cmd(handle, "set grid ytics"); // Griglia orizzontale per leggere meglio i valori
    gnuplot_cmd(handle, "set xlabel 'Solar Systen Object'");
    gnuplot_cmd(handle, "set title 'Gravity on Solar System Objects' font 'arial,14'");
}


int plot_weight(SkyObject *so, int dim, gnuplot_ctrl *handle, char *ifname){
  char cmdstring[2048];
  /* Setup for histograms */
    gnuplot_cmd(handle, "set style data histograms");
    gnuplot_cmd(handle, "set style histogram cluster gap 1");
    gnuplot_cmd(handle, "set style fill solid 0.6 border -1");
    gnuplot_cmd(handle, "set xtics rotate by -45 font 'arial,10'");
    /* Comando corretto per usare le stringhe del CSV come etichette sull'asse X
    snprintf(cmdstring, 2047,
        "plot '%s' using 2:xtic(1) title 'Respect to Earth', '' using 3 title 'N/m'",
             ifname);*/
    snprintf(cmdstring, 2047,"plot '%s' using 2:xtic(1) title 'Respect to Earth'",ifname);
    gnuplot_cmd(handle, cmdstring);
    fprintf(stderr, "plot file generated, look in the folder\n");
  return 0;
}

int plot_weight2(SkyObject *so, int dim, gnuplot_ctrl *handle, char *ifname){
  char cmdstring[2048];
  /* Setup for histograms */
    gnuplot_cmd(handle, "set style data histograms");
    gnuplot_cmd(handle, "set style histogram cluster gap 1");
    gnuplot_cmd(handle, "set style fill solid 0.6 border -1");
    gnuplot_cmd(handle, "set xtics rotate by -45 font 'arial,10'");
    /* Comando corretto per usare le stringhe del CSV come etichette sull'asse X
    snprintf(cmdstring, 2047,
        "plot '%s' using 2:xtic(1) title 'Respect to Earth', '' using 3 title 'N/m'",
             ifname);*/
    snprintf(cmdstring, 2047,"plot '%s' using 3:xtic(1) lc 3 title 'N/m                   '",ifname);
    gnuplot_cmd(handle, cmdstring);
    fprintf(stderr, "plot file generated, look in the folder\n");
  return 0;
}

int set_row(char *surf, double re, double fo, SkyObject *so, int addr){
  strcpy(so[addr].object, surf);
  so[addr].resp_e = re;
  so[addr].force = fo;
  return 0;
}

int sort_table(SkyObject *so, int dim){
  int flag = 0;
  SkyObject tempso[1];
  int i;
  do {
  flag = 0;
  for(i=0;i<dim-1;i++){
    if (so[i].resp_e > so[i+1].resp_e){
      if (DEBUG) fprintf(stderr,"%5.2f > %5.2f\n",so[i].resp_e,so[i+1].resp_e );
      set_row(so[i].object, so[i].resp_e, so[i].force, tempso, 0);
      set_row(so[i+1].object, so[i+1].resp_e, so[i+1].force, so, i);
      set_row(tempso[0].object, tempso[0].resp_e, tempso[0].force, so, i+1);
      flag = 1;
    } else {
        if (DEBUG) fprintf(stderr,"%5.2f <= %5.2f\n",so[i].resp_e,so[i+1].resp_e );
    }
  }
  } while (flag == 1);
  return 0;
}

int create_datafile(SkyObject *so, int dim, char *ofname){
  FILE *ofp;
  int i;
  ofp = fopen(ofname, "w");
  fprintf(ofp,"#Object, Resp2Earth, N/m\n");
  for (i=0; i<dim; i++){
    fprintf(ofp,"%8s, %7.4lf, %7.3lf\n",so[i].object,so[i].resp_e, so[i].force);
  }
  fclose(ofp);
  return 0;
}
