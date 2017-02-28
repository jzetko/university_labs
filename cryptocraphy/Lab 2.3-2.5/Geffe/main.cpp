#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

struct for_crypt{
    char letter;//символ
    int bin_code[8];//двочиное 8-битное представление числа
    int dec_code;//десятичное представление числа
};

char text[512];
int crypt_text[2048];
char encrypt_text[512];
int Geffe;
int LFSR1[25];
int LFSR2[33];
int LFSR3[23];
int LFSR1_exit;
int LFSR2_exit;
int LFSR3_exit;
int it_crypt_text=0;

vector <for_crypt> code_of_symbols;
for_crypt model;

void forming_source_alfabet(){//формирование таблицы кодов сиволов

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


void LFSRs_null(){

    for(int i=0;i<25;i++){
        LFSR1[i]=1;
    }

    for(int i=0;i<33;i++){
        LFSR2[i]=1;
    }

    for(int i=0;i<23;i++){
        LFSR3[i]=1;
    }
    LFSR1_exit=1;
    LFSR2_exit=1;
    LFSR3_exit=1;

}

void new_LFSR1(){

    LFSR1_exit=LFSR1[24];
    int Xor=(LFSR1[24]+LFSR1[2])%2;

    for(int i=24;i>=0;i--){
        LFSR1[i]=LFSR1[i-1];
    }

    LFSR1[0]=Xor;

}


void new_LFSR2(){

    LFSR2_exit=LFSR2[32];
    int Xor=(LFSR2[32]+LFSR2[12])%2;

    for(int i=32;i>=0;i--){
        LFSR2[i]=LFSR2[i-1];
    }

    LFSR2[0]=Xor;

}

void new_LFSR3(){

    LFSR3_exit=LFSR3[22];
    int Xor=(LFSR3[22]+LFSR3[4])%2;

    for(int i=22;i>=0;i--){
        LFSR3[i]=LFSR3[i-1];
    }

    LFSR3[0]=Xor;

}

void new_LFSRs(){

    new_LFSR1();
    new_LFSR2();
    new_LFSR3();

}

void Geffe_generate(){

        /*cout<<endl<<i+1<<" step:"<<endl;
        for(int i=0;i<25;i++){
            cout<<LFSR1[i];
        }
        cout<<endl;
        for(int i=0;i<33;i++){
            cout<<LFSR2[i];
        }
        cout<<endl;
        for(int i=0;i<23;i++){
            cout<<LFSR3[i];
        }
        cout<<endl;*/
        Geffe=((LFSR1_exit+LFSR2_exit)/2+((LFSR1_exit+1)%2+LFSR3_exit)/2)%2;
        //cout<<"x1="<<LFSR1_exit<<"  x2="<<LFSR2_exit<<"  x3="<<LFSR3_exit<<endl;
        new_LFSRs();
        //cout<<endl<<"New Geffe="<<Geffe<<endl;

}

void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

}

void output_period(){

    unsigned long long x1=33554431;
    unsigned long long x2=8589934592;
    unsigned long long x3=8388608;

    double k1,k2,k3;
    int m1,m2,m3;

    for(int i=0;i<100;i++){
        k1=x1/pow(10,i);
        if(k1<1){
            m1=i;
            break;
        }
    }
    for(int i=0;i<100;i++){
        k2=x2/pow(10,i);
        if(k2<1){
            m2=i;
            break;
        }
    }
    for(int i=0;i<100;i++){
        k3=x3/pow(10,i);
        if(k3<1){
            m3=i;
            break;
        }
    }
    double offer=k1*k2*k3;
    int mantis=m1+m2+m3;

    cout<<endl<<"Period="<<offer<<"e+"<<mantis<<endl;

}


void crypt(){

    int it_text=0;
    vector <for_crypt>::iterator it;
    while(text[it_text]!='\0'){
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(text[it_text]==it->letter){
                for(int i=0;i<8;i++){
                    Geffe_generate();
                    crypt_text[it_crypt_text]=(Geffe+it->bin_code[i])%2;
                    it_crypt_text++;
                }
            }
        }
        it_text++;
    }

}


void encrypt(){

    vector <for_crypt>::iterator it;
    int dec,one;
    LFSRs_null();
    int it_encrypt_text=0;
    int it_text=0;
    cout<<endl;
    for(int i=0;i<it_crypt_text/8;i++){
        dec=0;
        for(int j=0;j<8;j++){
            Geffe_generate();
            one=(Geffe+crypt_text[it_text])%2;
            dec+=one*pow(2,7-j);
            it_text++;
        }
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(dec==it->dec_code){
                encrypt_text[i]=it->letter;
                it_encrypt_text++;
            }
        }
    }

}

void output_multiplexor(){

    LFSRs_null();
    cout<<endl<<"Firsts 300 bits:"<<endl;
    for(int i=0;i<300;i++){
        Geffe_generate();
        cout<<Geffe;
    }
    for(int i=0;i<1611900;i++){
        for(long long j;j<1500000000000000000;j++){
            Geffe_generate();
        }
    }
    for(long long i=0;i<1278659821814939047;i++){
        Geffe_generate();
    }
    cout<<endl<<"Lasts 300 bits:"<<endl;
    for(int i=0;i<300;i++){
        Geffe_generate();
        cout<<Geffe;
    }
    cout<<endl<<"!!!NEW PERIOD!!! Firsts 300 bits:"<<endl;
    for(int i=0;i<300;i++){
        Geffe_generate();
        cout<<Geffe;
    }
}

void text_into_bin(){

    vector <for_crypt>::iterator it;
    cout<<endl<<"Source text into bin:"<<endl;
    int i=0;
    int j;
    while(text[i]!='\0'){
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(text[i]==it->letter){
                for(j=0;j<8;j++){
                    cout<<it->bin_code[j];
                }
                cout<<" ";
            }
        }
        i++;
    }

}

int main()
{

    forming_source_alfabet();
    LFSRs_null();
    entering();
    crypt();

    int j;
    cout<<endl<<"Cryption text:"<<endl;
    for(j=0;j<it_crypt_text;j++){
        if(j%8==0&&j!=0){
            cout<<" ";
        }
        cout<<crypt_text[j];
    }


    encrypt();
    cout<<endl<<endl<<"Encryption text:"<<endl;
    j=0;
    while(encrypt_text[j]!='\0'){
        cout<<encrypt_text[j];
        j++;
    }
    cout<<endl;

    output_period();
    text_into_bin();
    //output_multiplexor();


    delete text;
    delete crypt_text;
    delete encrypt_text;
    code_of_symbols.clear();
    delete LFSR1;
    delete LFSR2;
    delete LFSR3;
    return 0;

}
