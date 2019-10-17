#ifndef INC_161044101_CSE241_HW5_CIRCLE_H
#define INC_161044101_CSE241_HW5_CIRCLE_H
#include <string>
#include <fstream>
#include "Shape.h"

using namespace std;

class Circle : public Shape {
public:
    Circle();
    Circle(double radius);
    double getRadius();
    void setRadius(double R);
    void setX(double x);
    void setY(double Y);
    void setColor(string Col);
    double getX();
    double getY();
    string getColor();
    double getArea() override;
    double getPerimeter() override;

    Shape& operator++(int) override;
    Shape& operator++() override;
    Shape& operator--(int) override;
    Shape& operator--() override;
    Circle operator+(double d);
    Circle operator-(double d);
    friend bool operator==(Circle&, Circle&);
    friend bool operator!=(Circle, Circle);
    friend bool operator>(Circle&, Circle&);
    friend bool operator<(Circle, Circle);
    friend ofstream &operator<<(ostream &os, Circle C);

    double FindHeightOfBottom(double bigRadius, double smallWidth);
    double CalculateAreaOfCirc();
    double CalculatePerimeterOfCirc();
    const double pi=3.14159265359;

private:
    static double CurrentArea;
    static double CurrentPerimeter;
    double radius;
    double x, y;
    string color;

};


#endif //INC_161044101_CSE241_HW5_CİRCLE_H
