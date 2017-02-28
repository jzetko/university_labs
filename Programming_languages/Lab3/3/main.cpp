#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    int n;

    cout<<"Enter n: ";
    cin>>n;

    if (n<=0){
        cout<<"Failed input";
        return 0;
    }

    int *mas=new int[n];
    string s;
    cout<<"Do you want enter elements from keyboard?(y/n): ";
    cin>>s;
    if(s=="y"){
        cout<<"Enter the elements of array:"<<endl;
        for(int i=0;i<n;i++){
            cout<<i+1<<" element: ";
            cin>>mas[i];
        }
    }
    else{
        for(int i=0;i<n;i++){
            mas[i]=-100+rand()%200;
        }
    }
    cout<<"Our array:"<<endl<<"Array=[";
    for(int i=0;i<n;i++){
        cout<<mas[i]<<",";
    }
    cout<<"]"<<endl;


    int pos=0;
    int neg=0;
    int null=0;


    for(int i=0;i<n;i++){
        if(mas[i]<0){
            neg++;
        }
         if(mas[i]>0){
            pos++;
        }
         if(mas[i]==0){
            null++;
        }
    }
    cout<<"Positive elements="<<pos<<endl;
    cout<<"Negative elements="<<neg<<endl;
    cout<<"Null elements="<<null<<endl;

    delete [] mas;
    return 0;
}
