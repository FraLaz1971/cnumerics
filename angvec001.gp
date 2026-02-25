# Impostazioni generali del grafico
set terminal wxt size 600,600 persist  # O 'png' / 'pdf' se vuoi salvare su file
set title "Visualizzazione Vettori e Angolo"
set grid
set size ratio -1             # Mantiene le proporzioni 1:1 (fondamentale per gli angoli)

# Definiamo i limiti degli assi
set xrange [-0.5:4.5]
set yrange [-0.5:4.5]
set xlabel "X"
set ylabel "Y"

# Definizione dei vettori (origine x, y, delta_x, delta_y)
# Vettore a = (3, 4)
set arrow 1 from 0,0 to 3,4 lc rgb "blue" lw 2 head filled
# Vettore b = (1, 2)
set arrow 2 from 0,0 to 1,2 lc rgb "red" lw 2 head filled

# Etichette per i vettori
set label 1 "a (3,4)" at 3, 4.2 tc rgb "blue" center
set label 2 "b (1,2)" at 1, 2.2 tc rgb "red" center

# Disegniamo un arco per rappresentare l'angolo (opzionale ma utile)
# Sintassi: set object circle at x,y size r arc [start:end]
set object 1 circle at 0,0 size 0.8 arc [53.1:63.4] fc rgb "black" lw 1

# Nota sull'angolo calcolato
set label 3 "θ ≈ 10.3°" at 0.9, 0.7 font ",10"

# Comando per visualizzare (se non usi un terminale interattivo, usa 'plot')
plot NaN title "" # Plot "vuoto" per attivare la visualizzazione delle frecce
