/* c gnuplot animation */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "gnuplot_i.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Cube vertices (8 vertices) - centered at origin
double cube_vertices[8][3] = {
    {1, 1, 1},    // 0
    {1, -1, 1},   // 1
    {-1, -1, 1},  // 2
    {-1, 1, 1},   // 3
    {1, 1, -1},   // 4
    {1, -1, -1},  // 5
    {-1, -1, -1}, // 6
    {-1, 1, -1}   // 7
};

// Cube edges (12 edges connecting vertices)
int cube_edges[12][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},  // Top face
    {4, 5}, {5, 6}, {6, 7}, {7, 4},  // Bottom face
    {0, 4}, {1, 5}, {2, 6}, {3, 7}   // Vertical edges
};

// Function to rotate a point around X axis
void rotate_x(double *point, double angle) {
    double y = point[1];
    double z = point[2];
    point[1] = y * cos(angle) - z * sin(angle);
    point[2] = y * sin(angle) + z * cos(angle);
}

// Function to rotate a point around Y axis
void rotate_y(double *point, double angle) {
    double x = point[0];
    double z = point[2];
    point[0] = x * cos(angle) + z * sin(angle);
    point[2] = -x * sin(angle) + z * cos(angle);
}

// Function to rotate a point around Z axis
void rotate_z(double *point, double angle) {
    double x = point[0];
    double y = point[1];
    point[0] = x * cos(angle) - y * sin(angle);
    point[1] = x * sin(angle) + y * cos(angle);
}

// Function to plot cube edges - FIXED VERSION
void plot_cube(gnuplot_ctrl *handle, double vertices[8][3]) {
    char cmd[2048];
    char point_str[256];
    int edge_count = 0;

    // Start building the splot command
    strcpy(cmd, "splot ");

    // Add each edge to the command
    for (int i = 0; i < 12; i++) {
        int v1 = cube_edges[i][0];
        int v2 = cube_edges[i][1];

        // Format the two points for this edge
        if (edge_count > 0) strcat(cmd, ", ");

        sprintf(point_str, "'-' u 1:2:3 with lines lw 2 notitle");
        strcat(cmd, point_str);
        edge_count++;
    }

    // Send the plot command
    gnuplot_cmd(handle, "%s", cmd);

    // Send the data for each edge
    for (int i = 0; i < 12; i++) {
        int v1 = cube_edges[i][0];
        int v2 = cube_edges[i][1];

        // Send the two points for this edge
        gnuplot_cmd(handle, "%g %g %g", vertices[v1][0], vertices[v1][1], vertices[v1][2]);
        gnuplot_cmd(handle, "%g %g %g", vertices[v2][0], vertices[v2][1], vertices[v2][2]);
        gnuplot_cmd(handle, "e"); // End of data for this dataset
    }
}

// Function to set up gnuplot parameters
void setup_gnuplot(gnuplot_ctrl *handle) {
    gnuplot_cmd(handle, "set xyplane at 0");
    gnuplot_cmd(handle, "set view 60, 30, 1.5, 1");
    gnuplot_cmd(handle, "set border 4095");
    gnuplot_cmd(handle, "set ticslevel 0");
    gnuplot_cmd(handle, "set xrange [-2:2]");
    gnuplot_cmd(handle, "set yrange [-2:2]");
    gnuplot_cmd(handle, "set zrange [-2:2]");
    gnuplot_cmd(handle, "set xlabel 'X Axis'");
    gnuplot_cmd(handle, "set ylabel 'Y Axis'");
    gnuplot_cmd(handle, "set zlabel 'Z Axis'");
    gnuplot_cmd(handle, "set key off");
}

// Simple function for single rotation animation
void animate_rotation(gnuplot_ctrl *handle, int gif_mode,
                      void (*rotate_func)(double *, double),
                      const char *axis_name, int total_frames) {
    double current_vertices[8][3];

    for (int frame = 0; frame <= total_frames; frame++) {
        double angle = 2 * M_PI * frame / total_frames;

        // Copy and rotate vertices
        memcpy(current_vertices, cube_vertices, sizeof(cube_vertices));
        for (int j = 0; j < 8; j++) {
            rotate_func(current_vertices[j], angle);
        }

        gnuplot_resetplot(handle);
        gnuplot_cmd(handle, "set title 'Rotation around %s-axis (%d°)'",
                    axis_name, (int)(angle * 180 / M_PI));
        plot_cube(handle, current_vertices);

        if (!gif_mode) {
            usleep(100000); // 100ms delay
        }
    }
}

int main(int argc, char *argv[]) {
    gnuplot_ctrl *handle;
    int gif_mode = 0;
    char *output_file = "rotation_animation.gif";
    int frames_per_rotation = 36; // 10° steps

    // Check for GIF output option
    if (argc > 1) {
        if (strcmp(argv[1], "gif") == 0) {
            gif_mode = 1;
            if (argc > 2) {
                output_file = argv[2];
            }
        }
    }

    printf("*** 3D Rotation Animation ***\n");
    handle = gnuplot_init();

    // Set up GIF output if requested
    if (gif_mode) {
        printf("Creating GIF animation: %s\n", output_file);
        // Use simpler GIF setup
        gnuplot_cmd(handle, "set terminal gif animate optimize delay 5 size 800,600");
        gnuplot_cmd(handle, "set output '%s'", output_file);
    } else {
        // Use wxt terminal for interactive display
        gnuplot_setterm(handle, "wxt", 800, 600);
    }

    setup_gnuplot(handle);

    printf("Animating rotation around X-axis...\n");
    animate_rotation(handle, gif_mode, rotate_x, "X", frames_per_rotation);

    printf("Animating rotation around Y-axis...\n");
    animate_rotation(handle, gif_mode, rotate_y, "Y", frames_per_rotation);

    printf("Animating rotation around Z-axis...\n");
    animate_rotation(handle, gif_mode, rotate_z, "Z", frames_per_rotation);

    if (gif_mode) {
        gnuplot_cmd(handle, "set output"); // Close GIF file
        printf("Animation saved to %s\n", output_file);
    } else {
        printf("Press Enter to exit...\n");
        getchar(); // Wait for user input before closing
    }

    gnuplot_close(handle);
    printf("Animation complete!\n");
    return 0;
}
