import numpy as np
import matplotlib.pyplot as plt

# --- Load observational data ---
# Assume file "mw_rotation_data.csv" with columns r_kpc, v_obs, v_err
data = np.genfromtxt("milky_way_rotation_mock.dat", delimiter="", names=True)
r_obs = data['r_kpc']
v_obs = data['v_obs']
v_err = data['v_err']

# --- Model curves (as in your previous script) ---
# Constants
G = 6.67430e-11
Msun = 1.989e30
kpc = 3.086e19

# Model radii
r_model = np.linspace(0.5,30,500)
r_m = r_model * kpc

# Keplerian
M0 = 5e10 * Msun
v_kepler = np.sqrt(G * M0 / r_m) / 1000  # km/s

# Uniform
rho = 5e-21
M_uniform = (4/3)*np.pi*rho*r_m**3
v_uniform = np.sqrt(G * M_uniform / r_m) / 1000

# Flat
v0 = 220
v_flat = np.ones_like(r_model) * v0

# --- Plot ---
plt.figure(figsize=(8,6))

# Observational data
plt.errorbar(r_obs, v_obs, yerr=v_err, fmt='o', markersize=4, alpha=0.7, label="Observed")

# Models
plt.plot(r_model, v_kepler, label="Keplerian")
plt.plot(r_model, v_uniform, label="Uniform")
plt.plot(r_model, v_flat, label="Flat")

plt.xlabel("Galactocentric radius (kpc)")
plt.ylabel("Rotation speed (km/s)")
plt.title("Milky Way Rotation Curve: Observations vs Models")
plt.legend()
plt.grid(True)
plt.xlim(0,30)
plt.ylim(0,300)

plt.show()
