#pragma once
#include "Point.h"
#include "RotationMatrix.h"
#include "Utils.h"

typedef std::vector<double> ColumnVector;

Point rotate(Point point, double angleAmountInDegrees, RotationAxisType type) {
    RotationMatrix rotationMatrix = RotationMatrix(angleAmountInDegrees, type);
    ColumnVector pointColumnVector = { point.x, point.y, point.z };
    ColumnVector rotatedPointColumnVector(3, 0);
    for (int i = 0; i < 3; ++i) {
        double sum = 0;
        for (int j = 0; j < 3; ++j)
            sum += rotationMatrix.matrix[i][j] * pointColumnVector[j];

        double roundedSum = round(sum, 6);

        rotatedPointColumnVector[i] = roundedSum == 0 ? std::abs(roundedSum) : roundedSum;
    }
    return point = {rotatedPointColumnVector[0], rotatedPointColumnVector[1], rotatedPointColumnVector[2]};
};
