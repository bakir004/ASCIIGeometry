#pragma once
#include <cmath>

double round(double value, int numOfDecimals) {
    return std::round(value * pow(10, numOfDecimals)) / pow(10, numOfDecimals);
}

void printPoints(const std::vector<Point>& points) {
    std::cout << "Points: " << std::endl;
    for(Point point : points) {
        point.print();
    }
}

double distance(Point a, Point b) {
    return sqrt(pow((a.x-b.x),2) + pow((a.y-b.y),2));
}

double dot(Vector a, Vector b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

char getLuminance(double dotProductResult) {
    std::string luminance = ".,-~:;=!*#$@";
    dotProductResult += 1;
    dotProductResult *= 6;
    if(dotProductResult == 12) dotProductResult = 11;
    int index = floor(dotProductResult);

    return luminance[index];
}