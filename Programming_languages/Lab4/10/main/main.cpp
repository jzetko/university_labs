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

    int *arr=new int[n];

    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<": ";
        cin>>arr[i];
        if(arr[i]<1){
            cout<<"Failed input"<<endl;
            return 0;
        }
    }


    cout<<"Our Array: [";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
    cout<<"]"<<endl;

    int mx=arr[0];
    for(int i=0;i<n;i++){
        if (arr[i]>mx){
            mx=arr[i];
        }
    }

    int stoper=0;
    int counter=1;
    int check=0;
    while(stoper==0){
        for(int i=0;i<n;i++){
            if((mx*counter)%arr[i]!=0){
                check++;
            }
        }
        if(check==0){
                stoper++;
        }
        counter++;
        check=0;
    }
    cout<<"NOK="<<mx*(counter-1)<<endl;


    delete [] arr;
    return 0;
}
