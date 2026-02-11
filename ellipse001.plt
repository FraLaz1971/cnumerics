set datafile separator ","
set terminal pngcairo
set output "ellipse001.png"
set parametric
set trange [0:2*pi]
set samples 500
set size ratio -1
set grid

x0 = 2
y0 = 4
a = 8
b = 3

# 3. Funzioni parametriche per il perimetro dell'ellisse
x(t) = x0 + a*cos(t)
y(t) = y0 + b*sin(t)

# 5. Definizione degli Assi (vettori che partono dal centro)
# Asse maggiore (lungo a)
set arrow from x0 - a, y0 to x0 + a, y0 nohead lc rgb "blue" dt 2
# Asse minore (lungo b)
set arrow from x0, y0-b to x0,y0+b nohead lc rgb "red" dt 2

set xrange [x0-a-2 : x0+a+2]
set yrange [y0-b-2 : y0+b+2]
set xtics x0-a-2,1,x0+a+2
set ytics y0-b-2,1,y0+b+2
plot x(t), y(t) with lines title "Ellipse" lw 2, \
"ellipse_points001.csv" with points pt 7 notitle, \
"ellipse_points001.csv" using 1:2:3 with labels offset 0.50,0.50 font 'arial,14' notitle
