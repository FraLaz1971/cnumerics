#set terminal wxt persist
set terminal pngcairo size 1000,750
set output "ellissoide_costruzione.png"

set hidden3d
set parametric
set samples 200
set isosamples 60
set view 65,35
set size ratio -1
set grid

# ============================
# Parametri ellisse
# ============================
a = 8
b = 3

# scegli un parametro t0 per il punto P
t0 = pi/4

# Punto P sull’ellisse nel piano xy
xP = a*cos(t0)
yP = b*sin(t0)

# ============================
# Ellisse originale (2D)
# ============================
xe(t) = a*cos(t)
ye(t) = b*sin(t)

# ============================
# Rotazione del punto P attorno all’asse x
# ============================
# Quando ruoti, y si divide in y e z:
#
# y(u) = yP*cos(u)
# z(u) = yP*sin(u)
#
# quindi y^2+z^2 = yP^2 = costante

xC(u) = xP
yC(u) = yP*cos(u)
zC(u) = yP*sin(u)

# ============================
# Ellissoide completo (superficie)
# ============================
x(u,v) = a*cos(v)
y(u,v) = b*sin(v)*cos(u)
z(u,v) = b*sin(v)*sin(u)

# ============================
# Assi cartesiani
# ============================
set arrow from -10,0,0 to 10,0,0 nohead lc rgb "black"
set arrow from 0,-6,0 to 0,6,0 nohead lc rgb "black"
set arrow from 0,0,-6 to 0,0,6 nohead lc rgb "black"

set label "x" at 10,0,0
set label "y" at 0,6,0
set label "z" at 0,0,6

# ============================
# Label punto P
# ============================
set label sprintf("P = (%.2f, %.2f)",xP,yP) at xP+0.5,yP+0.5,0

# ============================
# Plot finale
# ============================
splot \
   x(u,v),y(u,v),z(u,v) with lines lw 1 title "Ellissoide", \
   xC(u),yC(u),zC(u) with lines lw 3 title "Circonferenza generata da P", \
   xP,yP,0 with points pt 7 ps 2 title "P sull’ellisse"
