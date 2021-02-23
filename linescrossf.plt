#!/usr/bin/env gnuplot
set terminal png
set output "crossinglines.png"
set grid
set xlabel "x axis"
set ylabel "y axis"
set title "crossing of 2 lines"
set size square
set xtics 1
set ytics 1
set size ratio -1
set yrange[-5:5]
set xrange[-5:5]
plot 2*x-4, 3-x*1/3
