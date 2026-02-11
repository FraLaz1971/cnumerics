#set terminal wxt persist
set terminal pngcairo size 900,700
set output "ellissoide.png"

set hidden3d
set parametric
set urange [0:2*pi]
set vrange [0:pi]
set samples 80
set isosamples 40
set view 60,30
set size ratio -1

# semiassi
a = 8
b = 3

# parametrizzazione ellissoide di rotazione attorno a x
x(u,v) = a*cos(v)
y(u,v) = b*sin(v)*cos(u)
z(u,v) = b*sin(v)*sin(u)

splot x(u,v),y(u,v),z(u,v) with lines notitle
