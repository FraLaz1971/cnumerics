$Mydata << EOD
 1  0 (1,0)
 0  1 (0,1) 
-1  0 (-1,0)
 0 -1 (0,-1)
 1  0
 0  0 (0,0)
EOD

$Mydata2 << EOD
-1  0
 1  0

 0  1
 0 -1
EOD

$Mydata3 << EOD
 0.333333  0.333333 E
-0.666666  0.333333 F
-0.5      -0.5      G
 0.5      -0.25     H
EOD

$Mydata4 << EOD
 0         0
 0.333333  0.333333

 0         0
-0.666666  0.333333

 0         0
-0.5      -0.5     

 0         0
 0.5      -0.25
EOD

set object 5 circle at 0,0 size 0.471404 arc [0:45] fc "blue"
set object 6 circle at 0,0 size 0.745355 arc [0:153] fc "red"
set object 7 circle at 0,0 size 0.707106 arc [0:225] fc "green"
set object 8 circle at 0,0 size 0.559016 arc [0:333] fc "purple"

set terminal wxt persist
set xrange [-1.5:1.5]
set yrange [-1.5:1.5]
set size ratio -1
set object 1 circle at 0,0 size 1 arc [0:360]
plot $Mydata2 with lines lc 0 notitle, \
$Mydata using 1:2 with points pt 7 notitle, \
$Mydata using 1:2:3 with labels offset 0.5,0.5 font 'arial,14' tc lt 9  notitle, \
$Mydata3 using 1:2 with points pt 7 notitle, \
$Mydata3 using 1:2:3 with labels offset 0.5,0.5 font 'arial,14' tc lt 2  notitle, \
$Mydata4 with lines lc 0 notitle, \

# pt 7 = full circles
# E 0.471404
# F 0.745355
# G 0.707106
# H .559016
