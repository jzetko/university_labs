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

int operator+(const Decimal &m1, const Decimal &m2){
    if(m1>m2||m1==m2){
        int help[m1.sz+1];
        int help1[m1.sz];
        int help2[m1.sz];
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
        for(int i=0;i<m1.sz;i++){
            k=help1[i]+help2[i];
            if(k>=10){
                help[i]=help[i]+k-10;
                help[i+1]=help[i+1]+1;
            }
            else{
                help[i]=help[i]+k;
            }

        }
        if(help[m1.sz]==0){
            int newhelp[m1.sz];
            for(int i=0;i<m1.sz;i++){
                newhelp[i]=help[i];
            }
            for(int i=0;i<m1.sz;i++){
                return newhelp[i];
            }
        }
        else{
            for(int i=0;i<m1.sz+1;i++){
                return help[i];
            }
        }
    }

    if(m2>m1){
        int help[m2.sz+1];
        int help1[m2.sz];
        int help2[m2.sz];
        for(int i=0;i<m2.sz+1;i++){
            help[i]=0;
        }
        for(int i=0;i<m2.sz;i++){
            help2[i]=m2.dec[i]-'0';
        }
        for(int i=0;i<m1.sz;i++){
            help1[i]=m1.dec[i]-'0';
        }
        for(int i=m1.sz;i<m2.sz;i++){
            help1[i]=0;
        }
        int k;
        for(int i=0;i<m2.sz;i++){
            k=help1[i]+help2[i];
            if(k>=10){
                help[i]=help[i]+k-10;
                help[i+1]=help[i+1]+1;
            }
            else{
                help[i]=help[i]+k;
            }

        }
        if(help[m2.sz]==0){
            int newhelp[m2.sz];
            for(int i=0;i<m2.sz;i++){
                newhelp[i]=help[i];
            }
            for(int i=0;i<m2.sz;i++){
                return newhelp[i];
            }
        }
        else{
            for(int i=0;i<m2.sz+1;i++){
                return help[i];
            }
        }
    }
}


Decimal operator-(const Decimal &m1, const Decimal &m2){
    if(m1>m2||m1==m2){
        int help[m1.sz];
        int help1[m1.sz+1];
        int help2[m1.sz];
        for(int i=0;i<m1.sz;i++){
            help[i]=0;
        }
        for(int i=0;i<m1.sz;i++){
            help1[i]=m1.dec[i]-'0';
        }
        help[m1.sz]=0;
        for(int i=0;i<m2.sz;i++){
            help2[i]=m2.dec[i]-'0';
        }
        for(int i=m2.sz;i<m1.sz;i++){
            help2[i]=0;
        }
        int k;
        for(int i=0; i<m1.sz;i++){
            k=help1[i]-help2[i];
            if(k<0){
                help[i]=help1[i]+10-help2[i];

                help1[i+1]=help1[i+1]-1;
            }
            else{
                help[i]=help1[i]-help2[i];
            }
        }
        if(help[m1.sz-1]==0){
            unsigned newhelp[m1.sz-1];
            for(int i=0;i<m1.sz-1;i++){
                newhelp[i]=help[i];
            }
            for(int i=m1.sz-2;i>=0;i--){
                cout<<newhelp[i];
            }
        }
        else{
            for(int i=m1.sz-1;i>=0;i--){
                cout<<help[i];
            }
        }
    cout<<endl<<endl;
    }

    if(m1<m2){
        int help[m2.sz];
        int help2[m2.sz+1];
        int help1[m2.sz];
        for(int i=0;i<m2.sz;i++){
            help[i]=0;
        }
        for(int i=0;i<m2.sz;i++){
            help2[i]=m2.dec[i]-'0';
        }
        help2[m2.sz]=0;
        for(int i=0;i<m1.sz;i++){
            help1[i]=m1.dec[i]-'0';
        }
        for(int i=m1.sz;i<m2.sz;i++){
            help1[i]=0;
        }
        int k;
        for(int i=0;i<m2.sz;i++){
            k=help2[i]-help1[i];
            if(k<0){
                help[i]=help2[i]+10-help1[i];
                help2[i+1]=help2[i+1]-1;
            }
            else{
                help[i]=help2[i]-help1[i];
            }
        }
        if(help[m2.sz-1]==0){
            unsigned newhelp[m2.sz-1];
            for(int i=0;i<m2.sz-1;i++){
                newhelp[i]=help[i];
            }
            for(int i=m2.sz-2;i>=0;i--){
                cout<<newhelp[i];
            }
        }
        else{
            for(int i=m2.sz-1;i>=0;i--){
                cout<<help[i];
            }
        }
    cout<<endl<<endl;
    }
}




Decimal Summa(const Decimal &m1, const Decimal &m2){
    if(m1.sign==0&&m2.sign==0){
        m1+m2;
    }
    if(m1.sign==1&&m2.sign==1){
        cout<<"-";
        m1+m2;
    }
    if(m1.sign==0&&m2.sign==1){
        if(m2>m1){
            cout<<"-";
        }
        m1-m2;
    }
    if(m1.sign==1&&m2.sign==0){
        if(m1>m2){
            cout<<"-";
        }
        m1-m2;
    }
    cout<<endl<<endl;
}



Decimal Subtract(const Decimal &m1, const Decimal &m2){
    if(m1.sign==0&&m2.sign==0){
        m1-m2;
    }
    if(m1.sign==1&&m2.sign==1){
        if(m1>m2){
            cout<<"-";
        }
        m1-m2;
    }
    if(m1.sign==0&&m2.sign==1){
        m1+m2;
    }
    if(m1.sign==1&&m2.sign==0){
        cout<<"-";
        m1+m2;
    }
    cout<<endl<<endl;
}



Decimal operator !=(const Decimal &m1, const Decimal &m2){
    int k1[100];
    int k2[100];
    int i;
    for(i=0;i<100;i++){
        k1[i]=k2[i];
    }
}



Decimal Multiplication(const Decimal &m1, const Decimal &m2){
    int help[100];
    int help1[100];
    int help2[100];
    int h1[1];
    int h0[1];
    int i;
    h1[0]=1;
    h0[0]=0;
    for(i=0;i<m1.sz;i++){
        help1[i]=m1.dec[i]-'0';
    }
    for(i=m1.sz;i<100;i++){
        help1[i]=0;
    }
    for(i=0;i<m2.sz;i++){
        help2[i]=m2.dec[i]-'0';
    }
    for(i=m2.sz;i<0;i++){
        help2[i]=0;
    }
    for(i=0;i<100;i++){
        help[i]=0;
    }
    while(help2>h0){
        for(i=0;i<100;i++){
            help!=(help+help1);
            help2!=(help2-h1);
        }

    }

}




