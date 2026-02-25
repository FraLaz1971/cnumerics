# Impostazioni ambiente 3D
set terminal qt size 800,600
set title "Prodotto Vettoriale: w = u x v"
set grid
set xyplane at 0
set view 60, 30, 1.2, 1.2 # Angolazione della camera
set size ratio -1

# Limiti degli assi
set xrange [-1:3]
set yrange [-1:3]
set zrange [0:5]
set xlabel "X"
set ylabel "Y"
set zlabel "Z"

# Definizione dei vettori (x,y,z, dx,dy,dz)
# Vettore u (Blu)
set arrow 1 from 0,0,0 to 2,0,0 lc rgb "blue" lw 2 head filled
set label 1 "u" at 2.2,0,0 tc rgb "blue"

# Vettore v (Rosso)
set arrow 2 from 0,0,0 to 0,2,0 lc rgb "red" lw 2 head filled
set label 2 "v" at 0,2.2,0 tc rgb "red"

# Vettore w = u x v (Verde) - Risultato
set arrow 3 from 0,0,0 to 0,0,4 lc rgb "dark-green" lw 3 head filled
set label 3 "w = u x v" at 0,0,4.3 tc rgb "dark-green" center

# Disegno di un arco per l'angolo theta (nel piano XY)
set object 1 circle at 0,0,0 size 0.5 arc [0:90] fc rgb "black" lw 1

# Rappresentazione del piano individuato da u e v
set object 2 rect from 0,0 to 2,2 fc rgb "gray" fs transparent solid 0.2

splot NaN notitle
