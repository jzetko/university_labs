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
    cout<<endl<<"Result: ";
    for(int i=l;i<=r;i++){
        if(is_simple(i)){
            cout<<i<<"  ";
        }
    }
    cout<<endl;
    return 0;
}
