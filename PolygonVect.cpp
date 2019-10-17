//
// Created by egeme on 22.12.2018.
//

#include "PolygonVect.h"
#include <vector>
using namespace std;
using namespace Shapes;

PolygonVect::PolygonVect(vector<Polygon::Point2D> vecP2D) {
    delete[]coordinates;//dynamic memory'nin icini bosalttim, yeniden kullanmak icin
    numberOfPoint = static_cast<int>(vecP2D.size());//vektorun size'ını numberOfPoint'e atadim
    coordinates = new Point2D[numberOfPoint];
    for (int i = 0; i < numberOfPoint; i++) {
        coordinates[i] = vecP2D.at(static_cast<unsigned long long int>(i));//vektordeki her elemani sirasiyla koordinatlara atadim
    }
}

int PolygonVect::virtualFonksiyon() {
    return 0;
}
