#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

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
            arr[i]=-5+rand()%10;
        }
    }

    int lenght=1;
    int max_lenght=0;
    cout<<"Our Array: [ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ; ";
    }
    cout<<"]"<<endl;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            lenght++;
        }
        if(arr[i]!=arr[i-1]){
            if(lenght>max_lenght){
                max_lenght=lenght;
                lenght=1;
            }
            else{
                lenght=1;
            }
        }
    }
    cout<<"The maximum length of non-repeating sequence="<<max_lenght<<endl;

    delete [] arr;
    return 0;
}
