import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# --- Parametri ---
lat_roma_deg = 41.92
lon_roma_deg = 12.45
r_terra = 6371 # km
r_geo = 42164 # km (distanza centro Terra-satellite GEO)

lat_roma = np.radians(lat_roma_deg)
lon_roma = np.radians(lon_roma_deg)

# --- Calcolo Coordinate XYZ ---
# Posizione Roma (XYZ in sistema cartesiano globale)
x_r = r_terra * np.cos(lat_roma) * np.cos(lon_roma)
y_r = r_terra * np.cos(lat_roma) * np.sin(lon_roma)
z_r = r_terra * np.sin(lat_roma)

# Posizione Satellite (0,0) GEO
x_s = r_geo * np.cos(0) * np.cos(0)
y_s = 0
z_s = 0

# --- Plotting Globale ---
fig = plt.figure(figsize=(10, 10))
ax = fig.add_subplot(111, projection='3d')

# CORREZIONE 1: Forza un rapporto 1:1:1 per gli assi per avere una sfera reale
ax.set_box_aspect([1, 1, 1]) 

# Imposta limiti uguali per tutti gli assi per mantenere l'aspetto sferico
max_range = r_terra * 1.1 # Un po' di margine intorno alla Terra
ax.set_xlim([-max_range, max_range])
ax.set_ylim([-max_range, max_range])
ax.set_zlim([-max_range, max_range])


# Disegna Terra (sfera)
u = np.linspace(0, 2 * np.pi, 50)
v = np.linspace(0, np.pi, 50)
X = r_terra * np.outer(np.cos(u), np.sin(v))
Y = r_terra * np.outer(np.sin(u), np.sin(v))
Z = r_terra * np.outer(np.ones(np.size(u)), np.cos(v))
ax.plot_surface(X, Y, Z, color='lightblue', alpha=0.6, rstride=3, cstride=3)

# Vettore Roma-Satellite (LOS)
ax.plot([x_r, x_s], [y_r, y_s], [z_r, z_s], color='red', label='Linea di Vista (LOS)', linewidth=2)
ax.scatter([x_r], [y_r], [z_r], color='blue', s=100, label='Roma (Osservatore)')
ax.scatter([x_s], [y_s], [z_s], color='green', s=100, label='Satellite GEO (0,0)')

ax.set_xlabel('X (km - asse Greenwich)')
ax.set_ylabel('Y (km - asse 90E)')
ax.set_zlabel('Z (km - asse Polo Nord)')
ax.set_title('Geometria Satellite GEO-Terra con proporzioni corrette')
plt.legend()
plt.show()

