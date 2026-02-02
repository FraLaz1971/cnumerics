# ANGOLO GAMMA DI NADIR - Documentazione Tecnica

## 1. DEFINIZIONE

L'angolo gamma (γ) di nadir misura l'angolo di vista dal satellite verso un punto 
sulla superficie terrestre rispetto alla direzione nadir (verticale locale).

```
        Satellite (S) a quota H dal centro Terra
            │
            │ direzione nadir
            │ (verso centro Terra)
            │
     γ ────>│
           ╱│
          ╱ │
    Punto P │
         │  │
      Centro Terra
```

## 2. COORDINATE E SISTEMI DI RIFERIMENTO

### 2.1 Coordinate Geografiche
- **Latitudine (φ)**: angolo rispetto al piano equatoriale [-90°, +90°]
- **Longitudine (λ)**: angolo rispetto al meridiano di Greenwich [-180°, +180°]

### 2.2 Coordinate Cartesiane (sistema geocentrico)
Per un ellissoide di rivoluzione (WGS84):

```
x = R_eq * cos(φ) * cos(λ)
y = R_eq * cos(φ) * sin(λ)
z = R_p * sin(φ)
```

Dove:
- R_eq = raggio equatoriale (6378.137 km)
- R_p = raggio polare (6356.752 km)
- φ, λ in RADIANTI

### 2.3 Posizione Satellite GEO
Per satellite geostazionario:
- Latitudine: φ_sat = 0° (piano equatoriale)
- Longitudine: λ_sat = variabile (tipicamente 0° per tuo esempio)
- Distanza dal centro Terra: H ≈ 42164 km

## 3. DERIVAZIONE MATEMATICA

### 3.1 Versore Nadir
Il versore nadir (ŝ) punta dal satellite verso il centro Terra:

```
ŝ = (cos(φ_sat)*cos(λ_sat), cos(φ_sat)*sin(λ_sat), sin(φ_sat))
```

Per satellite a φ_sat=0°, λ_sat=0°:
```
ŝ = (1, 0, 0)
```

### 3.2 Vettore Satellite-Punto
```
r⃗ = (x_P, y_P, z_P)  [posizione punto P]
S⃗ = H·ŝ              [posizione satellite]
d⃗ = r⃗ - S⃗           [vettore satellite→punto]
```

### 3.3 Calcolo Angolo γ

Usando geometria vettoriale:

**S₁ = H - r⃗·ŝ** (proiezione sulla direzione nadir)
**S₂ = |r⃗|²** (quadrato distanza punto-centro)

L'angolo γ si ottiene da:
```
tan(γ) = distanza_perpendicolare / distanza_lungo_nadir
       = √(S₂ - S₁²) / S₁
```

Quindi:
```
γ = arctan(√(S₂ - S₁²) / S₁)
```

### 3.4 Interpretazione Geometrica

```
         S (satellite)
         │╲
      S₁ │ ╲ √S₂ (distanza sat-punto)
         │  ╲
         │ γ ╲
         P────┘
      √(S₂-S₁²)
```

## 4. ERRORI NEL CODICE ORIGINALE

### ERRORE 1: Angoli in gradi invece di radianti

**PROBLEMA:**
```c
// Codice originale - SBAGLIATO
double getS1(double rx, double ry, double rz){
  return H-(rx*cos(Lat)*cos(Lon)+...);  // Lat, Lon sono in gradi!
}
```

Le funzioni trigonometriche in C (cos, sin, tan) richiedono argomenti in RADIANTI.
Se Lat=40.366943° e Lon=49.84°:
- cos(40.366943) ≈ -0.64  [interpreta come radianti]
- cos(40.366943°) = cos(0.704 rad) ≈ 0.76  [valore corretto]

**SOLUZIONE:**
```c
// Aggiungi variabili globali
double rLat_sat, rLon_sat;

// Nel main, dopo aver letto Lat e Lon:
rLat_sat = ddeg2rad(Lat);
rLon_sat = ddeg2rad(Lon);

// Nella funzione:
double getS1(double rx, double ry, double rz){
  return H-(rx*cos(rLat_sat)*cos(rLon_sat)+
            ry*cos(rLat_sat)*sin(rLon_sat)+
            rz*sin(rLat_sat));
}
```

### ERRORE 2: Funzione getS3 non necessaria e errata

**PROBLEMA:**
La funzione getS3() calcola |S⃗ - r⃗|² ma:
1. Non è necessaria per calcolare γ
2. Usa ancora Lat/Lon in gradi invece di radianti

**SOLUZIONE:**
Rimuovere la funzione getS3() e il calcolo di S3.

## 5. VALORI ATTESI

Per un satellite GEO a (0°, 0°) che osserva:

### Baku (40.37°N, 49.84°E)
- Distanza angolare: ~61.4°
- γ atteso: ~8.2° - 8.5°

### Roma (41.90°N, 12.51°E)
- Distanza angolare: ~42.8°
- γ atteso: ~5.5° - 5.8°

### Lisbona (38.73°N, -9.15°W)
- Distanza angolare: ~39.4°
- γ atteso: ~5.1° - 5.4°

## 6. VERIFICA RISULTATI

### Test di consistenza:
1. **γ = 0°**: punto sub-satellite (nadir)
2. **γ max ≈ 8.7°**: all'orizzonte del satellite (limite visibilità)
3. **γ cresce**: con distanza angolare dal sub-satellite point

### Formula approssimata (per sfere):
```
sin(γ) ≈ (R_Terra / H) * sin(α)
```
dove α è la distanza angolare geocentrica.

## 7. COMPILAZIONE ED ESECUZIONE

```bash
gcc -o proj_geo_norm proj_geo_norm_fixed.c conversions.c -lm
./proj_geo_norm geonorm001.conf few_capitals.csv
```

Output atteso:
```
#City,Lat(deg),Lon(deg),Gamma(deg),Gamma(rad)
Baku,40.366943,49.840000,8.xxx,0.xxx
Jerusalem,31.776699,35.236946,5.xxx,0.xxx
Rome,41.899200,12.511666,5.xxx,0.xxx
Tallin,59.437222,24.745277,7.xxx,0.xxx
Lisbon,38.728054,-9.150000,5.xxx,0.xxx
```

## 8. RIFERIMENTI

- WGS84 Ellipsoid: NIMA TR8350.2
- Satellite Geometry: "Remote Sensing and Image Interpretation" 
  (Lillesand & Kiefer)
- Geostationary Orbit: https://en.wikipedia.org/wiki/Geostationary_orbit

## 9. NOTE IMPLEMENTATIVE

### Precisione numerica
Per calcoli accurati:
- Usa `double` (non `float`)
- Definisci PI con almeno 15 cifre significative
- Controlla discriminante negativo in √(S₂ - S₁²)

### Casi limite
- S₁ ≤ 0: punto dietro il satellite (non visibile)
- S₂ - S₁² < 0: errore numerico o geometria impossibile
- γ > 8.7°: punto oltre orizzonte satellite

### Ellissoide vs Sfera
L'uso di R_eq e R_p diversi modella correttamente l'ellissoide terrestre.
Per sfera perfetta: R_eq = R_p = 6371 km
