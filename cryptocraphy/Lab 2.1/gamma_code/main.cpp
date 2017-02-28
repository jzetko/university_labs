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

char text[512];//исходынй текст
int crypt_text[2048];//шифрованный текст в двоичном виде
char encrypt_text[512];//дешифрованный текст
char key[512];//ключ
int size_of_text=0;//размер текста
int count_for_crypt_text=0;//размер шифрованного текста

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


void count_lenght_of_text(){

    int i=0;
    while(text[i]!='\0'){
        size_of_text++;
        i++;
    }

}

char *massiv_for_key=new char[size_of_text];//массив под расширенный ключ

void forming_normal_key(){//задание ключа, длинной равного длине текста

    int i=0;
    int j=0;
    for(i=0;i<size_of_text;i++){
        if(key[j]=='\0'){
            j=0;
        }
        massiv_for_key[i]=key[j];
        j++;
    }
}


void entering(){//ввод ключа и тектса

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

    cout<<"Enter the key:"<<endl;
    cin.getline(key,512);
    cout<<endl;

}


void crypt(){//шифрование

    vector <for_crypt>::iterator it,it_key;

    int i=0;
    int j;
    while(text[i]!='\0'){
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(text[i]==it->letter){//поиск буквы из текста в таблице
                for(it_key=code_of_symbols.begin();it_key!=code_of_symbols.end();it_key++){
                    if(massiv_for_key[i]==it_key->letter){//поиск буквы из ключа в таблице
                        for(j=0;j<8;j++){
                            crypt_text[count_for_crypt_text]=(it->bin_code[j]+it_key->bin_code[j])%2;//побитовое применение исключающего или
                            count_for_crypt_text++;
                        }
                    }
                }
            }
        }
        i++;
    }

}


void encrypt(){//дешифрование

    vector <for_crypt>::iterator it,it_key;

    int i=0;
    int k=0;
    int j;
    int one;
    while(massiv_for_key[i]!='\0'){
        int dec=0;
        for(it_key=code_of_symbols.begin();it_key!=code_of_symbols.end();it_key++){
            if(massiv_for_key[i]==it_key->letter){//поиск буквы ключа в таблице
                for(j=0;j<8;j++){
                    one=(crypt_text[k]+it_key->bin_code[j])%2;//побитовое исключающее или шифрованного текста и ключа
                    k++;
                    dec+=one*pow(2,7-j);//подсчет десятичного кода буквы из таблицы
                }
            }
        }
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(dec==it->dec_code){
                encrypt_text[i]=it->letter;//запись буквы в дешифрованный текст
            }
        }
        i++;
    }

}


void text_and_key_into_bin(){

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

    cout<<endl<<endl<<"Key into bin:"<<endl;
    i=0;
    while(massiv_for_key[i]!='\0'){
        for(it=code_of_symbols.begin();it!=code_of_symbols.end();it++){
            if(massiv_for_key[i]==it->letter){
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

    entering();
    forming_source_alfabet();
    count_lenght_of_text();
    forming_normal_key();
    crypt();
    encrypt();

    int i;
    cout<<"Cryption text:"<<endl;
    for(i=0;i<count_for_crypt_text;i++){
        if(i%8==0&&i!=0){
            cout<<" ";
        }
        cout<<crypt_text[i];
    }


    cout<<endl<<endl<<"Encryption text:"<<endl;
    i=0;
    while(encrypt_text[i]!='\0'){
        cout<<encrypt_text[i];
        i++;
    }
    cout<<endl<<endl;

    cout<<"Do you want view binary code of text and key?(y/n): ";
    string answer;
    cin>>answer;
    if(answer=="y"){
        text_and_key_into_bin();
    }


    delete text;
    delete crypt_text;
    delete encrypt_text;
    delete key;
    delete massiv_for_key;
    code_of_symbols.clear();
    return 0;
}
