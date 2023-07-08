#include <iostream>
#include <vector>
#include "DonutPointGeneration.h"
#include "Point.h"
#include "Rotate.h"

int main() {

    Points points = generateDonutPoints(5, 2);

    printPoints(points);

    return 0;
}
