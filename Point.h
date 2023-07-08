#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include "Vector.h"


class Point {
public:
    double x, y, z;
    Vector surfaceNormal = Vector(1, 1, 1);

    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() const {
        std::cout << "(" << this->x << ", " << this->y << ", " << this->z << "), V: " << "(" << this->surfaceNormal.x << ", " << this->surfaceNormal.y << ", " << this->surfaceNormal.z << ")" << std::endl;
    }

    Point operator+(const Point &other) const {
        Point result = Point(this->x + other.x, this->y + other.y, this->z + other.z);
        return result;
    }
};