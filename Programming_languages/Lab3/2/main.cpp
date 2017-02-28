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

    int *mass=new int[n];

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<" element: ";
            cin>>mass[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            mass[i]=-100+rand()%200;
        }
    }
    cout<<"Our array:"<<endl<<"Array=[";
    for(int i=0;i<n;i++){
        cout<<mass[i]<<",";
    }
    cout<<"]"<<endl;

    int counter=0;


    for(int i=1;i<n-1;i++){
        if(mass[i]>mass[i-1]&&mass[i]>mass[i+1]){counter++;}
    }
    cout<<"Result: "<<counter;

    delete [] mass;
    return 0;
}
