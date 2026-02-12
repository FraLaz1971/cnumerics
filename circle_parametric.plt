set terminal pngcairo
set output "circle2_3_r5.png"
set parametric
set size ratio -1
xc=2
yc=3
r=5
#set trange[0:(1.5)*pi]
plot xc+r*cos(t),yc+r*sin(t)
