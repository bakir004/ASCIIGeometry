#pragma once
#include "Point.h"
#include "RotationMatrix.h"
#include "Utils.h"

Point rotateX(Point point, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    return {point.x, point.y*cosine + point.z*sine, -point.y*sine + point.z*cosine};
}
Point rotateY(Point point, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    return {point.x*cosine + point.z*sine, point.y, -point.x*sine + point.z*cosine};
}
Point rotateZ(Point point, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    return {point.x*cosine + point.y*sine, -point.x*sine + point.y*cosine, point.z};
}
Point rotateOnAll3Axes(Point point, double angleY, double angleX, double angleZ) {
    point = rotateY(point, angleY);
    point = rotateX(point, angleX);
    point = rotateZ(point, angleZ);
    return point;
}
