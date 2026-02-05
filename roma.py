import numpy as np
import matplotlib.pyplot as plt

# Coordinate
lat_roma = np.radians(41.92)
lon_roma = np.radians(12.45)
r_terra = 6371
r_geo = 42164

# Posizione Roma (XYZ)
x_r = r_terra * np.cos(lat_roma) * np.cos(lon_roma)
y_r = r_terra * np.cos(lat_roma) * np.sin(lon_roma)
z_r = r_terra * np.sin(lat_roma)

# Posizione Satellite (0,0) GEO
x_s = r_geo * np.cos(0) * np.cos(0)
y_s = 0
z_s = 0

# Plotting
fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

# Disegna Terra (semplificata)
u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
ax.plot_wireframe(r_terra*np.cos(u)*np.sin(v), r_terra*np.sin(u)*np.sin(v), r_terra*np.cos(v), color="lightblue", alpha=0.3)

# Vettore Roma-Satellite
ax.plot([x_r, x_s], [y_r, y_s], [z_r, z_s], color='red', label='Linea di Vista (LOS)', linewidth=2)
ax.scatter([x_r], [y_r], [z_r], color='blue', s=50, label='Roma')
ax.scatter([x_s], [y_s], [z_s], color='green', s=50, label='Satellite (0,0)')

ax.set_xlabel('X (km)')
ax.set_ylabel('Y (km)')
ax.set_zlabel('Z (km)')
plt.legend()
plt.show()

