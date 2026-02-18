set terminal wxt persist
#set term pngcairo size 800,400
#set output "2d_rotation.png"
set multiplot layout 1,2

# Original square
set title "Before Rotation"
set xrange [-2:2]
set yrange [-2:2]
set xlabel 'X Axes'
set ylabel 'Y Axes'
set size ratio 1
plot '-' with lines title "Square"
 1  1
 1 -1
-1 -1
-1  1
 1  1
e

# Rotated square (45 degrees)
set title "After Rotation (45°)"
theta = pi/4
s = sin(theta)
c = cos(theta)
plot '-' using (c*$1 - s*$2):(s*$1 + c*$2) with lines title "Rotated Square"
 1  1
 1 -1
-1 -1
-1  1
 1  1
e

unset multiplot
