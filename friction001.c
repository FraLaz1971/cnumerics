#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gnuplot_i.h"

#define DIM 1024
#define NPOINTS 50 // Aumentato per sicurezza
#define DEBUG 0
typedef struct FricRow {
  char surfaces[128];
  double ustat;
  double udyn;
} FricRow;

int set_row(char *surf, double ust, double udy, FricRow *fr, int addr);
int show_table(FricRow *fr, int dim);
int plot_coeff(FricRow *fr, int dim, gnuplot_ctrl *handle,char *ifname);
void setup_gnuplot(gnuplot_ctrl *handle);
int sort_table(FricRow *fr, int dim);
int create_datafile(FricRow *fr, int dim,char *ofname);
int sort(FricRow *fr, int dim);

int main(int argc, char **argv){
  gnuplot_ctrl *handle;
  char *output_file = "frictional.png";
  char *sorted_file = "sorted_file.csv";
/*  char cmdstring[1024]; */
  FILE *ifp;
  int llen=DIM, fc, i, dim, ires;
  char line[DIM],*field;
  char *ifname,*res;
  FricRow fr[NPOINTS];
  /* take in input the coefficients table */
  fprintf(stderr,"argc = %d\n", argc);
  if (argc < 2){
    fprintf(stderr,"usage:%s <coeff.file>\n",argv[0]);
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
/*      printf("field n. %d %s ",fc,field); */
      if (fc==0){
              strcpy(fr[i].surfaces,field);
      } else if (fc==1){
              fr[i].ustat = atof(field);
      } else if (fc == 2) {
                fr[i].udyn = (strstr(field, "nan")) ? -1.0 : atof(field); // basic nan handling
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
  ires = show_table(fr, dim);
  fprintf(stderr,"*** Frictional force coefficients ***\n");
  handle = gnuplot_init();
  if (!handle) {
        fprintf(stderr, "Error: Gnuplot not found!\n");
        return 1;
    }
  fprintf(stderr,"Creating png file: %s\n", output_file);
  gnuplot_cmd(handle, "set terminal png size 1000,600");
  gnuplot_cmd(handle, "set output '%s'", output_file);
  setup_gnuplot(handle);
  ires = sort_table(fr, dim);
  ires = create_datafile(fr, dim, sorted_file);
  ires = plot_coeff(fr, dim, handle, sorted_file);
  gnuplot_close(handle);
  printf("Execution completed check %s\n", output_file);
  return 0;
}

int show_table(FricRow *fr, int dim){
  int i;
  fprintf(stderr,"_____________________________________________________\n");
  fprintf(stderr,"|                  Surfaces|u_s(static)|u_d(dynamic)|\n");
  fprintf(stderr,"|---------------------------------------------------|\n");
  for(i=0;i<dim;i++){
        fprintf(stderr,"|%26s|%11.2lf|%12.2lf|\n",fr[i].surfaces, fr[i].ustat, fr[i].udyn);
  fprintf(stderr,"-----------------------------------------------------\n");
  }
  return 0;
}

// Function to set up gnuplot parameters
void setup_gnuplot(gnuplot_ctrl *handle) {
    gnuplot_cmd(handle, "set datafile separator ','");
    gnuplot_cmd(handle, "set size ratio 0.5");
    gnuplot_cmd(handle, "set xrange [0:20]");
    gnuplot_cmd(handle, "set yrange [0:2]");
    /* Margine inferiore aumentato per far stare le scritte inclinate */
    gnuplot_cmd(handle, "set bmargin 10");
    /* Etichette asse X: ruotate, allineate a destra e font 10 */
    gnuplot_cmd(handle, "set xtics rotate by -45 font 'arial,10' offset -1,-0.5");
    gnuplot_cmd(handle, "set ylabel 'Coefficient value (μ)' font 'arial,12'");
    gnuplot_cmd(handle, "set grid ytics"); // Griglia orizzontale per leggere meglio i valori
    gnuplot_cmd(handle, "set xlabel 'Frictional Coefficient'");
    gnuplot_cmd(handle, "set title 'frictional coefficients' font 'arial,14'");
}
int plot_coeff(FricRow *fr, int dim, gnuplot_ctrl *handle, char *ifname){
  char cmdstring[2048];
  /* Setup for histograms */
    gnuplot_cmd(handle, "set style data histograms");
    gnuplot_cmd(handle, "set style histogram cluster gap 1");
    gnuplot_cmd(handle, "set style fill solid 0.6 border -1");

    gnuplot_cmd(handle, "set style data histograms");
/*    gnuplot_cmd(handle, "set style fill solid 1.0 border -1"); */
    gnuplot_cmd(handle, "set xtics rotate by -45 font 'arial,10'");

    // Comando corretto per usare le stringhe del CSV come etichette sull'asse X
    snprintf(cmdstring, 2047,
        "plot '%s' using 2:xtic(1) title 'Static (u_s)', '' using 3 title 'Dynamic (u_d)'",
             ifname);

/*  snprintf(cmdstring,1023,"plot '%s' using 2 with histogram title 'static frictional', '%s' using 3 with histogram title 'dynamic frictional','%s' using :2:1 with labels offset 0.5,0.5 font 'arial,8' notitle", ifname, ifname, ifname); */
  gnuplot_cmd(handle, cmdstring);
  fprintf(stderr, "plot file generated, look in the folder\n");
  return 0;
}

int sort_table(FricRow *fr, int dim){
  int flag = 0;
  FricRow tempfr[1];
  int i;
  do {
  flag = 0;
  for(i=0;i<dim-1;i++){
    if (fr[i].ustat > fr[i+1].ustat){
      if (DEBUG) fprintf(stderr,"%5.2f > %5.2f\n",fr[i].ustat,fr[i+1].ustat );
      set_row(fr[i].surfaces, fr[i].ustat, fr[i].udyn, tempfr, 0);
      set_row(fr[i+1].surfaces, fr[i+1].ustat, fr[i+1].udyn, fr, i);
      set_row(tempfr[0].surfaces, tempfr[0].ustat, tempfr[0].udyn, fr, i+1);
      flag = 1;
    } else {
        if (DEBUG) fprintf(stderr,"%5.2f <= %5.2f\n",fr[i].ustat,fr[i+1].ustat );
    }
  }
  } while (flag == 1);
  return 0;
}

int create_datafile(FricRow *fr, int dim, char *ofname){
  FILE *ofp;
  int i;
  ofp = fopen(ofname, "w");
  fprintf(ofp,"#Surfaces, u_s (static), u_d (dynamic)\n");
  for (i=0; i<dim; i++){
    fprintf(ofp,"%s, %5.2f, %5.2f\n",fr[i].surfaces,fr[i].ustat, fr[i].udyn);
  }
  fclose(ofp);
  return 0;
}

int set_row(char *surf, double ust, double udy, FricRow *fr, int addr){
  strcpy(fr[addr].surfaces, surf);
  fr[addr].ustat = ust;
  fr[addr].udyn = udy;
  return 0;
}
