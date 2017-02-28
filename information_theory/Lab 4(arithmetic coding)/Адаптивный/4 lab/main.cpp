#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Probability{
    char name;//название элемента
    int frequency;
};

vector <Probability> vector_of_simbols;
int numbers=0;//кол-во элементов
Probability model;
char text[512];//исходный текст
int it_text=0;
int it_detext=0;
long double low,high;
int fractional_part[100];
int counter=0;
int decoding_sequence[100];
long double input;
char decoding_text[512];

void forming_source_alfabet(){//формирование таблицы кодов сиволов

    vector <Probability>::iterator it;
    int i=0;
    while(text[i]!='\0'){
        int count=0;
        for(it=vector_of_simbols.begin();it!=vector_of_simbols.end();it++){
            if(text[i]==it->name){
                count++;
            }
        }
        if(count==0){
            model.name=text[i];
            model.frequency=1;
            numbers++;
            vector_of_simbols.push_back(model);
        }
        i++;
    }

}


int add_one(){

    int ost=1;
    int i=99;
    while(ost!=0){
        fractional_part[i]=fractional_part[i]+ost;
        ost=fractional_part[i]/2;
        fractional_part[i]=fractional_part[i]%2;
        i--;
    }

}

long double bin_to_dec(){

    long double result=0;
    int step;
    for(int i=99;i>=0;i--){
        step=(100-i)*(-1);
        result=result+(fractional_part[i]*pow(2,step));
    }
    return result;
}

void dec_to_bin(long double X){

    int i=0;
    while(X!=0){
        fractional_part[i]=(X*2)/1;
        i++;
        X*=2;
        if(X>=1){
            X-=1;
        }
        counter++;
    }

}

long double bin_sequence_to_dec(){

    for(int i=0;i<counter;i++){
        decoding_sequence[i]=fractional_part[i];
    }
    long double x=0;
    for(int i=0;i<counter;i++){
        x+=decoding_sequence[i]*pow(2,(i+1)*(-1));
    }

    return x;

}

void optimal_code(){

    for(int i=0;i<100;i++){
        fractional_part[i]=0;
    }
    long double x;
    long double y=1;
    unsigned long k=0;
    while(y>0){
        k++;
        add_one();
        x=bin_to_dec();
        if(x>low&&x<high){
            break;
        }
    }
    cout<<"K="<<k<<endl;
    for(int i=0;i<100;i++){
        fractional_part[i]=0;
    }

    dec_to_bin(x);
    cout<<"Final point: "<<x<<endl<<endl;
    cout<<"Binary sequence: ";
    for(int i=0;i<counter;i++){
        cout<<fractional_part[i];
    }
    cout<<endl;

}


void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

    int i=0;
    while(text[i]!='\0'){
        i++;
    }
    text[i]='#';

}


void search_interval_for_code(long double oldLow, long double oldHigh){

    if(text[it_text-1]=='#'){
        low=oldLow;
        high=oldHigh;
        return;
    }

    long double *points=new long double[vector_of_simbols.size()+1];
    long double newLow, newHigh;
    points[0]=oldLow;
    vector <Probability>::iterator it;
    int it_vector=0;
    for(int i=0;i<=vector_of_simbols.size();i++){
        if(i==0){
            continue;
        }
        points[i]=points[i-1]+((oldHigh-oldLow)/numbers*vector_of_simbols[it_vector].frequency);
        it_vector++;
    }


    it_vector=0;
    for(it=vector_of_simbols.begin();it!=vector_of_simbols.end();it++){
        if(text[it_text]==it->name){
            it->frequency++;
            newLow=points[it_vector];
            newHigh=points[it_vector+1];
            break;
        }
        else{
            it_vector++;
        }
    }
    it_text++;
    numbers++;

    delete [] points;
    search_interval_for_code(newLow,newHigh);

}


void search_interval_for_decode(long double oldLow, long double oldHigh){

    long double *points=new long double[vector_of_simbols.size()+1];
    long double newLow, newHigh;
    points[0]=oldLow;
    vector <Probability>::iterator it;
    int it_vector=0;
    for(int i=0;i<=vector_of_simbols.size();i++){
        if(i==0){
            continue;
        }
        points[i]=points[i-1]+((oldHigh-oldLow)/numbers*vector_of_simbols[it_vector].frequency);
        it_vector++;
    }

    for(int i=0;i<vector_of_simbols.size();i++){
        if(input>points[i]&&input<points[i+1]){
            if(vector_of_simbols[i].name=='#'){
                return;
            }
            decoding_text[it_detext]=vector_of_simbols[i].name;
            newLow=points[i];
            newHigh=points[i+1];
            vector_of_simbols[i].frequency++;
            it_detext++;
            break;
        }
    }
    numbers++;

    delete [] points;
    search_interval_for_decode(newLow,newHigh);

}


int main()
{
    entering();
    forming_source_alfabet();

    search_interval_for_code(0,1);
    cout<<"Our interval: ["<<low<<";"<<high<<"]"<<endl;

    optimal_code();
    it_text=0;

    input=bin_sequence_to_dec();
    vector_of_simbols.clear();
    numbers=0;
    forming_source_alfabet();
    search_interval_for_decode(0,1);

    int i=0;
    cout<<"decode_text: ";
    while(decoding_text[i]!='\0'){
        cout<<decoding_text[i];
        i++;
    }
    cout<<endl<<endl;
    i=0;
    while(text[i]!='#'){
        i++;
    }
    int min_bin=ceil(log2(vector_of_simbols.size()-1))*i;
    cout<<"Numbers of bits to coding without algorithm="<<min_bin<<endl;
    cout<<"Numbers of bits to coding after using algorithm="<<counter<<endl<<endl;


    delete [] decoding_sequence;
    delete [] fractional_part;
    delete [] text;
    vector_of_simbols.clear();
    return 0;
}
