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

    int s1,s2;
    int k,h1;

    double i=1;
    h1=1;
    for(int j=0;j<i;j++){
        h1*=10;
    }
    k=n%h1;
    h1=1;
    for(int j=0;j<i-1;j++){
        h1*=10;
    }
    s1=k/h1;
    h1=1;
    for(int j=0;j<i-1;j++){
        h1*=10;
    }
    h1=k*h1;
    n=n-h1;
    i++;


    while(n!=0){
        h1=1;
        for(int j=0;j<i;j++){
            h1*=10;
        }
        k=n%h1;
        h1=1;
        for(int j=0;j<i-1;j++){
            h1*=10;
        }
        s2=k/h1;
        if(s1<s2){
            cout<<"The sequence is not increasing"<<endl;
            return 0;
        }
        s1=s2;
        k=s1;
        h1=1;
        for(int j=0;j<i-1;j++){
            h1*=10;
        }
        h1=k*h1;
        n=n-h1;
        i++;
    }

    cout<<"The sequence is increasing"<<endl;


    return 0;
}
