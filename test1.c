#include <stdio.h>
int main(){
FILE *fptr;
fptr = fopen("filename.txt", "r");
int a, b, c;
fscanf(fptr, "%i + %i = %i", &a, &b, &c);
printf("a = %d \n", a);
printf("b = %d \n", b);
printf("c = %d \n", c);
fclose(fptr); 
return 0;
}
