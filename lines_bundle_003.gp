set terminal pngcairo size 800,800
set output 'lines_bundle_003.png'

set grid
set size square
set xrange [-10:10]
set yrange [-10:10]
set key outside right

x0 = 0
y0 = 0
R = 15  # Lunghezza della retta

# Puliamo eventuali frecce precedenti
unset arrow

# Ciclo per creare le rette come "frecce senza punta"
# Questo metodo non soffre del problema della tangente a 90°
do for [a=-90:90:5] {
    # Calcoliamo i punti estremi della retta centrata in (x0,y0)
    x1 = x0 + R*cos(a * pi/180.0)
    y1 = y0 + R*sin(a * pi/180.0)
    x2 = x0 - R*cos(a * pi/180.0)
    y2 = y0 - R*sin(a * pi/180.0)

    # Creiamo una freccia senza testa (una linea)
    set arrow from x1,y1 to x2,y2 nohead lc rgb "blue" lw 0.5
}

# Gnuplot ha bisogno di un comando 'plot' per generare l'output.
# Plottiamo una funzione invisibile (NaN) solo per attivare il rendering.
plot NaN notitle
