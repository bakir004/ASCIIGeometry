#pragma once
#include <vector>
#include <cmath>
#include <iostream>

class NormalVector {
public:
    double x, y, z;
    double magnitude;

    NormalVector(double x, double y, double z) {
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

class Point {
public:
    double x, y, z;
    NormalVector normalVector = NormalVector(1, 1, 1);

    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() const {
        std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
    }

    Point operator+(const Point &other) const {
        Point result = Point(this->x + other.x, this->y + other.y, this->z + other.z);
        return result;
    }
};