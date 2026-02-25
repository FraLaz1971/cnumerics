# Dimensioni
a = 28.9
b = 14.5
c = 9.0

set terminal wxt persist
set title "Parallelepipedo 3D con Facce Trasparenti"
set view 60, 30
set view equal xyz

# Limiti assi
set xrange [-5:a+5]
set yrange [-5:b+5]
set zrange [-5:c+5]

# Configurazione Trasparenza (0.0 trasparente, 1.0 opaco)
# Il colore "forest-green" con trasparenza 0.3
set style fill transparent solid 0.3 border

# Definizione delle 6 facce come poligoni
# Base inferiore (z=0)
set object 1 polygon from 0,0,0 to a,0,0 to a,b,0 to 0,b,0 to 0,0,0
set object 1 fc rgb "blue"

# Base superiore (z=c)
set object 2 polygon from 0,0,c to a,0,c to a,b,c to 0,b,c to 0,0,c
set object 2 fc rgb "blue"

# Faccia frontale (y=0)
set object 3 polygon from 0,0,0 to a,0,0 to a,0,c to 0,0,c to 0,0,0
set object 3 fc rgb "red"

# Faccia posteriore (y=b)
set object 4 polygon from 0,b,0 to a,b,0 to a,b,c to 0,b,c to 0,b,0
set object 4 fc rgb "red"

# Faccia laterale sinistra (x=0)
set object 5 polygon from 0,0,0 to 0,b,0 to 0,b,c to 0,0,c to 0,0,0
set object 5 fc rgb "green"

# Faccia laterale destra (x=a)
set object 6 polygon from a,0,0 to a,b,0 to a,b,c to a,0,c to a,0,0
set object 6 fc rgb "green"

# Plottiamo sopra il tuo file .dat per mantenere spigoli e label ben visibili
splot 'parallelepiped001.dat' using 1:2:3 with linespoints lt 1 pt 7 ps 1.5 lc rgb "black" title "Spigoli", \
      'parallelepiped001.dat' using 1:2:3:4 with labels offset 0.5,0.5 notitle
