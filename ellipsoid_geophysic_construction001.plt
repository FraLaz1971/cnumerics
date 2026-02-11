#set terminal wxt persist

set terminal pngcairo size 1100,800
set output "ellissoide_geofisico.png"

set hidden3d
set parametric
set samples 250
set isosamples 80
set view 65,35
set size ratio -1
set grid

# ============================
# Parametri ellissoide planetario
# ============================
a = 8     # raggio equatoriale
b = 3     # raggio polare

# scegli un parametro t0 per il punto P sul meridiano
t0 = pi/4

# ============================
# Meridiano ellittico nel piano xz
# ============================
# Ellisse 2D:
# x = a cos(t)
# z = b sin(t)

xP = a*cos(t0)
zP = b*sin(t0)

# ============================
# Rotazione del punto P attorno all’asse z
# ============================
# Ruotando attorno a z:
#
# x(u) = xP cos(u)
# y(u) = xP sin(u)
# z(u) = zP costante
#
# quindi x^2+y^2 = xP^2

xC(u) = xP*cos(u)
yC(u) = xP*sin(u)
zC(u) = zP

# ============================
# Ellissoide completo (superficie)
# ============================
x(u,v) = a*cos(v)*cos(u)
y(u,v) = a*cos(v)*sin(u)
z(u,v) = b*sin(v)

# ============================
# Assi planetari (ECEF)
# ============================
set arrow from -10,0,0 to 10,0,0 nohead lc rgb "black"
set arrow from 0,-10,0 to 0,10,0 nohead lc rgb "black"
set arrow from 0,0,-6 to 0,0,6 nohead lc rgb "black"

set label "x (equatore)" at 10,0,0
set label "y (equatore)" at 0,10,0
set label "z (polo nord)" at 0,0,6

# ============================
# Punto P sul meridiano
# ============================
set label sprintf("P meridiano: (%.2f, 0, %.2f)",xP,zP) \
    at xP+0.5,0,zP+0.3

# ============================
# Plot finale
# ============================
splot \
   x(u,v),y(u,v),z(u,v) with lines lw 1 title "Ellissoide planetario", \
   xC(u),yC(u),zC(u) with lines lw 3 title "Parallelo generato da P", \
   xP,0,zP with points pt 7 ps 2 title "P sul meridiano"
