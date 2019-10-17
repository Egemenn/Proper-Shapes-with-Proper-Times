#ifndef INC_161044101_CSE241_HW5_RECTANGLE_H
#define INC_161044101_CSE241_HW5_RECTANGLE_H
#include <string>
#include <iostream>
#include <fstream>
#include "Shape.h"

using namespace std;

class Rectangle : public Shape {
public:
    Rectangle();
    Rectangle (double x, double y);
    double getHeight() const;
    double getWidth() const;
    void setHeight(double H);
    void setWidth(double W);
    double getX();
    double getY();
    string getColor();
    void setX(double X);
    void setY(double Y);
    void setColor(string Col);
    double getArea() override;
    double getPerimeter() override;
    Shape& operator++(int) override;
    Shape& operator++() override;
    Shape& operator--(int) override;
    Shape& operator--() override;
    Rectangle operator+(double d);
    Rectangle operator-(double d);
    /*friend bool operator==(Rectangle&, Rectangle&);
    friend bool operator!=(Rectangle&, Rectangle&);
    friend bool operator>(Rectangle&, Rectangle&);
    friend bool operator<(Rectangle&, Rectangle&);*/
    //ofstream &operator<<(ostream &os, Shape&) override;
    //ostream &operator<<(ostream &os, Shape&);
    friend ofstream &operator<<(ostream &os, Rectangle R);

    double CalculateAreaOfRect();

private:
    static double CurrentArea;
    static double CurrentPerimeter;
    double width;
    double height;
    double x, y;
    string color;
};


#endif //INC_161044101_CSE241_HW5_RECTANGLE_H
