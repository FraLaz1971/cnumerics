#set terminal wxt persist
set term pngcairo size 800,400
set output '2d_rotated_triangle.png'
set multiplot layout 1,2
# Original triangle
set title 'Before Rotation'
set xrange [-2:2]
set yrange [-2:2]
set xlabel 'X Axes'
set ylabel 'Y Axes'
set size ratio 1
plot 'triangle.dat' with lines title 'Triangle', \
'triangle.dat' with labels notitle offset 0.6,0.5 
set title 'After Rotation (60.0°)'
theta = 1.047198
s = sin(theta)
c = cos(theta)
plot 'triangle.dat' using (c*$1 - s*$2):(s*$1 + c*$2) with lines title 'Rotated Triangle', \
'triangle.dat'using (c*$1 - s*$2):(s*$1 + c*$2):3 with labels offset 0.6,0.5 notitle
