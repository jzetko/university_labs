#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;


    double *arr1=new double[n];
    double *arr2=new double[n];
    double *arr3=new double[n];
    vector <int> result;
    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of 1st array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>arr1[i];
        }
        cout<<"Enter the elements of 2nd array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>arr2[i];
        }
        cout<<"Enter the elements of 3d array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>arr3[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            arr1[i]=-10+rand()%20;
            arr2[i]=-10+rand()%20;
            arr3[i]=-10+rand()%20;
        }
    }

    cout<<"1st array: [";
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<";";
    }
    cout<<"]"<<endl;

    cout<<"2nd array: [";
    for(int i=0;i<n;i++){
        cout<<arr2[i]<<";";
    }
    cout<<"]"<<endl;

    cout<<"3d array: [";
    for(int i=0;i<n;i++){
        cout<<arr3[i]<<";";
    }
    cout<<"]"<<endl;

    int check=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr1[i]==arr2[j]){
                for(int k=0;k<n;k++){
                    if(arr1[i]==arr3[k]){
                        for(int l=0;l<result.size();l++){
                            if(arr1[i]==result[l]){
                                check++;
                            }
                        }
                        if(check==0){
                            result.push_back(arr1[i]);
                        }
                        check=0;
                    }
                }
            }
        }
    }
    cout<<"Result: ";
    for (int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    return 0;
}
