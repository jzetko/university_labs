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
    int l,r;
    cout<<"Enter left border of interval: ";
    cin>>l;
    cout<<"Enter right border of interval: ";
    cin>>r;
    int s1,s2;
    s1=1;
    int counter=1;
    cout<<endl<<"Result: "<<endl;
    for(int i=l;i<=r;i++){
        if(is_simple(i)){
            s2=i;
            if(s2-s1==2){
                cout<<counter<<" pair: "<<s1<<" and "<<s2<<endl;
                counter++;
            }
            s1=s2;
        }
    }
    cout<<endl;
    return 0;
}
