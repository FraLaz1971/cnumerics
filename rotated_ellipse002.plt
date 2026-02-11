set terminal wxt persist
set parametric
set trange [0:2*pi]
set samples 500
set size ratio -1
set grid

# 1. Parametri base
x0 = 2
y0 = 4
a = 8
b = 3
angolo_deg = 30
alpha = angolo_deg * pi / 180.0

# 2. Calcolo distanza focale c = sqrt(a^2 - b^2)
c_dist = sqrt(a**2 - b**2)

# 3. Funzioni parametriche per il perimetro dell'ellisse
x(t) = x0 + a*cos(t)*cos(alpha) - b*sin(t)*sin(alpha)
y(t) = y0 + a*cos(t)*sin(alpha) + b*sin(t)*cos(alpha)

# 4. Coordinate dei Fuochi (ruotate)
f1_x = x0 + c_dist * cos(alpha)
f1_y = y0 + c_dist * sin(alpha)
f2_x = x0 - c_dist * cos(alpha)
f2_y = y0 - c_dist * sin(alpha)

# 5. Definizione degli Assi (vettori che partono dal centro)
# Asse maggiore (lungo a)
set arrow from x0 - a*cos(alpha), y0 - a*sin(alpha) to x0 + a*cos(alpha), y0 + a*sin(alpha) nohead lc rgb "blue" dt 2
# Asse minore (lungo b)
set arrow from x0 + b*sin(alpha), y0 - b*cos(alpha) to x0 - b*sin(alpha), y0 + b*cos(alpha) nohead lc rgb "red" dt 2

# Limiti del grafico
set xrange [x0-10 : x0+10]
set yrange [y0-10 : y0+10]

# 6. Plot dell'ellisse e dei fuochi
plot x(t), y(t) with lines title "Ellisse" lw 2 lc rgb "black", \
f1_x,f1_y with points pt 7 ps 1.5 lc rgb "forest-green" title "Fuoco1",\
f2_x,f2_y with points pt 7 ps 1.5 lc rgb "blue" title "Fuoco2"
#"< echo ".f1_x." ".f1_y."\n ".f2_x." ".f2_y."" with points pt 7 ps 1.5 lc rgb "forest-green" title "Fuochi"

