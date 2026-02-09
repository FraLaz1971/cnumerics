lat0 = 0
lon0 = 0
pi=3.14159265
a=6378.1
b=6356.8
set terminal wxt persist
set datafile separator ','
deg2rad(x) = x*pi/180.0

#xproj(lat,lon) = (cos(deg2rad(lat))*sin(deg2rad(lon))*497.0)+497.0
#yproj(lat,lon) = sin(deg2rad(lat))*494+494

xproj(lat,lon) = (cos(deg2rad(lat))*sin(deg2rad(lon-lon0))*497)+497
yproj(lat,lon) = ((cos(deg2rad(lat0))*sin(deg2rad(lat)) - sin(deg2rad(lat0))*cos(deg2rad(lat))*cos(deg2rad(lon-lon0)))*494)+494



set terminal pngcairo size 994,988
set output "earth_cities_orthographic_013.png"

# Definisci la funzione di visibilità
is_visible(lat, lon) = (cos(deg2rad(lat))*cos(deg2rad(lat0))*cos(deg2rad(lon-lon0)) + \
                        sin(deg2rad(lat))*sin(deg2rad(lat0)) > 0) ? 1 : 1/0

set samples 100
set isosamples 2

set size ratio -1
set xrange [0:993]
set yrange [0:987]
#unset key
#unset border
#unset tics

# Draw planet disk
# set object circle at 0,0 size 497 fillstyle empty border

plot 'Earth-view_0_0.png' binary filetype=png with rgbimage notitle, \
'few_capitals.csv' using  (xproj($1,$2)):(yproj($1,$2)) with points pt 7 ps 0.7 lc rgb 'red'  notitle, \
'few_capitals.csv' using  (xproj($1,$2)):(yproj($1,$2))*is_visible($1,$2):3 with labels tc rgb "yellow" notitle, \
for [l=-90:90:15] [t=0:360:5] '+' u (xproj(l,t)):(yproj(l,t) * is_visible(l,t)) \
          with lines lc "white" dt 3 notitle, \
for [t=0:360:30] [l=-90:90:5] '+' u (xproj(l,t)):(yproj(l,t) * is_visible(l,t)) \
          with lines lc "white" dt 3 notitle, \
#lc rgb 'red' title 'Rome', \

#x=577 y=824 Rome
