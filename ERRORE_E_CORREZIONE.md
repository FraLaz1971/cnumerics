# ERRORE NELL'IMPLEMENTAZIONE DELL'ANGOLO DI NADIR

## IL PROBLEMA

Il tuo codice originale calcolava:

```c
S1 = H - (rx*cos(Lat)*cos(Lon) + ry*cos(Lat)*sin(Lon) + rz*sin(Lat))
S2 = rx*rx + ry*ry + rz*rz
Gamma = atan(sqrt(S2 - S1*S1) / S1)
```

### Risultato per Baku:
- S1 = 39029.94 km ❌
- S2 = 40566388 km²
- S2 - S1² = **NEGATIVO!** ❌

## LA CAUSA DELL'ERRORE

### Errore 1: Interpretazione sbagliata di S₁
La formula `S1 = H - r⃗·ŝ` che stavi usando proviene probabilmente da una 
fonte che tratta proiezioni cartografiche, NON il calcolo dell'angolo di nadir!

Quella formula calcola una "distanza lungo l'asse nadir" in un contesto di 
proiezione, non l'angolo geometrico reale.

### Errore 2: Ordine di grandezza impossibile
S₁ = 39029 km è **6 volte più grande** del raggio terrestre (6369 km)!

Geometricamente questo è assurdo: S₁ dovrebbe rappresentare una componente 
della geometria satellite-Terra, e non può superare le dimensioni del sistema.

### Errore 3: Formula matematicamente inconsistente
Con S₁ ≈ 39000 km:
```
S₁² ≈ 1.52 × 10⁹ km²
S₂ ≈ 4.06 × 10⁷ km²

S₂ - S₁² ≈ -1.48 × 10⁹ km² < 0  ❌
```

Questo rende √(S₂ - S₁²) un numero immaginario!

## LA SOLUZIONE CORRETTA

### Geometria del Problema

```
        Satellite S (posizione: H dal centro)
           /|
          / | 
         /  |  
      d / y |    
       /    |    
      /     |     
     /	    |	   
    P       |       
  (punto)   |
	    |
            | 
            |
            C
      (centro Terra)
ex.    
    |S-C| = H ≈ 42164 km
    |P-C| = R ≈ 6369 km  
    |S-P| = d ≈ 39422 km

 Calculate nadir angle γ using the law of cosines
 
  In the triangle Satellite-Point-EarthCenter:
    H = distance satellite to Earth center
    R = distance point to Earth center
    d = distance satellite to point
  
  By law of cosines:
    R² = H² + d² - 2·H·d·cos(γ)
  
  Therefore:
    cos(γ) = (H² + d² - R²) / (2·H·d)
    γ = acos((H² + d² - R²) / (2·H·d))

```

### Formula Corretta: Teorema del Coseno

Nel triangolo S-P-C, per il teorema del coseno:

```
R² = H² + d² - 2·H·d·cos(γ)
```

Risolviamo per cos(γ):

```
cos(γ) = (H² + d² - R²) / (2·H·d)
```

Quindi:

```
γ = arccos[(H² + d² - R²) / (2·H·d)]
```

## IMPLEMENTAZIONE CORRETTA

```c
double getGamma(double rx, double ry, double rz) {
  // 1. Distanza punto dal centro Terra
  double R = sqrt(rx*rx + ry*ry + rz*rz);
  
  // 2. Distanza satellite-punto (diretta)
  double dx = Sx - rx;  // Sx, Sy, Sz = coordinate satellite
  double dy = Sy - ry;
  double dz = Sz - rz;
  double d = sqrt(dx*dx + dy*dy + dz*dz);
  
  // 3. Angolo di nadir (teorema del coseno)
  double cos_gamma = (H*H + d*d - R*R) / (2.0 * H * d);
  double gamma = acos(cos_gamma);
  
  return gamma;  // in radianti
}
```

### Coordinate Satellite

Per satellite GEO a (Lat, Lon) = (0°, 0°):

```c
// Converti in radianti
rLat_sat = ddeg2rad(Lat);  // 0° → 0 rad
rLon_sat = ddeg2rad(Lon);  // 0° → 0 rad

// Coordinate cartesiane satellite
Sx = H * cos(rLat_sat) * cos(rLon_sat) = 42164 km
Sy = H * cos(rLat_sat) * sin(rLon_sat) = 0 km
Sz = H * sin(rLat_sat) = 0 km
```

## RISULTATI CORRETTI

### Baku (40.37°N, 49.84°E)
- Coordinate ECEF: (3134.06, 3713.92, 4117.14) km
- Distanza dal centro: R = 6369.17 km
- Distanza da satellite: d = 39421.82 km
- Angolo geocentrico: α = 60.52°
- **Angolo di nadir: γ = 8.086°** ✓

### Roma (41.90°N, 12.51°E)
- Angolo geocentrico: α ≈ 43°
- **Angolo di nadir: γ ≈ 5.6°** ✓

### Lisbona (38.73°N, -9.15°W)
- Angolo geocentrico: α ≈ 39°
- **Angolo di nadir: γ ≈ 5.1°** ✓

### Verifica: Orizzonte Satellite
L'angolo massimo visibile da GEO è:
```
γ_max = arcsin(R/H) = arcsin(6369/42164) ≈ 8.69°
```

Tutti i punti con γ < 8.69° sono visibili ✓

## CONFRONTO TRA FORMULE

### Formula SBAGLIATA (originale):
```
S₁ = H - r⃗·ŝ          [dà valori enormi ~39000 km]
S₂ = |r⃗|²             [≈ 40×10⁶ km²]
γ = arctan(√(S₂-S₁²)/S₁)  [discriminante negativo!]
```

### Formula CORRETTA:
```
R = |r⃗|               [≈ 6369 km]
d = |S⃗ - r⃗|           [≈ 39422 km]
γ = arccos[(H²+d²-R²)/(2·H·d)]  [dà valori sensati 5-8°]
```

## PERCHÉ LA FORMULA ORIGINALE ERA SBAGLIATA?

La formula S₁ = H - r⃗·ŝ probabilmente proviene da:

1. **Proiezioni cartografiche**: In alcune proiezioni (come la proiezione 
   ortografica da satellite), S₁ rappresenta una "coordinata di proiezione", 
   non un angolo geometrico.

2. **Contesto diverso**: Quella formula può essere usata per calcolare 
   coordinate 2D proiettate su un piano, non per calcolare angoli 3D.

3. **Fraintendimento**: La notazione è simile, ma il significato fisico è 
   completamente diverso.

## CONCLUSIONE

L'angolo di nadir γ deve essere calcolato usando la **geometria del triangolo**
satellite-punto-centro, non usando formule di proiezione.

La formula corretta è il **teorema del coseno** applicato a questo triangolo.

## FORMULA ALTERNATIVA (EQUIVALENTE)

Usando il teorema dei seni:

```
sin(γ) / R = sin(α) / d
```

dove α è l'angolo geocentrico tra satellite e punto:

```
cos(α) = (S⃗ · P⃗) / (H · R)
```

Questa formula dà gli stessi risultati e serve come verifica.
