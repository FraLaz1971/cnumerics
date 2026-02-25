set terminal pngcairo
set output 'trigonometry001.png'
set title "Trigonometry"
set grid
set xyplane at 0
set size ratio -1

# Limiti degli assi
set xrange [-1.2:1.2]
set yrange [-1.2:1.2]
set xlabel "X axes"
set ylabel "Y axes"

#set object 1 circle at 0,0 size 1 arc [0:90] fc "blue"
set object 1 circle at 0,0 size 1
set arrow 1 from -1.2,0 to 1.2,0 lw 2 head filled
set arrow 2 from 0,-1.2 to 0,1.2 lw 2 head filled
set arrow 3 from 0.867,0 to 0.867,0.5 lc rgb 'blue' lw 2 nohead
set arrow 4 from 0,0 to 0.867,0.5 lc rgb 'red' lw 1 nohead
set arrow 5 from 0,0 to 0.867,0 lc rgb 'light-green' lw 2 nohead
set label 1 "O" at 0,0 offset 0.5,-0.5
set label 2 "W" at 0.867,0 offset -0.5,-0.5
set label 3 "A" at 0.867,0.5 offset 0.5,0.5
set object 2 circle at 0,0 size 0.2 arc [0:30] fc "red"
set label 4 "{/Symbol a} = 30°" at 0.18,0.03 offset 0.5,0.5
set label 5 "X" at 1,0 offset 0.5,-0.8
set label 6 "Y" at 0,1 offset 0.8,0.5
set label 7 "sen {/Symbol a}" at 0.867,0.25 offset 0.5,0.5 tc rgb "blue"
set label 8 "cos {/Symbol a}" at 0.43,0 offset 0.5,-0.5 tc rgb "green" center
plot NaN notitle
