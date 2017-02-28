#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n,B;
    cout<<"Enter n: ";
    cin>>n;


    int *A=new int[n];

    cout<<"Enter the elements of 1st array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<": ";
        cin>>A[i];
        if(i>0&&A[i]<A[i-1]){
            cout<<"Failed input";
            return 0;
        }
    }

    cout<<"Enter B: ";
    cin>>B;

    cout<<"Our array: [";
    for(int i=0;i<n;i++){
        cout<<A[i]<<";";
    }
    cout<<"]"<<endl;


    int checker=0;
    for(int i=0;i<n;i++){
        if (A[i]==B){
            checker++;
        }
    }
    if (checker!=0){
        cout<<"Array has element B="<<B<<endl;
        return 0;
    }
    else{
        if(B<A[0]){
            for(int i=n-1;i>0;i--){
                A[i]=A[i-1];
            }
            A[0]=B;
        }
        else{
            for(int i=1;i<n-1;i++){
                if(B>A[i]&&B<A[i+1]){
                    for(int j=n-1;j>i+1;j--){
                        A[j]=A[j-1];
                    }
                    A[i+1]=B;
                }
            }
        }

    }
    cout<<"Result array: [";
    for(int i=0;i<n;i++){
        cout<<A[i]<<";";
    }
    cout<<"]"<<endl;

    delete [] A;
    return 0;
}
