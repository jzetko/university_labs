#include <iostream>
#include <cstdlib>

using namespace std;

int Evclid(int a, int b){
    int t;
    if (a<b){
        t=a;
        a=b;
        b=t;
    }
    while(a!=b){
        t=a%b;
        if(t==0){
            break;
        }
        a=b;
        b=t;
    }
    return(b);
}



int main()
{
    int a,b,nod;
    cout<<"Enter the numbers:"<<endl<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    if(a<=0||b<=0){
        cout<<"Number(s) is(are) wrong!"<<endl;
        return 0;
    }

    nod=Evclid(a,b);
    cout<<"NOD="<<nod<<endl;


    return 0;
}
