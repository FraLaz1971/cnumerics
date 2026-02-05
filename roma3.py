# Richiede lo stesso setup iniziale di numpy e math del primo script
import numpy as np
import matplotlib.pyplot as plt

# Valori calcolati in precedenza per Roma -> GEO(0,0)
azimut_deg = 198.3
elevazione_deg = 40.5

azimut_rad = np.radians(azimut_deg)
elevazione_rad = np.radians(elevazione_deg)

# --- Plotting Locale (Azimut ed Elevazione) ---
fig, ax = plt.subplots(figsize=(8, 8), subplot_kw={'projection': 'polar'})

# CORREZIONE 2 & 3: Rappresentazione dell'Azimut con un arco e label
# L'azimut si misura in senso orario dal Nord (0 gradi)
# La convenzione di Matplotlib per i grafici polari è antioraria, quindi aggiustiamo l'angolo
angle_plot = np.radians(90 - azimut_deg) # Converti da [0-360 Clockwise from North] a [0-2pi Anticlockwise from East]

# Disegna la linea di vista proiettata sul piano orizzontale
ax.plot([0, angle_plot], [0, 1], color='red', linewidth=3, label=f'Azimut: {azimut_deg:.1f}° (Sud-Ovest)')

# Disegna l'arco che rappresenta l'angolo
arc_angles = np.linspace(0, angle_plot, 100)
ax.plot(arc_angles, [0.5]*100, color='orange', linestyle='--', linewidth=2)
ax.text(angle_plot/2, 0.6, 'Azimut', rotation=0, ha='center', va='center', color='darkorange', fontweight='bold')


# Impostazioni grafico polare
ax.set_theta_zero_location('N')  # Imposta 0 gradi (Nord) in alto
ax.set_theta_direction(-1)      # Imposta la direzione in senso orario (come l'Azimut reale)
ax.set_title(f'Vista Orizzontale da Roma: Angolo di Azimut\nElevazione: {elevazione_deg:.1f}°', va='bottom')
ax.set_yticks([]) # Nasconde i raggi di distanza, ci interessa solo l'angolo
plt.legend(loc='upper right', bbox_to_anchor=(1.2, 1.1))
plt.show()

