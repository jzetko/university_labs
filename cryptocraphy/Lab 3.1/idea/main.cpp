#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

struct for_crypt{
    char letter;//символ
    int bin_code[8];//двочиное 8-битное представление числа
    int dec_code;//десятичное представление числа
};

char key_text[30];
int key[128];
char text[512];
int bin_out[16];
int it_text=0;
int it_text_plus=0;
int it_crypt_text=0;
int crypt_text[2048];
vector <for_crypt> code_of_symbols;
int it_key;
int key_help[16];
int encrypt_text[2048];

void forming_source_alfabet(){//формирование таблицы кодов сиволов

    for_crypt model;

    model.letter='a';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=1;
    model.dec_code=97;
    code_of_symbols.push_back(model);

    model.letter='b';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=1;model.bin_code[7]=0;
    model.dec_code=98;
    code_of_symbols.push_back(model);

    model.letter='c';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=1;model.bin_code[7]=1;
    model.dec_code=99;
    code_of_symbols.push_back(model);

    model.letter='d';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=0;model.bin_code[7]=0;
    model.dec_code=100;
    code_of_symbols.push_back(model);

    model.letter='e';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=0;model.bin_code[7]=1;
    model.dec_code=101;
    code_of_symbols.push_back(model);

    model.letter='f';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=1;model.bin_code[7]=0;
    model.dec_code=102;
    code_of_symbols.push_back(model);

    model.letter='g';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=1;model.bin_code[7]=1;
    model.dec_code=103;
    code_of_symbols.push_back(model);

    model.letter='h';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=0;
    model.dec_code=104;
    code_of_symbols.push_back(model);

    model.letter='i';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=1;
    model.dec_code=105;
    code_of_symbols.push_back(model);

    model.letter='j';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=0;model.bin_code[6]=1;model.bin_code[7]=0;
    model.dec_code=106;
    code_of_symbols.push_back(model);

    model.letter='k';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=0;model.bin_code[6]=1;model.bin_code[7]=1;
    model.dec_code=107;
    code_of_symbols.push_back(model);

    model.letter='l';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=1;model.bin_code[6]=0;model.bin_code[7]=0;
    model.dec_code=108;
    code_of_symbols.push_back(model);

    model.letter='m';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=1;model.bin_code[6]=0;model.bin_code[7]=1;
    model.dec_code=109;
    code_of_symbols.push_back(model);

    model.letter='n';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=1;model.bin_code[6]=1;model.bin_code[7]=0;
    model.dec_code=110;
    code_of_symbols.push_back(model);

    model.letter='o';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=1;model.bin_code[5]=1;model.bin_code[6]=1;model.bin_code[7]=1;
    model.dec_code=111;
    code_of_symbols.push_back(model);

    model.letter='p';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=0;
    model.dec_code=112;
    code_of_symbols.push_back(model);

    model.letter='q';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=1;
    model.dec_code=113;
    code_of_symbols.push_back(model);

    model.letter='r';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=1;model.bin_code[7]=0;
    model.dec_code=114;
    code_of_symbols.push_back(model);

    model.letter='s';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=1;model.bin_code[7]=1;
    model.dec_code=115;
    code_of_symbols.push_back(model);

    model.letter='t';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=0;model.bin_code[7]=0;
    model.dec_code=116;
    code_of_symbols.push_back(model);

    model.letter='u';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=0;model.bin_code[7]=1;
    model.dec_code=117;
    code_of_symbols.push_back(model);

    model.letter='v';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=1;model.bin_code[7]=0;
    model.dec_code=118;
    code_of_symbols.push_back(model);

    model.letter='w';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=0;model.bin_code[5]=1;model.bin_code[6]=1;model.bin_code[7]=1;
    model.dec_code=119;
    code_of_symbols.push_back(model);

    model.letter='x';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=1;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=0;
    model.dec_code=120;
    code_of_symbols.push_back(model);


    model.letter='y';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=1;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=1;
    model.dec_code=121;
    code_of_symbols.push_back(model);

    model.letter='z';
    model.bin_code[0]=0;model.bin_code[1]=1;model.bin_code[2]=1;model.bin_code[3]=1;model.bin_code[4]=1;model.bin_code[5]=0;model.bin_code[6]=1;model.bin_code[7]=0;
    model.dec_code=122;
    code_of_symbols.push_back(model);

    model.letter=' ';
    model.bin_code[0]=0;model.bin_code[1]=0;model.bin_code[2]=1;model.bin_code[3]=0;model.bin_code[4]=0;model.bin_code[5]=0;model.bin_code[6]=0;model.bin_code[7]=0;
    model.dec_code=32;
    code_of_symbols.push_back(model);

}

int bin_to_dec(int bin[]){

    int dec=0;
    for(int i=0;i<16;i++){
        dec+=bin[i]*pow(2,15-i);
    }
    return dec;
}

void dec_to_bin(unsigned long dec){

    int help[16];
    for(int i=0;i<16;i++){
        help[i]=0;
    }
    for(int i=0;i<16;i++){
        help[i]=dec%2;
        dec=dec/2;
        bin_out[15-i]=help[i];
    }

}

int enter_key(){

    cout<<"Enter the key(key => 16 symbols):"<<endl;
    cin.getline(key_text,512);
    cout<<endl;

}

void key_generation(){

    vector<for_crypt>::iterator iter;
    int k=0;
    for(int i=0;i<16;i++){
        for(iter=code_of_symbols.begin();iter!=code_of_symbols.end();iter++){
            if(key_text[i]==iter->letter){
                for(int j=0;j<8;j++){
                    key[k]=iter->bin_code[j];
                    k++;
                }
            }
        }
    }



}

void new_key(){

    int save;
    for(int i=0;i<25;i++){
        save=key[0];
        for(int j=0;j<127;j++){
            key[j]=key[j+1];
        }
        key[127]=save;
    }

}

void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

}

void multiplication(int m1[],int m2[]){

    int x1,x2;
    x1=bin_to_dec(m1);
    x2=bin_to_dec(m2);

    unsigned long res=((x1*x2)%65536)+1;
    dec_to_bin(res);

}

void addition(int m1[],int m2[]){

    int x1,x2;
    x1=bin_to_dec(m1);
    x2=bin_to_dec(m2);

    int res=(x1+x2)%65536;
    dec_to_bin(res);

}


void Xor(int m1[],int m2[]){

    for(int i=0;i<16;i++){
        bin_out[i]=(m1[i]+m2[i])%2;
    }

}

void create_under_key(){

    if(it_key==128){
            new_key();
            it_key=0;
    }
    for(int i=0;i<16;i++){
        key_help[i]=key[it_key];
        it_key++;
    }

}

void gcd(int a, int b, int *x, int *y, int *nod){
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

void under_decript_key(int number, int operation){//0-аддитивное, 1-мультипликативное

    it_key=0;
    key_generation();
    for(int i=0;i<number;i++){
        create_under_key();
    }
    if(operation==1){
        int x,y,nod;
        int k=bin_to_dec(key_help);
        gcd(k,65537,&x,&y,&nod);
        dec_to_bin(x);
        for(int i=0;i<16;i++){
            key_help[i]=bin_out[i];
        }
    }
    if(operation==0){
        int k=bin_to_dec(key_help);
        int x=65536-k;
        dec_to_bin(x);
        for(int i=0;i<16;i++){
            key_help[i]=bin_out[i];
        }
    }

}

void output(){

    int i=0;
    cout<<endl<<"Encrypt text:"<<endl;
    while(text[i]!='\0'){
        cout<<text[i];
        i++;
    }
    cout<<endl;

}


void crypt_one_block(){

    int text_bin[64];
    int step=0;
    vector <for_crypt>::iterator it;
    it_text=0;
    for(int i=0;i<8;i++){
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(text[it_text]==it->letter){
                for(int j=0;j<8;j++){
                    text_bin[step]=it->bin_code[j];
                    step++;
                }
            }
        }
        it_text++;
    }
    int D1[16];
    int D2[16];
    int D3[16];
    int D4[16];

    step=0;
    for(int i=0;i<16;i++){
        D1[i]=text_bin[step];
        step++;
    }
    for(int i=0;i<16;i++){
        D2[i]=text_bin[step];
        step++;
    }
    for(int i=0;i<16;i++){
        D3[i]=text_bin[step];
        step++;
    }
    for(int i=0;i<16;i++){
        D4[i]=text_bin[step];
        step++;
    }


    int save1[16];
    int save2[16];
    int save[16];
    it_key=0;


    for(int j=0;j<8;j++){
        if(j!=0){
            for(int k=0;k<16;k++){
                save[k]=D2[k];
                D2[k]=D3[k];
                D3[k]=save[k];
            }
        }
        create_under_key();
        multiplication(D1,key_help);//D1*K1
        for(int i=0;i<16;i++){D1[i]=bin_out[i];}

        create_under_key();
        addition(D2,key_help);//D2+K2
        for(int i=0;i<16;i++){D2[i]=bin_out[i];}

        create_under_key();
        addition(D3,key_help);//D2+K2
        for(int i=0;i<16;i++){D3[i]=bin_out[i];}

        create_under_key();
        multiplication(D4,key_help);//D1*K1
        for(int i=0;i<16;i++){D4[i]=bin_out[i];}

        Xor(D1,D3);//D1 xor D3
        for(int i=0;i<16;i++){save1[i]=bin_out[i];}

        Xor(D2,D4);//D2 xor D4
        for(int i=0;i<16;i++){save2[i]=bin_out[i];}

        create_under_key();
        multiplication(save1,key_help);//save1*K5
        for(int i=0;i<16;i++){save1[i]=bin_out[i];}

        addition(save2,save1);//save2+save1
        for(int i=0;i<16;i++){save2[i]=bin_out[i];}

        create_under_key();
        multiplication(save2,key_help);//save2*K6
        for(int i=0;i<16;i++){save2[i]=bin_out[i];}

        addition(save2,save1);//save2+save1
        for(int i=0;i<16;i++){save1[i]=bin_out[i];}

        Xor(D1,save2);//D1 xor save2
        for(int i=0;i<16;i++){D1[i]=bin_out[i];}

        Xor(D3,save2);//D3 xor save2
        for(int i=0;i<16;i++){D3[i]=bin_out[i];}

        Xor(D2,save1);//D2 xor save1
        for(int i=0;i<16;i++){D2[i]=bin_out[i];}

        Xor(D4,save1);//D4 xor save1
        for(int i=0;i<16;i++){D4[i]=bin_out[i];}
    }

    create_under_key();
    multiplication(D1,key_help);//D1*K1
    for(int i=0;i<16;i++){D1[i]=bin_out[i];}

    create_under_key();
    addition(D2,key_help);//D2+K2
    for(int i=0;i<16;i++){D2[i]=bin_out[i];}

    create_under_key();
    addition(D3,key_help);//D2+K2
    for(int i=0;i<16;i++){D3[i]=bin_out[i];}

    create_under_key();
    multiplication(D4,key_help);//D1*K1
    for(int i=0;i<16;i++){D4[i]=bin_out[i];}


    for(int i=0;i<16;i++){
        crypt_text[it_text_plus]=D1[i];
        it_text_plus++;
    }
    for(int i=0;i<16;i++){
        crypt_text[it_text_plus]=D2[i];
        it_text_plus++;
    }
    for(int i=0;i<16;i++){
        crypt_text[it_text_plus]=D3[i];
        it_text_plus++;
    }
    for(int i=0;i<16;i++){
        crypt_text[it_text_plus]=D4[i];
        it_text_plus++;
    }

}



void encrypt_one_block(){

    int text_bin[64];
    for(int i=0;i<64;i++){
        text_bin[i]=crypt_text[it_crypt_text+i];
    }
    int D1[16];
    int D2[16];
    int D3[16];
    int D4[16];

    int step=0;
    for(int i=0;i<16;i++){
        D1[i]=text_bin[step];
        step++;
    }
    for(int i=0;i<16;i++){
        D2[i]=text_bin[step];
        step++;
    }
    for(int i=0;i<16;i++){
        D3[i]=text_bin[step];
        step++;
    }
    for(int i=0;i<16;i++){
        D4[i]=text_bin[step];
        step++;
    }

    int save1[16];
    int save2[16];
    int save[16];

    under_decript_key(49,1);
    multiplication(D1,key_help);//D1*K1'
    for(int i=0;i<16;i++){D1[i]=bin_out[i];}

    under_decript_key(50,0);
    addition(D2,key_help);//D2*K2'
    for(int i=0;i<16;i++){D2[i]=bin_out[i];}

    under_decript_key(51,0);
    addition(D3,key_help);//D3*K3'
    for(int i=0;i<16;i++){D3[i]=bin_out[i];}

    under_decript_key(52,1);
    multiplication(D4,key_help);//D4*K4'
    for(int i=0;i<16;i++){D4[i]=bin_out[i];}

    Xor(D1,D3);//D1 xor D3
    for(int i=0;i<16;i++){save1[i]=bin_out[i];}

    Xor(D2,D4);//D2 xor D4
    for(int i=0;i<16;i++){save2[i]=bin_out[i];}

    under_decript_key(47,-1);
    multiplication(save1,key_help);//save1*K5'
    for(int i=0;i<16;i++){save1[i]=bin_out[i];}

    addition(save2,save1);//save2+save1
    for(int i=0;i<16;i++){save2[i]=bin_out[i];}

    under_decript_key(48,-1);
    multiplication(save2,key_help);//save2*K6'
    for(int i=0;i<16;i++){save2[i]=bin_out[i];}

    addition(save2,save1);//save2+save1
    for(int i=0;i<16;i++){save1[i]=bin_out[i];}

    Xor(D1,save2);//D1 xor save2
    for(int i=0;i<16;i++){D1[i]=bin_out[i];}

    Xor(D3,save2);//D3 xor save2
    for(int i=0;i<16;i++){D3[i]=bin_out[i];}

    Xor(D2,save1);//D2 xor save1
    for(int i=0;i<16;i++){D2[i]=bin_out[i];}

    Xor(D4,save1);//D4 xor save1
    for(int i=0;i<16;i++){D4[i]=bin_out[i];}

    for(int i=2;i<9;i++){
        for(int k=0;k<16;k++){
                save[k]=D2[k];
                D2[k]=D3[k];
                D3[k]=save[k];
            }
        int ijk=(9-i)*6;
        under_decript_key(ijk+1,1);
        multiplication(D1,key_help);//D1*K1'
        for(int i=0;i<16;i++){D1[i]=bin_out[i];}

        under_decript_key(ijk+3,0);
        addition(D2,key_help);//D2*K2'
        for(int i=0;i<16;i++){D2[i]=bin_out[i];}

        under_decript_key(ijk+2,0);
        addition(D3,key_help);//D3*K3'
        for(int i=0;i<16;i++){D3[i]=bin_out[i];}

        under_decript_key(ijk+4,1);
        multiplication(D4,key_help);//D4*K4'
        for(int i=0;i<16;i++){D4[i]=bin_out[i];}

        Xor(D1,D3);//D1 xor D3
        for(int i=0;i<16;i++){save1[i]=bin_out[i];}

        Xor(D2,D4);//D2 xor D4
        for(int i=0;i<16;i++){save2[i]=bin_out[i];}

        under_decript_key(ijk-1,-1);
        multiplication(save1,key_help);//save1*K5'
        for(int i=0;i<16;i++){save1[i]=bin_out[i];}

        addition(save2,save1);//save2+save1
        for(int i=0;i<16;i++){save2[i]=bin_out[i];}

        under_decript_key(ijk,-1);
        multiplication(save2,key_help);//save2*K6'
        for(int i=0;i<16;i++){save2[i]=bin_out[i];}

        addition(save2,save1);//save2+save1
        for(int i=0;i<16;i++){save1[i]=bin_out[i];}

        Xor(D1,save2);//D1 xor save2
        for(int i=0;i<16;i++){D1[i]=bin_out[i];}

        Xor(D3,save2);//D3 xor save2
        for(int i=0;i<16;i++){D3[i]=bin_out[i];}

        Xor(D2,save1);//D2 xor save1
        for(int i=0;i<16;i++){D2[i]=bin_out[i];}

        Xor(D4,save1);//D4 xor save1
        for(int i=0;i<16;i++){D4[i]=bin_out[i];}
    }


    under_decript_key(1,1);
    multiplication(D1,key_help);//D1*K1
    for(int i=0;i<16;i++){D1[i]=bin_out[i];}

    under_decript_key(2,0);
    addition(D2,key_help);//D2+K2
    for(int i=0;i<16;i++){D2[i]=bin_out[i];}

    under_decript_key(3,0);
    addition(D3,key_help);//D2+K2
    for(int i=0;i<16;i++){D3[i]=bin_out[i];}

    under_decript_key(4,1);
    multiplication(D4,key_help);//D1*K1
    for(int i=0;i<16;i++){D4[i]=bin_out[i];}



    for(int i=0;i<16;i++){
        encrypt_text[it_crypt_text]=D1[i];
        it_crypt_text++;
    }
    for(int i=0;i<16;i++){
        encrypt_text[it_crypt_text]=D2[i];
        it_crypt_text++;
    }
    for(int i=0;i<16;i++){
        encrypt_text[it_crypt_text]=D3[i];
        it_crypt_text++;
    }
    for(int i=0;i<16;i++){
        encrypt_text[it_crypt_text]=D4[i];
        it_crypt_text++;
    }
    output();
}




int main()
{

    forming_source_alfabet();
    enter_key();
    int h=0;
    while(key_text[h]!='\0'){
        h++;
    }
    if(h<16){
        cout<<"!!!Key is wrong!!!"<<endl;
        return 0;
    }

    key_generation();
    entering();
    cout<<"Key:"<<endl;
    for(int i=0;i<128;i++){
        cout<<key[i];
    }
    cout<<endl<<endl;

    it_text=0;
    while(text[it_text]!='\0'){
        it_text++;
    }
    int div=it_text/8;
    int mod=it_text%8;
    if(mod==0){
        for(int j=0;j<div;j++){
            crypt_one_block();
        }
    }
    if(mod!=0){
        for(int j=it_text;j<it_text+8-div;j++){
            text[j]=' ';
        }
        for(int j=0;j<div+1;j++){
            crypt_one_block();
        }
    }

    cout<<endl<<"Crypt text in bin:"<<endl;
    for(int i=0;i<it_text_plus;i++){
        if(i%16==0&&i!=0){
            cout<<".";
        }
        cout<<crypt_text[i];
    }
    cout<<endl;

    it_crypt_text=0;
    int kol=it_text_plus/64;
    for(int i=0;i<kol;i++){
        encrypt_one_block();
    }
    cout<<endl<<"Encrypt text in bin:"<<endl;
    for(int i=0;i<it_crypt_text;i++){
        if(i%8==0&&i!=0){
            cout<<".";
        }
        cout<<encrypt_text[i];
    }
    cout<<endl;

    code_of_symbols.clear();
    delete [] key_text;
    delete [] bin_out;
    delete [] key;
    delete [] crypt_text;
    delete [] encrypt_text;
    return 0;
}
