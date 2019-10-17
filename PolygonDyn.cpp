//
// Created by egeme on 22.12.2018.
//

#include "PolygonDyn.h"
using namespace Shapes;


/*-------Point2D constructor-------*/
PolygonDyn::PolygonDyn(){


}
/*------------Copy Constructor-----------*/
PolygonDyn::PolygonDyn(const PolygonDyn& PolDynObject) {
    coordinates = new Point2D[getNumberOfPoint()];
    for(int i=0; i< getNumberOfPoint(); i++)
    {
        coordinates[i]=PolDynObject.coordinates[i];
    }
}

/*------Destructor-------*/
PolygonDyn::~PolygonDyn(){
    delete [] coordinates;

}

/*----Assignment Operator-----*/
PolygonDyn& PolygonDyn::operator =(const PolygonDyn& r){

    if(coordinates!= r.coordinates){
        delete [] coordinates;
        //coordinates = new Point2D[r.coordinates];
    }
}


int PolygonDyn::virtualFonksiyon() {
    return 0;
}


