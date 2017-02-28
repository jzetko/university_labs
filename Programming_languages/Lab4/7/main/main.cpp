#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;


    int *arr=new int[n];
    int *help=new int[n];
    for(int i=0;i<n;i++){
        help[i]=-1000;
    }

    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<": ";
            cin>>arr[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            arr[i]=-10+rand()%20;
        }
    }

    cout<<"Array: [";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<";";
    }
    cout<<"]"<<endl;

    int sum=0;
    int check=0;
    int point=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==help[j]){
                check++;
            }
        }
        if(check==0){
            help[point]=arr[i];
            point++;
            sum++;
        }
        check=0;
    }
    cout<<endl<<"Numbers of different elements="<<sum<<endl<<"Different elements: ";
    for(int i=0;i<point;i++){
        cout<<help[i]<<" ";
    }


    delete [] arr;

    return 0;
}
