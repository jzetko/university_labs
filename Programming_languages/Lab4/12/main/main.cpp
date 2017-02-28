#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    double *arr1=new double[n];
    double *arr2=new double[n];

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of 1st array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>arr1[i];
        }
        cout<<"Enter the elements of 2nd array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>arr2[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            arr1[i]=-50+rand()%100;
            arr2[i]=-50+rand()%100;
        }
    }
    cout<<"1st Array: [";
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<";";
    }
    cout<<"]"<<endl;

    cout<<"2nd Array: [";
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<";";
    }
    cout<<"]"<<endl;


    int checker=0;
    int mn=100000;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr1[i]==arr2[j]){
                checker++;
            }
        }
        if(checker==0&&arr1[i]<mn){
            mn=arr1[i];
        }
        checker=0;
    }
    if(mn!=100000){
        cout<<mn;
    }
    else{
        cout<<"Arrays are similar"<<endl;
    }


    delete [] arr1;
    delete [] arr2;
    return 0;
}
