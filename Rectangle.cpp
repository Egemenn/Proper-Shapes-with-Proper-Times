#include "Rectangle.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double Rectangle::CurrentArea=0;//Constructor'in icinde her sefrinde topladigimiz Area'yi en basta 0'a esitledim

double Rectangle::CurrentPerimeter=0;//boylece baslangic degeri olmus olacak

Rectangle::Rectangle (double X, double Y){
    setWidth(X);
    setHeight(Y);
    CurrentArea=CurrentArea+CalculateAreaOfRect();
    CurrentPerimeter=CurrentPerimeter+CalculateAreaOfRect();
}

Rectangle::Rectangle() {
    //sizeof(x)!= sizeof(int)
    cout << "Please enter the width:" << endl;//genişlik ve yükseklik girilmesini istiyorum
    cin >> width;
    cout << "Please enter the height:" << endl;
    cin >> height;
    CurrentArea=CurrentArea+CalculateAreaOfRect();
    CurrentPerimeter=CurrentPerimeter+CalculateAreaOfRect();
}

inline void Rectangle::setWidth(double W) {
    width=W;
}

inline void Rectangle::setHeight(double H){
    height=H;
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getHeight() const{
    return height;
}

double Rectangle:: getX(){
    return x;
}

double Rectangle::getY(){
    return y;
}

void Rectangle:: setX(double X){
    x=X;
}

void Rectangle:: setY(double Y){
    y=Y;
}

void Rectangle::setColor(string Col){
    color=Col;
}

string Rectangle::getColor(){
    return color;
}

ofstream &operator<<(ostream &os, Rectangle R){
//Private olan degerleri cagirmak icin getX ve getY kullanmadim, cunku fonksiyonu friend olarak tanimladim. private degere ulasabiliyor.
    os<< "<rect x=\"" << R.x << "\"  y=\"" << R.y << "\" width=\"" <<R.getWidth() << "\"  height=\"" << R.getHeight()  << "\" stroke=\"black\""
         " fill=\""<<R.getColor()<<"\" stroke-width=\"" << 0.1 << "\" />" << endl;
return dynamic_cast<ofstream &>(os);
}
/*
ofstream &operator<<(ostream &os, Shape &R) {
//Private olan degerleri cagirmak icin getX ve getY kullanmadim, cunku fonksiyonu friend olarak tanimladim. private degere ulasabiliyor.
    os<< "<rect x=\"" << 0 << "\"  y=\"" << 10 << "\" width=\"" <<100 << "\"  height=\"" << 270  << "\" stroke=\"black\""
                                                                                                                          " fill=\""<<"red"<<"\" stroke-width=\"" << 0.1 << "\" />" << endl;
    return dynamic_cast<ofstream &>(os);
}
*/
Rectangle Rectangle::operator+(double d){
    Rectangle rNew(width+d, height+d);
    return rNew;
}

Rectangle Rectangle::operator-(double d){
    Rectangle rNew(width-d, height-d);
    return rNew;
}

Shape& Rectangle::operator++(){

    x++;
    y++;

    Rectangle C(width, height);
    C.x=x;
    C.y=y;
    C.color=color;

    return C;
}

Shape& Rectangle::operator++(int){

    Rectangle C(width, height);
    C.x=x;
    C.y=y;
    C.color=color;

    x++;
    y++;

    return C;

    /*double cX=c.getX();
    double cY=c.getY();
    c.x=cX;
    c.y=cY;
    cX++;
    cY++;
    return c;*/
}

Shape& Rectangle::operator--(){
    x--;
    y--;

    Rectangle C(width, height);
    C.x=x;
    C.y=y;
    C.color=color;

    return C;
}

Shape& Rectangle::operator--(int){
    Rectangle R(width, height);
    R.x=x;
    R.y=y;
    R.color=color;

    x++;
    y++;

    return R;
}

bool operator==(Rectangle &c1, Rectangle &c2){
    bool equal=false;
    if(c1.CalculateAreaOfRect()==c2.CalculateAreaOfRect())
        equal=true;

    return equal;
}

bool operator!=(Rectangle &c1, Rectangle &c2){
    bool equal=false;
    if(c1.CalculateAreaOfRect()!=c2.CalculateAreaOfRect())
        equal=true;

    return equal;
}

bool operator>(Rectangle &c1, Rectangle &c2){
    bool smaller=false;
    if(c1.CalculateAreaOfRect()>c2.CalculateAreaOfRect())
        smaller=true;

    return smaller;
}

bool operator<(Rectangle &c1, Rectangle &c2){
    bool bigger=false;
    if(c1.CalculateAreaOfRect()<c2.CalculateAreaOfRect())
        bigger=true;

    return bigger;
}


double Rectangle::getArea(){
    return CurrentArea;
}

double Rectangle::getPerimeter(){
    return CurrentPerimeter;
}

double Rectangle::CalculateAreaOfRect(){
    return (width*width);
}



