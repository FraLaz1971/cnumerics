import numpy as np
import matplotlib.pyplot as plt

r = np.linspace(0.1, 10, 500)
v = np.ones_like(r)

plt.figure()
plt.plot(r, v)
plt.xlabel("r")
plt.ylabel("v")
plt.title("Flat Galaxy Rotation Curve")
plt.savefig("rotation_curve.png")
plt.show()
