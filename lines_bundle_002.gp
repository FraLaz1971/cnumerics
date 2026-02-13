# Impostazioni grafiche
#set terminal wxt persist
set terminal pngcairo
set output 'lines_bundle_002.png'
set grid
set size square              # FONDAMENTALE per vedere gli angoli reali
set view equal xy
set key outside right        # Sposta la legenda fuori per non coprire il fascio

# Definizione del centro del fascio (puoi passarli come variabili)
x0 = 0
y0 = 0

# Definizione del range di visualizzazione
set xrange [x0-10 : x0+10]
set yrange [y0-10 : y0+10]

# Funzione della retta basata sull'angolo (convertito in radianti)
# m = tan(alpha * pi / 180)
f(x, a) = y0 + tan(a * pi / 180.0) * (x - x0)

# Plot iterativo: gradi da 0 a 170 con step di 10
# Usiamo 'samples 2' perché per una retta bastano due punti
set samples 2
plot for [a=-89:89:5] f(x, a) title sprintf("%d°", a) lw 1
