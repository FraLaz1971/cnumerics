# Set terminal and output
#set terminal wxt persist
set terminal pngcairo enhanced font "Arial,12" size 1200,600
set output "3d_rotation.png"

# Set margins to create space between plots
set multiplot layout 1,2 spacing 20

# Common settings
set xyplane at 0
set view 60, 25, 1.2, 1
set border 4095
set ticslevel 0
set hidden3d
set view equal xyz
# Define rotation function (45 degrees around z and x axes)
theta = 45 * pi/180  # 45 degrees in radians

# First plot: Original cube
set title "Original Cube" offset 0,-1
set xlabel "X Axis" offset 0,1
set ylabel "Y Axis" offset 0,1
set zlabel "Z Axis" rotate by 90 offset -1,0
splot 'cube.dat' using 1:2:3 with lines title "" lw 2

# Second plot: Rotated cube
set title "Cube Rotated 45° around Z and X axes" offset 0,-1
set xlabel "X Axis" offset 0,1
set ylabel "Y Axis" offset 0,1
set zlabel "Z Axis" rotate by 90 offset -1,0
splot 'cube.dat' using ($1*cos(theta) - $2*sin(theta)):($1*sin(theta) + $2*cos(theta)):($3) with lines title "" lw 2

unset multiplot

# Alternative view with different rotation
set terminal pngcairo enhanced font "Arial,12" size 1200,600
set output "3d_rotation_alternative.png"
set multiplot layout 1,2 spacing 20
set view 60, 45, 1.2, 1

# First plot: Original cube
set title "Original Cube" offset 0,-1
set xlabel "X Axis" offset 0,1
set ylabel "Y Axis" offset 0,1
set zlabel "Z Axis" rotate by 90 offset -1,0
splot 'cube.dat' using 1:2:3 with lines title "" lw 2

# Second plot: Rotated cube (different angle)
theta2 = 60 * pi/180  # 60 degrees in radians
set title "Cube Rotated 60° around Z Axis" offset 0,-1
set xlabel "X Axis" offset 0,1
set ylabel "Y Axis" offset 0,1
set zlabel "Z Axis" rotate by 90 offset -1,0
splot 'cube.dat' using ($1*cos(theta2) - $2*sin(theta2)):($1*sin(theta2) + $2*cos(theta2)):3 with lines title "" lw 2

unset multiplot
