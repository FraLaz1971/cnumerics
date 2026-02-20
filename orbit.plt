set terminal png
set output "orbit.png"
set parametric
set trange [0:2*pi]
plot cos(t), sin(t)
