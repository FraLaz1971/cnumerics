lat0 = 0
lon0 = 0
pi = 3.14159265
deg2rad(x) = x*pi/180.0
set datafile separator ','
dim_x=3712
dim_y=3712

# --- Geostationary Parameters ---
H = 42164.13
R_eq = 6378.137
R_pol = 6356.752

# --- Projection Functions ---
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

# --- Calibration (Offset and Scaling) ---
X0 = dim_x/2.0
Y0 = dim_y/2.0
Kx = 11900.0
Ky = 11900.0

xproj(lat,lon) = (scan_x(lat,lon) * Kx) + X0
yproj(lat,lon) = (scan_y(lat,lon) * Ky) + Y0

xproj_grid(lat,lon) = (cos(deg2rad(lat))*sin(deg2rad(lon-lon0))*X0)+X0
yproj_grid(lat,lon) = ((cos(deg2rad(lat0))*sin(deg2rad(lat)) - sin(deg2rad(lat0))*cos(deg2rad(lat))*cos(deg2rad(lon-lon0)))*Y0)+Y0


# --- Extended visibility for the grid ---
is_visible(lat, lon) = (x_cart(lat,lon) > (R_eq**2 / H)) ? 1 : 1/0

#set terminal wxt persist
set terminal pngcairo size 3712,3712
set output "earth_cities_meteosat_20240422.png"

set size ratio -1
set xrange [0:dim_x-1]
set yrange [0:dim_y-1]
set samples 400  # Fundamental for the curving at the borders
set isosamples 2

plot 'MET10_RGBNatColourEnhncd_FullResolution_20240422110000.jpg' binary filetype=jpg with rgbimage notitle, \
'few_capitals.csv' using (xproj($1,$2)):(yproj($1,$2)) with points pt 7 ps 0.7 lc rgb 'red' notitle, \
'few_capitals.csv' using (xproj($1,$2)):(yproj($1,$2)):3 with labels tc rgb "yellow" offset 0,1 notitle, \
for [l=-82:82:15] [t=-82:82:0.5] '+' u (xproj_grid(l,t)):(yproj_grid(l,t)*is_visible(l,t)) with lines lc "white" dt 3 notitle, \
for [t=-82:82:15] [l=-82:82:0.5] '+' u (xproj_grid(l,t)):(yproj_grid(l,t)*is_visible(l,t)) with lines lc "white" dt 3 notitle

# Parallels: extended to +/- 82 degrees and dense sampled
# Meridians: extended to +/- 82 degrees
