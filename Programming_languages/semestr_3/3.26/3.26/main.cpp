#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "Decimal.h"

using namespace std;

int main()
{
    Decimal m1,m2;
    m1.Read();
    m2.Read();
    cout<<"m1=";
    m1.Display();
    cout<<"m2=";
    m2.Display();

    /*if(m1==m2){
        cout<<"Yes";
    }
    else
        cout<<"No";*/

    Compare(m1,m2);
    m1+m2;

    return 0;
}
