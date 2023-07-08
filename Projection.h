#pragma once

Points projectToXYPlane(const Points& points, double distanceFromViewer) {
    Points projectedPoints;
    for(Point point : points) {
        double projectedX = -distanceFromViewer * point.x/point.z;
        double projectedY = -distanceFromViewer * point.y/point.z;

//        std::cout << "(" << point.x << ", " << point.y << ", " << point.z << ") projected to (" << projectedX << ", " << projectedY << ", " << 0 << ")" << std::endl;

        projectedPoints.emplace_back(projectedX, projectedY, 0);
    }
    return projectedPoints;
}
