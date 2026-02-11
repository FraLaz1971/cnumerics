set terminal wxt persist
set parametric
set trange [0:2*pi]
set samples 500
set size ratio -1
set grid

# Parametri dell'ellisse
x0 = 2
y0 = 4
a = 8
b = 3

# Angolo di rotazione (in gradi)
angolo_deg = 30
alpha = angolo_deg * pi / 180.0

# Funzioni di rotazione applicate alle coordinate
x(t) = x0 + a*cos(t)*cos(alpha) - b*sin(t)*sin(alpha)
y(t) = y0 + a*cos(t)*sin(alpha) + b*sin(t)*cos(alpha)

# Impostazione margini per visibilità
set xrange [x0-10 : x0+10]
set yrange [y0-10 : y0+10]

# Plot
plot x(t), y(t) with lines title sprintf("Ellisse ruotata di %d°", angolo_deg) lw 2
