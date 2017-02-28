#include <iostream>
#include <cstdlib>

using namespace std;

void Evclid(int a, int b, int *x, int *y, int *nod){

    long q, r, x1, x2, y1, y2;

    if(b==0){
        *nod=a;
        *x=1;
        *y=0;
        return;
    }

    x2=1;
    x1=0;
    y2=0;
    y1=1;

    while(b>0){
        q=a/b;
        r=a-q*b;
        *x=x2-q*x1;
        *y=y2-q*y1;
        a=b;
        b=r;
        x2=x1;
        x1=*x;
        y2=y1;
        y1=*y;
    }

    *nod=a;
    *x=x2;
    *y=y2;

}



int main()
{
    int a,b,nod,x,y;
    cout<<"Enter the numbers:"<<endl<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    if(a<=0||b<=0){
        cout<<"Number(s) is(are) wrong!"<<endl;
        system("PAUSE");
        return 0;
    }

    Evclid(a,b,&x,&y,&nod);
    if(nod!=1){
        cout<<"!!!This numbers are not coprime!!!\n";
    }
    cout<<"nod="<<nod<<endl<<"x="<<x<<endl<<"y="<<y<<endl<<"Our function is:"<<endl<<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<nod<<endl;



    return 0;
}
