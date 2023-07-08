#pragma once
#include <cmath>

class Vector {
public:
    double x, y, z;
    double magnitude;

    Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->magnitude = sqrt(x*x+y*y+z*z);
        normalize();
    }
private:
    void normalize() {
        this->x = this->x/magnitude;
        this->y = this->y/magnitude;
        this->z = this->z/magnitude;
    }
};
