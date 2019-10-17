#ifndef INC_161044101_CSE241_HW5_COMPOSEDSHAPE_H
#define INC_161044101_CSE241_HW5_COMPOSEDSHAPE_H
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Shape.h"

using namespace std;

class ComposedShape : public Shape {


public:
    ComposedShape();
    ComposedShape(Rectangle& ContainerShape, Rectangle& InnerShapes);
    ComposedShape(Rectangle& ContainerShape, Triangle& InnerShapes);
    ComposedShape(Rectangle& ContainerShape, Circle& InnerShapes);
    ComposedShape(Triangle& ContainerShape, Rectangle& InnerShapes);
    ComposedShape(Triangle& ContainerShape, Triangle& InnerShapes);
    ComposedShape(Triangle& ContainerShape, Circle& InnerShapes);
    ComposedShape(Circle& ContainerShape, Rectangle& InnerShapes);
    ComposedShape(Circle& ContainerShape, Triangle& InnerShapes);
    ComposedShape(Circle& ContainerShape, Circle& InnerShapes);
    void OptimalFit(Rectangle& ContainerShape, Rectangle& InnerShapes);
    void OptimalFit(Rectangle& ContainerShape, Triangle& InnerShapes);
    void OptimalFit(Rectangle& ContainerShape, Circle& InnerShapes);
    void OptimalFit(Triangle& ContainerShape, Rectangle& InnerShapes);
    void OptimalFit(Triangle& ContainerShape, Triangle& InnerShapes);
    void OptimalFit(Triangle& ContainerShape, Circle& InnerShapes);
    void OptimalFit(Circle& ContainerShape, Rectangle& InnerShapes);
    void OptimalFit(Circle& ContainerShape, Triangle& InnerShapes);
    void OptimalFit(Circle& ContainerShape, Circle& InnerShapes);
    double CalculateRest(double bigArea, double smallArea);
    double getArea() override;
    double getPerimeter() override;
    Shape& operator ++()override;
    Shape& operator ++(int) override;
    Shape& operator --() override;
    Shape& operator --(int) override;
    /*vector<Rectangle> getVectorRect();
    vector<Triangle> getVectorTri();
    vector<Circle> getVectorCirc();
    vector<Polygon> getVectorPol();*/
    double bigWidth, bigHeight, smallWidth, smallHeight;
    double bigEdge, smallEdge;
    double bigRadius, smallRadius;
    double RestArea, bigArea, smallArea;
    int count=0;
    const string startSVG = "<svg  version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";//SVG kodunu her fonksiyonda tekrar yazmama adina string degere atadim
    vector<Shape*> getVector();
private:
    vector<Shape*>V_Pol;
};


#endif //INC_161044101_CSE241_HW5_COMPOSEDSHAPE_H
