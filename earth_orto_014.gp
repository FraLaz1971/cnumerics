lat0 = 0.0
lon0 = 0.0
pi=3.14159265
set terminal wxt persist
set datafile separator ','
deg2rad(x) = x*pi/180.0

xproj(lat,lon) = (cos(deg2rad(lat))*sin(deg2rad(lon-lon0))*1024)+1024
yproj(lat,lon) = ((cos(deg2rad(lat0))*sin(deg2rad(lat)) - sin(deg2rad(lat0))*cos(deg2rad(lat))*cos(deg2rad(lon-lon0)))*1024)+1024

set terminal pngcairo size 2048,2048
set output "earth_cities_orthographic_014.png"

# Definisci la funzione di visibilità
is_visible(lat, lon) = (cos(deg2rad(lat))*cos(deg2rad(lat0))*cos(deg2rad(lon-lon0)) + \
                        sin(deg2rad(lat))*sin(deg2rad(lat0)) > 0) ? 1 : 1/0

set samples 100
set isosamples 2

set size ratio -1
set xrange [0:2047]
set yrange [0:2047]
#unset key
#unset border
#unset tics

# Draw planet disk
# set object circle at 0,0 size 495.5 fillstyle empty border

plot 'Orthographic_Projection_Transversal.jpg' binary filetype=jpg with rgbimage notitle, \
'few_capitals.csv' using  (xproj($1,$2)):(yproj($1,$2))*is_visible($1,$2) with points pt 7 ps 0.7 lc rgb 'red'  notitle, \
'few_capitals.csv' using  (xproj($1,$2)):(yproj($1,$2))*is_visible($1,$2):3 with labels tc rgb "yellow"  notitle, \

