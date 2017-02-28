#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;


//≈сли € правильно пон€л задание, то эта задача 1 в 1 как и 19
int main(int argc, char *argv[])
{
    int N;
    cout<<"Enter N: ";
    cin>>N;


    int **A;
    A=new int*[N];
    for(int i=0;i<N;i++){
        A[i]=new int[2];
    }


    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<N;i++){
            cout<<i+1<<": ";
            cin>>A[i][0];
            cin>>A[i][1];
        }
    }
    else{
        for(int i=0;i<N;i++){
            A[i][0]=-50+rand()%100;
            A[i][1]=-50+rand()%100;
        }
    }

    cout<<"Our array:"<<endl<<"Array=[ ";
    for(int i=0;i<N;i++){
        cout<<" "<<A[i][0]<<";"<<A[i][1]<<" ";
    }
    cout<<"]"<<endl;

    int mx=0;
    int position;

    for(int i=0;i<N;i++){
        int h=sqrt(pow(A[i][0],2)+pow(A[i][1],2));
        if(mx<h){
            mx=h;
            position=i;
        }
    }

    cout<<"Position of point="<<position+1<<endl;
    cout<<"Coordinatesof point=["<<A[position][0]<<";"<<A[position][1]<<"]"<<endl;

    for(int i=0;i<N;i++){
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
