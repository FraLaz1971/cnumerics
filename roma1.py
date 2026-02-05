import numpy as np
import matplotlib.pyplot as plt

# Valori calcolati per Roma -> GEO(0,0)
azimut_deg = 198.3
elevazione_deg = 40.5

azimut_rad = np.radians(azimut_deg)

# --- Plotting Locale (Azimut ed Elevazione) ---
fig, ax = plt.subplots(figsize=(8, 8), subplot_kw={'projection': 'polar'})

# --- IMPOSTAZIONI CHIAVE PER LA CONVENZIONE AZIMUT ---
ax.set_theta_zero_location('N')  # Imposta 0 gradi (Nord) in alto
ax.set_theta_direction(-1)      # Imposta la direzione in senso orario (come l'Azimut reale)

# --- DISEGNO CORRETTO DELLA LINEA E DELL'ARCO ---

# Disegna la linea di vista (direzione del satellite) esattamente a 198.3°
# Il grafico polare ora usa direttamente i radianti dell'azimut grazie alle impostazioni sopra
ax.plot([0, azimut_rad], [0, 1], color='red', linewidth=3, label=f'Azimut: {azimut_deg:.1f}° (Sud-Ovest)')

# Disegna l'arco che rappresenta l'angolo, dal Nord (0 rad) fino all'azimut_rad
# L'ampiezza dell'arco è corretta ora
arc_angles = np.linspace(0, azimut_rad, 100)
# '0.5' definisce il raggio dell'arco disegnato
ax.plot(arc_angles, [0.5]*100, color='orange', linestyle='--', linewidth=2)
ax.text(azimut_rad/2, 0.55, 'Azimut', rotation=0, ha='center', va='center', color='darkorange', fontweight='bold')


# Impostazioni generali del grafico
ax.set_title(f'Vista Orizzontale da Roma: Angolo di Azimut\nElevazione: {elevazione_deg:.1f}°', va='bottom')
ax.set_yticks([]) # Nasconde i raggi di distanza, ci interessa solo l'angolo

# Aggiunge etichette per i punti cardinali e i 45 gradi
ax.set_xticks(np.radians([0, 45, 90, 135, 180, 225, 270, 315]))
ax.set_xticklabels(['NORD 360°', '45°', 'EST 90°', '135°', 'SUD 180°', '225°', 'OVEST 270°', '315°'])

plt.legend(loc='upper right', bbox_to_anchor=(1.2, 1.1))
plt.show()

