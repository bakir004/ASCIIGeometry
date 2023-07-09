#pragma once

#include "Vector.h"
#include "Point.h"
#include "Rotate.h"

#define PI 3.14159265
double cubeSideLength = 5;
double distanceFromViewer = 12;
double pointSpacing = 0.15;
int screenWidthInPixels = 30;
int screenHeightInPixels = 25;
double distanceOfScreenFromViewer = 3;

Vector lightSourceVector = Vector(0,-1,-0.5).normalize();

void render(double angleX, double angleY, double angleZ) {
    std::vector<std::vector<double>> zDistances(screenHeightInPixels, std::vector<double>(screenWidthInPixels, 0));
    std::vector<std::vector<char>> screen(screenHeightInPixels, std::vector<char>(screenWidthInPixels, ' '));

    for(double i = -cubeSideLength; i < cubeSideLength; i += pointSpacing) {
        for(double j = -cubeSideLength; j < cubeSideLength; j += pointSpacing) {
            Points points;
            points.emplace_back(i, j, -cubeSideLength);
            points.emplace_back(i, j, cubeSideLength);
            points.emplace_back(-cubeSideLength, i, j);
            points.emplace_back(cubeSideLength, i, j);
            points.emplace_back(i, -cubeSideLength, j);
            points.emplace_back(i, cubeSideLength, j);
            Vectors luminances = {
                    Vector(0,0,-1),
                    Vector(0,0,1),
                    Vector(-1,0,0),
                    Vector(1,0,0),
                    Vector(0,-1,0),
                    Vector(0,1,0),
            };
            for(int k = 0; k < 6; k++) {
                Point current = points[k];
                Point finalPoint = rotateOnAll3Axes(current, angleX, angleY, angleZ) + Point(0,0,distanceFromViewer);
                double ooz = 1 / finalPoint.z;
//                int projectedX = (int) (screenWidthInPixels / 2 + finalPoint.x * distanceOfScreenFromViewer * ooz);
//                int projectedY = (int) (screenHeightInPixels / 2 - finalPoint.y * distanceOfScreenFromViewer * ooz);
                int projectedX = (int)(screenWidthInPixels / 2 + finalPoint.x);
                int projectedY = (int)(screenWidthInPixels / 2 + finalPoint.y);

                Point luminance = Point(luminances[k].x,luminances[k].y,luminances[k].z);
                luminance = rotateOnAll3Axes(luminance, angleX, angleY, angleZ);
                Vector luminanceVector = Vector(luminance.x, luminance.y, luminance.z).normalize();
                double luminanceProduct = dot(luminanceVector, lightSourceVector)+1;
                if (luminanceProduct > 0) {
                    if (ooz > zDistances[projectedY][projectedX]) {
                        int luminanceIndex = (luminanceProduct * 6);
                        if(luminanceIndex == 12) luminanceIndex = 11;
                        zDistances[projectedY][projectedX] = ooz;
                        screen[projectedY][projectedX] = ".,-~:;=!*#$@"[luminanceIndex];
                    }
                }
            }
        }
    }

    system("cls");
    for (int i = 0; i < screenHeightInPixels; i++) {
        for (int j = 0; j < screenWidthInPixels; j++) {
            std::cout << screen[i][j];
        }
        putchar('\n');
    }
}

void Cube() {
    double X = 0, Y = 0, Z = 0;
    double xIncrement=0.05, yIncrement=0.03, zIncrement=0.1;
    while(true) {
        render(X,Y,Z);
        X += xIncrement;
        Y += yIncrement;
        Z += zIncrement;
    }
}