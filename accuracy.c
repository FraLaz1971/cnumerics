#include <stdio.h>

int main(){
    char c;
    float x; int j;
    x=1.0; j=0;
    while (x+1 != x){
        j=j+1;
        x=x*2;
    }
    printf("float accuracy %d (bits) %f (digits)\n", j,j*0.30103);

    double xd; 
    xd=1.0; j=0;
    while (xd+1 != xd){
        j=j+1;
        xd=xd*2;
    }
    printf("double accuracy %d (bits) %f (digits)\n", j,j*0.30103);
    printf("Please press ENTER");
    c =  getchar();
    return(0);
}
