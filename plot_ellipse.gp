set terminal png enhanced size 1600,1200
set output 'ellipse_plots.png'
set multiplot layout 2,2

# Plot 1: Basic Ellipse Properties
set title 'Basic Ellipse (a=5, b=3)'
set xlabel 'x'
set ylabel 'y'
set size ratio -1
set xrange [-6:6]
set yrange [-4:4]
plot 'ellipse1.dat' with lines title 'Ellipse', 'foci.dat' index 0 with points pt 7 ps 2 title 'Foci', 'axes1.dat' index 0 with lines lt 2 title 'Major Axis', 'axes1.dat' index 1 with lines lt 3 title 'Minor Axis'

# Plot 2: Translated and Rotated Ellipse
set title 'Translated and Rotated Ellipse (30° rotation)'
set xrange [-3:7]
set yrange [-4:6]
plot 'ellipse2.dat' with lines title 'Ellipse', 'foci2.dat' index 0 with points pt 7 ps 2 title 'Foci', 'axes.dat' index 0 with lines lt 2 title 'Major Axis', 'axes.dat' index 1 with lines lt 3 title 'Minor Axis'

# Plot 3: Ellipse Arc
set title 'Ellipse Arc (30° to 150°)'
set xrange [-6:6]
set yrange [-4:4]
plot 'ellipse1.dat' with lines lt 1 title 'Full Ellipse', 'arc.dat' with lines lt 2 lw 3 title 'Arc'

# Plot 4: Circle as Special Case of Ellipse
set title 'Circle (a = b = 4)'
set xrange [-5:5]
set yrange [-5:5]
plot 'circle_ellipse.dat' with lines title 'Circle'

unset multiplot
