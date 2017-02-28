#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

struct words{
    string phrase;
    int index;
    int code[9];
};

vector <words> dictionary;
words one_word;
int bin_out[9];
int compressed_text[2048];
int it_text=0;
char text[256];

void dec_to_bin(int x){

    for(int i=8;i>=0;i--){
        bin_out[i]=x%2;
        x=x/2;
    }

}

void forming_single_alphabet(){

    for(int i=0;i<256;i++){
        one_word.phrase=char(i);
        one_word.index=i;
        dec_to_bin(i);
        for(int j=0;j<9;j++){
            one_word.code[j]=bin_out[j];
        }
        dictionary.push_back(one_word);
    }

}

void entering(){

    cout<<"Enter the text: ";
    cin.getline(text,256);
    cout<<endl;

}

void compressing(){

    int k=0;
    vector <words>::iterator it;
    char help[50],help2[50];
    help[0]='\0';
    string str_help,backup;
    int it_help=0;
    while(text[k]!='\0'){
        int cnt=0;
        help[it_help]=text[k];
        help[it_help+1]='\0';
        str_help=help;
        for(it=dictionary.begin();it!=dictionary.end();it++){
            if(str_help==it->phrase){
                cnt++;
            }
        }
        if(cnt==0){
            one_word.phrase=str_help;
            one_word.index=dictionary.size();
            dec_to_bin(dictionary.size());
            for(int j=0;j<9;j++){
                one_word.code[j]=bin_out[j];
            }
            dictionary.push_back(one_word);

            for(int j=0;j<50;j++){
                help2[j]=help[j];
            }
            help2[it_help]='\0';
            backup=help2;
            for(it=dictionary.begin();it!=dictionary.end();it++){
                if(backup==it->phrase){
                    for(int l=0;l<9;l++){
                        compressed_text[it_text]=it->code[l];
                        it_text++;
                    }
                }
            }
            char ch=help[it_help];
            memset(help,NULL,50);
            help[0]=ch;
            it_help=1;
            help[1]='\0';
        }
        else{
            it_help++;
        }
        k++;
    }

}

int main()
{
    forming_single_alphabet();
    entering();
    compressing();

    cout<<"Our dictionary:"<<endl;
    vector <words>::iterator it;
    for(it=dictionary.begin();it!=dictionary.end();it++){
        cout<<it->phrase<<" - "<<it->index<<" - ";
            for(int j=0;j<9;j++){
                cout<<it->code[j];
            }
            cout<<endl;
    }

    cout<<endl<<"Compressed text: ";
    for(int i=0;i<it_text;i++){
        cout<<compressed_text[i];
    }
    cout<<endl;

    int l=0;
    while(text[l]!='\0'){
        l++;
    }
    cout<<endl<<"Size of text before LZW compressing="<<l*8<<endl;
    cout<<endl<<"Size of text after LZW compressing="<<it_text<<endl;



    delete [] bin_out;
    delete [] compressed_text;
    dictionary.clear();

    return 0;
}
