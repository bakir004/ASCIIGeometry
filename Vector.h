#pragma once
#include <cmath>
#include <vector>

class Vector {
public:
    double x, y, z;
    double magnitude;

    Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->magnitude = sqrt(x*x+y*y+z*z);
    }
    [[nodiscard]] Vector normalize() const {
        return {this->x/this->magnitude,this->y/this->magnitude,this->z/this->magnitude};
    }
};

typedef std::vector<Vector> Vectors;
