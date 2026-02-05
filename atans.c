#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double y = -1.0;
    double x = -1.0;

    // atan only sees the result of the division (-1 / -1 = 1.0)
    double result_atan = atan(y / x);

    // atan2 sees both signs and knows this is the 3rd quadrant
    double result_atan2 = atan2(y, x);

    printf("Point (-1, -1):\n");
    printf("atan(y/x): %7.2f degrees (Wrong quadrant)\n", result_atan * 180 / PI);
    printf("atan2(y,x): %7.2f degrees (Correct quadrant)\n", result_atan2 * 180 / PI);

    return 0;
}

