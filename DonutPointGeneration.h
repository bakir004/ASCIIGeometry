#pragma once
#include <vector>
#include "Point.h"
#include "RotationMatrix.h"
#include "Rotate.h"
typedef std::vector<Point> Points;

Points generateRingOfPointsAroundYAxis(Point origin, int numOfPointsAroundYAxis) {

}

Points generatePointsAroundCenterOfDonutSlice(
        double donutRadius,
        double donutThicknessRadius,
        int numOfPointsOnOriginalCircle,
        int numOfPointsAroundYAxis
    ) {
    Point origin(donutThicknessRadius,0,0);

    Points points;
    for (int i = 0; i < numOfPointsOnOriginalCircle; ++i) {
        Point newPoint = rotate(origin, (double)i*360/numOfPointsOnOriginalCircle, AroundZAxis);
        Point translatedPoint = newPoint + Point(donutRadius, 0, 0);
        Points ringOfPoints = generateRingOfPointsAroundYAxis(translatedPoint, numOfPointsAroundYAxis);
        points.push_back(newPoint);
    }
}

Points generateDonutPoints(double donutRadius, double donutThicknessRadius) {
    Points points;
    int numOfPointsOnOriginalCircle = 36;
    int numOfPointsAroundYAxis = 36;

    points = generatePointsAroundCenterOfDonutSlice(donutRadius, donutThicknessRadius, numOfPointsOnOriginalCircle, numOfPointsAroundYAxis);

    for(Point point : points) {
        point.print();
    }

    return points;
};

