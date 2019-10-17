#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Circle.h"

double Circle::CurrentArea=0;//Constructor'in icinde her sefrinde topladigimiz Area'yi en basta 0'a esitledim
double Circle::CurrentPerimeter=0;//boylece baslangic degeri olmus olacak

Circle::Circle() {
    cout << "Please enter the radius:" << endl;
    cin >> radius;
    CurrentArea=CurrentArea+CalculateAreaOfCirc();
    CurrentPerimeter=CurrentPerimeter+CalculateAreaOfCirc();
}

Circle::Circle(double radius){
    setRadius(radius);
    CurrentArea=CurrentArea+CalculateAreaOfCirc();
    CurrentPerimeter=CurrentPerimeter+CalculateAreaOfCirc();

}

void Circle::setRadius(double R) {
    radius=R;
}

inline double Circle::getRadius(){
    return radius;
}

void Circle::setX(double X){
    x=X;
}

void Circle::setY(double Y){
    y=Y;
}

double Circle::getX() {
    return x;
}

double Circle::getY(){
    return y;
}

void Circle::setColor(string Col){
    color= Col;
}

string Circle::getColor(){
    return color;
}


/*----------operator overloading part----------*/
ofstream &operator<<(ostream &os, Circle C){

    os << "<circle cx=\"" << C.getX() << "\"  cy=\"" << C.getY() << "\" r=\"" << C.getRadius() << "\" stroke=\"black\""
                                                                                                  " fill=\"" << C.getColor() << "\" stroke-width=\"" << 0.1 << "\" />" << endl;
}

Circle Circle::operator+(double d){
    Circle cNew(radius +d);
    return cNew;
}

Circle Circle::operator-(double d){
    Circle cNew(radius -d);
    return cNew;
}

Shape& Circle::operator++(){

    x++;
    y++;

    Circle C(radius);
    C.x=x;
    C.y=y;
    C.color=color;

    return C;
}

Shape& Circle::operator++(int){

    Circle C(radius);
    C.x=x;
    C.y=y;
    C.color=color;

    x++;
    y++;

    return C;
}

Shape& Circle::operator--(){

    x--;
    y--;

    Circle C(radius);
    C.x=x;
    C.y=y;
    C.color=color;

    return C;
}

Shape& Circle::operator--(int){
    Circle C(radius);
    C.x=x;
    C.y=y;
    C.color=color;

    x++;
    y++;

    return C;
}

bool operator==(Circle &c1, Circle &c2){
    bool equal=false;
    if(c1.CalculateAreaOfCirc()==c2.CalculateAreaOfCirc())
        equal=true;

    return equal;
}

bool operator!=(Circle c1, Circle c2){
    bool equal=false;
    if(c1.CalculateAreaOfCirc()!=c2.CalculateAreaOfCirc())
        equal=true;

    return equal;
}

bool operator>(Circle &c1, Circle &c2){
    bool smaller=false;
    if(c1.CalculateAreaOfCirc()>c2.CalculateAreaOfCirc())
        smaller=true;

    return smaller;
}

bool operator<(Circle &c1, Circle &c2){
    bool bigger=false;
    if(c1.CalculateAreaOfCirc()<c2.CalculateAreaOfCirc())
        bigger=true;

    return bigger;
}


/*bool operator<=(Circle, Circle){
}
bool operator>=(Circle, Circle){
}*/

double Circle::getArea(){
    return CurrentArea;
}

double Circle::getPerimeter(){
    return CurrentPerimeter;
}

double Circle::CalculateAreaOfCirc(){
    return (pi*(radius*radius));//dairenin alani pi r kare'yi return ettirdim
}

double Circle::CalculatePerimeterOfCirc(){
    return (2*(radius*radius));//dairenin cevresi
}

double Circle::FindHeightOfBottom(double bigRadius, double smallWidth) {
/*Circle icine Rectangle fonksiyonunda dairenin en altindan oraya sigan tek dortgeni oturtacak kadar
 *yuksekligi bu fonksiyonda buluyor. daha sonra bottomheight degerini return ediyor */

    double tempBottom = bigRadius*bigRadius - (smallWidth/2)*smallWidth/2;
    double tempBottom2 = sqrt(tempBottom);
    double bottomHeight = bigRadius - tempBottom2;//bottomHeight'i hesaplayip return ediyorum ve RinC fonksiyonuna gonderiyorum

    return bottomHeight;
}
