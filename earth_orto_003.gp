lat0 = -5.0
lon0 = -5.0
pi=3.14159265
set terminal wxt persist
set datafile separator ','
deg2rad(x) = x*pi/180.0

xproj(lat,lon) = (cos(deg2rad(lat))*sin(deg2rad(lon-lon0))*544.5)+544.5
yproj(lat,lon) = ((cos(deg2rad(lat0))*sin(deg2rad(lat)) - sin(deg2rad(lat0))*cos(deg2rad(lat))*cos(deg2rad(lon-lon0)))*541.5)+541.5

#set terminal pngcairo size 1089,1083
#set output "earth_cities_orthographic_004.png"

# Definisci la funzione di visibilità
is_visible(lat, lon) = (cos(deg2rad(lat))*cos(deg2rad(lat0))*cos(deg2rad(lon-lon0)) + \
                        sin(deg2rad(lat))*sin(deg2rad(lat0)) > 0) ? 1 : 1/0

set samples 100
set isosamples 2

set size ratio -1
set xrange [0:1088]
set yrange [0:1082]
#unset key
#unset border
#unset tics

# Draw planet disk
# set object circle at 0,0 size 495.5 fillstyle empty border

plot 'Earth_Disk_003.png' binary filetype=png with rgbimage notitle, \
'few_capitals.csv' using  (xproj($2,$3)):(yproj($2,$3))*is_visible($2,$3) with points pt 7 ps 0.7 lc rgb 'red'  notitle, \
'few_capitals.csv' using  (xproj($2,$3)):(yproj($2,$3))*is_visible($2,$3):1 with labels tc rgb "yellow" notitle, \
for [l=-90:90:15] [t=0:360:5] '+' u (xproj(l,t)):(yproj(l,t) * is_visible(l,t)) \
          with lines lc "white" dt 3 notitle, \
for [t=0:360:30] [l=-90:90:5] '+' u (xproj(l,t)):(yproj(l,t) * is_visible(l,t)) \
          with lines lc "white" dt 3 notitle, \


