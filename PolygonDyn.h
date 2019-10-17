#ifndef INC_161044101_CSE241_HW5_POLYGONDYN_H
#define INC_161044101_CSE241_HW5_POLYGONDYN_H
#include "Polygon.h"
using namespace Shapes;
class PolygonDyn : public Polygon {

    PolygonDyn();
    PolygonDyn(const PolygonDyn&);
    ~PolygonDyn();
    PolygonDyn& operator=(const PolygonDyn&);
    int virtualFonksiyon() override ;

};


#endif //INC_161044101_CSE241_HW5_POLYGONDYN_H
