set terminal wxt persist
#set terminal qt persist
set datafile separator ','
#set terminal pngcairo
#set output "sphere_001.png"
set parametric
set isosamples 50,50
set hidden
set view equal xyz
set size ratio -1
R = 3.0   # radius of sphere
cx = 1.0
cy = 2.0
cz = -3.0
O = 10.0
set urange [-pi/2:pi/2]
set vrange [0:2*pi]
set xrange [cx-R-O : cx+R+O]
set yrange [cy-R-O : cy+R+O]
set zrange [cz-R-O : cz+R+O]
splot cx + R*cos(u)*cos(v), cy + R*cos(u)*sin(v), cz + R*sin(u) w l lc rgb "yellow" notitle, \
'surface4.csv' using 2:3:4 w p pt 7 ps 1 lc rgb 'red' title "Surface Points", \
'surface4.csv' using 2:3:4:1 with labels offset 1,1 notitle, \
'outside.csv' w p pt 7 ps 1 lc rgb 'blue' title "Outside Points", \
'inside.csv' w p pt 7 ps 1 lc rgb 'green' title "Inside Points",
