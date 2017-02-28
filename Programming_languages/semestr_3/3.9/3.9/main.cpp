#include <iostream>
#include <cstdlib>
#include <string>
#include "math.h"
using namespace std;

class Triangle{
    protected:
        double a,b,c;
    public:
        Triangle(double aa, double bb, double cc);
        Triangle();
        ~Triangle();
        void AddTriangle();
        void Check();
        void ChangeTriangle();
        void Perimetr();
        void Findangles();
};

class Rightangle: public Triangle{
    private:
        double square;
    public:
        void Findsquare();
        void CheckonRight();
        void Menu();
};

Triangle::Triangle(double aa, double bb, double cc){
    a=aa;
    b=bb;
    c=cc;
    Check();
}

Triangle::Triangle(){
a=0;
b=0;
c=0;
}

Triangle::~Triangle(){
    std::cout << "Destructor\n";
}

void Triangle::AddTriangle(){
    cout<<"ВВедите сторону a:";
    cin>>a;
    cout<<"ВВедите сторону b:";
    cin>>b;
    cout<<"ВВедите сторону c:";
    cin>>c;
    Check();
}

void Triangle::Check(){
    double a1=a;
    double b1=b;
    double c1=c;
    if ((a1+b1<c1)||(a1+c1<b1)||(b1+c1<a1)){
        cout<<"Данный объект не является треугольником! Задайте другие параметры."<<endl<<endl;
        ChangeTriangle();
    }
}

void Triangle::ChangeTriangle(){
cout<<"Введите новые параметры(стороны) треугольника:"<<endl;
cout<<"Сторона a=";
cin>>a;
cout<<"Сторона b=";
cin>>b;
cout<<"Сторона c=";
cin>>c;
Check();
}

void Triangle::Perimetr(){
    double a2=a;
    double b2=b;
    double c2=c;
    double p=a2+b2+c2;
    cout<<"Периметр треугольника равен="<<p<<endl<<endl;
}

void Triangle::Findangles(){
    double alfa, beta, gamma; //alfa-угол против стороны a, beta-угол против стороны b, gamma-угол против стороны с
    double a3=a;
    double b3=b;
    double c3=c;
    alfa=acos((pow(a3,2)-pow(b3,2)-pow(c3,2))/(-2*b3*c3));
    beta=acos((pow(b3,2)-pow(a3,2)-pow(c3,2))/(-2*a3*c3));
    gamma=acos((pow(c3,2)-pow(a3,2)-pow(b3,2))/(-2*a3*b3));
    cout<<"Угол против стороны a(alfa)="<<alfa<<endl;
    cout<<"Угол против стороны b(beta)="<<beta<<endl;
    cout<<"Угол против стороны c(gamma)="<<gamma<<endl;
    cout<<"Все углы выражены в радианах"<<endl<<endl;
}

void Rightangle::Menu(){
    int j;//переменная для свича
	do{
	cout<<"\n1. Изменить стороны\n2. Вывести периметр треугольника\n3. Вывести углы треугольника\n4. Проверка на прямоугольность и нахождение площади\n5. Выход"<<endl<<endl;
	cin>>j;
	switch (j){
		case 1:{
            ChangeTriangle();
            break;
        }
		case 2:{
            Perimetr();
            break;
        }
		case 3:{
            Findangles();
            break;
        }
        case 4:{
            CheckonRight();
            break;
        }
        case 5:{
            exit (0);
        }
	}
	}while (true);
}

void Rightangle::CheckonRight(){
    if((pow(a,2)==pow(b,2)+pow(c,2))||(pow(b,2)==pow(a,2)+pow(c,2))||(pow(c,2)==pow(a,2)+pow(b,2))){
        Findsquare();
    }
    else{
        cout<<"Данный треугольник не являеться прямоугольным, чтобы найти площадь, измените параметры треугольника"<<endl;
    }
}


void Rightangle::Findsquare(){
    if(pow(a,2)==pow(b,2)+pow(c,2)){
        square=(b*c)/2;
    }
    if (pow(b,2)==pow(a,2)+pow(c,2)){
        square=(a*c)/2;
    }
    if (pow(c,2)==pow(a,2)+pow(b,2)){
        square=(a*b)/2;
    }
    cout<<"Данный треугольник является прямоугольным\nПлощадь="<<square<<endl;
}
int main()
{
    setlocale(LC_ALL,"Russian");

    Triangle t1(90,4,5);
    Rightangle r1;
    r1.Menu();
    system("PAUSE");
    return 0;
}
