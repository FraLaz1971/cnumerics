import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def rotate_vector(v, angle_deg, axis):
    """Simple rotation of a vector around X, Y, or Z axis."""
    rad = np.radians(angle_deg)
    if axis == 'x':
        R = np.array([[1, 0, 0], [0, np.cos(rad), -np.sin(rad)], [0, np.sin(rad), np.cos(rad)]])
    elif axis == 'y':
        R = np.array([[np.cos(rad), 0, np.sin(rad)], [0, 1, 0], [-np.sin(rad), 0, np.cos(rad)]])
    else: # z
        R = np.array([[np.cos(rad), -np.sin(rad), 0], [np.sin(rad), np.cos(rad), 0], [0, 0, 1]])
    return R.dot(v)

# 1. Define original camera boresight (pointing along Z axis)
boresight = np.array([0, 0, 1])

# 2. Simulate a wobble (Nutation)
time = np.linspace(0, 10, 100)
wobble_x = 5 * np.sin(time) # 5 degree wobble in pitch
wobble_y = 5 * np.cos(time) # 5 degree wobble in yaw

points = []
for i in range(len(time)):
    v = rotate_vector(boresight, wobble_x[i], 'x')
    v = rotate_vector(v, wobble_y[i], 'y')
    points.append(v)

points = np.array(points)

# 3. Plotting
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')

# Plot the "Target" center
ax.quiver(0, 0, 0, 0, 0, 1, color='green', label='Ideal Pointing', length=1.2)

# Plot the "Wobbling" path
ax.plot(points[:,0], points[:,1], points[:,2], color='red', label='Satellite Wobble Path')
ax.scatter(points[-1,0], points[-1,1], points[-1,2], color='red')

ax.set_title("Satellite Boresight Wobble (Attitude Error)")
ax.set_xlim([-1, 1]); ax.set_ylim([-1, 1]); ax.set_zlim([0, 1.5])
ax.legend()
plt.show()

