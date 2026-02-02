#include <stdio.h>
#include <math.h>
int main()
{
    float s1,s2;
    s1 = 42164.0-(3134.061035*cos(0)*cos(0)+3713.916504*cos(0)*sin(0)+4117.144043*sin(0));
    s2 = pow(3134.061035,2)+pow(3713.916504,2)+pow(4117.144043,2);
    printf("S1=%9.6f\n", s1);
    printf("S2=%9.6f\n", s2);
    printf("S2-S1^2=%9.6f\n",s2-s1*s1);
    return 0;
}
