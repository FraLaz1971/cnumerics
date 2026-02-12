set terminal wxt persist
set datafile separator ','
set size ratio -1
set xrange [0:6]
set yrange [4:10]
set xlabel 'x'
set ylabel 'y'
plot 'points001.csv' with points pt 7 title 'circle points'
