#pragma once

#define PI 3.14159265
enum RotationAxisType { AroundXAxis, AroundYAxis, AroundZAxis };

class RotationMatrix {
public:
    double angleInDegrees;
    RotationAxisType type;
    std::vector<std::vector<double>> matrix;

    RotationMatrix(double angleInDegrees, RotationAxisType type) {
        double angleInRadians = angleInDegrees * PI / 180;
        this->angleInDegrees = angleInDegrees;
        this->type = type;
        switch(type) {
            case AroundXAxis: {
                this->matrix = {
                        {1, 0, 0},
                        {0, cos(angleInRadians), -sin(angleInRadians)},
                        {0, sin(angleInRadians), cos(angleInRadians)}
                };
                break;
            }
            case AroundYAxis: {
                this->matrix = {
                        {cos(angleInRadians), 0, sin(angleInRadians)},
                        {0, 1, 0},
                        {-sin(angleInRadians), 0, cos(angleInRadians)}
                };
                break;
            }
            case AroundZAxis: {
                this->matrix = {
                        {cos(angleInRadians), -sin(angleInRadians), 0},
                        {sin(angleInRadians), cos(angleInRadians), 0},
                        {0, 0, 1}
                };
                break;
            }
        }
    }
};