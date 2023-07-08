#pragma once
#include <vector>
#include "Vector.h"
#include "Point.h"
#include "RotationMatrix.h"
#include "Rotate.h"
typedef std::vector<Point> Points;

Vector calculateSurfaceNormal(Point point, double donutRadius, double angleInDegrees) {
    Point center = rotate(Point(donutRadius, 0, 0), angleInDegrees, AroundYAxis);
    return {point.x - center.x, point.y - center.y, point.z - center.z};
}

Points generateRingOfPointsAroundYAxis(Point origin, int numOfPointsAroundYAxis, double donutRadius) {
    Points points;

    for (int i = 0; i < numOfPointsAroundYAxis; ++i) {
        double angleInDegrees = (double)i*360/numOfPointsAroundYAxis;
        Point newPoint = rotate(origin, angleInDegrees, AroundYAxis);
        newPoint.surfaceNormal = calculateSurfaceNormal(newPoint, donutRadius, angleInDegrees);
        points.push_back(newPoint);
    }

    return points;
}

Points generateRingOfPointsAroundZAxis(
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
        Points ringOfPoints = generateRingOfPointsAroundYAxis(translatedPoint, numOfPointsAroundYAxis, donutRadius);
        points.insert( points.end(), ringOfPoints.begin(), ringOfPoints.end() );
    }

    return points;
}

Points generateDonutPoints(double donutRadius, double donutThicknessRadius) {
    Points points;
    int numOfPointsOnOriginalCircle = 36;
    int numOfPointsAroundYAxis = 36;

    return generateRingOfPointsAroundZAxis(donutRadius, donutThicknessRadius, numOfPointsOnOriginalCircle, numOfPointsAroundYAxis);;
};

void translatePointsAlongZAxis(Points &points, double amount) {
    for (Point & point : points) {
        point = point + Point(0,0,amount);
    }
}

