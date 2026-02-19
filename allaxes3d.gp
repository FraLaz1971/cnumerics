# Set terminal and output
set terminal pngcairo enhanced font "Arial,12" size 1600,800
set output "3d_rotation_complete.png"

# Set margins and layout
set multiplot layout 2,2 spacing 20

# Common settings
set xyplane at 0
set view 60, 30, 1.2, 1
set border 4095
set ticslevel 0
set hidden3d
set view equal xyz

# Define rotation angles (in degrees)
alpha = 30 * pi/180  # 30 degrees around X-axis
beta = 45 * pi/180   # 45 degrees around Y-axis
gamma = 60 * pi/180  # 60 degrees around Z-axis

# First plot: Original cube
set title "Original Cube" offset 0,-1
set xlabel "X Axis" offset 0,1
set ylabel "Y Axis" offset 0,1
set zlabel "Z Axis" rotate by 90 offset -1,0
splot 'cube.dat' using 1:2:3 with lines title "" lw 2

# Second plot: Rotated around X-axis
set title "Rotation around X-axis (α=30°)" offset 0,-1
splot 'cube.dat' using 1:($2*cos(alpha) - $3*sin(alpha)):($2*sin(alpha) + $3*cos(alpha)) with lines title "" lw 2

# Third plot: Rotated around Y-axis
set title "Rotation around Y-axis (β=45°)" offset 0,-1
splot 'cube.dat' using ($1*cos(beta) + $3*sin(beta)):2:(-$1*sin(beta) + $3*cos(beta)) with lines title "" lw 2

# Fourth plot: Rotated around Z-axis
set title "Rotation around Z-axis (γ=60°)" offset 0,-1
splot 'cube.dat' using ($1*cos(gamma) - $2*sin(gamma)):($1*sin(gamma) + $2*cos(gamma)):3 with lines title "" lw 2

unset multiplot

# Combined rotation plot
set terminal pngcairo enhanced font "Arial,12" size 1200,600
set output "3d_rotation_combined.png"
set multiplot layout 1,2 spacing 20

# Combined rotation (R_z * R_y * R_x)
set title "Original Cube" offset 0,-1
splot 'cubea.dat' using 1:2:3 with lines title "" lw 2

set title "Combined Rotation (R_z(60°)·R_y(45°)·R_x(30°))" offset 0,-1
splot 'cubea.dat' using (($1*cos(beta) + ($2*sin(alpha) + $3*cos(alpha))*sin(beta))*cos(gamma) - (($2*cos(alpha) - $3*sin(alpha))*sin(gamma))) : (($1*cos(beta) + ($2*sin(alpha) + $3*cos(alpha))*sin(beta))*sin(gamma) + (($2*cos(alpha) - $3*sin(alpha))*cos(gamma))) : (-$1*sin(beta) + ($2*sin(alpha) + $3*cos(alpha))*cos(beta)) with lines lw 2 notitle

unset multiplot
