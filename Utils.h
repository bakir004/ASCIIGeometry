#pragma once
#include <cmath>
typedef std::vector<double> ColumnVector;

double round(double value, int numOfDecimals) {
    return std::round(value * pow(10, numOfDecimals)) / pow(10, numOfDecimals);
}

void printPoints(const std::vector<Point>& points) {
    std::cout << "Points: " << std::endl;
    for(Point point : points) {
        point.print();
    }
}