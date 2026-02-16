#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point center;
    double a;  // semi-major axis
    double b;  // semi-minor axis
    double rotation;  // rotation angle in radians
} Ellipse;

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

// Calculate ellipse area
double ellipse_area(double a, double b) {
    return PI * a * b;
}

// Calculate ellipse perimeter (approximation using Ramanujan's formula)
double ellipse_perimeter(double a, double b) {
    double h = pow((a - b), 2) / pow((a + b), 2);
    return PI * (a + b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
}

// Calculate eccentricity
double eccentricity(double a, double b) {
    return sqrt(1 - (b * b) / (a * a));
}

// Calculate focal distance
double focal_distance(double a, double b) {
    return 2 * sqrt(a * a - b * b);
}

// Get focal points
void get_foci(Ellipse ellipse, Point *f1, Point *f2) {
    double c = sqrt(ellipse.a * ellipse.a - ellipse.b * ellipse.b);
    f1->x = ellipse.center.x - c * cos(ellipse.rotation);
    f1->y = ellipse.center.y - c * sin(ellipse.rotation);
    f2->x = ellipse.center.x + c * cos(ellipse.rotation);
    f2->y = ellipse.center.y + c * sin(ellipse.rotation);
}

// Generate points for plotting ellipse
void generate_ellipse_points(Ellipse ellipse, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i <= 360; i++) {
        double t = to_radians(i);
        // Parametric equations for ellipse
        double x = ellipse.a * cos(t);
        double y = ellipse.b * sin(t);

        // Apply rotation
        double x_rot = x * cos(ellipse.rotation) - y * sin(ellipse.rotation);
        double y_rot = x * sin(ellipse.rotation) + y * cos(ellipse.rotation);

        // Apply translation
        x_rot += ellipse.center.x;
        y_rot += ellipse.center.y;

        fprintf(fp, "%f %f\n", x_rot, y_rot);
    }

    fclose(fp);
}

// Generate points for arc visualization
void generate_ellipse_arc_points(Ellipse ellipse, double start_angle, double end_angle, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    double start_rad = to_radians(start_angle);
    double end_rad = to_radians(end_angle);

    fprintf(fp, "%f %f\n", ellipse.center.x, ellipse.center.y); // Center point

    for (double t = start_rad; t <= end_rad; t += 0.01) {
        double x = ellipse.a * cos(t);
        double y = ellipse.b * sin(t);

        // Apply rotation
        double x_rot = x * cos(ellipse.rotation) - y * sin(ellipse.rotation);
        double y_rot = x * sin(ellipse.rotation) + y * cos(ellipse.rotation);

        // Apply translation
        x_rot += ellipse.center.x;
        y_rot += ellipse.center.y;

        fprintf(fp, "%f %f\n", x_rot, y_rot);
    }
        fprintf(fp, "%f %f\n", 0.0, 0.0);

    fclose(fp);
}

// Generate axes lines
void generate_axes(Ellipse ellipse, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error opening file\n");
        return;
    }

    // Major axis endpoints
    Point maj1, maj2;
    maj1.x = ellipse.center.x - ellipse.a * cos(ellipse.rotation);
    maj1.y = ellipse.center.y - ellipse.a * sin(ellipse.rotation);
    maj2.x = ellipse.center.x + ellipse.a * cos(ellipse.rotation);
    maj2.y = ellipse.center.y + ellipse.a * sin(ellipse.rotation);

    // Minor axis endpoints (perpendicular to major axis)
    Point min1, min2;
    min1.x = ellipse.center.x - ellipse.b * cos(ellipse.rotation + PI/2);
    min1.y = ellipse.center.y - ellipse.b * sin(ellipse.rotation + PI/2);
    min2.x = ellipse.center.x + ellipse.b * cos(ellipse.rotation + PI/2);
    min2.y = ellipse.center.y + ellipse.b * sin(ellipse.rotation + PI/2);

    fprintf(fp, "%f %f\n%f %f\n\n", maj1.x, maj1.y, maj2.x, maj2.y);
    fprintf(fp, "%f %f\n%f %f\n", min1.x, min1.y, min2.x, min2.y);

    fclose(fp);
}

int main() {
    printf("=== ELLIPSE MATHEMATICS LESSON ===\n\n");

    // Lesson content
    printf("1. DEFINITION:\n");
    printf("   An ellipse is the set of all points where the sum of distances\n");
    printf("   to two fixed points (foci) is constant.\n\n");

    printf("2. STANDARD EQUATION (center at origin, aligned with axes):\n");
    printf("   x^2/a^2 + y^2/b^2 = 1\n");
    printf("   where a = semi-major axis, b = semi-minor axis (a >= b > 0)\n\n");

    printf("3. PARAMETRIC EQUATIONS:\n");
    printf("   x = a·cos(t), y = b·sin(t) where t in [0, 2pi]\n\n");

    printf("4. ECCENTRICITY:\n");
    printf("   e = sqrt(1 - b^2/a^2) where 0 <= e < 1\n");
    printf("   e = 0: circle, e → 1: highly elongated ellipse\n\n");

    printf("5. FOCI:\n");
    printf("   Located at (±c, 0) where c^2 = a^2 - b^2\n");
    printf("   Distance between foci = 2c\n\n");

    printf("6. AREA: A = pi*a*b\n\n");

    printf("7. PERIMETER (approximation):\n");
    printf("   P ~= pi[3(a+b) - sqrt((3a+b)(a+3b))] (Ramanujan's formula)\n\n");

    printf("8. TRANSLATION:\n");
    printf("   Center at (h,k): (x-h)^2/a^2 + (y-k)^2/b^2 = 1\n\n");

    printf("9. ROTATION:\n");
    printf("   Rotate coordinate system by angle theta using rotation matrix\n\n");

    // Example 1: Basic ellipse properties
    Ellipse ellipse1 = {{0, 0}, 5, 3, 0};

    printf("=== Example 1: Basic Ellipse Properties ===\n");
    printf("Center: (%.2f, %.2f)\n", ellipse1.center.x, ellipse1.center.y);
    printf("Semi-major axis (a): %.2f\n", ellipse1.a);
    printf("Semi-minor axis (b): %.2f\n", ellipse1.b);
    printf("Major axis length: %.2f\n", 2 * ellipse1.a);
    printf("Minor axis length: %.2f\n", 2 * ellipse1.b);
    printf("Area: %.2f\n", ellipse_area(ellipse1.a, ellipse1.b));
    printf("Perimeter (approx): %.2f\n", ellipse_perimeter(ellipse1.a, ellipse1.b));
    printf("Eccentricity: %.4f\n", eccentricity(ellipse1.a, ellipse1.b));

    Point f1, f2;
    get_foci(ellipse1, &f1, &f2);
    printf("Foci: (%.2f, %.2f) and (%.2f, %.2f)\n", f1.x, f1.y, f2.x, f2.y);
    printf("Focal distance: %.2f\n", distance(f1, f2));

    // Example 2: Translated and rotated ellipse
    Ellipse ellipse2 = {{2, 1}, 4, 2, to_radians(30)};

    printf("\n=== Example 2: Translated and Rotated Ellipse ===\n");
    printf("Center: (%.2f, %.2f)\n", ellipse2.center.x, ellipse2.center.y);
    printf("Semi-axes: a=%.2f, b=%.2f\n", ellipse2.a, ellipse2.b);
    printf("Rotation: %.2f°\n", to_degrees(ellipse2.rotation));
    printf("Area: %.2f\n", ellipse_area(ellipse2.a, ellipse2.b));
    printf("Eccentricity: %.4f\n", eccentricity(ellipse2.a, ellipse2.b));

    get_foci(ellipse2, &f1, &f2);
    printf("Foci: (%.2f, %.2f) and (%.2f, %.2f)\n", f1.x, f1.y, f2.x, f2.y);

    // Example 3: Circle as special case of ellipse (a = b)
    Ellipse circle = {{0, 0}, 4, 4, 0};

    printf("\n=== Example 3: Circle (Special Case of Ellipse) ===\n");
    printf("When a = b = %.2f, we get a circle\n", circle.a);
    printf("Eccentricity: %.4f (0 = perfect circle)\n", eccentricity(circle.a, circle.b));
    printf("Area: %.2f (pi*r^2)\n", ellipse_area(circle.a, circle.b));
    printf("Perimeter: %.2f (2pi*r)\n", ellipse_perimeter(circle.a, circle.b));

    // Generate data files for gnuplot
    generate_ellipse_points(ellipse1, "ellipse1.dat");
    generate_ellipse_points(ellipse2, "ellipse2.dat");
    generate_ellipse_points(circle, "circle_ellipse.dat");
    generate_axes(ellipse1, "axes1.dat");
    generate_axes(ellipse2, "axes.dat");
    generate_ellipse_arc_points(ellipse1, 30, 150, "arc.dat");

    // Generate foci points
    FILE *fp = fopen("foci.dat", "w");
    get_foci(ellipse1, &f1, &f2);
    fprintf(fp, "%f %f\n", f1.x, f1.y);
    fprintf(fp, "%f %f\n", f2.x, f2.y);
    fclose(fp);
    FILE *fp2 = fopen("foci2.dat", "w");
    get_foci(ellipse2, &f1, &f2);
    fprintf(fp2, "%f %f\n", f1.x, f1.y);
    fprintf(fp2, "%f %f\n", f2.x, f2.y);
    fclose(fp2);

    // Create gnuplot script
    FILE *gnuplot = fopen("plot_ellipse.gp", "w");
    fprintf(gnuplot, "set terminal png enhanced size 1600,1200\n");
    fprintf(gnuplot, "set output 'ellipse_plots.png'\n");
    fprintf(gnuplot, "set multiplot layout 2,2\n\n");

    fprintf(gnuplot, "# Plot 1: Basic Ellipse Properties\n");
    fprintf(gnuplot, "set title 'Basic Ellipse (a=5, b=3)'\n");
    fprintf(gnuplot, "set xlabel 'x'\n");
    fprintf(gnuplot, "set ylabel 'y'\n");
    fprintf(gnuplot, "set size ratio -1\n");
    fprintf(gnuplot, "set xrange [-6:6]\n");
    fprintf(gnuplot, "set yrange [-4:4]\n");
    fprintf(gnuplot, "plot 'ellipse1.dat' with lines title 'Ellipse', ");
    fprintf(gnuplot, "'foci.dat' index 0 with points pt 7 ps 2 title 'Foci', ");
    fprintf(gnuplot, "'axes1.dat' index 0 with lines lt 2 title 'Major Axis', ");
    fprintf(gnuplot, "'axes1.dat' index 1 with lines lt 3 title 'Minor Axis'\n\n");

    fprintf(gnuplot, "# Plot 2: Translated and Rotated Ellipse\n");
    fprintf(gnuplot, "set title 'Translated and Rotated Ellipse (30° rotation)'\n");
    fprintf(gnuplot, "set xrange [-3:7]\n");
    fprintf(gnuplot, "set yrange [-4:6]\n");
    fprintf(gnuplot, "plot 'ellipse2.dat' with lines title 'Ellipse', ");
    fprintf(gnuplot, "'foci2.dat' index 0 with points pt 7 ps 2 title 'Foci', ");
    fprintf(gnuplot, "'axes.dat' index 0 with lines lt 2 title 'Major Axis', ");
    fprintf(gnuplot, "'axes.dat' index 1 with lines lt 3 title 'Minor Axis'\n\n");

    fprintf(gnuplot, "# Plot 3: Ellipse Arc\n");
    fprintf(gnuplot, "set title 'Ellipse Arc (30° to 150°)'\n");
    fprintf(gnuplot, "set xrange [-6:6]\n");
    fprintf(gnuplot, "set yrange [-4:4]\n");
    fprintf(gnuplot, "plot 'ellipse1.dat' with lines lt 1 title 'Full Ellipse', ");
    fprintf(gnuplot, "'arc.dat' with lines lt 2 lw 3 title 'Arc'\n\n");

    fprintf(gnuplot, "# Plot 4: Circle as Special Case of Ellipse\n");
    fprintf(gnuplot, "set title 'Circle (a = b = 4)'\n");
    fprintf(gnuplot, "set xrange [-5:5]\n");
    fprintf(gnuplot, "set yrange [-5:5]\n");
    fprintf(gnuplot, "plot 'circle_ellipse.dat' with lines title 'Circle'\n\n");

    fprintf(gnuplot, "unset multiplot\n");
    fclose(gnuplot);

    printf("\ngnuplot script created. Run 'gnuplot plot_ellipse.gp' to generate plots.\n");
    printf("\nKey concepts demonstrated:\n");
    printf("- Standard and parametric ellipse equations\n");
    printf("- Foci and eccentricity calculation\n");
    printf("- Area and perimeter formulas\n");
    printf("- Translation and rotation transformations\n");
    printf("- Relationship between ellipses and circles\n");

    return 0;
}
