#include <iostream>
#include <cstdlib>

using namespace std;

int p,q,r,fi,Ko,Kc,numbers;
char text[256];
int text_dec[256];

int checking_for_simple(int number){

    int j=0;
    for(int i=2;i<number;i++){
        if(number%i==0){
            j++;
        }
    }
    if (j==0){
        return 1;
    }
    else{
        return 0;
    }

}

void evclid(int a, int b, int *x, int *y, int *nod){
    long q, r, x1, x2, y1, y2;
    if(b==0){
        *nod=a;
        *x=1;
        *y=0;
        return;
    }
    x2=1;
    x1=0;
    y2=0;
    y1=1;
    while(b>0){
        q=a/b;
        r=a-q*b;
        *x=x2-q*x1;
        *y=y2-q*y1;
        a=b;
        b=r;
        x2=x1;
        x1=*x;
        y2=y1;
        y1=*y;
    }
    *nod=a;
    *x=x2;
    *y=y2;

}

void pq_generation(){

    int k=0;
    int check;
    while(k==0){
        p=rand()%100;
        check=checking_for_simple(p);
        if(p>40&&check==1){
            break;
        }
    }

    while(k==0){
        q=rand()%100;
        check=checking_for_simple(q);
        if(q>40&&check==1){
            break;
        }
    }

}

void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,256);
    cout<<endl;

    numbers=0;
    while(text[numbers]!='\0'){
        text_dec[numbers]=(int)text[numbers];
        numbers++;
    }

}

int quick(int a, int z, int n){

    int b=1;
    while(z) {
        if(z%2==0) {
             z/=2;
             a=(a*a)%n;
        }
        else {
             z--;
             b=(b*a)%n;
        }
    }
    return b;
}


int main()
{

    pq_generation();
    cout<<"p="<<p<<"  q="<<q<<endl;

    r=p*q;
    cout<<"r="<<r<<endl;
    fi=(p-1)*(q-1);
    cout<<"fi(r)="<<fi<<endl;
    Ko=257;
    cout<<"Ko="<<Ko<<endl;
    int x,y,nod;
    evclid(fi,Ko,&x,&y,&nod);
    Kc=y;
    if(Kc<0){
        Kc+=fi;
    }
    cout<<"Kc="<<Kc<<endl;

    entering();

    cout<<"Text in dec numbers:"<<endl;
    for(int i=0;i<numbers;i++){
        cout<<text_dec[i]<<" ";
    }
    cout<<endl;

    int *crypt=new int[numbers];

    cout<<"Crypt text:"<<endl;
    for(int i=0;i<numbers;i++){
        crypt[i]=quick(text_dec[i],Ko,r);
        cout<<crypt[i]<<" ";
    }
    cout<<endl;

    int *encrypt=new int[numbers];

    cout<<"Encrypt text in dec:"<<endl;
    for(int i=0;i<numbers;i++){
        encrypt[i]=quick(crypt[i],Kc,r);
        cout<<encrypt[i]<<" ";
    }
    cout<<endl;

    cout<<"Encrypt text:"<<endl;
    char simv;
    for(int i=0;i<numbers;i++){
        simv=char(encrypt[i]);
        cout<<simv;
    }
    cout<<endl;

    delete [] encrypt;
    delete [] crypt;
    delete [] text;
    delete [] text_dec;

    return 0;
}
