set datafile separator ','
set terminal wxt persist
set xrange [0:360]
set yrange [-1:1]
set xlabel 'Angle (degrees)'
set ylabel 'function'
set arrow from 0,0 to 360,0 nohead lc rgb "blue" dt 2
plot 'piangles.out' using 3:4 with linespoints title 'sin(x)', \
'piangles.out' using 3:5 with linespoints title 'cos(x)', \
'piangles.out' using 3:4:1 with labels offset 0.5,0.5 notitle, \
'piangles.out' using 3:5:1 with labels offset 0.5,0.5 notitle

