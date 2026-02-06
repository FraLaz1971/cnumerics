import matplotlib.pyplot as plt
import numpy as np

# Parametri della sfera
r = 1
theta_p = np.pi / 4  # 45 gradi
phi_p = np.pi / 4    # 45 gradi

# Coordinate del punto specifico
rx = r * np.sin(theta_p) * np.cos(phi_p)
ry = r * np.sin(theta_p) * np.sin(phi_p)
rz = r * np.cos(theta_p)

# Creazione della superficie della sfera
u = np.linspace(0, 2 * np.pi, 30)
v = np.linspace(0, np.pi, 30)
x = r * np.outer(np.cos(u), np.sin(v))
y = r * np.outer(np.sin(u), np.sin(v))
z = r * np.outer(np.ones(np.size(u)), np.cos(v))

fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

# Disegno della sfera (trasparente)
ax.plot_surface(x, y, z, color='cyan', alpha=0.3, edgecolor='k', linewidth=0.1)

# Disegno del punto
ax.scatter([rx], [ry], [rz], color='red', s=100, label=f'Punto P({rx:.2f}, {ry:.2f}, {rz:.2f})')

# Assi e etichette
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Punto su superficie sferica')
ax.legend()

plt.show()

