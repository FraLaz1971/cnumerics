#include <stdio.h>
int main(){
FILE *fptr;
fptr = fopen("filename.txt", "r");
float a, b, c;
fscanf(fptr, "%f,%f,%f", &a, &b, &c);
printf("a = %4.1f \n", a);
printf("b = %4.1f \n", b);
printf("c = %4.1f \n", c);
fclose(fptr); 
return 0;
}
