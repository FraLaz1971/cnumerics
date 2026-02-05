set terminal wxt persist
set datafile separator ','
splot 'atans001.csv' using 1:2:3 title 'atan()', \
'atans001.csv' using 1:2:4 title 'atan2()'

