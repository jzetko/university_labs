#include <iostream>
#include <cstdlib>
using namespace std;

int nok(int a, int b){
    int mx=b;
    for(int i=mx;i>0;i++){
        if((i%a==0)&&(i%b==0)){
            return i;
        }
    }
}

int main()
{
    int a,b;
    cout<<"Enter the 1st number: ";
    cin>>a;
    cout<<"Enter the 2nd number: ";
    cin>>b;

    int res;
    res=nok(a,b);
    cout<<"NOK="<<res;

    return 0;
}


