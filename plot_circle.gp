set terminal png enhanced size 1200,400
set output 'circle_plots.png'
#set terminal qt persist
set multiplot layout 1,3

# Plot 1: Basic Circle
set title 'Basic Circle Properties'
set xlabel 'x'
set ylabel 'y'
set size ratio -1
plot 'circle.dat' with lines title 'Circle', 'circle.dat' every 90 with points pt 7 title 'Points every 90°'

# Plot 2: Arc and Sector
set title 'Arc and Sector (30° to 120°)'
plot 'arc.dat' with lines title 'Arc', \
'arc.dat' using 1:2:(2-$1):(3-$2) with vectors nohead lt 2 title 'Radius'
#plot 'arc.dat' with lines title 'Arc', 'arc.dat' using 1:2:($1-2):($2-3) with vectors nohead lt 2 title 'Radius'

# Plot 3: Circle Through 3 Points
set title 'Circle Through 3 Points'
plot 'circle_3points.dat' with lines title 'Circle', 'points.dat' with points pt 7 ps 2 title 'Given Points', 'circle_3points.dat' every 120 with points pt 2 title 'Circle Points'

unset multiplot
