#include <vector>
#include "DonutPointGeneration.h"
#include "Rotate.h"
#include "Projection.h"

int main() {

    Points points = generateDonutPoints(5, 2);

    translatePointsAlongZAxis(points, -10);

    double distanceFromViewer = 7;
    int screenWidthInCharacters = 120;
    int screenHeightInCharacters = 30;

    Points projectedPoints = projectToXYPlane(points, distanceFromViewer);

//    printPoints(projectedPoints);

    std::vector<Points> screenPointsMatrix(30, Points(30, Point(0,0,0)));

    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {

        }
    }


    Points pointsProjectedToScreen;

    return 0;
}
