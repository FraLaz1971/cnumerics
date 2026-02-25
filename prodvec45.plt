# Impostazioni ambiente 3D
set terminal qt size 800,600
set title "Prodotto Vettoriale - Arco su Piano UV"
set grid
set xyplane at 0
set view 65, 35, 1.2, 1.2
set size ratio -1

# Parametri dell'angolo
theta_deg = 45.0
theta_rad = theta_deg * pi/180.0

# Coordinate vettori
ux=2.0; uy=0.0; uz=0.0
vx=2.0*cos(theta_rad); vy=2.0*sin(theta_rad); vz=0.0
wx=0.0; wy=0.0; wz=ux*vy # Modulo u*v*sin(theta)

# Limiti assi
set xrange [-0.5:3]
set yrange [-0.5:3]
set zrange [0:4]

# Frecce e Etichette
set arrow 1 from 0,0,0 to ux,uy,uz lc rgb "blue" lw 2 head filled
set arrow 2 from 0,0,0 to vx,vy,vz lc rgb "red" lw 2 head filled
set arrow 3 from 0,0,0 to wx,wy,wz lc rgb "dark-green" lw 3 head filled

set label 1 "u" at ux+0.1, uy, uz tc rgb "blue"
set label 2 "v" at vx, vy+0.2, vz tc rgb "red"
set label 3 "w = u x v" at wx, wy, wz+0.3 tc rgb "dark-green" center
set label 4 "θ = 45°" at 0.8, 0.4, 0 tc rgb "black"

# Parallelogramma
set object 1 polygon from 0,0,0 to ux,uy,uz to ux+vx,uy+vy,uz+vz to vx,vy,vz to 0,0,0 \
    fillstyle transparent solid 0.15 fillcolor rgb "gray"

# DISEGNO DELL'ARCO USANDO LE FUNZIONI PARAMETRICHE CORRETTE
set parametric
#set dummy t          # Usiamo 't' come variabile per la linea
t = 0
set trange [0:theta_rad]
r = 0.6              # Raggio dell'arco

# In splot parametric, bisogna fornire x(t,v), y(t,v), z(t,v)
# Ignoriamo la seconda variabile v per disegnare una linea
splot r*cos(t), r*sin(t), 0 lc rgb "black" lw 2 notitle
reset
set terminal qt size 800,600
set title "Prodotto Vettoriale: w = u x v"
set xyplane at 0
set view 65, 35, 1.2, 1.2
set size ratio -1
set grid

# 1. DEFINIZIONE COSTANTI E VETTORI
deg2rad = pi/180.0
theta_deg = 45.0
theta_rad = theta_deg * deg2rad

ux = 2.0; uy = 0.0; uz = 0.0
vx = 2.0 * cos(theta_rad); vy = 2.0 * sin(theta_rad); vz = 0.0
# Modulo del prodotto vettoriale: |u||v|sin(theta)
wz = ux * vy

set xrange [-0.5:3]; set yrange [-0.5:3]; set zrange [0:4]

# 2. ELEMENTI GRAFICI (Frecce e Etichette)
set arrow 1 from 0,0,0 to ux,uy,uz lc rgb "blue" lw 2 head filled
set arrow 2 from 0,0,0 to vx,vy,vz lc rgb "red" lw 2 head filled
set arrow 3 from 0,0,0 to 0,0,wz lc rgb "dark-green" lw 3 head filled

set label 1 "u" at ux+0.1, uy, uz tc rgb "blue"
set label 2 "v" at vx, vy+0.2, vz tc rgb "red"
set label 3 "w = u x v" at 0, 0, wz+0.3 tc rgb "dark-green" center
set label 4 "θ = 45°" at 0.7, 0.3, 0 tc rgb "black"

# Parallelogramma
set object 1 polygon from 0,0,0 to ux,uy,uz to ux+vx,uy+vy,uz+vz to vx,vy,vz to 0,0,0 \
    fillstyle transparent solid 0.15 fillcolor rgb "gray"

# 3. DISEGNO DELL'ARCO (MODALITÀ PARAMETRICA CORRETTA)
set parametric
set urange [0:theta_rad]
set vrange [0:1] # v non viene usato ma deve essere definito
r = 0.6          # Raggio dell'archetto

# In splot parametric x,y,z devono essere funzioni di (u,v).
# Usiamo solo 'u' per far scorrere l'angolo.
splot r*cos(u), r*sin(u), 0 with lines lc rgb "black" lw 2 notitle
