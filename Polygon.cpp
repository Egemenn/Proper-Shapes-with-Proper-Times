//
// Created by egeme on 22.12.2018.
//

#include "Polygon.h"
#include <iostream>
#include <vector>
#include <math.h>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

//using namespace std;


namespace Shapes {


    Polygon::Polygon() = default;

/*-------Point2D constructor-------*/
    Polygon::Point2D::Point2D(double x, double y) : X(x), Y(y) {
        //setX(x); bu sekilde set etmedim cunku yukaridaki kullanimi kullandim. x degerini set ettim
        //setY(y); y degerini de ayni sekilde yukarida set ettim
    }

/*-------Polygon destructor------*/
//    Polygon::~Polygon(){}





/*-------Point2D vektor alan constructor-------*/
/*Polygon::Polygon(vector<Point2D> vecP2D) {//Point2D vector alan constructor definition'ı
    delete[]coordinates;//dynamic memory'nin icini bosalttim, yeniden kullanmak icin
    numberOfPoint = static_cast<int>(vecP2D.size());//vektorun size'ını numberOfPoint'e atadim
    coordinates = new Point2D[numberOfPoint];
    for (int i = 0; i < numberOfPoint; i++) {
        coordinates[i] = vecP2D.at(static_cast<unsigned long long int>(i));//vektordeki her elemani sirasiyla koordinatlara atadim
    }

}*/
















    /*-------Rectangle alan Polygon constructor-------*/
    Polygon::Polygon(Rectangle Rect) {

        if (Rect.getWidth() <= 0 || Rect.getWidth() <= 0) {
            /*0'dan kucuk veya 0'a esit sayi verildiginde hata ver ve programi kapat.*/
            cerr << "Error! Given width or height is negative number" << endl;
            exit(1);
        }
        decltype(Rect.getX()) x1, y1, x2, y2, x3, y3, x4, y4;//dort kenarli oldugu icin dorder adet x ve y noktalari tanımladim
        double X = Rect.getX();     //guncel nesnenin x koordinatini aldim
        double Y = Rect.getY();     //guncel nesnenin y koordinatini aldim
        numberOfPoint = 4;          //dort kenar inin numberOfPoint'i 4'e esitledim.
        x1 = X, y1 = Y;             //sol ustteki nokta
        x2 = X + Rect.getWidth();
        y2 = Y;                     //sag ustteki nokta
        x3 = X + Rect.getWidth();
        y3 = Y + Rect.getHeight();  //sag alttaki nokta
        x4 = X;
        y4 = Y + Rect.getHeight();  //sol alttaki nokta

        /*cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
        cout << y1 << " " << y2 << " " << y3 << " " << y4 << endl << endl;*/
        coordinates = new Point2D[4];//dynamic Point2D arrayi tanimladim
        coordinates[0] = Point2D(x1, y1);
        coordinates[1] = Point2D(x2, y2);
        coordinates[2] = Point2D(x3, y3);
        coordinates[3] = Point2D(x4, y4);
        color = Rect.getColor();

    }

/*-------Triangle alan Polygon constructor-------*/
    Polygon::Polygon(Triangle Tri) {

        if (Tri.getEdge() <= 0) {
            /*0'dan kucuk veya 0'a esit sayi verildiginde hata ver ve programi kapat.*/
            cerr << "Error! Given edge is negative number or zero (0) " << endl;
            exit(1);

        }
        double x1 = Tri.getx1();    //triangle noktalarini burada getter ile cagirdim
        double y1 = Tri.gety1();
        double x2 = Tri.getx2();
        double y2 = Tri.gety2();
        double x3 = Tri.getx3();
        double y3 = Tri.gety3();
        numberOfPoint = 3;          //her nesnenin 3 adet noktasi olacak, ucgen oldugu icin
        coordinates = new Point2D[3];
        coordinates[0] = Point2D(x1, y1);
        coordinates[1] = Point2D(x2, y2);
        coordinates[2] = Point2D(x3, y3);
        color = Tri.getColor();
    }

/*-------Circle alan Polygon constructor-------*/
    Polygon::Polygon(Circle Circ) {

        double x1, y1;
        x1 = Circ.getX();//guncel circle'in x koordinatini x1'e atadim
        y1 = Circ.getY();//guncel circle'in y koordinatini y1'e atadim
        double r = Circ.getRadius();
        double a =
                r / 25;//dairenin kenarlarini 360 nokta olarak dusundugumuzde her 90'lik dilimi kendi icinde cizdirdim
        numberOfPoint = 100;//point sayisi 360
        coordinates = new Point2D[100];//360 parcaya bolersem daha duzgun bir  goruntu olusuyor fakat odevde 100 istendigi icin 100 noktaya boldum
        for (int i = 0; i < 25; i++) {
            double k = pow(r, 2) - pow((r - a * i),
                                       2);//pisagor bagintisini kullanarak radiusun karesinden her parcanin karesini cıkarıp karekokunu aldım
            double x = sqrt(k);

            cout << a << " " << x << endl;
            /*koordinatlari sol bastan, saat 9 yonunden baslayip saat yonunde cizerek
             * once 12, sonra 3, sonra 6, sonra da tekrar saat 9 yonune getirerek
             * cizdirdim. Bu islemi circle'in kenarlarini 4 parcaya bolerek yaptim*/
            coordinates[i] = Point2D(x1 - r + i * a, y1 - r + r - x);           //ilk dilim
            coordinates[i + 25] = Point2D(x1 - r + r + x, y1 - r + i * a);      //ikinci dilim
            coordinates[i + 50] = Point2D(x1 - r + 2 * r - i * a, y1 - r + r + x);//ucuncu dilim
            coordinates[i + 75] = Point2D(x1 - r + r - x, y1 - r + 2 * r - i * a);//dorduncu dilim
        }
        color = Circ.getColor();

    }

    Polygon::Polygon(int conversion) {

    }

    Polygon::Point2D::Point2D() {
        setX(0);
        setY(0);
    }


/*-------Getter Setter-------*/
    void Polygon::Point2D::setX(double inputx) {
        X = inputx;
    }

    void Polygon::Point2D::setY(double inputy) {
        Y = inputy;
    }

    double Polygon::Point2D::getX() const {
        return X;
    }

    double Polygon::Point2D::getY() const {
        return Y;
    }

/*-------OPERATOR OVERLOADINGLER-------*/
/*-------operator[] overloading-------*/
    Polygon::Point2D &Polygon::operator[](int order) {
        if (order >= numberOfPoint) {//nokta sayisina esitse veya buyukse olmaz. 0'dan basladigi ve n-1'de bittigi icin
            cerr << "There is a mistake! Index is bigger than number of count";
            exit(1);//programi sonlandir
        }
        return coordinates[order];//order numberOfPointten buyuk degilse o boyutta koordinati dondur
    }

/*-------operator== overloading-------*/
    /*  bool operator==(Polygon P1, Polygon P2) {
          if (P1.getNumberOfPoint() == P2.getNumberOfPoint()) {
              for (int k = 0; k < P1.getNumberOfPoint(); k++) {
                  if ((P1.coordinates[k].getX() != P2.coordinates[k].getX()) &&
                      (P1.coordinates[k].getY() !=
                       P2.coordinates[k].getY()))//bi tanesinin bile koordinatlari esit degilse
                      return false;              //direkt false dondur
              }
          } else return P1.getNumberOfPoint() == P2.getNumberOfPoint();
      }*/

/*-------operator+ overloading-------*/
    /*   Polygon operator+(Polygon P1, Polygon P2) {

           Polygon Pnew;//yeni polygon nesnesi tanimladim, return etmek icin
           Pnew.coordinates = new Polygon::Point2D[P1.getNumberOfPoint() + P1.getNumberOfPoint()];
           //noktalarin sayisini toplayarak olusaka yeni nesnenin nokta sayisini buldum
           for (int i = 0; i < P1.getNumberOfPoint(); i++) {
               Pnew.coordinates[i] = P1.coordinates[i];
           }
           for (int i = 0; i < P2.getNumberOfPoint(); i++) {//ilk seklin koordinatlarini yeni nesneye esitledikten sonra 2.seklinkini de ekliyorum
               Pnew.coordinates[i + P1.getNumberOfPoint()] = P2.coordinates[i];
           }

       }*/

/*-------operator<< overloading-------*/
    /*ostream &operator<<(ostream &os, Polygon P) {//Polygon class'i icin << operator overloading'i

        os << "<polygon points=\"";
        for (int k = 0; k < P.numberOfPoint; k++) {
            os << P.coordinates[k].getX() << "," << P.coordinates[k].getY() << " ";
        }
        os << "\" stroke=\"black\"" " fill=\"" << P.color << "\" stroke-width=\"" << 0.1 << "\" />" << endl;
        return os;
    }*/

    int Polygon::getNumberOfPoint() {
        return numberOfPoint;
    }

    double Polygon::getArea() {
        return 0;
    }

    double Polygon::getPerimeter() {
        return 0;
    }

    Shape &Polygon::operator++(int) {
        //return <#initializer#>;
    }

    Shape &Polygon::operator++() {
        //  return <#initializer#>;
    }

    Shape &Polygon::operator--(int) {
        // return <#initializer#>;
    }

    Shape &Polygon::operator--() {
//    return <#initializer#>;
    }


}