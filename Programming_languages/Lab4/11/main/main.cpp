#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    if(n<1){
        cout<<"Failed input"<<endl;
        return 0;
    }

    double *arr=new double[n];

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>arr[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            arr[i]=-50+rand()%100;
        }
    }

    cout<<"Our Array: [";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
    cout<<"]"<<endl;

    int mn=arr[0];
    int position=0;
    int h1;
    for(int i=1;i<n;i++){
        if (arr[i]<mn){
            mn=arr[i];
            position=i;
        }
    }

    cout<<mn<<" "<<position<<endl;

    h1=arr[position];
    arr[position]=arr[0];
    arr[0]=h1;

    for(int i=1;i<n-1;i++){
        mn=arr[i];
        position=i;
        for(int j=i+1;j<n;j++){
            if (arr[j]<mn){
                mn=arr[j];
                position=j;
            }
        }
        h1=arr[position];
        arr[position]=arr[i];
        arr[i]=h1;
    }



    cout<<"Result array: [";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
    cout<<"]"<<endl;


    delete [] arr;
    return 0;
}
