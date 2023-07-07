#pragma once
#include <vector>
#include "Point.h"
#include "RotationMatrix.h"
#include "Rotate.h"

std::vector<Point> points;

void generateDonutPoints(double donutRadius, double donutThicknessRadius) {
    Point origin(donutThicknessRadius,0,0);
    int pointsOnOriginalCircle = 36;

    for (int i = 0; i < pointsOnOriginalCircle; ++i) {
        Point newPoint = rotate(origin, (double)i*360/pointsOnOriginalCircle, AroundZAxis);
        points.push_back(newPoint);
    }

    for(Point point : points) {
        point.print();
    }

//    origin.print();
};

