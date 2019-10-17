#ifndef INC_161044101_CSE241_HW5_POLYGONVECT_H
#define INC_161044101_CSE241_HW5_POLYGONVECT_H
#include "Polygon.h"
#include <vector>
using namespace std;
using namespace Shapes;

class PolygonVect : public Polygon {

    PolygonVect(vector<Polygon::Point2D> vecP2D);//Point2D vector alan constructor
    int numberOfPoint = 0;//private tanimladim. <<overloading friend oldugu icin buna ulasabilecek
    int virtualFonksiyon() override ;

};


#endif //INC_161044101_CSE241_HW5_POLYGONVECT_H
