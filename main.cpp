#include <vector>
#include <unistd.h>
#include "DonutPointGeneration.h"
#include "Rotate.h"
#include "Projection.h"
#include "PointRotation.h"

int main() {
    double donutRadius = 5, donutThicknessRadius = 2;
    Vector lightSourceVector = Vector(1,0,-1);

    Points points = generateDonutPoints(donutRadius, donutThicknessRadius);

    translatePointsAlongZAxis(points, -10);

    double distanceFromViewer = 10;
    int screenWidthInCharacters = 40;
    int screenHeightInCharacters = 20;

    std::vector<Points> screenPointsMatrix(screenHeightInCharacters, Points(screenWidthInCharacters, Point(0,0,0)));

    double startingX = -donutRadius - donutThicknessRadius - 1, startingY = donutRadius + donutThicknessRadius + 1;
    double pixelWidth = -startingX*2/screenWidthInCharacters;
    double pixelHeight = -startingY*2/screenHeightInCharacters;


    while(true) {
        system("cls");

        points = rotatePoints(points);
        Points projectedPoints = projectToXYPlane(points, distanceFromViewer);

        for (int i = 0; i < screenPointsMatrix.size(); ++i) {
            for (int j = 0; j < screenPointsMatrix[i].size(); ++j) {
                double pixelX = startingX + j * pixelWidth;
                double pixelY = startingY + i * pixelHeight;
                screenPointsMatrix[i][j] = Point(pixelX, pixelY, 0);

                Points pointsInCorrespondingPixel;
                for(Point point : projectedPoints) {
                    if(distance(screenPointsMatrix[i][j], point) < pixelWidth/2) {
                        pointsInCorrespondingPixel.push_back(point);
                    }
                }
                if(pointsInCorrespondingPixel.empty()) {
                    std::cout << " ";
                    continue;
                }
                Vector closestPointSurfaceNormal = Vector(0,0,1);
                for(Point point : pointsInCorrespondingPixel) {
                    double minDistance = 9999;
                    if(distance(screenPointsMatrix[i][j], point) < minDistance) {
                        minDistance = distance(screenPointsMatrix[i][j], point);
                        closestPointSurfaceNormal = point.surfaceNormal;
                    }
                }
                std::cout << getLuminance(dot(closestPointSurfaceNormal, lightSourceVector));
            }
            std::cout << std::endl;
        }
        usleep(50000);
    }
}
