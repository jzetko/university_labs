#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    int n;

    cout<<"Enter n: ";
    cin>>n;

    if (n<=0){
        cout<<"Failed input";
        return 0;
    }

    int *A=new int[n];

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>A[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            A[i]=-50+rand()%100;
        }
    }

    cout<<"Our array:"<<endl<<"Array=[";
    for(int i=0;i<n;i++){
        cout<<A[i]<<";";
    }
    cout<<"]"<<endl;

    int mn=A[0];
    int mx=A[0];

    for(int i=1;i<n;i++){
        if(A[i]<mn){
            mn=A[i];
        }
        if(A[i]>mx){
            mx=A[i];
        }
    }

    cout<<"Result: "<<mx<<"-"<<mn<<"="<<mx-mn<<endl;

    delete [] A;
    return 0;
}
