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

    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<" element: ";
        cin>>A[i];
    }

    cout<<"Our array:"<<endl<<"Array=[";
    for(int i=0;i<n;i++){
        cout<<A[i]<<";";
    }
    cout<<"]"<<endl;

    int sum=0;
    int k=0;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            k++;
            if(i==n-1){
                if(k>sum){
                    sum=k;
                }
            }
        }
        else{
            if(k>sum){
                sum=k;
            }
            k=0;
        }
    }
    cout<<"Lenght of secuence="<<sum<<endl;

    delete [] A;
    return 0;
}
