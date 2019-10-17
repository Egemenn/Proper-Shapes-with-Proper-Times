#include "ComposedShape.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

ComposedShape::ComposedShape() {}

//Overloaded Constructorlari burada tanimladim. ilki rectangle icine rectangle icin
ComposedShape::ComposedShape(Rectangle& ContainerShape, Rectangle& InnerShapes) {

    OptimalFit(ContainerShape, InnerShapes);//optimalFit fonksiyonu inner shape'lerin sayisini bulacak ve draw fonksiyonunu cagiracak
}

//Rectangle icine circle icin overloaded constructor
ComposedShape::ComposedShape(Rectangle& ContainerShape, Triangle& InnerShapes){

    OptimalFit(ContainerShape, InnerShapes);
}

//Rectangle icine circle icin overloaded constructor
ComposedShape::ComposedShape(Rectangle &ContainerShape, Circle &InnerShapes){

    OptimalFit(ContainerShape, InnerShapes);
}

//Rectangle icine Triangle icin overloaded constructor
ComposedShape::ComposedShape(Triangle &ContainerShape, Rectangle &InnerShapes){ //KONTROL EDİLECEK. KÜÇÜLTÜLECEK HATA GİDERİLECEK

    OptimalFit(ContainerShape, InnerShapes);
}

//Triangle icine Rectangle icin overloaded constructor
ComposedShape::ComposedShape(Triangle &ContainerShape, Triangle &InnerShapes){

    OptimalFit(ContainerShape, InnerShapes);

}

//Triangle icine Triangle icin overloaded constructor
ComposedShape::ComposedShape(Triangle &ContainerShape, Circle &InnerShapes){

    OptimalFit(ContainerShape, InnerShapes);
}

//Circle icine Rectangle icin overloaded constructor
ComposedShape::ComposedShape(Circle &ContainerShape, Rectangle &InnerShapes){

    OptimalFit(ContainerShape, InnerShapes);
}

//Circle icine Triangle icin overloaded constructor
ComposedShape::ComposedShape(Circle &ContainerShape, Triangle &InnerShapes){

    OptimalFit(ContainerShape, InnerShapes);
}

//Circle icine circle icin overloaded constructor
ComposedShape::ComposedShape(Circle &ContainerShape, Circle &InnerShapes){

    OptimalFit(ContainerShape, InnerShapes);
}

void ComposedShape::OptimalFit(Rectangle& ContainerShape, Rectangle& InnerShapes){
/*OptimalFit fonksiyonlarini da overload ederek her kombinasyon icin yeniden tanimladim
 * Object Oriented mantigini bu foknsiyonlarda ve de ComposedShape constructorlarinda
 * anlayarak ve bu farktan yararlanarak, her fonksiyon gonderdigim parametrelerin
 * type'ina gore hangi fonksiyonu ya da constructor'ı cagiracagini anladi*/

    bigWidth=ContainerShape.getWidth();//bigWidth'e Buyuk Seklin width'ini atiyorum. Width Private oldugu icin getter kullaniyorum
    bigHeight=ContainerShape.getHeight();//Ayni islemi height icin yappiyorum
    smallWidth=InnerShapes.getWidth();//smallWidth ve smallHeight icin de getterlari kucuk sekle uyguluyorum
    smallHeight = InnerShapes.getHeight();
    double X = 0;//X ve Y kooordinatini 0'a esitledim, bunu buyuk sekil icin kullanacagim
    double Y = 0;

    ofstream outFile("output.svg");//burada SVG dosyasini actim
    outFile<< startSVG << endl;//baslangictaki "<svg  version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">" seklindeki SVG kodu

    ContainerShape.setX(X);
    ContainerShape.setY(Y);
    ContainerShape.setColor("red");

    Rectangle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);
    //outFile<<BigPol;//overload ettigim << operatorunu burada kullandim. Outfile dosyasine drawing (writing) islemini yapiyor

    for (int i = 1; i <= bigHeight / smallHeight; ++i) {//Y koordinatini degistirerek cizdiren for dongusu
        for (int j = 1; j <= bigWidth / smallWidth; ++j) {//X koordinatini degistirerek cizdiren for dongusu
            Rectangle tempR(InnerShapes.getWidth(), InnerShapes.getHeight());//Vektorde inner nesneleri (kucuk sekilleri) tutmasi icin Rectangle cinsinden temporary nesne olusturdum
            tempR.setX(X);
            tempR.setY(Y);
            tempR.setColor("green");
            //V_Rect.push_back(tempR);//her bir kucuk sekli burada vector'e atiyorum
            //V_Rect.push_back(tempR);
            //Polygon Pol(tempR);
            V_Pol.push_back(&tempR);
            X += smallWidth;//X'i saga kaydirmak icin smallWidth kadar arttiriyorum
            count++;//kac adet kucuk sekil sigdigini bulmak icin her sekil cizdiginde count'u 1 arttırıyorum
        }
        X = 0;//ilk sira tamamlandiginda X koordinatini tekrar 0' esitliyorum
        Y += smallHeight;//Y koordiantini ilk sira tamamlandiginda bir yukari atiyorum
    }


    /*for(int i =0; i<5; i++){
        cout<< V_Pol.at(i)<<endl;
    }*/


    for(Shape* i: V_Pol){
        outFile<<i;
    }
    outFile <<"</svg>";//SVG kodunu kapattim
    outFile.close();//SVG dosyasini kapattim

    bigArea=ContainerShape.CalculateAreaOfRect();//buyuk ve kucuk alanı buluyorum
    smallArea=count*InnerShapes.CalculateAreaOfRect();
    RestArea=CalculateRest(bigArea, smallArea);//kalan alani hesapliyorum
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;
}

void ComposedShape::OptimalFit(Rectangle& ContainerShape, Triangle& InnerShapes){

    bigWidth=ContainerShape.getWidth();//buyuk seklin kenar ve yuksekliklerini burada atiyorum
    bigHeight=ContainerShape.getHeight();
    smallEdge=InnerShapes.getEdge();

    double X=0;//buyuk dortgenin koordinatlarinin ilk degerlerini atadim
    double Y=0;
    decltype(smallEdge) x1=smallEdge/2, x2=0, x3=smallEdge;//kucuk ucgenin koordinatlarinin ilk degerlerini atadim
    //decltype'i kullandim, x1, x2 ve x3 smallEdge cinsinden tanimladim
    double y1=bigHeight-smallEdge*sqrt(3)/2, y2=bigHeight, y3=bigHeight;

    ofstream outFile("output.svg");//SVG dosyasini burada aciyorum
    outFile<< startSVG << endl;
    ContainerShape.setX(X);
    ContainerShape.setY(Y);
    ContainerShape.setColor("red");
    Rectangle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);
    //outFile<<ContainerShape;//overload ettigim << operatorunu burada kullandim. Outfile dosyasine drawing (writing) islemini yapiyor

    for (int i = 0; i <= bigHeight / smallEdge * sqrt(3) / 2; ++i) {
        for (int j = 0; j <= bigWidth / smallEdge - 1; ++j) {
            Triangle tempT(InnerShapes.getEdge());
            tempT.setX1_Y1(x1, y1);
            tempT.setX2_Y2(x2, y2);
            tempT.setX3_Y3(x3,y3);
            tempT.setColor("green");
            //Polygon Pol(tempT);
            V_Pol.push_back(&tempT);
            count++;
            x1 += smallEdge;
            x2 += smallEdge;
            x3 += smallEdge;
        }
        x1 = smallEdge / 2;//x1'i bir üst siraya cikardigimda tekrar ilk degerini aliyor, en sola geciyor
        x2 = 0;
        x3 = smallEdge;
        y1 -= smallEdge*sqrt(3)/2;//y1 y2 ve y3'u i ise bir üste cikardigimda kucuk ucgenin yüksekligi kadar azaltıyorum.
        y2 -= smallEdge*sqrt(3)/2;
        y3 -= smallEdge*sqrt(3)/2;
    }

    //Ters ucgenler icin buraya girip yine asagidan saga ve yukariya dogru dolduruyorum

    x1=smallEdge/2, x2=x1+smallEdge, x3=smallEdge;//x1 ve x3'u sabit tutup x2'yi degistirdim yukardaki noktaya aldim
    y1=bigHeight-smallEdge*sqrt(3)/2, y2=y1, y3=bigHeight;//y1 ve y3'u de ayni sekilde sabit tutup y2'yi degistirdim
    //burada y2 ile y1 ayni koordinatta oldugu icin y2'ye direkt y1'i atadim

    for (int i=0; i<bigHeight/smallEdge*sqrt(3)/2; ++i) {
        for (int j = 0; j <= bigWidth / smallEdge - 2; ++j) {
            Triangle tempT(InnerShapes.getEdge());
            tempT.setX1_Y1(x1, y1);
            tempT.setX2_Y2(x2, y2);
            tempT.setX3_Y3(x3,y3);
            tempT.setColor("green");
            //Polygon Pol(tempT);
            V_Pol.push_back(&tempT);
            count++;//kucuk seklin sayisini 1 arttiriyorum
            x1 += smallEdge;
            x2 += smallEdge;
            x3 += smallEdge;
        }
        x1 = smallEdge / 2;//duz yerlesen ucgenler gibi ayni islemler, ters yerlesenler icin de yaptim
        x2 = smallEdge  + x1;
        x3 = smallEdge;
        y1 -= smallEdge * sqrt(3)/2 ;
        y2 -= smallEdge * sqrt(3)/2 ;
        y3 -= smallEdge * sqrt(3)/2 ;
    }

    for(Shape* i: V_Pol){
        outFile<<i;
    }
    outFile << "</svg>";//svg kodunu kapattim
    outFile.close();//svg dosyasini kapattim

    bigArea=ContainerShape.CalculateAreaOfRect();//buyuk seklin alanini hesapladim
    smallArea=count*InnerShapes.CalculateAreaOfTri();//kucuk seklin alanini hesapladim
    RestArea=CalculateRest(bigArea, smallArea);//kalan alanaihesapladim. bunlari fonksiyonlarda hesapladim
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;
}

void ComposedShape::OptimalFit(Rectangle& ContainerShape, Circle& InnerShapes){
    bigWidth = ContainerShape.getWidth();
    bigHeight = ContainerShape.getHeight();
    smallRadius=InnerShapes.getRadius();//buyuk seklin kenar yukseklik ve kucuk seklin yaricapini getter fonksiyonlariyla atadim
    double X=0;
    double Y=0;
    decltype(smallRadius) cX=smallRadius;//X koordinati Circle'i ifade ediyor. Cunku Rectangle'in koordinatlari zaten 0,0 ve degismiyor
    decltype(smallRadius) cY=smallRadius;//Y koordinati da ayni sekilde Circle'i ifade ediyor.
    //decltype ile smallRadius cinsinden tanimladim, cX ve cY'leri.

    ofstream outFile("output.svg");//SVG doyasini burada actim
    outFile<< startSVG << endl;//SVG kodunu burada baslattim
    ContainerShape.setX(X);
    ContainerShape.setY(Y);
    ContainerShape.setColor("red");

    Rectangle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);

    for(int i=1; i<=bigHeight/(smallRadius*2); i++) {
        for (int j = 1; j <= bigWidth / (smallRadius * 2); j++) {
            Circle tempC(smallRadius);//Vektorde inner nesneleri (kucuk sekilleri) tutmasi icin Circle cinsinden temporary nesne olusturdum
            tempC.setX(cX);
            tempC.setY(cY);
            tempC.setColor("green");
            count++;
            //Polygon Pol(tempC);
            V_Pol.push_back(&tempC);
            cX += (smallRadius*2);
        }
        cX=smallRadius;// X'i tekrar smallRadius'a esitledim, en alt sira doldugunda bi alt en sola gecmesi icin
        cY += (smallRadius*2);//Y ise 2R kadar asagi inmeli
    }

    for(Shape* i: V_Pol){
        outFile<<i;
    }
    outFile << "</svg>";
    outFile.close();

    bigArea=ContainerShape.CalculateAreaOfRect();//buyuk seklin alaninin hesapladim
    smallArea=count*InnerShapes.CalculateAreaOfCirc();//kucuk seklin alanini hesapladim
    RestArea=CalculateRest(bigArea, smallArea);//kalan alanaihesapladim. bunlari fonksiyonlarda hesapladim
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;
}

void ComposedShape::OptimalFit(Triangle& ContainerShape, Rectangle& InnerShapes){

    bigEdge=ContainerShape.getEdge();
    smallWidth=InnerShapes.getWidth();
    smallHeight=InnerShapes.getHeight();
    /*double tempSH=max(smallWidth,smallHeight);
    double tempSW=min(smallWidth,smallHeight);
    smallHeight=max(tempSH, tempSW);//buyuk olana gore hareket etmem gerektigi icin max olani smallHeight'e estiledim
    smallWidth=min(tempSH, tempSW);//boylece seklin icine daha iyi oturacak ve daha cok sayida sekil sigabilecek*/

    double X1=bigEdge / 2, X2=0, X3= bigEdge;//buyuk ucgenin koordinatlarinin ilk degerlerini atadim
    double Y1=0, Y2=bigEdge * sqrt(3) / 2, Y3=bigEdge * sqrt(3) / 2;
    //60'in karsisi smallHeight, 30'un karsisi smallHeigth/sqrt(3), 90'in karsisi smallHeight/sqrt(3)*2 olur
    auto tempDown= smallHeight / sqrt(3);
    auto tempLeft= smallHeight / sqrt(3) * 2;

    auto x= tempDown;//tempDown tipinden olacak sekilde x degeri ve y degerini tanimladim.
    auto y= Y3 - smallHeight;

    ofstream outFile("output.svg");
    outFile<< startSVG << endl;

    ContainerShape.setX1_Y1(X1, Y1);
    ContainerShape.setX2_Y2(X2, Y2);
    ContainerShape.setX3_Y3(X3, Y3);
    ContainerShape.setColor("red");
    Triangle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);
    //outFile<<ContainerShape;
    //ContainerShape.draw(X1, Y1, X2, Y2, X3, Y3, "red", outFile);//buyuk sekli burada cizdirmek icin draw'u cagirdim

    for(int i=1; i<=bigEdge/smallHeight-1; ++i) {
        for (int j = 1; j <= bigEdge / smallWidth - i; ++j) {
            if ((x + smallWidth > X3 - (i * tempDown) && j >= bigEdge / smallHeight - i)) {
                //kucuk dortgen ucgenin en sagindaki cizgiden tasarsa hic bir sey yapmıyor ve bir üste geciyor.
            }
            else {
                Rectangle tempR(InnerShapes.getWidth(), InnerShapes.getHeight());//Vektorde inner nesneleri (kucuk sekilleri) tutmasi icin Rectangle cinsinden temporary nesne olusturdum
                tempR.setX(x);
                tempR.setY(y);
                tempR.setColor("green");
                //Polygon Pol(tempR);
                V_Pol.push_back(&tempR);
                count++;
                x += smallWidth;//x'i kucuk dortgenin yuksekligi kadar kaydiriyorum
            }
        }
        x= static_cast<int>(tempDown + i * tempDown);//x bir yukari gectiginde tekrar baslangic koordinatlarini ayarliyoruz
        y-=smallHeight;
    }
    for(Shape* i: V_Pol){
        outFile<<i;
    }
    outFile << "</svg>";
    outFile.close();//SVG dosyasini kapattim

    bigArea=ContainerShape.CalculateAreaOfTri();
    smallArea=count*InnerShapes.CalculateAreaOfRect();
    RestArea=CalculateRest(bigArea, smallArea);//buyuk sekil, kucuk sekil ve kalan alani hesapladim
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;
}

void ComposedShape::OptimalFit(Triangle& ContainerShape, Triangle& InnerShapes){
    bigEdge=ContainerShape.getEdge();
    smallEdge=InnerShapes.getEdge();
    double X1=bigEdge/2, X2=0, X3=bigEdge;//buyuk ucgenin koordinatlarinin ilk degerlerini atadim
    double Y1=0, Y2=bigEdge*sqrt(3)/2, Y3=bigEdge*sqrt(3)/2;
    double x1=smallEdge/2, x2=0, x3=smallEdge;//kucuk ucgenin koordinatlarinin ilk degerlerini atadim
    double y1=Y3-smallEdge*sqrt(3)/2, y2=bigEdge*sqrt(3)/2, y3=bigEdge*sqrt(3)/2;
    double tempJ=0;//bu degeri ikinci (icteki) for'un icinde kullanacagim

    ofstream outFile("output.svg");
    outFile<< startSVG << endl;

    ContainerShape.setX1_Y1(X1, Y1);
    ContainerShape.setX2_Y2(X2, Y2);
    ContainerShape.setX3_Y3(X3, Y3);
    ContainerShape.setColor("red");
    Triangle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);
    outFile<<ContainerShape;

    for(int i=0; i<bigEdge/smallEdge; ++i) {//dikey olarak dizilmelerini burada yapiyorum
        for (int j = 0; j <= bigEdge / smallEdge - i - 1; ++j) {//yatay dizilen ucgenleri burada sirayla diziyorum
            Triangle tempT(InnerShapes.getEdge());
            tempT.setX1_Y1(x1, y1);
            tempT.setX2_Y2(x2, y2);
            tempT.setX3_Y3(x3,y3);
            tempT.setColor("green");
            //Polygon Pol(tempT);
            V_Pol.push_back(&tempT);
            count++;//kucuk seklin sayisini 1 arttiriyorum
            x1+=smallEdge;
            x2+=smallEdge;
            x3+=smallEdge;
            tempJ=j;
        }
        x1=x1-(smallEdge)*tempJ-smallEdge/2;//x1 x2 ve x2'u en solda bi üstte olacak sekilde guncelliyorum
        x2=x2-(smallEdge)*tempJ-smallEdge/2;
        x3=x3-(smallEdge)*tempJ-smallEdge/2;
        y1-=smallEdge*sqrt(3)/2;//y1 y2 ve y3'u de ayni sekilde guncelliyorum
        y2-=smallEdge*sqrt(3)/2;
        y3-=smallEdge*sqrt(3)/2;
    }

    //ters yerlesen ucgenler icin ayni islemleri koordinatlarini degistirip yapiyorum
    x1=smallEdge, x2=smallEdge/2, x3=smallEdge*3/2;
    y1=bigEdge*sqrt(3)/2 ,y2=Y3-smallEdge*sqrt(3)/2, y3=Y3-smallEdge*sqrt(3)/2;
    tempJ;

    for(int i=0; i<bigEdge/smallEdge; ++i) {//burada da ters dizilen ucgenler icin ayni islemleri yapiyorum
        for (int j = 0; j <= bigEdge / smallEdge - i - 2; ++j) {
            Triangle tempT(InnerShapes.getEdge());
            tempT.setX1_Y1(x1, y1);
            tempT.setX2_Y2(x2, y2);
            tempT.setX3_Y3(x3,y3);
            tempT.setColor("green");
            //Polygon Pol(tempT);
            V_Pol.push_back(&tempT);
            count++;//kucuk seklin sayisini 1 arttiriyorum
            x1 += smallEdge;
            x2 += smallEdge;
            x3 += smallEdge;
            tempJ = j;
        }
        x1 = x1 - (smallEdge) * tempJ - smallEdge / 2;//x1 x2 ve x3'leri burada yeniden tanimliyorum
        x2 = x2 - (smallEdge) * tempJ - smallEdge / 2;//ilk sira bitti cunku
        x3 = x3 - (smallEdge) * tempJ - smallEdge / 2;
        y1 -= smallEdge * sqrt(3) / 2;
        y2 -= smallEdge * sqrt(3) / 2;
        y3 -= smallEdge * sqrt(3) / 2;
    }

    for(Shape* i: V_Pol){
        outFile<<i;
    }
    outFile << "</svg>";
    outFile.close();

    bigArea=ContainerShape.CalculateAreaOfTri();//buyuk seklin alanini hesapladim
    smallArea=count*InnerShapes.CalculateAreaOfTri();//kucuk seklin alanini hesapladim
    RestArea=CalculateRest(bigArea, smallArea);//kalan alanaihesapladim. bunlari fonksiyonlarda hesapladim
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;

}

void ComposedShape::OptimalFit(Triangle& ContainerShape, Circle& InnerShapes){
    bigEdge=ContainerShape.getEdge();
    smallRadius=InnerShapes.getRadius();
    double X1= bigEdge / 2, X2=0, X3=bigEdge;//buyuk ucgenin koordinatlarinin ilk degerlerini atadim
    double Y1=0, Y2= bigEdge * sqrt(3) / 2, Y3=bigEdge * sqrt(3) / 2;
    double x=smallRadius*sqrt(3);//x en soldan kucuk yaricapin kok 3 kati kadar sagda baslar
    double y=bigEdge*sqrt(3)/2-smallRadius;//y ucgenin yuksekliginin kucuk yaricap eksigi kadar asagida baslar

    ofstream outFile("output.svg");
    outFile<< startSVG << endl;

    ContainerShape.setX1_Y1(X1, Y1);
    ContainerShape.setX2_Y2(X2, Y2);
    ContainerShape.setX3_Y3(X3, Y3);
    ContainerShape.setColor("red");
    Triangle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);

    for(int i=1; i<=(bigEdge- 2*(smallRadius*sqrt(3)-smallRadius))/(smallRadius*2); i++) {
        for (int j = 1; j <= (bigEdge - 2 * (smallRadius * sqrt(3) - smallRadius)) / (smallRadius * 2) - i + 1; j++) {

            Circle tempT(InnerShapes.getRadius());
            tempT.setX(x);
            tempT.setY(y);
            tempT.setColor("green");
            //Polygon Pol(tempT);
            V_Pol.push_back(&tempT);
            count++;//kucuk seklin sayisini 1 arttiriyorum
            x += (smallRadius * 2); //x'i Cap kadar saga kaydiriyor yatayda
        }
        x=smallRadius*i + smallRadius*sqrt(3);//x'i ilk halinin yaricap * i kadar sagina kaydiriyor her seferinde
        y-=(smallRadius*sqrt(3));//y'yi de kucuk yaricap carpi kok 3 kadar yukari cıkartıyor
    }
    for(Shape* i: V_Pol){
        outFile<<i;
    }
    outFile << "</svg>";
    outFile.close();

    bigArea=ContainerShape.CalculateAreaOfTri();//buyuk seklin alanini hesapladim
    smallArea=count*InnerShapes.CalculateAreaOfCirc();//kucuk seklin alanini hesapladim
    RestArea=CalculateRest(bigArea, smallArea);//kalan alanaihesapladim. bunlari fonksiyonlarda hesapladim
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;

}

void ComposedShape::OptimalFit(Circle& ContainerShape, Rectangle& InnerShapes){
    bigRadius=ContainerShape.getRadius();
    smallWidth=InnerShapes.getWidth();
    smallHeight=InnerShapes.getHeight();
    double X=bigRadius;//buyuk seklin yaricapini x ve y koordinatlarina atadım
    double Y=bigRadius;

    double bottomHeight=ContainerShape.FindHeightOfBottom(bigRadius, smallWidth);//burada en altta bulunan yuksekligi bulan fonksiyona gerekli parametreleri gonderdim
    int top = 1; //asagidan doldurmaya basladigim circle icinde tam ortaya gelip yukari kisma gecmis miyim onu kontrol eden integer deger
    double x;
    double y = 2*bigRadius-(smallHeight+bottomHeight);//x ve y koordinatlarina gerekli degerleri atadim

    ofstream outFile("output.svg");
    outFile<< startSVG << endl;

    ContainerShape.setX(X);
    ContainerShape.setY(Y);
    ContainerShape.setColor("red");
    Circle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);

    Rectangle tempR(smallWidth, smallHeight);

    for (int i=0; i <=((2*bigRadius-2 * bottomHeight)/smallHeight); i++) {
        double bottom=0;//her seferinde circle icinde olusturdugum hayali dortgenin en alt kısmının yarisini bottom olarak belirledim
        int countOfWRect = 0;
        double tempbottom;
        if (y - bigRadius<=smallHeight / 2 && top==1) {//tam ortadaki hat icin bu kısmı olusturdum.
            /*eger y-bigradius, smallHeight/2'den kucuk veya esitse ve top degeri 1'e
             * esitse tam ortadaki hayali dortgen hatta gelmisiz demektir.*/
            top = 0;
        }
        else {
            if (top==1){ //alt kısım

                tempbottom = (bigRadius*bigRadius)-(bigRadius-(bottomHeight+(i)*smallHeight))*(bigRadius-(bottomHeight + (i)*smallHeight));
                bottom = sqrt(tempbottom);//burada bottomu tekrar guncelledim
                countOfWRect = static_cast<int>(2 * bottom / smallWidth);//yanyana kac dortgen sigdigini tutan degeri guncelledim
                x = bigRadius-bottom;//x degeri buyuk yaricaptan bottom kadar geriye gelir
                y = 2*bigRadius-(bottomHeight + smallHeight*(i + 1));

                for (int j=0; j<countOfWRect; j++) {
                    count++;//kucuk seklin sayisini 1 arttiriyorum
                    Rectangle tempR(InnerShapes.getWidth(), InnerShapes.getHeight());//Vektorde inner nesneleri (kucuk sekilleri) tutmasi icin Rectangle cinsinden temporary nesne olusturdum
                    tempR.setX(x);
                    tempR.setY(y);
                    tempR.setColor("green");
                    //Polygon Pol(tempR);
                    V_Pol.push_back(&tempR);
                    x+=smallWidth;//x koordinatini dortgenin uzunlugu (aslinda yeni genisligi) kadar artiriyorum
                }
            }

            else{//ust kısıma gectigi yer burasi ortadaki hattan ust kısma gectik

                tempbottom = (bigRadius*bigRadius)-(smallHeight-(y-bigRadius))*(smallHeight - (y-bigRadius));
                bottom = sqrt(tempbottom);//bottomu yine guncelledim
                countOfWRect = static_cast<int>(2 * bottom / smallWidth);//yanyana kac dortgen sigdigini bulan degeri burada da guncelledim
                x = bigRadius - bottom;//x degeri buyuk yaricaptan bottom kadar geriye gelir
                y = y - smallHeight;

                for (int j=0; j<countOfWRect; j++) {
                    count++;//kucuk seklin sayisini 1 arttiriyorum
                    Rectangle tempR(InnerShapes.getWidth(), InnerShapes.getHeight());//Vektorde inner nesneleri (kucuk sekilleri) tutmasi icin Rectangle cinsinden temporary nesne olusturdum
                    tempR.setX(x);
                    tempR.setY(y);
                    tempR.setColor("green");
                    //Polygon Pol(tempR);
                    V_Pol.push_back(&tempR);
                    x+=smallWidth;//x koordinatini dortgenin uzunlugu (aslinda yeni genisligi) kadar artiriyorum
                }
            }
        }
    }

    for(Shape* i: V_Pol){
        outFile<<i;
    }
    /*for(Rectangle tempR: V_Rect){
        outFile<<tempR;
    }*/


    outFile << "</svg>";
    outFile.close();

    bigArea=ContainerShape.CalculateAreaOfCirc();//buyuk seklin alanini hesapladim
    smallArea=count*InnerShapes.CalculateAreaOfRect();//kucuk seklin alanini hesapladim
    RestArea=CalculateRest(bigArea, smallArea);//kalan alani hesapladim. bunlari fonksiyonlarda hesapladim
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;
}

void ComposedShape::OptimalFit(Circle& ContainerShape, Triangle& InnerShapes){

    bigRadius=ContainerShape.getRadius();
    smallEdge=InnerShapes.getEdge();
    double X=bigRadius;
    double Y=bigRadius;
    auto centerX=bigRadius;
    auto centerY=bigRadius;
    auto x2= centerX - smallEdge / 2, y2= centerY + smallEdge * sqrt(3) / 2;//kucuk ucgenin koordinatlarinin ilk degerlerini atadim.
    auto x3= centerX + smallEdge / 2, y3= centerY + smallEdge * sqrt(3) / 2;//auto kullandim, burada tipi ne ise degeri o sekilde olusturacak
    double rot=0, rotX=bigRadius, rotY=bigRadius;

    Circle tempC=(smallRadius);
    ofstream outFile("output.svg");
    outFile << startSVG << endl;

    ContainerShape.setX(X);
    ContainerShape.setY(Y);
    ContainerShape.setColor("red");
    Circle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);
    //outFile<<ContainerShape;

    if(bigRadius==smallEdge){
        count=0;//dairenin merkez noktasının açısı 360 derece olduğu için merkezden dışa doğru 60 derecelik 6 adet eşkenar uçgen sığdırılır

        for(int i=0; i<6; i++) {

            count++;
            V_Pol.push_back(&tempC);
            //    V_Circ.push_back(tempC);//her bir kucuk sekli burada vector'e atiyorum
            //InnerShapes.draw(centerX, centerY, x2, y2, x3, y3, "green", outFile);

            outFile << "<polygon transform=\"rotate(" <<rot<< " " <<rotX<< " " <<rotY<<")\" points=\"" << centerX << "," << centerY
                    << "," << x2 << "," << y2 << "," << x3 << "," << y3 <<
                    "\" fill=\"green\"/>" << endl;//burada rotate de isin icine girdigi icin elle yazdirdim. draw fonksiyonunu cagirmadim.

            rot+=60;//60'ar derece dönderiyoruz merkez cevresinde
        }
    }
    else if(smallEdge>bigRadius && smallEdge<=bigRadius*sqrt(3)){
        count=1;//ucgenin kenari dairenin çapindan bir mm bile buyukse 1 taneden fazla ucgen sigamaz
        Triangle tempT(InnerShapes.getEdge());
        tempT.setX1_Y1(centerX, 0);
        tempT.setX2_Y2(x2, y2-bigRadius/4-(centerY-bigRadius/4));
        tempT.setX3_Y3(x3, y3-bigRadius/4-(centerY-bigRadius/4));
        tempT.setColor("green");
        //Polygon Pol(tempT);
        V_Pol.push_back(&tempT);
        //InnerShapes.draw(centerX, 0, x2, y2-bigRadius/4-(centerY-bigRadius/4), x3, y3-bigRadius/4-(centerY-bigRadius/4), "green", outFile );
//        V_Tri.push_back(tempT);//kucuk sekli burada vector'e atiyorum. zaten 1 tane olusacak
    }
    else if(smallEdge>bigRadius*sqrt(3)){
        count=0;//yaricapin kok 3 katindan buyukse sigmaz
    }
    else{
        //ucgenin kenari yaricaptan cok daha kucukse buraya girecek
        bigEdge=bigRadius*2;
        double Y3=bigEdge*sqrt(3)/2;
        double a1=smallEdge/2, a2=0, a3=smallEdge;
        double b1=Y3-smallEdge*sqrt(3)/2, b2=bigEdge*sqrt(3)/2, b3=bigEdge*sqrt(3)/2;
        int tempJ=0;

        for(int i=0; i<bigEdge/smallEdge; ++i) {
            for(int j=0; j<=bigEdge/smallEdge-i-1; ++j) {
                Triangle tempT(InnerShapes.getEdge());
                tempT.setX1_Y1(a1, b1);
                tempT.setX2_Y2(a2, b2);
                tempT.setX3_Y3(a3, b3);
                tempT.setColor("green");
                //V_Tri.push_back(tempT);
                //Polygon Pol(tempT);
                V_Pol.push_back(&tempT);
                a1+=smallEdge;//koordinatlari arttiriyorum
                a2+=smallEdge;
                a3+=smallEdge;
                tempJ=j;
                count++;
            }
            a1=a1-(smallEdge)*tempJ-smallEdge/2;//koordinatlari tekrar tanimliyorum
            a2=a2-(smallEdge)*tempJ-smallEdge/2;
            a3=a3-(smallEdge)*tempJ-smallEdge/2;
            b1-=smallEdge*sqrt(3)/2;
            b2-=smallEdge*sqrt(3)/2;
            b3-=smallEdge*sqrt(3)/2;
        }



    }

    for(Shape* i: V_Pol){
        outFile<<i;
    }
    /*for(Triangle tempT: V_Tri){
        outFile<<tempT;
    }*/
    outFile << "</svg>";
    outFile.close();//SVG kodu burada bitiyor


    bigArea=ContainerShape.CalculateAreaOfCirc();//buyuk seklin alanini hesapladim
    smallArea=count*InnerShapes.CalculateAreaOfTri();//kucuk seklin alanini hesapladim
    RestArea=CalculateRest(bigArea, smallArea);//kalan alani hesapladim. bunlari fonksiyonlarda hesapladim
    cout<<"I can fit at most "<< count << " small shapes into the main container. The empty area (red) in container is "<< RestArea<<endl<<endl;
}

void ComposedShape::OptimalFit(Circle& ContainerShape, Circle& InnerShapes) {

    bigRadius = ContainerShape.getRadius();
    smallRadius = InnerShapes.getRadius();
    double smallR = smallRadius * 2;//smallRadius'u iki ile çarptım, cunku bazı fonksiyonlarda yaricap degil capini kullanacagim
    decltype(bigRadius) X = bigRadius;//buyuk seklin yaricapini x ve y koordinatlarina atadım
    double Y = bigRadius;

    /*double tempSH= smallHeight;
    double tempSW = smallWidth;
    smallWidth=max(tempSW, tempSH);//buyuk olan width olmali, o yüzden buyuk olani width'e tanimladim. RinT'deki gibi
    smallHeight=min(tempSW, tempSH);//cunku asagidaki kisimda buyuk olana gore hareket ediyorum
*/
    double bottomHeight = ContainerShape.FindHeightOfBottom(bigRadius, smallR);//burada en alttaki yuksekligi bulan fonksiyona gerekli parametreleri gonderdim
    int top = 1; //asagidan doldurmaya basladigim circle icinde tam ortaya gelip yukari kisma gecmis miyim onu kontrol eden integer deger
    double x = bigRadius - smallR + smallRadius;
    double y = 2 * bigRadius - (smallR + bottomHeight) + smallRadius;//x ve y koordinatlarina gerekli degerleri atadim

    ofstream outFile("output.svg");
    outFile << startSVG << endl;

    ContainerShape.setX(X);
    ContainerShape.setY(Y);
    ContainerShape.setColor("red");
    Circle BigPol(ContainerShape);
    V_Pol.push_back(&BigPol);
    //outFile<<ContainerShape;

    double oran = bigRadius / smallRadius;
    if (oran >= 1 && oran < 2) {//buyuk R ile kucuk r'nin bolumu 1 ile 2 arasinda ise 1 tane sigar
        count = 1;//1 tane sigacagi icin direkt olarak 1'e esitledim
        Circle tempC(InnerShapes.getRadius());
        tempC.setX(X);
        tempC.setY(Y);
        tempC.setColor("green");
        //Polygon Pol(tempC);
        V_Pol.push_back(&tempC);
        //V_Circ.push_back(tempC);//her bir kucuk sekli burada vector'e atiyorum
    }
    else if (oran == 2) {//buyuk R ile kucuk r'nin bolumu 2 ise en fazla 2 tane sigar
        count = 2;
        for(int t=0; t<2; t++) {
            Circle tempC(InnerShapes.getRadius());
            tempC.setX(X / 2);
            tempC.setY(Y);
            tempC.setColor("green");
            //Polygon Pol(tempC);
            V_Pol.push_back(&tempC);
            //V_Circ.push_back(tempC);
            X= 2* (bigRadius * 3 / 2);
        }
    }
    else if (oran >= 3 && oran < 4) {//oran 4 ile 4 arasinda ise de 5 adet sigar
        count = 5;
        x = X / 3;
        for (int i = 1; i < 4; i++) {
            Circle tempC(InnerShapes.getRadius());
            tempC.setX(x);
            tempC.setY(Y);
            tempC.setColor("green");
            //Polygon Pol(tempC);
            V_Pol.push_back(&tempC);
            //V_Circ.push_back(tempC);
            x += 2 * X / 3;
        }
        y = Y / 3;
        for (int j = 1; j < 3; ++j) {
            Circle tempC(InnerShapes.getRadius());
            tempC.setX(X);
            tempC.setY(y);
            tempC.setColor("green");
            //Polygon Pol(tempC);
            V_Pol.push_back(&tempC);
            //V_Circ.push_back(tempC);
            y += 4 * Y / 3;
        }
    }
    else {

        for (int i = 0; i <= ((2 * bigRadius - 2 * bottomHeight) / smallR); i++) {

            double bottom = 0;//her seferinde circle icinde olusturdugum hayali dortgenin en alt kısmının yarisini bottom olarak belirledim
            int countOfWRect = 0;
            double tempbottom;
            if (y - bigRadius <= smallR / 2 && top == 1) {//tam ortadaki hat icin bu kısmı olusturdum.
                //eger y-bigradius, smallHeight/2'den kucuk veya esitse ve top degeri 1'e
                // esitse tam ortadaki hayali dortgen hatta gelmisiz demektir.
                top = 0;
            }
            else {
                if (top == 1) { //alt kısım

                    tempbottom = (bigRadius * bigRadius) - (bigRadius - (bottomHeight + (i) * smallR)) * (bigRadius - (bottomHeight + (i) * smallR));
                    bottom = sqrt(tempbottom);//burada bottomu tekrar guncelledim
                    countOfWRect = static_cast<int>(2 * bottom / smallR);//yanyana kac daire sigdigini tutan degeri guncelledim
                    x = bigRadius - bottom +smallRadius;//x degeri buyuk yaricaptan bottom kadar geriye gelir
                    y = 2 * bigRadius - (bottomHeight + smallR * (i + 1)) + smallRadius;

                    for (int j = 0; j < countOfWRect; j++) {
                        Circle tempC(InnerShapes.getRadius());
                        tempC.setX(x);
                        tempC.setY(y);
                        tempC.setColor("green");
                        count++;//kucuk seklin sayisini 1 arttiriyorum
                        //V_Circ.push_back(tempC);//her bir kucuk sekli burada vector'e atiyorum
                        //Polygon Pol(tempC);
                        V_Pol.push_back(&tempC);
                        x += smallR;//x koordinatini dairenin ucapi kadar artiriyorum
                    }
                }
                else {//ust kısıma gectigi yer burasi ortadaki hattan ust kısma gectik

                    tempbottom = (bigRadius * bigRadius) - (smallR - (y - bigRadius)) * (smallR - (y - bigRadius));
                    bottom = sqrt(tempbottom);//bottomu yine guncelledim
                    countOfWRect = static_cast<int>(2 * bottom / smallR);//yanyana kac daire sigdigini bulan degeri burada da guncelledim
                    x = bigRadius - bottom+ smallRadius;//x degeri buyuk yaricaptan bottom kadar geriye gelir
                    y = y - smallR ;

                    for (int j = 0; j < countOfWRect; j++) {
                        count++;//kucuk seklin sayisini 1 arttiriyorum
                        Circle tempC(InnerShapes.getRadius());
                        tempC.setX(x);
                        tempC.setY(y);
                        tempC.setColor("green");
                        //V_Circ.push_back(tempC);//her bir kucuk sekli burada vector'e atiyorum
                        //Polygon Pol(tempC);
                        V_Pol.push_back(&tempC);
                        x += smallR;//x koordinatini dairenin capi kadar artiriyorum
                    }
                }
            }
        }

    }
    for(Shape* i: V_Pol){
        outFile<<i;
    }
    /*for(Circle tempC: V_Circ){//BURAYA NE YAPILABILIR ????
        outFile<<tempC;
    }*/
    outFile << "</svg>";
    outFile.close();

    bigArea = ContainerShape.CalculateAreaOfCirc();//buyuk seklin alanini hesapladim
    smallArea =count*(InnerShapes.CalculateAreaOfCirc());//kucuk seklin alanini hesapladim
    RestArea = CalculateRest(bigArea, smallArea);//kalan alani hesapladim. bunlari fonksiyonlarda hesapladim
    cout << "I can fit at most " << count
         << " small shapes into the main container. The empty area (red) in container is " << RestArea<<endl;
}

double ComposedShape::CalculateRest(double bigArea, double smallArea) {
    return (bigArea - smallArea);
}

double ComposedShape::getArea() {
    return 0;
}

double ComposedShape::getPerimeter() {
    return 0;
}

Shape &ComposedShape::operator++() {
    //return <#initializer#>;
}

Shape &ComposedShape::operator++(int) {
    //return <#initializer#>;
}

Shape &ComposedShape::operator--() {
    //return <#initializer#>;
}

Shape &ComposedShape::operator--(int) {
    //return <#initializer#>;
}

vector<Shape *> ComposedShape::getVector() {
    return V_Pol;
}









/*
vector<Rectangle> ComposedShape::getVectorRect() {//rectangle tutan vektorun getter'ı
    return V_Rect;
}
vector<Triangle> ComposedShape::getVectorTri() {//triangle tutan vektorun getter'ı
    return V_Tri;
}
vector<Circle> ComposedShape::getVectorCirc() {//triangle tutan vektorun getter'ı
    return V_Circ;
}
vector<Polygon> ComposedShape::getVectorPol(){
    return V_Pol;
}

*/