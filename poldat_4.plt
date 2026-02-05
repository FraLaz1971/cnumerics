#set terminal pngcairo  transparent enhanced font "arial,14" fontscale 1.0 size 600, 400
#set output 'poldat_4.png'
set title "yerrors in polar mode"
set terminal wxt persist
set size square
#t  r  e_r name
$DATA << EOD
0   1.3 0.2 A
30  0.9 0.1 B
60  0.7 0.1 C
90  1.0 0.3 D
120 1.1 0.1 E
150 0.5 0.1 F
180 1.2 0.2 G
210 0.7 0.3 H
240 1.3 0.2 I
270 0.9 0.3 L
300 0.6 0.1 M
330 1.0 0.4 N
EOD
unset border
set dummy t, y
set angles degrees
set grid polar 15.000000
set grid layerdefault lt 0 linecolor -1 linewidth 0.800, lt 0 linecolor -1 linewidth 0.800
set polar
set trange [0:360] 
set rrange [0:1.6]
#set size ratio 0.5 1,1
unset xtics
unset ytics
set title "yerrors in polar mode" 
plot $DATA with yerrorbars lw 1.5 title "polar error bars", \
$DATA using 1:($2):4 with labels offset 0.5,0.5 notitle


