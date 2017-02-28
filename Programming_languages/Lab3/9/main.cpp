#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int l,r;
    cout<<"Enter the left border of interval: ";
    cin>>l;
    cout<<"Enter the right border of interval: ";
    cin>>r;

    int N=r-l+1;

    int **A;
    A=new int*[N];
    for(int i=0;i<N;i++){
        A[i]=new int[2];
    }


    int position=0;
    for(int i=l;i<=r;i++){
        int sum=0;
        for(int j=1;j<i;j++){
            if(i%j==0){
                sum+=j;
            }
        }
        A[position][0]=i;
        A[position][1]=sum;
        position++;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Result:"<<endl;

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(A[i][1]==A[j][0]&&A[i][0]==A[j][1]){
                cout<<A[i][0]<<"(sum="<<A[i][1]<<") and "<<A[j][0]<<"(sum="<<A[j][1]<<")"<<endl;
            }
        }
    }






    for(int i=0;i<N;i++){
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
