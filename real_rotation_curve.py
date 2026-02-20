import numpy as np
import matplotlib.pyplot as plt

# Physical constants
G = 6.67430e-11            # m^3 kg^-1 s^-2
Msun = 1.989e30           # kg
kpc = 3.086e19            # meters

# Radius range (kpc)
r_kpc = np.linspace(0.5, 30, 500)
r_m = r_kpc * kpc

# -----------------------------
# Case 1: Central mass
# -----------------------------
M0 = 5e10 * Msun
v_kepler = np.sqrt(G * M0 / r_m) / 1000  # km/s

# -----------------------------
# Case 2: Uniform density sphere
# -----------------------------
rho = 5e-21  # kg/m^3 (chosen to give realistic velocities)
M_uniform = (4/3) * np.pi * rho * r_m**3
v_uniform = np.sqrt(G * M_uniform / r_m) / 1000  # km/s

# -----------------------------
# Case 3: Flat rotation curve (dark halo)
# -----------------------------
v0 = 220  # km/s
v_flat = np.ones_like(r_kpc) * v0

# -----------------------------
# Plot
# -----------------------------
plt.figure(figsize=(8,6))

plt.plot(r_kpc, v_kepler, label="Central Mass (Keplerian decline)")
plt.plot(r_kpc, v_uniform, label="Uniform Density (solid body)")
plt.plot(r_kpc, v_flat, label="Dark Matter Halo (flat curve)")

plt.xlabel("Radius (kpc)")
plt.ylabel("Circular Velocity (km/s)")
plt.title("Galaxy Rotation Curves")
plt.legend()
plt.grid(True)

plt.xlim(0, 30)
plt.ylim(0, 350)

plt.savefig("real_rotation_curves.png", dpi=300)
plt.show()
