import numpy as np
import matplotlib.pyplot as plt

a = 1
e = 0.7
theta = np.linspace(0, 2*np.pi, 1000)
r = a*(1-e**2)/(1+e*np.cos(theta))

x = r*np.cos(theta)
y = r*np.sin(theta)

plt.figure()
plt.plot(x,y)
plt.scatter(0,0)
plt.gca().set_aspect('equal')
plt.title('Elliptical Orbit')
plt.savefig("elliptical_orbit.png")
plt.show()
