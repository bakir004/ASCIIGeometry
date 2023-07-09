#pragma once
#include "Point.h"
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
Point rotateOnAll3Axes(Point point, double angleX, double angleY, double angleZ) {
    point = rotateY(point, angleY);
    point = rotateX(point, angleX);
    point = rotateZ(point, angleZ);
    return point;
}

Vector rotateX(Vector point, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    return {point.x, point.y*cosine + point.z*sine, -point.y*sine + point.z*cosine};
}
Vector rotateY(Vector point, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    return {point.x*cosine + point.z*sine, point.y, -point.x*sine + point.z*cosine};
}
Vector rotateZ(Vector point, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    return {point.x*cosine + point.y*sine, -point.x*sine + point.y*cosine, point.z};
}
Vector rotateOnAll3Axes(Vector point, double angleX, double angleY, double angleZ) {
    point = rotateY(point, angleY);
    point = rotateX(point, angleX);
    point = rotateZ(point, angleZ);
    return point;
}
