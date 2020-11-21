#ifndef  UTILITY_H
#define  UTILITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* global variables declaration */
char temp[10]="";int ret;char c1; float deg;
/* functions declaration */
void PAUSE();
float f2c(float t_f);
float c2f(float t_c);
void show_conversions(float ftemp, float ctemp);

/* Fahrhenheit to/from celsius degrees conversions 
 * T_C = (T_F - 32) x 5/9
 * T_F = 32 + 9/5 x T_C
 */

void show_conversions(float ftemp, float ctemp){
    printf("Temperature is %.2f deg. Fahrenheit\n", ftemp);
    printf("Temperature is %.2f deg. Celsius\n", ctemp );    
}

float f2c(float t_f){
    deg = (t_f - 32) * 5/9;
    return deg;
}

float c2f(float t_c){
    deg = 32 + 9/5 * t_c; 
    return deg;
}

/* functions implementation */
void PAUSE(){
	char c;
        puts("please, type enter\n");
        c = getchar();
}


#endif /* UTILITY_H*/
