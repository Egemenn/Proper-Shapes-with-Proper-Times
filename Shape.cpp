#include "Shape.h"


bool operator==(Shape & S1, Shape & S2) {
    return (S1.getArea() == S2.getArea() && S1.getArea() == S2.getArea());
}

bool operator!=(Shape &S1, Shape &S2) {
    return !(S1.getArea() == S2.getArea() && S1.getArea() == S2.getArea());
}

bool operator>(Shape &S1, Shape &S2) {
    return (S1.getArea()>S2.getArea());
}

bool operator<(Shape &S1, Shape &S2) {
    return (S1.getArea()<S2.getArea());
}

ofstream &Shape::operator<<(ostream &os) {
//    return <#initializer#>;
}


