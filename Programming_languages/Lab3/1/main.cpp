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
    int checker;
    if(mass[0]<0){checker=-1;}
    else{checker=1;}

    for(int i=0;i<n;i++){
        if(mass[i]>=0&&checker==-1){
            counter++;
            checker=1;
        }
        if(mass[i]<0&&checker==1){
            counter++;
            checker=-1;
        }

    }
    cout<<"Result: "<<counter;

    delete [] mass;
    return 0;
}
