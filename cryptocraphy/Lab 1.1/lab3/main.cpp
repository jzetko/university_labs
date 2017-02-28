#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<char> alfabet;
char text[512];
char crypt_text[512];
int key;

void Forming_alfabet(){
    alfabet.push_back('a');
    alfabet.push_back('b');
    alfabet.push_back('c');
    alfabet.push_back('d');
    alfabet.push_back('e');
    alfabet.push_back('f');
    alfabet.push_back('g');
    alfabet.push_back('h');
    alfabet.push_back('i');
    alfabet.push_back('j');
    alfabet.push_back('k');
    alfabet.push_back('l');
    alfabet.push_back('m');
    alfabet.push_back('n');
    alfabet.push_back('o');
    alfabet.push_back('p');
    alfabet.push_back('q');
    alfabet.push_back('r');
    alfabet.push_back('s');
    alfabet.push_back('t');
    alfabet.push_back('u');
    alfabet.push_back('v');
    alfabet.push_back('w');
    alfabet.push_back('x');
    alfabet.push_back('y');
    alfabet.push_back('z');
}

void cript_pos(){
    int i=0;
    int j=0;
    while(text[i]!='\0'){
        vector <char>::iterator it;
        if(text[i]==' '){
            crypt_text[j]=' ';
                j++;
        }
        vector <char>::iterator it_test;
        for(it=alfabet.begin();it<alfabet.end();it++){
            if(text[i]==*it){
                it_test=it;
                for(int count=0;count<abs(key);count++){
                    if(it_test==alfabet.end()-1){
                        it_test=alfabet.begin();
                    }
                    else{it_test++;}
                }
                crypt_text[j]=*it_test;
                j++;
            }
        }
        i++;
    }

}


void cript_neg(){
    int i=0;
    int j=0;
    while(text[i]!='\0'){
        vector <char>::iterator it;
        if(text[i]==' '){
            crypt_text[j]=' ';
                j++;
        }
        vector <char>::iterator it_test;
        for(it=alfabet.begin();it<alfabet.end();it++){
            if(text[i]==*it){
                it_test=it;
                for(int count=0;count<abs(key);count++){
                    if(it_test==alfabet.begin()){
                        it_test=alfabet.end()-1;
                    }
                    else{it_test--;}
                }
                crypt_text[j]=*it_test;
                j++;
            }
        }
        i++;
    }

}


void encription(){
    int i=0;
    while(crypt_text[i]!='\0'){
        text[i]=crypt_text[i];
        i++;
    }
    if(key>=0){
        cript_neg();
    }
    else{
        cript_pos();
    }

    i=0;
    cout<<"The encrypt text:"<<endl;
        while(crypt_text[i]!='\0'){
            cout<<crypt_text[i];
            i++;
        }
    cout<<endl;
}


void cription(){
    if(key>=0){
        cript_pos();
    }
    else{
        cript_neg();
    }

    int i=0;
    cout<<"The crypt text:"<<endl;
        while(crypt_text[i]!='\0'){
            cout<<crypt_text[i];
            i++;
        }
    cout<<endl;
}

int main()
{
    Forming_alfabet();
    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<"Enter the step k: ";
    cin>>key;

    cout<<endl<<endl;

    int i=0;
    cout<<"The source text:"<<endl;
    while(text[i]!='\0'){
        cout<<text[i];
        i++;
    }
    cout<<endl;

    cription();
    delete crypt_text;
    encription();





    alfabet.clear();
    delete text;
    delete crypt_text;
    system("PAUSE");
    return 0;
}
