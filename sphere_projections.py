import numpy as np
import matplotlib.pyplot as plt

# Parametri della sfera e del punto
R = 1
theta = np.radians(45)  # Angolo dall'asse Z (colatitudine)
phi = np.radians(60)    # Angolo sul piano XY (longitudine)

# Coordinate del punto P
rx = R * np.sin(theta) * np.cos(phi)
ry = R * np.sin(theta) * np.sin(phi)
rz = R * np.cos(theta)

# Creazione del grafico
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Disegno della sfera (wireframe leggero)
u, v = np.mgrid[0:2*np.pi:30j, 0:np.pi:20j]
x_sphere = R * np.cos(u) * np.sin(v)
y_sphere = R * np.sin(u) * np.sin(v)
z_sphere = R * np.cos(v)
ax.plot_wireframe(x_sphere, y_sphere, z_sphere, color="lightgrey", alpha=0.3, linewidth=0.5)

# 1. Raggio (0,0,0) -> P
ax.plot([0, rx], [0, ry], [0, rz], color='red', label='Raggio R', linewidth=2)
ax.scatter([rx], [ry], [rz], color='red', s=50)

# 2. Proiezione sul piano XY (R*sin(theta))
ax.plot([0, rx], [0, ry], [0, 0], color='blue', linestyle='--', label='Proiezione piano XY ($R \sin\\theta$)')

# 3. Linea verticale da P al piano XY (R*cos(theta))
ax.plot([rx, rx], [ry, ry], [0, rz], color='green', linestyle='--', label='Altezza ($R \cos\\theta$)')

# 4. Assi e etichette
ax.set_xlabel('Asse X')
ax.set_ylabel('Asse Y')
ax.set_zlabel('Asse Z')
ax.set_title(f'Proiezione del Punto P\n$\theta={np.degrees(theta):.0f}^\circ, \phi={np.degrees(phi):.0f}^\circ$')
ax.legend()

# Impostazione limiti uguali per non deformare la sfera
max_range = R
ax.set_xlim(-max_range, max_range)
ax.set_ylim(-max_range, max_range)
ax.set_zlim(-max_range, max_range)

plt.show()

