#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

char text[256];
int bin_out8[8];
int bin_out[20];
vector <int> text_bin,control_bin;
int r_count=0;

void enter(){
    cout<<"Enter the text:"<<endl;
    cin.getline(text,256);
    cout<<endl;

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


void text_to_bin(){

    int i=0;
    while(text[i]!='\0'){
        int x=int(text[i]);
        dec_to_bin8(x);
        for(int j=0;j<8;j++){
            text_bin.push_back(bin_out8[j]);
        }
        i++;
    }

}




void creation_control_bits(){

    int i=text_bin.size();
    int j=1;
    int k=0;
    int l=0;
    while(i>0){
        if(pow(2,k)==j){
            control_bin.push_back(0);
            k++;
            j++;
            r_count++;
        }
        else{
            control_bin.push_back(text_bin[l]);
            l++;
            j++;
            i--;
        }
    }

}

void dec_to_bin(int dec){

    for(int i=0;i<20;i++){
        bin_out[i]=dec%2;
        dec=dec/2;
    }

}

int inverse(int x){

    x=(x+1)%2;
    return x;

}


int bin_to_dec(int mas[],int koefficient){

    int sum=0;
    for(int i=0;i<koefficient;i++){
        double help=pow(2,koefficient-1-i);
        sum+=help*mas[i];
    }
    return sum;

}


int main()
{
    enter();
    text_to_bin();

    vector<int>::iterator it;
    cout<<"Text in binary digits: ";
    for(it=text_bin.begin();it!=text_bin.end();it++){
        cout<<*it;
    }
    cout<<endl;

    creation_control_bits();


    int width=control_bin.size()+1;//ширина
    int height=r_count+1;//высота


    int **matrix=new int *[height];
    for(int i=0;i<height;i++){
        matrix[i]=new int[width];
    }

    for(int j=0;j<width-1;j++){
        matrix[0][j]=control_bin[j];
    }

    for(int j=0;j<width-1;j++){
        dec_to_bin(j+1);
        for(int i=1;i<height;i++){
            matrix[i][j]=bin_out[i-1];
        }
    }

    int control_sum;

    for(int i=1;i<height;i++){
        control_sum=0;
        for(int j=0;j<width-1;j++){
            control_sum+=matrix[i][j]*matrix[0][j];
        }
        control_sum=control_sum%2;
        matrix[i][width-1]=control_sum;
    }

    int step=0;
    int iter=1;

    for(int j=0;j<width-1;j++){
        if(pow(2,step)==j+1){
            matrix[0][j]=matrix[iter][width-1];
            step++;
            iter++;
        }
    }

    matrix[0][width-1]=8;
    cout<<"Matrix:"<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<"Control bits:"<<endl;
    for(int i=1;i<height;i++){
        cout<<"r"<<i<<"="<<matrix[i][width-1]<<endl;
    }

    cout<<endl<<"Codeword: ";
    for(int j=0;j<width-1;j++){
        cout<<matrix[0][j];
    }
    cout<<endl;

    int corrupted_bit;
    cout<<endl<<"Enter the number of bit to inverse [1;"<<width-1<<"]: ";
    cin>>corrupted_bit;
    if(corrupted_bit<1||corrupted_bit>width-1){
        cout<<"Number is wrong!"<<endl;
        return 0;
    }


    int **matrix_of_syndromes=new int *[height];
    for(int i=0;i<height;i++){
        matrix_of_syndromes[i]=new int[width];
    }

    step=0;
    for(int j=0;j<width-1;j++){
        if(corrupted_bit!=j+1){
            matrix_of_syndromes[0][j]=matrix[0][j];
        }
        else{
            matrix_of_syndromes[0][j]=inverse(matrix[0][j]);
        }
    }


    for(int i=1;i<height;i++){
        for(int j=0;j<width-1;j++){
            matrix_of_syndromes[i][j]=matrix[i][j];
        }
    }

    for(int i=1;i<height;i++){
        control_sum=0;
        for(int j=0;j<width-1;j++){
            control_sum+=matrix_of_syndromes[i][j]*matrix_of_syndromes[0][j];
        }
        control_sum=control_sum%2;
        matrix_of_syndromes[i][width-1]=control_sum;
    }

    matrix_of_syndromes[0][width-1]=8;
    cout<<endl<<"Matrix of syndromes:"<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<matrix_of_syndromes[i][j]<<" ";
        }
        cout<<endl;
    }

    int s_count=r_count;
    int *syndroms=new int[s_count];

    int cnt=0;
    for(int i=height-1;i>0;i--){
        syndroms[cnt]=matrix_of_syndromes[i][width-1];
        cnt++;
    }

    int incorrect_bit=bin_to_dec(syndroms,s_count);
    cout<<endl<<"Number of incorrect bit="<<incorrect_bit<<endl;


    cout<<endl<<"Text in bin after recovery: ";
    step=0;
    for(int j=0;j<width-1;j++){
        if(pow(2,step)==j+1){
            step++;
        }
        else{
            if(j+1!=incorrect_bit){
                cout<<matrix_of_syndromes[0][j];
            }
            else{
                cout<<inverse(matrix_of_syndromes[0][j]);
            }
        }
    }

    cout<<endl;



    for(int i=0;i<=r_count;i++){
        delete [] matrix_of_syndromes[i];
    }
    delete [] matrix_of_syndromes;


    for(int i=0;i<=r_count;i++){
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}
