#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int k;
    cout<<"Enter k: ";
    cin>>k;

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

    cout<<"Our Array: [";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
    cout<<"]"<<endl;

    if(k>0){
        for(int j=0;j<k;j++){
            int help=arr[n-1];
            for(int i=n-1;i>0;i--){
                arr[i]=arr[i-1];
            }
            arr[0]=help;
        }
    }
    if(k<0){
        for(int j=0;j<abs(k);j++){
            int help=arr[0];
            for(int i=0;i<n-1;i++){
                arr[i]=arr[i+1];
            }
            arr[n-1]=help;
        }
    }

    cout<<"Array after shift elements with step k="<<k<<":"<<endl<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
    cout<<"]"<<endl;

    delete [] arr;
    return 0;
}
