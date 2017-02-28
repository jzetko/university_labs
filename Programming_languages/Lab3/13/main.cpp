#include <iostream>
#include <cstdlib>

using namespace std;

int nod(int a,int b){
    if(b==0){
        if(a==0)
            return -1;
        else return a;}
    else abs(nod(b,a%b));
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    int *A=new int[n];

    for(int i=0;i<n;i++){
        cout<<i+1<<": ";
        cin>>A[i];
        if (A[i]<1){
            cout<<"Failed input"<<endl;
            return 0;
        }
    }
    int n1=0;
    int n2=0;
    for(int i=0;i<3 & (n1!=1);i++){
        n2=n1;
        n1=nod(n2,A[i]);
    }
    cout<<"NOD="<<n1<<endl;
}
