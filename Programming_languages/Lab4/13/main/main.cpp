#include <iostream>
#include <cstdlib>


using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int *A=new int[n];
    int *B=new int[n];
    int *C=new int[n+1];

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of 1st array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>A[i];
            if(A[i]<0||A[i]>9){
                cout<<"Failed input";
                return 0;
            }
        }
        cout<<"Enter the elements of 2nd array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>B[i];
            if(B[i]<0||B[i]>9){
                cout<<"Failed input";
                return 0;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            A[i]=rand()%10;
            B[i]=rand()%10;
        }
    }
    for(int i=0;i<n+1;i++){
        C[i]=0;
    }
    cout<<"Array A: [";
    for(int i=0;i<n;i++){
        cout<<A[i];
    }
    cout<<"]"<<endl;

    cout<<"Array B: [";
    for(int i=0;i<n;i++){
        cout<<B[i];
    }
    cout<<"]"<<endl;



    for(int i=n-1;i>=0;i--){
        C[i+1]+=(A[i]+B[i])%10;
        C[i]+=(A[i]+B[i])/10;
    }

    cout<<"Array C:[";
    for(int i=0;i<n+1;i++){
        cout<<C[i];
    }
    cout<<"]"<<endl;

    delete [] A;
    delete [] B;
    delete [] C;
    return 0;
}
