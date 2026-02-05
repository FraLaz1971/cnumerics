set terminal wxt persist
$Mydata3 << EOD
 0.333333  0.333333 E 0.471404  0.785398
-0.666666  0.333333 F 0.745355 -1.10715
-0.5      -0.5      G 0.707106 -2.35619
 0.5      -0.25     H 0.559016  2.03444
EOD
set xrange[-1:1]
set yrange[-1:1]
set zrange[-2.5:2.5]

splot $Mydata3 using 1:2:4 with impulses notitle, \
$Mydata3 using 1:2:5 with points pt 7 title 'atan2(x,y)', \
$Mydata3 using 1:2:(atan($2/$1)) with points pt 7 title 'atan(y/x)', \
$Mydata3 using 1:2:(atan2($1,$2)):3 with labels offset 0.5,0.5 font 'arial,14' tc lt 3
# E 0.471404
# F 0.745355
# G 0.707106
# H 0.745355
