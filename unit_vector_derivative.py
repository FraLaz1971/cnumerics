import numpy as np
import matplotlib.pyplot as plt

# Parameters
omega = 1.0        # angular velocity
t = 1.0            # time
theta = omega * t  # angle

# Unit vectors
r_hat = np.array([np.cos(theta), np.sin(theta)])
theta_hat = np.array([-np.sin(theta), np.cos(theta)])

# Derivative of r_hat
dr_hat_dt = omega * theta_hat

# Create figure
plt.figure(figsize=(7,7))

# Draw unit circle
angles = np.linspace(0, 2*np.pi, 500)
plt.plot(np.cos(angles), np.sin(angles), linestyle='--')

# Draw coordinate axes
plt.axhline(0)
plt.axvline(0)

# Draw vectors
plt.quiver(0,0,r_hat[0],r_hat[1], angles='xy', scale_units='xy', scale=1)
plt.quiver(0,0,theta_hat[0],theta_hat[1], angles='xy', scale_units='xy', scale=1)
plt.quiver(r_hat[0],r_hat[1],
           dr_hat_dt[0],dr_hat_dt[1],
           angles='xy', scale_units='xy', scale=1)

# Labels for vectors
plt.text(r_hat[0]*1.1, r_hat[1]*1.1, r'$\hat{\mathbf{r}}$', fontsize=14)
plt.text(theta_hat[0]*1.1, theta_hat[1]*1.1,
         r'$\hat{\mathbf{\theta}}$', fontsize=14)

plt.text(r_hat[0] + dr_hat_dt[0]*0.8,
         r_hat[1] + dr_hat_dt[1]*0.9,
         r'$\dot{\hat{\mathbf{r}}} = \dot{\theta}\,\hat{\mathbf{\theta}}$',
         fontsize=12)

# Draw angle arc
arc_angles = np.linspace(0, theta, 100)
arc_radius = 0.4
plt.plot(arc_radius*np.cos(arc_angles),
         arc_radius*np.sin(arc_angles))

# Angle label
mid_angle = theta/2
plt.text(arc_radius*np.cos(mid_angle)*1.2,
         arc_radius*np.sin(mid_angle)*1.2,
         r'$\theta$', fontsize=14)

# Add angular velocity label
plt.text(-1.2,1.2,r'$\dot{\theta}$ = angular velocity', fontsize=11)

# Formatting
plt.gca().set_aspect('equal')
plt.xlim(-1.5,1.5)
plt.ylim(-1.5,1.5)
plt.title("Time Derivative of Radial Unit Vector")

plt.savefig("unit_vector_derivative.png", dpi=300)
plt.show()
