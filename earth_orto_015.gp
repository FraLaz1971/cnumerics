lat0 = 0
lon0 = 0
pi = 3.14159265
deg2rad(x) = x*pi/180.0
set datafile separator ','

# --- Parametri Geostazionari ---
H = 42164.13
R_eq = 6378.137
R_pol = 6356.752

# --- Funzioni di Proiezione ---
r_e(lat) = R_pol / sqrt(1.0 - (1.0 - (R_pol/R_eq)**2) * cos(deg2rad(lat))**2)
x_cart(lat,lon) = r_e(lat) * cos(deg2rad(lat)) * cos(deg2rad(lon-lon0))
y_cart(lat,lon) = r_e(lat) * cos(deg2rad(lat)) * sin(deg2rad(lon-lon0))
z_cart(lat,lon) = r_e(lat) * sin(deg2rad(lat))

s_x(lat,lon) = H - x_cart(lat,lon)
s_y(lat,lon) = y_cart(lat,lon)
s_z(lat,lon) = z_cart(lat,lon)
dist(lat,lon) = sqrt(s_x(lat,lon)**2 + s_y(lat,lon)**2 + s_z(lat,lon)**2)

scan_x(lat,lon) = atan2(s_y(lat,lon), s_x(lat,lon))
scan_y(lat,lon) = asin(s_z(lat,lon) / dist(lat,lon))

# --- Calibrazione (Offset e Scala) ---
X0 = 497.0
Y0 = 502.0
Kx = 3118.0
Ky = 3118.0

xproj(lat,lon) = (scan_x(lat,lon) * Kx) + X0
yproj(lat,lon) = (scan_y(lat,lon) * Ky) + Y0

xproj_grid(lat,lon) = (cos(deg2rad(lat))*sin(deg2rad(lon-lon0))*497)+497
yproj_grid(lat,lon) = ((cos(deg2rad(lat0))*sin(deg2rad(lat)) - sin(deg2rad(lat0))*cos(deg2rad(lat))*cos(deg2rad(lon-lon0)))*494)+494


# --- Visibilità Estesa per la Griglia ---
# Usiamo un margine infinitesimo per arrivare al bordo estremo
is_visible(lat, lon) = (x_cart(lat,lon) > (R_eq**2 / H)*0.99) ? 1 : 1/0

set termina wxt persist
#set terminal pngcairo size 994,988
#set output "earth_cities_final_grid.png"

set size ratio -1
set xrange [0:993]
set yrange [0:987]
set samples 400  # Fondamentale per la curvatura ai bordi
set isosamples 2

plot 'Earth-view_0_0.png' binary filetype=png with rgbimage notitle, \
'few_capitals.csv' using (xproj($1,$2)):(yproj($1,$2)) with points pt 7 ps 0.7 lc rgb 'red' notitle, \
'few_capitals.csv' using (xproj($1,$2)):(yproj($1,$2)):3 with labels tc rgb "yellow" offset 0,1 notitle, \
for [l=-90:90:15] [t=-90:90:0.5] '+' u (xproj_grid(l,t)):(yproj_grid(l,t)*is_visible(l,t)) with lines lc "white" dt 3 notitle, \
for [t=-90:90:15] [l=-90:90:0.5] '+' u (xproj_grid(l,t)):(yproj_grid(l,t)*is_visible(l,t)) with lines lc "white" dt 3 notitle

# Paralleli: estesi a +/- 82 gradi e campionati densamente
# Meridiani: estesi a +/- 82 gradi
