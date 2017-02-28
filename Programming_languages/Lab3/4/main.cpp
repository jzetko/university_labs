#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    if(n<=0){
        cout<<"Failed input"<<endl;
        return 0;
    }

    int summ=0;
    int k,h2;
    int h1;
    int counter=0;
    double i=1;
    while(n!=0){
        counter++;
        h1=1;
        for(int j=0;j<i;j++){
            h1*=10;
        }
        k=n%h1;
        h1=1;
        for(int j=0;j<i-1;j++){
            h1*=10;
        }
        k=k/h1;
        summ+=k;
        h2=1;
        for(int j=0;j<i-1;j++){
            h2*=10;
        }
        h2=k*h2;
        n=n-h2;
        i++;
    }


    cout<<"Number of elements="<<counter<<endl;
    cout<<"Addition of elements="<<summ<<endl;
    return 0;
}
