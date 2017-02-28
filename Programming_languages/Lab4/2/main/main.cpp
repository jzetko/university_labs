#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int N,M;
    cout<<"Enter N: ";
    cin>>N;
    cout<<"Enter M: ";
    cin>>M;

    double *arr1=new double[N];
    double *arr2=new double[M];

    cout<<"Enter the 1st array:"<<endl;
    for(int i=0;i<N;i++){
        cout<<i+1<<" element: ";
        cin>>arr1[i];
    }
    for(int i=0;i<N-1;i++){
        if(arr1[i]>arr1[i+1]){
            cout<<"The 1st array is wrong!"<<endl;
            return 0;
        }
    }

    cout<<"Enter the 2st array:"<<endl;
    for(int i=0;i<M;i++){
        cout<<i+1<<" element: ";
        cin>>arr2[i];
    }

    for(int i=0;i<M-1;i++){
        if(arr2[i]>arr2[i+1]){
            cout<<"The 2nd array is wrong!"<<endl;
            return 0;
        }
    }

    cout<<"Result: ";
    int res[N+M];
    int i=0;
    int j=0;
    for(int k=0;k<N+M;k++){
        if(i==N||j==M){
            if(i==N){
                res[k]=arr2[j];
                if(j!=M-1){
                    j++;
                }
            }
            if(j==M){
                res[k]=arr1[i];
                if(i!=N-1){
                    i++;
                }
                i++;
            }
        }
        else{
            if(arr1[i]>=arr2[j]){
                res[k]=arr2[j];
                j++;
            }
            else{
                res[k]=arr1[i];
                i++;
            }
        }

        cout<<res[k]<<" ";


    }


    delete [] arr1;
    delete [] arr2;
    return 0;
}
