//Egemen Çağşırlı 161044101 CSE241 HW5

#include <vector>
#include "Polygon.h"
#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"

using namespace Shapes;
using  namespace std;
void Start();


int main() {



    for(int k=0; k<5; k++){         //5 class icin 5 kez olacak sekilde for dongusu icinde start fonksiyonumu cagirdim.
        //driver fonksiyonum start fonksiyonu
        Start();
    }



    return 0;
}


void Start() {

    string FC, SC;                  //first choice ve second choice olacak sekilde iki string tanimladim
    cout << "Please enter the main container shape (R, C, T):" << endl;
    cin >> FC;                      //ilk secimi kullanicidan aldim

    /*--------------------------------input control-------------------------------------*/
    if (FC != "R" && FC != "r" && FC != "C" && FC != "c" && FC != "T" &&
        FC != "t") {                //hatali input girilmesi durumunda uyari veriyor
        do {
            cerr << "Wrong Input! Please enter R, C or T";
            cin >> FC;
        } while (FC != "R" && FC != "r" && FC != "C" && FC != "c" && FC != "T" &&
                 FC != "t");        //dogru inputlardan birini girene kadar dongu devam edecek
    }
    /*--------------------------------input control-------------------------------------*/

    if (FC == "R" || FC == "r") {   //R girildiyse dikdörtgen istenmiştir

        Rectangle Rect;             //Rectangle sinifindan Rect nesnesi olusturdum
        /*Burada buyuk sekli nesne olarak olusturup icerisinde kullanicidan width ve height'leri aldim. Rect Constructor olarak calisiyor

        /*Kucuk Sekli kullaniciya soralim, ve nesne olarak olusturup, degerlerini kullanicidan alalım*/
        cout << "Please enter the small shape (R, C, T):" << endl;//kullanicidan kucuk seklin adini girmesini istedim
        cin >> SC;                  //second choice'a atadım

        /*-------------input control----------------------------*/
        if (SC != "R" && SC != "r" && SC != "C" && SC != "c" && SC != "T" &&
            SC != "t") {            //second choice R, r, T, t, C veya c'den biri degilse hatali inputtur
            do {
                cerr << "Wrong Input! Please enter R, C or T";
                cin >> SC;
            } while (SC != "R" && SC != "r" && SC != "C" && SC != "c" && SC != "T" &&  SC != "t");
            //dogru inputlardan birini girene kadar dongu devam edecek
        }/*-------------input control----------------------------*/

        if (SC == "R" || SC == "r") {//R girildiginde kucuk sekil Rectangle olur
            Rectangle InnerRect;            //Bu kez de kucuk sekli Retangle sinifindan nesne olarak olusturdum
            ComposedShape(Rect, InnerRect); //Olusturdugum bu iki nesneyi ComposedShape constructor'ına parametre olarak verdim
        }
        else if (SC == "C" || SC == "c") {  //C girildiginde kucuk sekil Circle olur
            Circle InnerCirc;
            ComposedShape(Rect, InnerCirc);
        }
        else if (SC == "T" || SC == "t") {  //T girildiginde kucuk sekil Triangle olur
            Triangle InnerTri;
            ComposedShape(Rect, InnerTri);
        }
    }
    else if (FC == "C" || FC == "c") {      //C veya c girildiyse daire istenmiştir

        Circle Circ;

        /*Kucuk Seklin degerlerini kullanicidan alalım*/
        cout << "Please enter the small shape (R, C, T):" << endl;
        cin >> SC;

        /*-------------input control----------------------------*/
        if (SC != "R" && SC != "r" && SC != "C" && SC != "c" && SC != "T" && SC != "t") {
            do {
                cerr << "Wrong Input! Please enter R, C or T";
                cin >> SC;
            } while (SC != "R" && SC != "r" && SC != "C" && SC != "c" && SC != "T" && SC != "t");
        }
        /*-------------input control----------------------------*/

        if (SC == "R" || SC == "r") {           //R girildiginde kucuk sekil Rectangle olur
            Rectangle InnerRect;
            ComposedShape(Circ, InnerRect);
        } else if (SC == "C" || SC == "c") {    //C girildiginde kucuk sekil Circle olur
            Circle InnerCirc;
            ComposedShape(Circ, InnerCirc);

        } else if (SC == "T" || SC == "t") {    //T girildiginde kucuk sekil Triangle olur
            Triangle InnerTri;
            ComposedShape(Circ, InnerTri);
        }
    }
    else if (FC == "T" || FC == "t") {          //T veya t girildiyse ucgen istenmiştir

        Triangle Tri;

        /*Kucuk Seklin degerlerini kullanicidan alalım*/
        cout << "Please enter the small shape (R, C, T):" << endl;
        cin >> SC;

        /*-------------input control----------------------------*/
        if (SC != "R" && SC != "r" && SC != "C" && SC != "c" && SC != "T" && SC != "t") {
            do {
                cerr << "Wrong Input! Please enter R, C or T";
                cin >> SC;
            } while (SC != "R" && SC != "r" && SC != "C" && SC != "c" && SC != "T" && SC != "t");
        }
        /*-------------input control----------------------------*/

        if (SC == "R" || SC == "r") {           //R girildiginde kucuk sekil Rectangle olur
            Rectangle InnerRect;
            ComposedShape(Tri, InnerRect);
        }
        else if (SC == "C" || SC == "c") {      //C girildiginde kucuk sekil Circle olur
            Circle InnerCirc;
            ComposedShape(Tri, InnerCirc);

        } else if (SC == "T" || SC == "t") {    //T girildiginde kucuk sekil Triangle olur
            Triangle InnerTri;
            ComposedShape(Tri, InnerTri);
        }
    }
}



void printAll(vector<Shape*> VSP){
    for(int k=0; k<VSP.capacity(); k++)
        cout<<VSP[k];
}



void printPoly(vector<Shape*> VSP){

}

vector<Polygon> convertAll(vector<Shape *> VSP) { //convertAll global fonksiyonu

    Shapes::Polygon::Point2D tempP;
    vector<Shapes::Polygon> tempV;

    for(int k=0; k<VSP.capacity(); k++){
        //tempP.coordinates->getX() = VSP.at(k).coordinates.getX(); bu şekilde olması lazım fakat hata verdi, yorum satırına aldım
        //tempP.coordinates->getY() = VSP.at(k).coordinates.getY();
    }
}

void sortShapes(vector<Shape*> VSP){ //sortShapes global fonksiyonu


}

