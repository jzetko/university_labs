#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N;
    cout<<"Enter N: ";
    cin>>N;

    double *arr=new double[N];

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<N;i++){
            cout<<i+1<<": ";
            cin>>arr[i];
        }
    }
    else{
        for(int i=0;i<N;i++){
            arr[i]=-50+rand()%100;
        }
    }
    int mx=arr[0];
    int sum=0;
    cout<<"Our Array: [ ";
    for(int i=0;i<N;i++){
        if(arr[i]>mx){
            mx=arr[i];
            sum=0;
        }
        if(arr[i]==mx){
            sum++;
        }
        cout<<arr[i]<<" ; ";
    }
    cout<<"]"<<endl<<"Maximum element="<<mx<<endl<<"Numbers of maximum element="<<sum<<endl;


    delete [] arr;
    return 0;
}
