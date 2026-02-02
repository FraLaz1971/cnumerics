#include <stdio.h>
#include <math.h>

/*
 * CORREZIONE FONDAMENTALE:
 * 
 * La formula per l'angolo di nadir γ usa la geometria del triangolo
 * formato da: Satellite (S), Punto (P), Centro Terra (C)
 * 
 * Nel triangolo S-P-C:
 * - |S-C| = H (distanza satellite-centro)
 * - |P-C| = R (distanza punto-centro)  
 * - |S-P| = d (distanza satellite-punto)
 * 
 * L'angolo γ è l'angolo in S tra SC e SP.
 * 
 * Per il teorema del coseno nel triangolo SPC:
 *   d² = H² + R² - 2*H*R*cos(α)
 * 
 * dove α è l'angolo geocentrico tra satellite e punto.
 * 
 * L'angolo γ si calcola con la formula dei seni:
 *   sin(γ) / R = sin(α) / d
 * 
 * OPPURE, più direttamente:
 *   cos(γ) = (H² + d² - R²) / (2*H*d)
 */

int main() {
    double H = 42164.0;  // km - distanza satellite dal centro Terra
    double rx = 3134.061035;  // km
    double ry = 3713.916504;  // km  
    double rz = 4117.144043;  // km
    
    // Satellite at (0,0) -> position (H, 0, 0)
    double Sx = H;
    double Sy = 0.0;
    double Sz = 0.0;
    
    // Distance of point from Earth center
    double R = sqrt(rx*rx + ry*ry + rz*rz);
    
    // Distance satellite to point
    double dx = Sx - rx;
    double dy = Sy - ry;
    double dz = Sz - rz;
    double d = sqrt(dx*dx + dy*dy + dz*dz);
    
    // Geocentric angle between satellite and point
    // cos(alpha) = (S⃗ · P⃗) / (|S⃗| * |P⃗|)
    double dot_product = Sx*rx + Sy*ry + Sz*rz;
    double cos_alpha = dot_product / (H * R);
    double alpha = acos(cos_alpha);
    
    // Nadir angle using law of cosines
    // In triangle S-P-C:
    // R² = H² + d² - 2*H*d*cos(γ)
    // cos(γ) = (H² + d² - R²) / (2*H*d)
    double cos_gamma = (H*H + d*d - R*R) / (2.0 * H * d);
    double gamma_rad = acos(cos_gamma);
    double gamma_deg = gamma_rad * 180.0 / M_PI;
    
    // Alternative: using law of sines
    // sin(γ) / R = sin(α) / d
    double sin_gamma_alt = R * sin(alpha) / d;
    double gamma_rad_alt = asin(sin_gamma_alt);
    double gamma_deg_alt = gamma_rad_alt * 180.0 / M_PI;
    
    printf("=== CORRECTED BAKU CALCULATION ===\n\n");
    
    printf("Point P (Baku):\n");
    printf("  Coordinates: (%.3f, %.3f, %.3f) km\n", rx, ry, rz);
    printf("  Distance from center: R = %.3f km\n\n", R);
    
    printf("Satellite S:\n");
    printf("  Coordinates: (%.1f, %.1f, %.1f) km\n", Sx, Sy, Sz);
    printf("  Distance from center: H = %.3f km\n\n", H);
    
    printf("Distances:\n");
    printf("  Satellite to point: d = %.3f km\n", d);
    printf("  Geocentric angle: α = %.6f rad = %.3f°\n\n", alpha, alpha*180/M_PI);
    
    printf("Nadir angle (law of cosines):\n");
    printf("  cos(γ) = %.6f\n", cos_gamma);
    printf("  γ = %.6f rad\n", gamma_rad);
    printf("  γ = %.3f°\n\n", gamma_deg);
    
    printf("Nadir angle (law of sines - verification):\n");
    printf("  sin(γ) = %.6f\n", sin_gamma_alt);
    printf("  γ = %.6f rad\n", gamma_rad_alt);
    printf("  γ = %.3f°\n\n", gamma_deg_alt);
    
    // Check if point is visible (γ < ~8.7°)
    double max_gamma = asin(R / H);
    printf("Maximum nadir angle (horizon): %.3f°\n", max_gamma*180/M_PI);
    if (gamma_deg < max_gamma*180/M_PI) {
        printf("Point is VISIBLE from satellite ✓\n");
    } else {
        printf("Point is BEYOND HORIZON ✗\n");
    }
    
    return 0;
}
