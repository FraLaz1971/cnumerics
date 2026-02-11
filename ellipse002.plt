set datafile separator ","
#set terminal wxt persist
set terminal pngcairo size 900,600
set output "ellipse002.png"

set parametric
set trange [0:2*pi]
set samples 800
set size ratio -1
set grid

# =========================
# Parametri ellisse
# =========================
x0 = 2
y0 = 4
a  = 8
b  = 3

# Parametro scelto
t0 = pi/4

# =========================
# Parametrizzazione ellisse
# =========================
xe(t) = x0 + a*cos(t)
ye(t) = y0 + b*sin(t)

# =========================
# Cerchio ausiliario r=a
# =========================
xc(t) = x0 + a*cos(t)
yc(t) = y0 + a*sin(t)

# Punto sul cerchio (anomalia eccentrica)
Cx = x0 + a*cos(t0)
Cy = y0 + a*sin(t0)

# Punto sull’ellisse (proiezione)
Px = x0 + a*cos(t0)
Py = y0 + b*sin(t0)

# Angolo polare reale theta
theta = atan2(Py-y0, Px-x0)

# =========================
# Assi principali
# =========================
set arrow from x0-a, y0 to x0+a, y0 nohead lc rgb "blue" dt 2
set arrow from x0, y0-b to x0, y0+b nohead lc rgb "red"  dt 2

# =========================
# Proiezioni cartesiane
# =========================
set arrow from Px,y0 to Px,Py nohead lc rgb "green" dt 3
set arrow from x0,Py to Px,Py nohead lc rgb "green" dt 3

# =========================
# Segmenti angolari
# =========================

# Raggio verso punto ellisse (theta)
set arrow from x0,y0 to Px,Py nohead lc rgb "black"

# Raggio verso punto cerchio (t)
set arrow from x0,y0 to Cx,Cy nohead lc rgb "purple"

# =========================
# Archi angoli (approssimati)
# =========================

# arco per t (anomalia eccentrica)
set object 1 circle at x0,y0 size 1 arc [0:45] fs empty border lc rgb "purple"

# arco per theta (angolo polare)
set object 2 circle at x0,y0 size 2 arc [0:20.5] fs empty border lc rgb "black"

# =========================
# Labels
# =========================
set label "t" at x0+1.0,y0+0.8 tc rgb "purple" font ",14"
set label "{/Symbol q}" at x0+2.0,y0+0.5 tc rgb "black" font ",14"

set label sprintf("P(%.2f, %.2f)",Px,Py) at Px+0.3,Py+0.3
set label sprintf("C(%.2f, %.2f)",Cx,Cy) at Cx+0.3,Cy+0.3

# =========================
# Plot finale
# =========================
set xrange [x0-a-3:x0+a+3]
set yrange [y0-a-3:y0+a+3]

plot xe(t),ye(t) w l lw 2 title "Ellisse", \
     xc(t),yc(t) w l lw 1 dt 2 title "Cerchio r=a", \
     "+" using (Px):(Py) w p pt 7 ps 1.5 lc rgb "green" title "P", \
     "+" using (Cx):(Cy) w p pt 7 ps 1.5 lc rgb "purple" title "C"
