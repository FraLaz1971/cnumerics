import numpy as np
import matplotlib.pyplot as plt

G = 1
M = 1
mu = 1
h = 1

r = np.linspace(0.1,5,500)
Veff = -G*M/r + h**2/(2*mu*r**2)

plt.figure()
plt.plot(r,Veff)
plt.xlabel("r")
plt.ylabel("V_eff")
plt.title("Effective Potential")
plt.savefig("effective_potential.png")
plt.show()
