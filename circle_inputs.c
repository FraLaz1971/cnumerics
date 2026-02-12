#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

// Convert degrees to radians
double to_radians(double degrees) {
    return degrees * PI / 180.0;
}

// Convert radians to degrees
double to_degrees(double radians) {
    return radians * 180.0 / PI;
}

// Calculate distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Calculate circle circumference
double circumference(double radius) {
    return 2 * PI * radius;
}

// Calculate circle area
double circle_area(double radius) {
    return PI * radius * radius;
}

// Calculate arc length
double arc_length(double radius, double angle_rad) {
    return radius * angle_rad;
}

// Calculate sector area
double sector_area(double radius, double angle_rad) {
    return 0.5 * radius * radius * angle_rad;
}

// Find circle through 3 points
Circle circle_through_three_points(Point p1, Point p2, Point p3) {
    Circle circle;
    double a = p2.x - p1.x;
    double b = p2.y - p1.y;
    double c = p3.x - p1.x;
    double d = p3.y - p1.y;

    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));

    if (fabs(g) < 1e-10) {
        printf("Points are collinear, no circle exists\n");
        circle.center.x = 0;
        circle.center.y = 0;
        circle.radius = 0;
        return circle;
    }

    circle.center.x = (d * e - b * f) / g;
    circle.center.y = (a * f - c * e) / g;
    circle.radius = distance(circle.center, p1);

    return circle;
}

// Generate points for plotting circle
void generate_circle_points(Circle circle, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i <= 360; i++) {
        double angle = to_radians(i);
        double x = circle.center.x + circle.radius * cos(angle);
        double y = circle.center.y + circle.radius * sin(angle);
        fprintf(fp, "%f %f\n", x, y);
    }

    fclose(fp);
}

// Generate points for arc visualization
void generate_arc_points(Circle circle, double start_angle, double end_angle, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    double start_rad = to_radians(start_angle);
    double end_rad = to_radians(end_angle);

    fprintf(fp, "%f %f\n", circle.center.x, circle.center.y); // Center point

    for (double angle = start_rad; angle <= end_rad; angle += 0.01) {
        double x = circle.center.x + circle.radius * cos(angle);
        double y = circle.center.y + circle.radius * sin(angle);
        fprintf(fp, "%f %f\n", x, y);
    }

    fclose(fp);
}

int main() {
    // Example 1: Basic circle properties
    Circle circle1 = {{2, 3}, 5};

    printf("=== Circle Properties Example ===\n");
    printf("Center: (%.2f, %.2f)\n", circle1.center.x, circle1.center.y);
    printf("Radius: %.2f\n", circle1.radius);
    printf("Diameter: %.2f\n", 2 * circle1.radius);
    printf("Circumference: %.2f\n", circumference(circle1.radius));
    printf("Area: %.2f\n", circle_area(circle1.radius));

    // Arc and sector examples
    double angle_deg = 60;
    double angle_rad = to_radians(angle_deg);

    printf("\n=== Arc and Sector Example ===\n");
    printf("Angle: %.2f° = %.2f radians\n", angle_deg, angle_rad);
    printf("Arc length: %.2f\n", arc_length(circle1.radius, angle_rad));
    printf("Sector area: %.2f\n", sector_area(circle1.radius, angle_rad));

    // Example 2: Circle through 3 points
    Point p1 = {0, 0}, p2 = {4, 0}, p3 = {0, 3};
    Circle circle2 = circle_through_three_points(p1, p2, p3);

    printf("\n=== Circle Through 3 Points ===\n");
    printf("Points: (%.2f,%.2f), (%.2f,%.2f), (%.2f,%.2f)\n",
           p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    printf("Circle center: (%.2f, %.2f)\n", circle2.center.x, circle2.center.y);
    printf("Circle radius: %.2f\n", circle2.radius);

    // Generate data files for GNUplot
    generate_circle_points(circle1, "circle.dat");
    generate_arc_points(circle1, 30, 120, "arc.dat");

    // Generate points for circle through 3 points
    generate_circle_points(circle2, "circle_3points.dat");

    FILE *fp = fopen("points.dat", "w");
    fprintf(fp, "%f %f\n", p1.x, p1.y);
    fprintf(fp, "%f %f\n", p2.x, p2.y);
    fprintf(fp, "%f %f\n", p3.x, p3.y);
    fclose(fp);

    // Create GNUplot script
    FILE *gnuplot = fopen("plot_circle.gp", "w");
    fprintf(gnuplot, "set terminal png enhanced size 1200,400\n");
    fprintf(gnuplot, "set output 'circle_plots.png'\n");
    fprintf(gnuplot, "set multiplot layout 1,3\n\n");

    fprintf(gnuplot, "# Plot 1: Basic Circle\n");
    fprintf(gnuplot, "set title 'Basic Circle Properties'\n");
    fprintf(gnuplot, "set xlabel 'x'\n");
    fprintf(gnuplot, "set ylabel 'y'\n");
    fprintf(gnuplot, "set size ratio -1\n");
    fprintf(gnuplot, "plot 'circle.dat' with lines title 'Circle', ");
    fprintf(gnuplot, "'circle.dat' every 90 with points pt 7 title 'Points every 90°'\n\n");

    fprintf(gnuplot, "# Plot 2: Arc and Sector\n");
    fprintf(gnuplot, "set title 'Arc and Sector (30° to 120°)'\n");
    fprintf(gnuplot, "plot 'arc.dat' with lines title 'Arc', ");
    fprintf(gnuplot, "'arc.dat' using 1:2:(2-$1):(3-$2) with vectors nohead lt 2 title 'Radius'\n\n");

    fprintf(gnuplot, "# Plot 3: Circle Through 3 Points\n");
    fprintf(gnuplot, "set title 'Circle Through 3 Points'\n");
    fprintf(gnuplot, "plot 'circle_3points.dat' with lines title 'Circle', ");
    fprintf(gnuplot, "'points.dat' with points pt 7 ps 2 title 'Given Points', ");
    fprintf(gnuplot, "'circle_3points.dat' every 120 with points pt 2 title 'Circle Points'\n\n");

    fprintf(gnuplot, "unset multiplot\n");
    fclose(gnuplot);

    printf("\nGNUplot script created. Run 'gnuplot plot_circle.gnu' to generate plots.\n");

    return 0;
}
