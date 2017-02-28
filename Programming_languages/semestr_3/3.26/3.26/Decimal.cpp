#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "Decimal.h"

using namespace std;

void Decimal::Read(){
    cout<<"Print the sign of massiv(0-positive, 1-negative): ";
    cin>>sign;
    cout<<"Print the size of massive(<100): ";
    cin>>sz;
    cout<<"Print elements of massive in the reverse order(0-9):"<<endl;
    for(int i=0; i<sz; i++){
        cin>>dec[i];
    }
    cout<<endl;
}
void Decimal::Display(){
    if(sign==1){
        cout<<"-";
    }
    for(int i=sz-1; i>=0; i--){
        cout<<dec[i];
    }
    cout<<endl<<endl;
}

bool operator>(const Decimal &m1, const Decimal &m2){
    if(m1.sz>m2.sz)
        return true;
    if(m1.sz<m2.sz)
        return false;
    if(m1.sz==m2.sz){
        for(int i=m1.sz-1; i>=0; i--){
            if(m1.dec[i]>m2.dec[i]){
                return true;
                break;
            }
            if(m1.dec[i]<m2.dec[i]){
                return false;
                break;
            }
        }
    }
}

bool operator<(const Decimal &m1, const Decimal &m2){
    if(m1.sz<m2.sz)
        return true;
    if(m1.sz>m2.sz)
        return false;
    else
        return false;
    if(m1.sz==m2.sz){
        for(int i=m1.sz-1; i>=0; i--){
            if(m1.dec[i]<m2.dec[i]){
                return true;
                break;
            }
            if(m1.dec[i]>m2.dec[i]){
                return false;
                break;
            }
        }
    }
}

bool operator==(const Decimal &m1, const Decimal &m2){
    int count=0;
    if(m1.sz==m2.sz){
        for(int i=0; i<m1.sz;i++){
            if(m1.dec[i]==m2.dec[i]){
                count++;
            }
        }
    }
    if(count==m1.sz)
        return true;
    else
        return false;
}


Decimal Compare(const Decimal &m1, const Decimal &m2){
    if(m1.sign==0&&m2.sign==1){
        cout<<"m1>m2"<<endl<<endl;
    }

    if(m1.sign==1&&m2.sign==0){
        cout<<"m2>m1"<<endl<<endl;
    }

    if((m1.sign==0)&&(m2.sign==0)){
        if(m1>m2){
            cout<<"m1>m2"<<endl<<endl;
        }
        if(m2>m1){
            cout<<"m2>m1"<<endl<<endl;
        }
        if(m1==m2){
            cout<<"m1=m2"<<endl<<endl;
        }
    }

    if((m1.sign==1)&&(m2.sign==1)){
        if(m1>m2){
            cout<<"m2>m1"<<endl<<endl;
        }
        if(m2>m1){
            cout<<"m1>m2"<<endl<<endl;
        }
        if(m1==m2){
            cout<<"m1=m2"<<endl<<endl;
        }
    }
}

Decimal operator+(const Decimal &m1, const Decimal &m2){
    if(m1>m2){
        unsigned help[m1.sz+1];
        unsigned help1[m1.sz];
        unsigned help2[m1.sz];
        for(int i=0;i<m1.sz+1;i++){
            help[i]=0;
        }
        for(int i=0;i<m1.sz;i++){
            help1[i]=m1.dec[i]-'0';
        }
        for(int i=0;i<m2.sz;i++){
            help2[i]=m2.dec[i]-'0';
        }
        for(int i=m2.sz;i<m1.sz;i++){
            help2[i]=0;
        }
        int k;
        for(int i=0;i<m1.sz+1;i++){
            k=help1[i]+help2[i];
            help[i]=k%10;
            help[i+1]=k/10;
        }
        if(help[m1.sz]==0){
            unsigned newhelp[m1.sz];
            for(int i=0;i<m1.sz;i++){
                newhelp[i]=help[i];
            }
            for(int i=m1.sz-1;i>=0;i--){
                cout<<newhelp[i];
            }
        }
        else{
            for(int i=m1.sz;i>=0;i--){
                cout<<help[i];
            }
        }
    }






}
