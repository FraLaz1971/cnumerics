import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection

# --- Configurazione Parametri ---
R = 1
theta_deg = 45  # Angolo dall'asse Z
phi_deg = 60    # Angolo dall'asse X sul piano XY
theta = np.radians(theta_deg)
phi = np.radians(phi_deg)

# Coordinate del punto P
rx = R * np.sin(theta) * np.cos(phi)
ry = R * np.sin(theta) * np.sin(phi)
rz = R * np.cos(theta)

fig = plt.figure(figsize=(12, 10))
ax = fig.add_subplot(111, projection='3d')

# 1. Disegno della Sfera (wireframe)
u, v = np.mgrid[0:2*np.pi:30j, 0:np.pi:20j]
xs = R * np.cos(u) * np.sin(v)
ys = R * np.sin(u) * np.sin(v)
zs = R * np.cos(v)
ax.plot_wireframe(xs, ys, zs, color="gray", alpha=0.1, linewidth=0.5)

# 2. Piani di Riferimento
# Piano Equatoriale (XY)
xx, yy = np.meshgrid(np.linspace(-1, 1, 2), np.linspace(-1, 1, 2))
ax.plot_surface(xx, yy, np.zeros_like(xx), alpha=0.1, color='blue') 

# 3. Vettori e Proiezioni
# Raggio principale verso P
ax.plot([0, rx], [0, ry], [0, rz], color='red', linewidth=3, label='Raggio R')
# Proiezione sul piano XY
ax.plot([0, rx], [0, ry], [0, 0], color='blue', linestyle='--', linewidth=2, label='Proiezione XY (R*sinθ)')
# Linea di caduta (altezza Z)
ax.plot([rx, rx], [ry, ry], [0, rz], color='green', linestyle=':', linewidth=2)

# 4. Archi degli Angoli
# Arco per Theta (angolo zenitale)
t_arc = np.linspace(0, theta, 20)
ax.plot(0.3 * np.sin(t_arc) * np.cos(phi), 0.3 * np.sin(t_arc) * np.sin(phi), 0.3 * np.cos(t_arc), color='orange', linewidth=2)
ax.text(0.15 * np.sin(theta/2) * np.cos(phi), 0.15 * np.sin(theta/2) * np.sin(phi), 0.4 * np.cos(theta/2), "θ", fontsize=15, color='orange')

# Arco per Phi (angolo azimutale)
p_arc = np.linspace(0, phi, 20)
ax.plot(0.4 * np.cos(p_arc), 0.4 * np.sin(p_arc), 0, color='purple', linewidth=2)
ax.text(0.5 * np.cos(phi/2), 0.5 * np.sin(phi/2), 0, "φ", fontsize=15, color='purple')

# 5. Etichette Punti
ax.scatter([rx], [ry], [rz], color='red', s=100)
ax.text(rx, ry, rz, f" P({rx:.2f}, {ry:.2f}, {rz:.2f})", color='black', fontweight='bold')

# Impostazioni Assi
ax.set_xlim([-1, 1]); ax.set_ylim([-1, 1]); ax.set_zlim([-1, 1])
ax.set_xlabel('X (cosφ)'); ax.set_ylabel('Y (sinφ)'); ax.set_zlabel('Z (cosθ)')
ax.view_init(elev=25, azim=35) # Angolazione camera ottimale
plt.title(f"Scomposizione Sferica: R={R}, θ={theta_deg}°, φ={phi_deg}°")
plt.legend()

plt.show()

