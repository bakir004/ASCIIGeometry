#include <iostream>
#include <vector>
#include "DonutPointGeneration.h"
#include "Point.h"
#include "Rotate.h"

int main() {
    std::vector<Point> points;

    Point point1(0,2,0);
    Point point2(1,3,0);

    Point point3 = point1 + point2;

    generateDonutPoints(5, 2);

    return 0;
}
