#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

const int exponent=33;
int bin_out8[8];
int generator_polynomial[exponent]={1,1,1,0,1,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,1};


void dec_to_bin8(int dec){

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

int main()
{

    ifstream text("text.txt");
    char mas[4000];
    text.getline(mas, 4000);
    text.close();


    int length_of_data=0;
    while(mas[length_of_data]!='\0'){
        length_of_data++;
    }

    length_of_data*=8;

    int *data_array=new int[length_of_data];

    int iter=0;
    for(int i=0;i<length_of_data/8;i++){
        int in_bin=char(mas[i]);
        dec_to_bin8(in_bin);
        for(int j=0;j<8;j++){
            data_array[iter]=bin_out8[j];
            iter++;
        }
    }

    /*cout<<"Data array in bin=";
    for(int i=length_of_data-1;i>=0;i--){
        cout<<data_array[i];
    }
    cout<<endl;

    cout<<"Polinom of data array=";
    for(int i=length_of_data-1;i>=0;i--){
        if(data_array[i]==1){
            if(i==0){
                cout<<"1";
            }
            else{
                cout<<"x"<<i<<"+";
            }
        }
    }
    cout<<endl<<endl;*/

    cout<<"Generator polynomial CRC-32-IEEE 802.3:"<<endl;
    cout<<"in bin: ";
    for(int i=exponent-1;i>=0;i--){
        cout<<generator_polynomial[i];
    }
    cout<<endl<<"As polynomial: ";
    for(int i=exponent-1;i>=0;i--){
        if(generator_polynomial[i]==1){
            if(i==0){
                cout<<"1";
            }
            else{
                cout<<"x"<<i<<"+";
            }
        }
    }
    cout<<endl;

    for(int i=length_of_data-1;i>=exponent-1;i--){
        if(data_array[i]==1){
            int k=i;
            for(int j=exponent-1;j>=0;j--){
                data_array[k]=(data_array[k]+generator_polynomial[j])%2;
                k--;
            }
        }
    }


    cout<<endl<<"Control sum:"<<endl;
    cout<<"As polynomial:";
    for(int i=length_of_data-1;i>=0;i--){
        if(data_array[i]==1){
            if(i==0){
                cout<<"1";
            }
            else{
                cout<<"x"<<i<<"+";
            }
        }
    }
    cout<<endl;

    cout<<"In bin:";
    for(int i=exponent-1;i>=0;i--){
        cout<<data_array[i];
    }
    cout<<endl<<endl;



    ifstream text2("distorted_text.txt");
    char mas2[4000];
    text2.getline(mas2, 4000);
    text2.close();

    int length_of_distorted_data=0;
    while(mas2[length_of_distorted_data]!='\0'){
        length_of_distorted_data++;
    }

    length_of_distorted_data*=8;

    int *distorted_data_array=new int[length_of_distorted_data];

    iter=0;
    for(int i=0;i<length_of_distorted_data/8;i++){
        int in_bin=char(mas2[i]);
        dec_to_bin8(in_bin);
        for(int j=0;j<8;j++){
            distorted_data_array[iter]=bin_out8[j];
            iter++;
        }
    }

    for(int i=length_of_distorted_data-1;i>=exponent-1;i--){
        if(distorted_data_array[i]==1){
            int k=i;
            for(int j=exponent-1;j>=0;j--){
                distorted_data_array[k]=(distorted_data_array[k]+generator_polynomial[j])%2;
                k--;
            }
        }
    }


    cout<<endl<<"Control sum of distorted data:"<<endl;
    cout<<"As polynomial:";
    for(int i=length_of_distorted_data-1;i>=0;i--){
        if(distorted_data_array[i]==1){
            if(i==0){
                cout<<"1";
            }
            else{
                cout<<"x"<<i<<"+";
            }
        }
    }
    cout<<endl;

    cout<<"In bin:";
    for(int i=exponent-1;i>=0;i--){
        cout<<distorted_data_array[i];
    }
    cout<<endl<<endl;


    int check=0;

    for(int i=0;i<exponent-1;i++){
        if(distorted_data_array[i]!=data_array[i]){
            check++;
        }
    }

    if(check==0){
        cout<<"Data haven't distortion!!!"<<endl;
    }
    else{
        cout<<"Data have distortion!!!"<<endl;
    }


    delete [] mas;
    delete [] mas2;
    delete [] data_array;
    delete [] distorted_data_array;
    return 0;
}
