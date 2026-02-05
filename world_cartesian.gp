set title "Gnuplot Correspondences\ngeographic coordinate system"
#set terminal wxt persist
set terminal pdfcairo
set output 'world_cities_001.pdf'
unset key
set xrange [-180:180]
set yrange [-90:90]
set yzeroaxis
set xtics geographic
set ytics geographic
set format x "%D %E"
set format y "%D %N"
#
# plot world map and correspondent locations as a +
plot 'world.dat' with lines lc rgb "blue" notitle, \
'world_short.cor' with points lt 1 pt 2 notitle, \
'world_short.cor' with labels offset 0.25,0.25 notitle, \

