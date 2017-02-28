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

const int N=26;
int polinom[N];
char text[512];//исходынй текст
int crypt_text[2048];//шифрованный текст в двоичном виде
char encrypt_text[512];//дешифрованный текст
int it_crypt_text=0;


vector <for_crypt> code_of_symbols;//таблица кодов символов
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


void key_null(){

    for(int i=0;i<N;i++){
        polinom[i]=1;
    }

}

void new_polinom(){

    int Xor=(((polinom[25]+polinom[7])%2+polinom[6])%2+polinom[0])%2;

    for(int i=25;i>=0;i--){
        polinom[i]=polinom[i-1];
    }

    polinom[0]=Xor;

}

void output_period_of_polinom(){

    unsigned long long period=pow(2,N)-1;
    cout<<"Period="<<period<<endl<<endl;

    key_null();

    for(unsigned long long i=0;i<pow(2,N)-3;i++){
        new_polinom();
    }

    cout<<"Second last element of period:"<<endl;
    for(int j=0;j<N;j++){
            cout<<polinom[j];
        }

    cout<<endl<<"Last element of period:"<<endl;
    new_polinom();
    for(int j=0;j<N;j++){
            cout<<polinom[j];
    }

    cout<<endl<<"!!!New period!!!"<<endl;
    new_polinom();
    for(int j=0;j<N;j++){
            cout<<polinom[j];
    }

}



void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

}


void crypt(){

    int it_text=0;
    int it_key=0;
    vector <for_crypt>::iterator it;
    while(text[it_text]!='\0'){
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(text[it_text]==it->letter){
                for(int i=0;i<8;i++){
                    if(it_key==N){
                        new_polinom();
                        it_key=0;
                    }
                    crypt_text[it_crypt_text]=(it->bin_code[i]+polinom[it_key])%2;
                    it_crypt_text++;
                    it_key++;
                }
            }
        }
        it_text++;
    }

}


void encrypt(){

    vector <for_crypt>::iterator it;
    int it_text=0;
    int it_encrypt_text=0;
    int it_key=0;
    key_null();
    int dec,one;
    for(int i=0;i<it_crypt_text/8;i++){
        dec=0;
        for(int j=0;j<8;j++){
            if(it_key==N){
                new_polinom();
                it_key=0;
            }
            one=(polinom[it_key]+crypt_text[it_text])%2;
            dec+=one*pow(2,7-j);
            it_key++;
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

    key_null();
    entering();
    forming_source_alfabet();
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

    cout<<endl<<"Do you want view binary code of text and key?(y/n): ";
    string answer;
    cin>>answer;
    if(answer=="y"){
        text_into_bin();
    }
    cout<<endl<<endl;

    cout<<"Do you want see polinom?(y/n): ";
    cin>>answer;
    if(answer=="y"){
        output_period_of_polinom();
    }

    delete text;
    delete crypt_text;
    delete encrypt_text;
    code_of_symbols.clear();
    delete polinom;

    return 0;
}
