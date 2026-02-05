#set terminal pngcairo  transparent enhanced font "arial,14" fontscale 1.0 size 600, 400
#set output 'poldat_4.png'
set title "angles"
set terminal wxt persist
set size square
#t  r  e_r name
unset border
set dummy t, y
#set angles degrees
set polar
set trange [0:6.28]
set rrange [0:8]
#set size ratio 0.5 1,1
unset xtics
unset ytics
plot 'out3.csv' lw 1.5 title "angles(rad)"
#'out.csv' using 1:($2):4 with labels offset 0.5,0.5 notitle


