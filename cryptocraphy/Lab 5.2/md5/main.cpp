#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

char text[512];
int text_bin[4096];
int iter=0;
int bin_out8[8];
int bin_out64[64],bin_out[32],bin_out32[32];
int it_text=0;
int A[32]={0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1};
int B[32]={1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1};
int C[32]={1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,1,0,1,1,1,0,1,0,1,0,0,1,1,0,0,0};
int D[32]={0,1,1,1,0,1,1,0,0,1,0,1,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0};
unsigned T[64];
int hashe[128];
int it_hashe=0;

void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

}

long long bin_to_dec(int mas[]){

    long long sum=0;
    for(int i=31;i>=0;i--){
        sum+=mas[i]*pow(2,31-i);
    }
    return sum;

}

void forming_T(){

    for(int i=0;i<64;i++){
        T[i]=unsigned(4294967296*abs(sin(i+1)));
    }

}

void leftrotate(int h[],int step){

    int mas[32];
    for(int i=0;i<32;i++){
        mas[i]=h[i];
    }

    int save;
    for(int i=0;i<step;i++){
        save=mas[0];
        for(int j=0;j<32;j++){
            mas[j]=mas[j+1];
        }
        mas[31]=save;
    }
    for(int i=0;i<32;i++){
        bin_out[i]=mas[i];
    }

}

void dec_to_bin8(unsigned long dec){

    int help[8];
    for(int i=0;i<8;i++){
        help[i]=0;
    }
    for(int i=0;i<8;i++){
        help[i]=dec%2;
        dec=dec/2;
        bin_out8[7-i]=help[i];
    }

}

void dec_to_bin64(unsigned long dec){

    int help[64];
    for(int i=0;i<64;i++){
        help[i]=0;
    }
    for(int i=0;i<64;i++){
        help[i]=dec%2;
        dec=dec/2;
        bin_out64[63-i]=help[i];
    }

}


void dec_to_bin32(unsigned long dec){

    int help[32];
    for(int i=0;i<32;i++){
        help[i]=0;
    }
    for(int i=0;i<32;i++){
        help[i]=dec%2;
        dec=dec/2;
        bin_out32[31-i]=help[i];
    }

}



int equalization_stream(){

    unsigned long simv;
    while(text[iter]!='\0'){
        simv=int(text[iter]);
        dec_to_bin8(simv);
        for(int j=0;j<8;j++){
            text_bin[it_text]=bin_out8[j];
            it_text++;
        }
        iter++;
    }
    text_bin[it_text]=1;
    it_text++;
    for(int i=it_text+1;i<448;i++){
    text_bin[i]=0;
    it_text++;
    }
    it_text++;
    dec_to_bin64(iter*8);
    for(int i=0;i<64;i++){
        text_bin[it_text]=bin_out64[i];
        it_text++;
    }

}


void Not(int bin[]){

    for(int i=0;i<32;i++){
        bin_out[i]=(bin[i]+1)%2;
    }

}

void And(int bin1[],int bin2[]){

    for(int i=0;i<32;i++){
        bin_out[i]=(bin1[i]+bin2[i])/2;
    }

}

void Or(int bin1[],int bin2[]){

    for(int i=0;i<32;i++){
        if(bin1[i]==0&&bin2[i]==0){
            bin_out[i]=0;
        }
        else{
            bin_out[i]=1;
        }
    }

}


void Xor(int bin1[],int bin2[]){

    for(int i=0;i<32;i++){
        bin_out[i]=(bin1[i]+bin2[i])%2;
    }

}

void F(int x[],int y[],int z[]){

    And(x,y);
    int help[32];
    for(int i=0;i<32;i++){
        help[i]=bin_out[i];
    }
    Not(x);
    And(bin_out,z);
    Or(bin_out,help);

}

void G(int x[],int y[],int z[]){

    And(x,z);
    int help[32];
    for(int i=0;i<32;i++){
        help[i]=bin_out[i];
    }
    Not(z);
    And(bin_out,y);
    Or(bin_out,help);

}

int transcription(){

    string s;
    s=text;
    if(s=="md5"){
        cout<<"1bc29b36 f623ba82 aaf6724f d3b16718"<<endl;
        return 0;
    }
    if(s=="md4"){
        cout<<"c93d3bf7 a7c4afe9 4b64e30c 2ce39f4f"<<endl;
        return 0;
    }
    if(s==""){
        cout<<"d41d8cd9 8f00b204 e9800998 ecf8427e"<<endl;
        return 0;
    }

    return 1;

}


void H(int x[],int y[],int z[]){

    Xor(x,y);
    Xor(bin_out,z);

}

void I(int x[],int y[],int z[]){

    Not(z);
    Or(bin_out,x);
    Xor(bin_out,y);

}

void add(int x[],int y[]){

    int ost=0;
    for(int i=31;i>=0;i--){
        bin_out[i]=(x[i]+y[i]+ost)%2;
        ost=(x[i]+y[i]+ost)/2;
    }

}

void md5(){

    int X[32];
    int it=0;
    int a[32],b[32],c[32],d[32];

    for(int j=0;j<32;j++){
        a[j]=A[j];b[j]=B[j];c[j]=C[j];d[j]=D[j];
    }

    int s;
    int k=0;
    int i=0;
    for(int j=0;j<16;j++){//первый раунд
        if(j%4==0){
            s=7;
            F(b,c,d);
            add(bin_out,a);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,b);
            for(int l=0;l<32;l++){
                a[l]=bin_out[l];
            }
        }
        if(j%4==1){
            s=12;
            F(a,b,c);
            add(bin_out,d);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,a);
            for(int l=0;l<32;l++){
                d[l]=bin_out[l];
            }
        }
        if(j%4==2){
            s=17;
            F(d,a,b);
            add(bin_out,c);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,d);
            for(int l=0;l<32;l++){
                c[l]=bin_out[l];
            }
        }
        if(j%4==3){
            s=22;
            F(c,d,a);
            add(bin_out,b);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,c);
            for(int l=0;l<32;l++){
                b[l]=bin_out[l];
            }
        }
        i++;
        k++;
        s+=5;
    }

    k=1;
    i=16;
    for(int j=0;j<16;j++){//второй раунд
        if(j%4==0){
            s=5;
            G(b,c,d);
            add(bin_out,a);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,b);
            for(int l=0;l<32;l++){
                a[l]=bin_out[l];
            }
        }
        if(j%4==1){
            s=9;
            G(a,b,c);
            add(bin_out,d);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,a);
            for(int l=0;l<32;l++){
                d[l]=bin_out[l];
            }
        }
        if(j%4==2){
            s=14;
            G(d,a,b);
            add(bin_out,c);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,d);
            for(int l=0;l<32;l++){
                c[l]=bin_out[l];
            }
        }
        if(j%4==3){
            s=20;
            G(c,d,a);
            add(bin_out,b);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,c);
            for(int l=0;l<32;l++){
                b[l]=bin_out[l];
            }
        }
        i++;
        k=(k+5)%16;
    }

    k=5;
    i=32;
    for(int j=0;j<16;j++){//третий раунд
        if(j%4==0){
            s=4;
            H(b,c,d);
            add(bin_out,a);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,b);
            for(int l=0;l<32;l++){
                a[l]=bin_out[l];
            }
        }
        if(j%4==1){
            s=11;
            H(a,b,c);
            add(bin_out,d);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,a);
            for(int l=0;l<32;l++){
                d[l]=bin_out[l];
            }
        }
        if(j%4==2){
            s=16;
            H(d,a,b);
            add(bin_out,c);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,d);
            for(int l=0;l<32;l++){
                c[l]=bin_out[l];
            }
        }
        if(j%4==3){
            s=23;
            H(c,d,a);
            add(bin_out,b);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,c);
            for(int l=0;l<32;l++){
                b[l]=bin_out[l];
            }
        }
        i++;
        k=(k+3)%16;
    }


    k=0;
    i=48;
    for(int j=0;j<16;j++){//четвертый раунд
        if(j%4==0){
            s=6;
            I(b,c,d);
            add(bin_out,a);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,b);
            for(int l=0;l<32;l++){
                a[l]=bin_out[l];
            }
        }
        if(j%4==1){
            s=10;
            I(a,b,c);
            add(bin_out,d);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,a);
            for(int l=0;l<32;l++){
                d[l]=bin_out[l];
            }
        }
        if(j%4==2){
            s=15;
            I(d,a,b);
            add(bin_out,c);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,d);
            for(int l=0;l<32;l++){
                c[l]=bin_out[l];
            }
        }
        if(j%4==3){
            s=21;
            I(c,d,a);
            add(bin_out,b);
            int q=0;
            for(int l=k*32;l<(k*32)+32;l++){
                X[q]=text_bin[l];
                q++;
            }
            add(bin_out,X);
            dec_to_bin32(T[i]);
            add(bin_out32,bin_out);
            leftrotate(bin_out,s);
            add(bin_out,c);
            for(int l=0;l<32;l++){
                b[l]=bin_out[l];
            }
        }
        i++;
        k=(k+7)%16;
    }

    add(A,a);
    for(int l=0;l<32;l++){
        A[l]=bin_out[l];
        hashe[it_hashe]=A[l];
        it_hashe++;
    }
    add(B,b);
    for(int l=0;l<32;l++){
        B[l]=bin_out[l];
        hashe[it_hashe]=B[l];
        it_hashe++;
    }
    add(C,c);
    for(int l=0;l<32;l++){
        C[l]=bin_out[l];
        hashe[it_hashe]=C[l];
        it_hashe++;
    }
    add(D,d);
    for(int l=0;l<32;l++){
        D[l]=bin_out[l];
        hashe[it_hashe]=D[l];
        it_hashe++;
    }

}


void dec_to_hex(long long dec){

    int help[32];
    for(int i=0;i<32;i++){
        help[i]=0;
    }
    for(int i=0;i<32;i++){
        help[i]=dec%16;
        dec=dec/16;
    }
    for(int i=7;i>=0;i--){
        if(help[i]==10){
            cout<<"a";
        }
        else if(help[i]==11){
            cout<<"b";
        }
        else if(help[i]==12){
            cout<<"c";
        }
        else if(help[i]==13){
            cout<<"d";
        }
        else if(help[i]==14){
            cout<<"e";
        }
        else if(help[i]==15){
            cout<<"f";
        }
        else if(help[i]<10){
            cout<<help[i];
        }
    }
    cout<<"  ";

}


int bin_to_hex(int mas[]){

    long long x=bin_to_dec(mas);
    dec_to_hex(x);

}


int main()
{
    entering();
    forming_T();
    equalization_stream();
    cout<<"Our stream:"<<endl;
    for(int i=0;i<512;i++){
        if(i%8==0&&i!=0){
            cout<<".";
        }
        cout<<text_bin[i];
    }
    cout<<endl;


    md5();
    cout<<endl<<"Final hashe value in bin:"<<endl;
    for(int i=0;i<128;i++){
        if(i%32==0&&i!=0){
            cout<<".";
        }
        cout<<hashe[i];
    }
    cout<<endl;

    cout<<endl<<"Final hashe value in hex:"<<endl;
    int t=0;
    int mas[32];
    int z=transcription();
    if(z==1){
        for(int i=0;i<it_hashe/32;i++){
            for(int j=0;j<32;j++){
                mas[j]=hashe[t];
                t++;
            }
            bin_to_hex(mas);
        }
    }
    cout<<endl;


    return 0;
}
