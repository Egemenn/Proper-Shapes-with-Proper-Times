#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Triangle.h"
using namespace std;

double Triangle::CurrentArea=0;
double Triangle::CurrentPerimeter=0;

Triangle::Triangle() {//T0irangle constuctor
    cout << "Please enter the edge of triangle" << endl;
    cin >> edge;
    CurrentArea=CurrentArea+CalculateAreaOfTri();
    CurrentPerimeter=CurrentPerimeter+CalculateAreaOfTri();
}

Triangle::Triangle(double edge){
    setEdge(edge);
    CurrentArea=CurrentArea+CalculateAreaOfTri();
    CurrentPerimeter=CurrentPerimeter+CalculateAreaOfTri();
}

void Triangle::setEdge(double E) {
    edge=E;
}

double Triangle::getEdge() const{
    return edge;
}

void Triangle::setX1_Y1(double X1, double Y1){
    x1=X1;
    y1=Y1;
}
void Triangle::setX2_Y2(double X2, double Y2){
    x2=X2;
    y2=Y2;
}
void Triangle::setX3_Y3(double X3, double Y3){
    x3=X3;
    y3=Y3;
}

void Triangle::setColor(string Col) {
    color=Col;
}

double Triangle::getx1(){
    return x1;
}
double Triangle::getx2(){
    return x2;
}
double Triangle::getx3(){
    return x3;
}
double Triangle::gety1(){
    return y1;
}
double Triangle::gety2(){
    return y2;
}
double Triangle::gety3(){
    return y3;
}
string Triangle::getColor() {
    return color;
}

ofstream &operator<<(ostream &os, Triangle T){

    os << "<polygon points=\"" << T.getx1() << "," << T.gety1() << "," << T.getx2() << "," << T.gety2()
       << "," << T.getx3() << "," << T.gety3() << "\" fill=\""<<T.getColor()<<"\"/>" << endl;

    return dynamic_cast<ofstream &>(os);
}

Triangle Triangle::operator+(double d){
    Triangle tNew(edge+d);
    return tNew;
}

Triangle Triangle::operator-(double d){
    Triangle tNew(edge-d);
    return tNew;
}

Shape& Triangle::operator++(){
    x1++;
    y1++;
    x2++;
    y2++;
    x3++;
    y3++;

    Triangle T(edge);
    T.x1=x1;
    T.y1=y1;
    T.x2=x2;
    T.y2=y2;
    T.x3=x3;
    T.y3=y3;
    T.color=color;

    return T;
}

Shape& Triangle::operator++(int){

    Triangle T(edge);
    T.x1=x1;
    T.y1=y1;
    T.x2=x2;
    T.y2=y2;
    T.x3=x3;
    T.y3=y3;
    T.color=color;

    x1++;
    y1++;
    x2++;
    y2++;
    x3++;
    y3++;

    return T;
}

Shape& Triangle::operator--(){
    x1--;
    y1--;
    x2--;
    y2--;
    x3--;
    y3--;

    Triangle T(edge);
    T.x1=x1;
    T.y1=y1;
    T.x2=x2;
    T.y2=y2;
    T.x3=x3;
    T.y3=y3;
    T.color=color;

    return T;
}

Shape& Triangle::operator--(int){
    Triangle T(edge);
    T.x1=x1;
    T.y1=y1;
    T.x2=x2;
    T.y2=y2;
    T.x3=x3;
    T.y3=y3;
    T.color=color;

    x1--;
    y1--;
    x2--;
    y2--;
    x3--;
    y3--;

    return T;
}


bool operator==(Triangle& t1, Triangle& t2){
    bool equal=false;
    if(t1.CalculateAreaOfTri()<t2.CalculateAreaOfTri())
        equal=true;

    return equal;
}

bool operator!=(Triangle t1, Triangle t2){
    bool notequal=false;
    if(t1.CalculateAreaOfTri()<t2.CalculateAreaOfTri())
        notequal=true;

    return notequal;
}

bool operator>(Triangle &t1, Triangle &t2){
    bool bigger=false;
    if(t1.CalculateAreaOfTri()<t2.CalculateAreaOfTri())
        bigger=true;

    return bigger;
}

bool operator<(Triangle t1, Triangle t2){
    bool smaller=false;
    if(t1.CalculateAreaOfTri()<t2.CalculateAreaOfTri())
        smaller=true;

    return smaller;
}

double Triangle::getArea(){
    return CurrentArea;
}
double Triangle::getPerimeter(){
    return CurrentPerimeter;
}

double Triangle::CalculateAreaOfTri() {
    return (edge * edge) * sqrt(3) / 4;//eskenar ucgenin alani a kare kok 3 bolu 2
}