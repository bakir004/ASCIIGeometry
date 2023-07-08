cmake_minimum_required(VERSION 3.25)
project(ASCIIShapes)

set(CMAKE_CXX_STANDARD 17)

add_executable(ASCIIShapes main.cpp DonutPointGeneration.h Point.h Rotate.h RotationMatrix.h Utils.h Vector.h Projection.h PointRotation.h)
