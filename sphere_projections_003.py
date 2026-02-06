import numpy as np
import matplotlib.pyplot as plt

# --- Configurazione Parametri ---
R = 1
theta_deg = 45  # Angolo dall'asse Z (Zenit)
phi_deg = 60    # Angolo dall'asse X (Azimut)
theta = np.radians(theta_deg)
phi = np.radians(phi_deg)

# Coordinate del punto P
rx = R * np.sin(theta) * np.cos(phi)
ry = R * np.sin(theta) * np.sin(phi)
rz = R * np.cos(theta)

fig = plt.figure(figsize=(12, 10))
ax = fig.add_subplot(111, projection='3d')

# 1. Disegno della Sfera (wireframe leggero)
u, v = np.mgrid[0:2*np.pi:30j, 0:np.pi:20j]
xs = R * np.cos(u) * np.sin(v)
ys = R * np.sin(u) * np.sin(v)
zs = R * np.cos(v)
ax.plot_wireframe(xs, ys, zs, color="gray", alpha=0.05, linewidth=0.5)

# 2. Disegno degli Assi X, Y, Z (rette nere che passano per l'origine)
ax.plot([-1.2, 1.2], [0, 0], [0, 0], color='black', linewidth=1, alpha=0.7) # Asse X
ax.plot([0, 0], [-1.2, 1.2], [0, 0], color='black', linewidth=1, alpha=0.7) # Asse Y
ax.plot([0, 0], [0, 0], [-1.2, 1.2], color='black', linewidth=1, alpha=0.7) # Asse Z

# 3. Piani in trasparenza
# Piano Equatoriale (XY) - Blu
xx, yy = np.meshgrid(np.linspace(-1, 1, 2), np.linspace(-1, 1, 2))
ax.plot_surface(xx, yy, np.zeros_like(xx), alpha=0.1, color='cyan') 

# Piano Meridiano (Verticale passante per P) - Giallo/Arancio
# Definiamo i 4 vertici del piano che congiunge l'asse Z al raggio di P
z_val = np.linspace(0, 1.1, 2)
r_val = np.linspace(0, 1.1, 2)
rv, zv = np.meshgrid(r_val, z_val)
px = rv * np.cos(phi)
py = rv * np.sin(phi)
ax.plot_surface(px, py, zv, alpha=0.15, color='orange')

# 4. Vettori e Proiezioni
ax.plot([0, rx], [0, ry], [0, rz], color='red', linewidth=3, label='Raggio R (Ipotenusa)')
ax.plot([0, rx], [0, ry], [0, 0], color='blue', linestyle='--', linewidth=2, label='R*sin(θ) (Proiezione XY)')
ax.plot([0, 0], [0, 0], [0, rz], color='green', linewidth=3, label='R*cos(θ) (Quota Z)')
# Linea tratteggiata di chiusura rettangolo verticale
ax.plot([0, rx], [0, ry], [rz, rz], color='green', linestyle=':', alpha=0.5)
ax.plot([rx, rx], [ry, ry], [0, rz], color='black', linestyle=':', alpha=0.5)

# 5. Archi e Angoli
t_arc = np.linspace(0, theta, 20)
ax.plot(0.3 * np.sin(t_arc) * np.cos(phi), 0.3 * np.sin(t_arc) * np.sin(phi), 0.3 * np.cos(t_arc), color='orange', linewidth=2)
ax.text(0.15, 0.15, 0.4, "θ", fontsize=14, color='orange', fontweight='bold')

p_arc = np.linspace(0, phi, 20)
ax.plot(0.4 * np.cos(p_arc), 0.4 * np.sin(p_arc), 0, color='purple', linewidth=2)
ax.text(0.5 * np.cos(phi/2), 0.5 * np.sin(phi/2), 0, "φ", fontsize=14, color='purple', fontweight='bold')

# 6. Dettagli finali
ax.scatter([rx], [ry], [rz], color='red', s=100)
ax.set_xlim([-1.1, 1.1]); ax.set_ylim([-1.1, 1.1]); ax.set_zlim([-1.1, 1.1])
ax.view_init(elev=20, azim=40)
ax.set_title(f"Scomposizione Vettoriale 3D\nZ = R·cos(θ)  |  Proiez_xy = R·sin(θ)")
ax.legend(loc='upper left')

plt.show()

