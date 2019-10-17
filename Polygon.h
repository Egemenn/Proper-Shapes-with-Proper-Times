#ifndef INC_161044101_CSE241_HW5_POLYGON_H
#define INC_161044101_CSE241_HW5_POLYGON_H
#include <iostream>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
using namespace std;

namespace Shapes {


    class Polygon : public Shape {
    public:
        class Point2D {
        public:
            Point2D();

            Point2D(double x, double y);

            void setX(double inputx);//X ve Y koordinatlarini atayan setter'lar
            void setY(double inputy);

            double getX() const;//X ve Y koordinatlarini cagiran getter'lar
            double getY() const;

        private:
            double X, Y;
        };


        Polygon();
        //Polygon(vector<Point2D> vecP2D);//Point2D vector alan constructor
        //~Polygon();


        double getArea() override;
        double getPerimeter() override;
        Shape &operator++(int) override;
        Shape &operator++() override;
        Shape &operator--(int) override;
        Shape &operator--() override;

        Polygon(Rectangle Rect);//Rectangle constructor
        Polygon(Triangle Tri);//Triangle constructor
        Polygon(Circle Circ);//Circle constructor
        Polygon(int conversion);//coversion constructor
        Point2D &operator[](int order);

        //friend bool operator==(Polygon P1, Polygon P2);
        //friend ostream &operator<<(ostream &os, Polygon P);
        Point2D *coordinates = new Point2D[0];
        string color;
        int getNumberOfPoint();
        virtual int virtualFonksiyon()=0;

    private:
        int numberOfPoint = 0;//private tanimladim. <<overloading friend oldugu icin buna ulasabilecek


    };

}
#endif //INC_161044101_CSE241_HW5_POLYGON_H
