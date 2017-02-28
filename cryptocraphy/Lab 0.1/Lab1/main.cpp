#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int quick(long A, long Z, long N){

    int res=1;
    while(Z>0){
        if(Z==1){
            res*=A%N;
            break;
        }
        res*=(A*A)%N;
        Z-=2;
    }
    res=res%N;

    return res;

}


int main()
{

    long a,z,n;
    cout<<"Equation is: x=(a^z)mod n\nEnter the koefficients!!!\na=";
    cin>>a;
    cout<<"z=";
    cin>>z;
    cout<<"n=";
    cin>>n;
    long result=quick(a,z,n);
    cout<<"Result="<<result<<endl;

    return 0;
}
