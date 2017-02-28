#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

int main()
{
    double A,B,C,D;
    cout<<"Enter A: ";
    cin>>A;
    cout<<"Enter B: ";
    cin>>B;
    cout<<"Enter C: ";
    cin>>C;

    double xn,xk,h,x,y;

    cout<<"Enter xn: ";
    cin>>xn;
    cout<<"Enter xk: ";
    cin>>xk;
    cout<<"Enter h: ";
    cin>>h;

    x=xn;
    cout<<"x:\ty:"<<endl;
    while(x<=xk){
        y=A*pow(x,3)+B*x-C;
        cout<<x<<"\t"<<y<<endl;
        x+=h;
    }


    return 0;
}
