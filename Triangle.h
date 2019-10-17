#ifndef INC_161044101_CSE241_HW5_TRIANGLE_H
#define INC_161044101_CSE241_HW5_TRIANGLE_H
#include <string>
#include <fstream>
#include "Shape.h"

using namespace std;

class Triangle : public Shape {

public:
    Triangle();
    Triangle(double edge);
    double getEdge()const;
    void setEdge(double E);
    double CalculateAreaOfTri();
    double getx1();
    double getx2();
    double getx3();
    double gety1();
    double gety2();
    double gety3();
    string getColor();
    void setX1_Y1(double X1, double Y1);
    void setX2_Y2(double X2, double Y2);
    void setX3_Y3(double X3, double Y3);
    void setColor(string Col);
    double getArea() override;
    double getPerimeter() override;

    friend ofstream &operator<<(ostream &os, Triangle T);
    Shape& operator++(int) override;
    Shape& operator++() override;
    Shape& operator--(int) override;
    Shape& operator--() override;
    Triangle operator+(double d);
    Triangle operator-(double d);
    friend bool operator==(Triangle&, Triangle&);
    friend bool operator!=(Triangle, Triangle);
    friend bool operator>(Triangle&, Triangle&);
    friend bool operator<(Triangle, Triangle);

private:
    double edge;
    double x1, x2, x3, y1, y2, y3;
    string color;
    static double CurrentArea;
    static double CurrentPerimeter;

};


#endif //INC_161044101_CSE241_HW5_TRİANGLE_H
