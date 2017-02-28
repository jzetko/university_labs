#include <iostream>
#include <cstdlib>

using namespace std;

bool is_simple(int x){
    for(int i=2; i<=(x/2); i++){
        if(!(x%i)){
            return false;
        }
    }
    return true;
}


int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;


    int *A=new int[n];

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
            A[i]=-30+rand()%60;
        }
    }

    cout<<"Our array: [";
    for(int i=0;i<n;i++){
        cout<<A[i]<<";";
    }
    cout<<"]"<<endl;

    int summa=0;
    cout<<"Simple positions of array (i;A[i]): ";
    for(int i=0;i<n;i++){
        if(is_simple(i+1)){
            cout<<i+1<<";"<<A[i]<<"  ";
            summa+=A[i];
        }
    }
    cout<<endl<<"Summa="<<summa<<endl;

    delete [] A;
    return 0;
}
