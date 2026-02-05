set terminal wxt persist
set datafile separator ','
plot 'atans.csv' using ($2)/($1):3 title 'atan()', \
'atans.csv' using ($2)/($1):4 title 'atan2()'

