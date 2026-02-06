#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

// Costante per conversione gradi in radianti
const double PI = 3.14159265358979323846;

struct Point3D {
    double x, y, z;
};

struct PointMap {
    double u, v; // Coordinate su mappa piana
};

class Planet {
private:
    std::string name;
    double r_equatorial; // raggio a
    double r_polar;      // raggio b

    double toRadians(double degrees) const {
        return degrees * (PI / 180.0);
    }

public:
    Planet(std::string n, double a, double b) 
        : name(n), r_equatorial(a), r_polar(b) {}

    // 1. Calcolo coordinate Cartesiane 3D
    Point3D getCartesian(double lat, double lon) const {
        double delta = toRadians(lat);
        double lambda = toRadians(lon);

        Point3D p;
        // La proiezione sul piano XY usa il raggio equatoriale (a)
        double d = r_equatorial * cos(delta);
        p.x = d * cos(lambda);
        p.y = d * sin(lambda);
        
        // La coordinata verticale usa il raggio polare (b)
        p.z = r_polar * sin(delta);
        
        return p;
    }

    // 2. Proiezione Ortografica (vista frontale centrata su lon 0)
    // Xmap usa il raggio equatoriale, Ymap usa il raggio polare
    PointMap projectOrthographic(double lat, double lon) const {
        double delta = toRadians(lat);
        double lambda = toRadians(lon);

        PointMap pm;
        pm.u = r_equatorial * cos(delta) * sin(lambda);
        pm.v = r_polar * sin(delta);
        
        return pm;
    }

    void printInfo(double lat, double lon) const {
        Point3D p = getCartesian(lat, lon);
        PointMap m = projectOrthographic(lat, lon);

        std::cout << "--- " << name << " ---" << std::endl;
        std::cout << "Coordinate 3D: X=" << p.x << ", Y=" << p.y << ", Z=" << p.z << std::endl;
        std::cout << "Mappa Ortografica: U(x)=" << m.u << ", V(y)=" << m.v << std::endl;
        std::cout << "---------------------------" << std::endl << std::endl;
    }
};

int main() {
    // Definizione dei pianeti (Raggio Equatoriale, Raggio Polare in km)
    Planet terra("Terra", 6378.1, 6356.8);
    Planet marte("Marte", 3396.2, 3376.2);
    Planet luna("Luna", 1737.4, 1737.4); // Sferica

    // Test Olympus Mons su Marte
    // Lat: 18.65, Lon: 226.2 (o -133.8)
    std::cout << std::fixed << std::setprecision(2);
    marte.printInfo(18.65, 226.2);

    // Test Apollo 11 su Luna
    luna.printInfo(0.67, 23.47);
    // Test Roma on Earth
    terra.printInfo(41.899200,12.511666);
    return 0;
}

