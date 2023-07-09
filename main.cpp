#include <vector>
#include <unistd.h>
#include <cmath>
#include <iostream>

#define PI 3.14159265
double alphaSpacing = 0.07, betaSpacing = 0.02;
double donutRadius = 2.5, donutThicknessRadius = 1;
double distanceOfDonutFromViewer = 6;
int screenWidthInPixels = 30;
int screenHeightInPixels = 25;
double distanceOfScreenFromViewer = 16;

class Point {
public:
    double x, y, z;

    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print() const {
        std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
    }

    Point operator+(const Point &other) const {
        Point result = Point(this->x + other.x, this->y + other.y, this->z + other.z);
        return result;
    }
};

class Vector {
public:
    double x, y, z;
    double magnitude;

    Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->magnitude = sqrt(x*x+y*y+z*z);
    }
    Vector normalize() const {
        return {this->x/this->magnitude,this->y/this->magnitude,this->z/this->magnitude};
    }
};
Vector lightSourceVector = Vector(0,1,-1).normalize();

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

double dot(Vector a, Vector b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

void render(double angleX, double angleZ) {
    std::vector<std::vector<double>> zDistances(screenHeightInPixels, std::vector<double>(screenWidthInPixels, 0));
    std::vector<std::vector<char>> screen(screenHeightInPixels, std::vector<char>(screenWidthInPixels, ' '));
    for(double alpha = 0; alpha < 2*PI; alpha += alphaSpacing) {
        double cosAlpha = cos(alpha);
        double sinAlpha = sin(alpha);
        Point current = Point(donutRadius+donutThicknessRadius*cosAlpha,donutThicknessRadius*sinAlpha,0);
        for(double beta = 0; beta < 2*PI; beta += betaSpacing) {
            Point finalPoint = rotateOnAll3Axes(current, beta, angleX, angleZ) + Point(0, 0, distanceOfDonutFromViewer);
            double ooz = 1 / finalPoint.z;

            int projectedX = (int) (screenWidthInPixels / 2 + finalPoint.x * distanceOfScreenFromViewer * ooz);
            int projectedY = (int) (screenHeightInPixels / 2 - finalPoint.y * distanceOfScreenFromViewer * ooz);

            Point luminance = rotateOnAll3Axes(Point(cosAlpha, sinAlpha, 0), beta, angleX, angleZ);
            Vector luminanceVector = Vector(luminance.x, luminance.y, luminance.z).normalize();
            double luminanceProduct = dot(luminanceVector, lightSourceVector);
            if (luminanceProduct > 0) {
                if (ooz > zDistances[projectedY][projectedX]) {
                    int luminanceIndex = (luminanceProduct * 12);
                    if(luminanceIndex == 12) luminanceIndex = 11;
                    zDistances[projectedY][projectedX] = ooz;
                    screen[projectedY][projectedX] = ".,-~:;=!*#$@"[luminanceIndex];
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

int main() {
    double X = 0, Z = 0;
    double xIncrement=0.15, zIncrement=0.2;
    while(true) {
        render(X,Z);
        X += xIncrement;
        Z += zIncrement;
    }
}
