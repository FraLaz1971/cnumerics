lat0 = -0.1  # Regola questo valore
lon0 = -3.5
pi = 3.14159265
deg2rad(x) = x*pi/180.0
set datafile separator ','
dim_x=1091
dim_y=1085


# --- Parametri corretti ---
H = 42164.13
R_eq = 6378.137
R_pol = 6356.752

# Angoli di scansione massimi (metà diametro)
alpha_x = asin(R_eq / H)
alpha_y = asin(R_pol / H)

# Calibrazione dinamica basata sul tuo crop
Kx = (dim_x-1) / (2.0 * alpha_x)
Ky = (dim_y-1) / (2.0 * alpha_y)

# Se il disco è perfettamente centrato nel crop:
#X0 = (dim_x-1) / 2.0 + 28
#Y0 = (dim_y-1) / 2.0 - 6
X0 = (dim_x-1)/2.0
Y0 = (dim_y-1)/2.0
set object 1 circle at (dim_x-1)/2.0,(dim_y-1)/2.0 size (alpha_x * Kx) front arc [0:360] fc rgb "cyan" fs empty border lc rgb "cyan" lw 2
# --- Funzioni di Proiezione ---
r_e(lat) = R_pol / sqrt(1.0 - (1.0 - (R_pol/R_eq)**2) * cos(deg2rad(lat))**2)
x_cart(lat,lon) = r_e(lat) * cos(deg2rad(lat)) * cos(deg2rad(lon-lon0))
y_cart(lat,lon) = r_e(lat) * cos(deg2rad(lat)) * sin(deg2rad(lon-lon0))
z_cart(lat,lon) = r_e(lat) * sin(deg2rad(lat))

# Coordinate cartesiane della città (Geocentriche)
cx(lat,lon) = r_e(lat) * cos(deg2rad(lat)) * cos(deg2rad(lon-lon0))
cy(lat,lon) = r_e(lat) * cos(deg2rad(lat)) * sin(deg2rad(lon-lon0))
cz(lat,lon) = r_e(lat) * sin(deg2rad(lat))

# Coordinate relative al satellite (H, 0, 0) ruotate per lat0
# Usiamo una matrice di rotazione sull'asse Y per la latitudine del satellite
s_x(lat,lon) = (H - cx(lat,lon)) * cos(deg2rad(lat0)) - cz(lat,lon) * sin(deg2rad(lat0))
s_y(lat,lon) = cy(lat,lon)
s_z(lat,lon) = (H - cx(lat,lon)) * sin(deg2rad(lat0)) + cz(lat,lon) * cos(deg2rad(lat0))

dist(lat,lon) = sqrt(s_x(lat,lon)**2 + s_y(lat,lon)**2 + s_z(lat,lon)**2)

# Angoli di scansione
scan_x(lat,lon) = atan2(s_y(lat,lon), s_x(lat,lon))
scan_y(lat,lon) = asin(s_z(lat,lon) / dist(lat,lon))


# --- Calibrazione (Offset e Scala) ---

xproj(lat,lon) = (scan_x(lat,lon) * Kx) + X0
yproj(lat,lon) = (scan_y(lat,lon) * Ky) + Y0

xproj_grid(lat,lon) = (cos(deg2rad(lat))*sin(deg2rad(lon-lon0))*dim_x/2.0)+dim_x/2.0
yproj_grid(lat,lon) = ((cos(deg2rad(lat0))*sin(deg2rad(lat)) - sin(deg2rad(lat0))*cos(deg2rad(lat))*cos(deg2rad(lon-lon0)))*dim_y/2.0)+dim_y/2.0


# --- Visibilità Estesa per la Griglia ---
# Usiamo un margine infinitesimo per arrivare al bordo estremo
is_visible(lat, lon) = (x_cart(lat,lon) > (R_eq**2 / H)) ? 1 : 1/0

#set terminal wxt persist
set terminal pngcairo size dim_x,dim_y
set output "earth_cities_Full_disc_Meteosat_ESA.png"

set size ratio -1
set xrange [0:dim_x-1]
set yrange [0:dim_y-1]
set samples 500  # Fondamentale per la curvatura ai bordi
set isosamples 2
#set object 1 circle at X0,Y0 size alpha_x*Kx fc rgb "red" fs empty border lc rgb "cyan"
# --- Impostazioni per le linee ---
set samples 500  # Alta risoluzione per linee curve fluide
is_on_disk(lat, lon) = (x_cart(lat,lon) > (R_eq**2 / H)) ? 1 : 1/0

# Funzione per nascondere i segmenti non visibili (dietro l'orizzonte)
# La condizione (H - x_cart) > 0 è già implicita nelle tue formule,
# ma usiamo un controllo sulla visibilità per sicurezza
plot 'Full_Earth_disc_Meteosat_ESA_short.png' binary filetype=png with rgbimage notitle, \
'few_capitals.csv' using (xproj($1,$2)):(yproj($1,$2)) with points pt 7 ps 0.7 lc rgb 'red' notitle, \
'few_capitals.csv' using (xproj($1,$2)):(yproj($1,$2)):3 with labels tc rgb "yellow" offset 0,1 notitle, \
for [l=0:0] [t=-80:80:0.5] '+' u (xproj(l,t)):(yproj(l,t)*is_on_disk(l,t)) with lines lw 2 lc rgb "yellow" title "Equatore", \
for [t=0:0] [l=-80:80:0.5] '+' u (xproj(l,t)):(yproj(l,t)*is_on_disk(l,t)) with lines lw 2 lc rgb "cyan" title "Greenwich", \
for [l=-82:82:15] [t=-82:82:0.5] '+' u (xproj_grid(l,t)):(yproj_grid(l,t)*is_visible(l,t)) with lines lc "white" dt 3 notitle, \
for [t=-82:82:15] [l=-82:82:0.5] '+' u (xproj_grid(l,t)):(yproj_grid(l,t)*is_visible(l,t)) with lines lc "white" dt 3 notitle \
# Paralleli: estesi a +/- 82 gradi e campionati densamente
# Meridiani: estesi a +/- 82 gradi
