set terminal wxt persist
set size ratio -1
set object 1 circle at 0,0 size 1 arc [0:90] fc "blue"
set object 2 circle at 0,0 size 1 arc [90:180] fc "red"
set object 3 circle at 0,0 size 1 arc [180:270] fc "green"
set object 4 circle at 0,0 size 1 arc [270:360] fc "purple"
plot  [-1.5:1.5] [-1.5:1.5] 0

