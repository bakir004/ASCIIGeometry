#pragma once
#include <cmath>
typedef std::vector<double> ColumnVector;

double round(double value, int numOfDecimals) {
    return std::round(value * pow(10, numOfDecimals)) / pow(10, numOfDecimals);
}