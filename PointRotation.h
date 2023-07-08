#pragma once

#include "DonutPointGeneration.h"

Points rotatePoints(const Points& points) {
    Points rotatedPoints;
    for(Point point : points) {
        Point newPoint = rotate(point, 5, AroundXAxis);
//        newPoint = rotate(newPoint, 5, AroundZAxis);
        rotatedPoints.push_back(newPoint);
    }
    return rotatedPoints;
}