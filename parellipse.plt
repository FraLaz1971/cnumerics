# 1. Environment configuration
set parametric
set size ratio -1
set grid
# 2. Shape Parameters definition (e.g.: a=5, b=3)
a = 5
b = 3
# 3. Set the interval of the t parameter (from 0 to 2*pi for a complete loop)
set trange [0:2*pi]
# 4. Plot the ellipse
plot a*cos(t), b*sin(t) title "Parametric Ellipse"
