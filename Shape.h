#ifndef INC_161044101_CSE241_HW5_SHAPE_H
#define INC_161044101_CSE241_HW5_SHAPE_H
#include <fstream>
using namespace std;

class Shape {

    virtual double getArea()=0;
    virtual double getPerimeter()=0;
    virtual Shape& operator ++()=0;
    virtual Shape& operator ++(int)=0;
    virtual Shape& operator --()=0;
    virtual Shape& operator --(int)=0;

    friend bool operator ==(Shape&, Shape&);
    friend bool operator !=(Shape&, Shape&);
    friend bool operator >(Shape&, Shape&);
    friend bool operator <(Shape&, Shape&);
    ofstream &operator<<(ostream &os );
};


#endif //INC_161044101_CSE241_HW5_SHAPE_H
