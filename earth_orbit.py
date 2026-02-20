import numpy as np
import matplotlib.pyplot as plt

r = 1.0
theta = np.linspace(0, 2*np.pi, 500)

x = r*np.cos(theta)
y = r*np.sin(theta)

plt.figure()
plt.plot(x, y)
plt.scatter(0,0)
plt.gca().set_aspect('equal')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Circular Orbit')
plt.savefig("earth_orbit.png")
plt.show()
