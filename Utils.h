#pragma once
#include <cmath>

double round(double value, int numOfDecimals) {
    return std::round(value * pow(10, numOfDecimals)) / pow(10, numOfDecimals);
}

double dot(Vector a, Vector b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

void printPoints(const Points& points){
    for(Point point : points) {
        point.print();
    }
}