#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

char mapp[26][26];
char key[10];
char text[512];
int size_of_text=0;
char text_after_cryption[512];
char text_after_encryption[512];

struct letter_by_number{
    char letter;
    int number;
};

letter_by_number model;
vector<letter_by_number> vect;

void forming_map(){

    int i,j;
    i=0;
    mapp[i][0]='a';
    mapp[i][1]='b';
    mapp[i][2]='c';
    mapp[i][3]='d';
    mapp[i][4]='e';
    mapp[i][5]='f';
    mapp[i][6]='g';
    mapp[i][7]='h';
    mapp[i][8]='i';
    mapp[i][9]='j';
    mapp[i][10]='k';
    mapp[i][11]='l';
    mapp[i][12]='m';
    mapp[i][13]='n';
    mapp[i][14]='o';
    mapp[i][15]='p';
    mapp[i][16]='q';
    mapp[i][17]='r';
    mapp[i][18]='s';
    mapp[i][19]='t';
    mapp[i][20]='u';
    mapp[i][21]='v';
    mapp[i][22]='w';
    mapp[i][23]='x';
    mapp[i][24]='y';
    mapp[i][25]='z';
    for(i=1;i<26;i++){
        for(j=0;j<26;j++){
            if(j==25){
                mapp[i][j]=mapp[i-1][0];
            }
            else{
                mapp[i][j]=mapp[i-1][j+1];
            }
        }
    }

}

void forming_vector(){

    model.letter='a';
    model.number=0;
    vect.push_back(model);

    model.letter='b';
    model.number=1;
    vect.push_back(model);


    model.letter='c';
    model.number=2;
    vect.push_back(model);

    model.letter='d';
    model.number=3;
    vect.push_back(model);

    model.letter='e';
    model.number=4;
    vect.push_back(model);

    model.letter='f';
    model.number=5;
    vect.push_back(model);

    model.letter='g';
    model.number=6;
    vect.push_back(model);

    model.letter='h';
    model.number=7;
    vect.push_back(model);

    model.letter='i';
    model.number=8;
    vect.push_back(model);

    model.letter='j';
    model.number=9;
    vect.push_back(model);

    model.letter='k';
    model.number=10;
    vect.push_back(model);

    model.letter='l';
    model.number=11;
    vect.push_back(model);

    model.letter='m';
    model.number=12;
    vect.push_back(model);

    model.letter='n';
    model.number=13;
    vect.push_back(model);

    model.letter='o';
    model.number=14;
    vect.push_back(model);

    model.letter='p';
    model.number=15;
    vect.push_back(model);

    model.letter='q';
    model.number=16;
    vect.push_back(model);

    model.letter='r';
    model.number=17;
    vect.push_back(model);

    model.letter='s';
    model.number=18;
    vect.push_back(model);

    model.letter='t';
    model.number=19;
    vect.push_back(model);

    model.letter='u';
    model.number=20;
    vect.push_back(model);

    model.letter='v';
    model.number=21;
    vect.push_back(model);

    model.letter='w';
    model.number=22;
    vect.push_back(model);

    model.letter='x';
    model.number=23;
    vect.push_back(model);

    model.letter='y';
    model.number=24;
    vect.push_back(model);

    model.letter='z';
    model.number=25;
    vect.push_back(model);

}


void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

    cout<<"Enter the key:"<<endl;
    cin.getline(key,10);
    cout<<endl;

}

int check(){
    int i=0;
    int count=0;
    while(key[i]!='\0'){
        i++;
        count++;
    }
    if(count<5||count>10){
        cout<<"Key is incorrect! Try again!"<<endl;
        return 0;
    }
}

void count_lenght_of_text(){

    int i=0;
    while(text[i]!='\0'){
        if(text[i]!=' '){
            size_of_text++;
        }
        i++;
    }

}

char *massiv_for_key=new char[size_of_text];

void forming_normal_key(){

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

void crypt_text(){

    int i=0;
    int j=0;
    int first,second;
    vector <letter_by_number>::iterator it;
    while(text[i]!='\0'){
        if(text[i]==' '){
            text_after_cryption[i]=' ';
            i++;
        }
        else{
            for(it=vect.begin();it!=vect.end();it++){
                if(text[i]==it->letter){
                    first=it->number;
                }
            }
            for(it=vect.begin();it!=vect.end();it++){
                if(massiv_for_key[j]==it->letter){
                    second=it->number;
                }
            }
            text_after_cryption[i]=mapp[first][second];
            i++;
            j++;
        }
    }

    i=0;
    cout<<"Cryption text:"<<endl;
    while(text_after_cryption[i]!='\0'){
        cout<<text_after_cryption[i];
        i++;
    }
    cout<<endl<<endl;

}

void encrypt_text(){

    int i=0;
    int j=0;
    int first,second;
    vector <letter_by_number>::iterator it;
    while(text_after_cryption[i]!='\0'){
        if(text_after_cryption[i]==' '){
            text_after_encryption[i]=' ';
            i++;
        }
        else{
            for(it=vect.begin();it!=vect.end();it++){
                if(massiv_for_key[j]==it->letter){
                    second=it->number;
                }
            }
            for(int k=0;k<25;k++){
                if(mapp[second][k]==text_after_cryption[i]){
                    first=k;
                    break;
                }
            }
            for(it=vect.begin();it!=vect.end();it++){
                if(first==it->number){
                    text_after_encryption[i]=it->letter;
                }
            }
            i++;
            j++;
        }
    }

    i=0;
    cout<<"Encryption text:"<<endl;
    while(text_after_encryption[i]!='\0'){
        cout<<text_after_encryption[i];
        i++;
    }
    cout<<endl<<endl;



}



int main()
{

    forming_map();
    forming_vector();

    entering();
    check();

    count_lenght_of_text();
    forming_normal_key();

    crypt_text();
    encrypt_text();

    delete mapp;
    vect.clear();
    delete key;
    delete text;
    delete text_after_cryption;
    delete text_after_encryption;
    delete [] massiv_for_key;

    return 0;

}
