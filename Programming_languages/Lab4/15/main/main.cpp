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
    int position=0;

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>A[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            A[i]=-20+rand()%40;
        }
    }

    cout<<"Our array: [";
    for(int i=0;i<n;i++){
        cout<<A[i]<<";";
    }
    cout<<"]"<<endl;

    B[0]=A[0];
    position++;
    int checker=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<position;j++){
            if(A[i]==B[j]){
                checker++;
            }
        }
        if(checker==0){
            B[position]=A[i];
            position++;
        }
        checker=0;
    }




    int mn=B[0];
    int pos=0;
    int h1;
    for(int i=1;i<position;i++){
        if (B[i]<mn){
            mn=B[i];
            pos=i;
        }
    }
    h1=B[pos];
    B[pos]=B[0];
    B[0]=h1;

    for(int i=1;i<position-1;i++){
        mn=B[i];
        pos=i;
        for(int j=i+1;j<position;j++){
            if (B[j]<mn){
                mn=B[j];
                pos=j;
            }
        }
        h1=B[pos];
        B[pos]=B[i];
        B[i]=h1;
    }




    cout<<"B: [";
    for(int i=0;i<position;i++){
        cout<<B[i]<<";";
    }
    cout<<"]"<<endl;

    delete [] A;
    return 0;
}
