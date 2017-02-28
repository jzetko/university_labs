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
            arr[i]=-50+rand()%100;
        }
    }


    int mx=-100000;
    int sum=0;
    cout<<"Our Array: [";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
    cout<<"]"<<endl;

    int check=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mx){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    mx=arr[i];
                    check++;
                }
            }
        }

    }
    if(check!=0){
        cout<<"Maximum element="<<mx<<endl;
    }
    if(check==0){
        cout<<"No symbol met twice"<<endl;
    }



    delete [] arr;
    return 0;
}
