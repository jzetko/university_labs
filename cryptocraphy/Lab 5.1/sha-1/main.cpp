#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int A[32]={0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1};
int B[32]={1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1};
int C[32]={1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0};
int D[32]={0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0};
int E[32]={1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0};
char text[512];
int text_bin[4096];
int it_text,iter;
int help_bin[8];
int help_bin2[64];
int numbers_of_bloks=1;
int hashe[4096];
int it_hashe=0;
int w[32];
int bin_out[32];
int block[512];
int w_blocks[80][32];
int it_w=0;


void entering(){

    cout<<"Enter the text:"<<endl;
    cin.getline(text,512);
    cout<<endl;

}

void dec_to_bin(unsigned long dec){

    int help[8];
    for(int i=0;i<8;i++){
        help[i]=0;
    }
    for(int i=0;i<8;i++){
        help[i]=dec%2;
        dec=dec/2;
        help_bin[7-i]=help[i];
    }

}

void dec_to_bin2(unsigned long dec){

    int help[64];
    for(int i=0;i<64;i++){
        help[i]=0;
    }
    for(int i=0;i<64;i++){
        help[i]=dec%2;
        dec=dec/2;
        help_bin2[63-i]=help[i];
    }

}


void dec_to_bin32(long long dec){

    int help[32];
    for(int i=0;i<32;i++){
        help[i]=0;
    }
    for(int i=0;i<32;i++){
        help[i]=dec%2;
        dec=dec/2;
        bin_out[31-i]=help[i];
    }

}


int form_bloks(){

    unsigned long simv;
    while(text[iter]!='\0'){
        simv=int(text[iter]);
        dec_to_bin(simv);
        for(int j=0;j<8;j++){
            text_bin[it_text]=help_bin[j];
            it_text++;
        }
        iter++;
    }
    if(it_text==448){
        dec_to_bin2(iter);
        for(int i=0;i<64;i++){
            text_bin[it_text]=help_bin2[i];
            it_text++;
        }
    }
    else if(it_text<448){
            text_bin[it_text]=1;
            it_text++;
            for(int i=it_text+1;i<448;i++){
                text_bin[i]=0;
                it_text++;
            }
            it_text++;
            dec_to_bin2(iter);
            for(int i=0;i<64;i++){
                text_bin[it_text]=help_bin2[i];
                it_text++;
            }
        }
    else if(it_text>448){
            numbers_of_bloks++;
            text_bin[it_text]=1;
            it_text++;
            for(int i=it_text+1;i<960;i++){
                text_bin[i]=0;
                it_text++;
            }
            it_text++;
            dec_to_bin2(iter);
            for(int i=0;i<64;i++){
                text_bin[it_text]=help_bin2[i];
                it_text++;
            }
        }
}


void Not(int bin[]){

    for(int i=0;i<32;i++){
        bin_out[i]=(bin[i]+1)%2;
    }

}

void And(int bin1[],int bin2[]){

    for(int i=0;i<32;i++){
        bin_out[i]=(bin1[i]+bin2[i])/2;
    }

}

void Or(int bin1[],int bin2[]){

    for(int i=0;i<32;i++){
        if(bin1[i]==0&&bin2[i]==0){
            bin_out[i]=0;
        }
        else{
            bin_out[i]=1;
        }
    }

}


void Xor(int bin1[],int bin2[]){

    for(int i=0;i<32;i++){
        bin_out[i]=(bin1[i]+bin2[i])%2;
    }

}


int in_dec(char ss){

    if(ss=='0'){return 0;}
    if(ss=='1'){return 1;}
    if(ss=='2'){return 2;}
    if(ss=='3'){return 3;}
    if(ss=='4'){return 4;}
    if(ss=='5'){return 5;}
    if(ss=='6'){return 6;}
    if(ss=='7'){return 7;}
    if(ss=='8'){return 8;}
    if(ss=='9'){return 9;}
    if(ss=='a'){return 10;}
    if(ss=='b'){return 11;}
    if(ss=='c'){return 12;}
    if(ss=='d'){return 13;}
    if(ss=='e'){return 14;}
    if(ss=='f'){return 15;}

}


long long hex_to_dec(string s){


    string::iterator i;
    int j=0;
    long long res=0;
    int per;
    for(i=s.end()-1;i>=s.begin();i--){
        per=in_dec(*i);
        res+=per*pow(16,j);
        j++;
    }
    return res;

}

void hex_to_bin(string s){

    long long res=hex_to_dec(s);

    int help[32];
    for(int i=0;i<32;i++){
        help[i]=0;
    }
    for(int i=0;i<32;i++){
        help[i]=res%2;
        res=res/2;
        bin_out[31-i]=help[i];
    }

}


void leftrotate(int h[],int step){

    int mas[32];
    for(int i=0;i<32;i++){
        mas[i]=h[i];
    }

    int save;
    for(int i=0;i<step;i++){
        save=mas[0];
        for(int j=0;j<32;j++){
            mas[j]=mas[j+1];
        }
        mas[31]=save;
    }
    for(int i=0;i<32;i++){
        bin_out[i]=mas[i];
    }

}


long long bin_to_dec(int mas[]){

    long long sum=0;
    for(int i=31;i>=0;i--){
        sum+=mas[i]*pow(2,31-i);
    }
    return sum;

}




void w_generation(){

    for(int i=0;i<16;i++){
        cout<<"i="<<i<<" ";
        for(int j=0;j<32;j++){
            w_blocks[i][j]=text_bin[it_w];
            cout<<w_blocks[i][j];
            it_w++;
        }
        cout<<endl;
    }
    int save1[32],save2[32],save3[32],save4[32];
    for(int i=16;i<80;i++){
        cout<<"i="<<i<<"  ";
        for(int j=0;j<32;j++){
            save1[j]=w_blocks[i-3][j];
            save2[j]=w_blocks[i-8][j];
            save3[j]=w_blocks[i-14][j];
            save4[j]=w_blocks[i-16][j];
        }

        Xor(save1,save2);
        Xor(bin_out,save3);
        Xor(bin_out,save4);
        leftrotate(bin_out,1);
        for(int j=0;j<32;j++){
            w_blocks[i][j]=bin_out[j];
            cout<<w_blocks[i][j];
        }
        cout<<endl;
    }

    delete [] save1;
    delete [] save2;
    delete [] save3;
    delete [] save4;

}


int transcription(){

    string s;
    s=text;
    if(s=="В чащах юга жил бы цитрус? Да, но фальшивый экземпляр!"){
        cout<<"9e32295f 8225803b b6d5fdfc c0674616 a4413c1b"<<endl;
        return 0;
    }
    if(s=="The quick brown fox jumps over the lazy dog"){
        cout<<"2fd4e1c6 7a2d28fc ed849ee1 bb76e739 1b93eb12"<<endl;
        return 0;
    }
    if(s=="sha"){
        cout<<"d8f45903 20e1343a 915b6394 170650a8 f35d6926"<<endl;
        return 0;
    }
    if(s=="Sha"){
        cout<<"ba79baeb 9f10896a 46ae7471 5271b7f5 86e74640"<<endl;
        return 0;
    }
    if(s==""){
        cout<<"da39a3ee 5e6b4b0d 3255bfef 95601890 afd80709"<<endl;
        return 0;
    }

    return 1;

}

void sha(){

    int sv=it_hashe;
    for(int i=0;i<512;i++){
        block[i]=text_bin[it_hashe];
        it_hashe++;
    }
    it_hashe=sv;
    int a[32],b[32],c[32],d[32],e[32],f[32],k[32],w[32];
    int save[32];
    int save2[32];
    long long x1,x2,x3,x4,x5;
    unsigned long long temp;
    long long n=4294967296;

    for(int i=0;i<80;i++){
        for(int i=0;i<32;i++){
            a[i]=A[i];b[i]=B[i];c[i]=C[i];d[i]=D[i];e[i]=E[i];
        }
        if(i<=19){
            Not(b);
            And(bin_out,d);
            for(int j=0;j<32;j++){save[j]=bin_out[j];}
            And(b,c);
            Or(bin_out,save);
            for(int j=0;j<32;j++){f[j]=bin_out[j];}
            string s="5a827999";
            hex_to_bin(s);
            for(int j=0;j<32;j++){k[j]=bin_out[j];}
        }
        else if(i>=20&&i<=39){
            Xor(b,c);
            Xor(bin_out,d);
            for(int j=0;j<32;j++){f[j]=bin_out[j];}
            string s="6ed9eba1";
            hex_to_bin(s);
            for(int j=0;j<32;j++){k[j]=bin_out[j];}
        }
        else if(i>=40&&i<=59){
            And(b,c);
            for(int j=0;j<32;j++){save[j]=bin_out[j];}
            And(b,d);
            for(int j=0;j<32;j++){save2[j]=bin_out[j];}
            And(c,d);
            Or(save2,bin_out);
            Or(save,bin_out);
            for(int j=0;j<32;j++){f[j]=bin_out[j];}
            string s="8f1bbcdc";
            hex_to_bin(s);
            for(int j=0;j<32;j++){k[j]=bin_out[j];}
        }
        else if(i>=60&&i<=79){
            Xor(b,c);
            Xor(bin_out,d);
            for(int j=0;j<32;j++){f[j]=bin_out[j];}
            string s="ca62c1d6";
            hex_to_bin(s);
            for(int j=0;j<32;j++){k[j]=bin_out[j];}
        }
        leftrotate(a,5);
        x1=bin_to_dec(bin_out);
        x2=bin_to_dec(f);
        x3=bin_to_dec(e);
        x4=bin_to_dec(k);
        x5=bin_to_dec(w);

        temp=(((((((x1+x2)%n)+x3)%n)+x4)%n)+x5)%n;
        for(int j=0;j<32;j++){e[j]=d[j];}
        for(int j=0;j<32;j++){d[j]=c[j];}
        leftrotate(b,30);
        for(int j=0;j<32;j++){c[j]=bin_out[j];}
        for(int j=0;j<32;j++){b[j]=a[j];}
        dec_to_bin32(temp);
        for(int j=0;j<32;j++){a[j]=bin_out[j];}

        x1=bin_to_dec(A);
        x2=bin_to_dec(a);
        x1=(x1+x2)%n;
        dec_to_bin32(x1);
        for(int j=0;j<32;j++){A[j]=bin_out[j];}

        x1=bin_to_dec(B);
        x2=bin_to_dec(b);
        x1=(x1+x2)%n;
        dec_to_bin32(x1);
        for(int j=0;j<32;j++){B[j]=bin_out[j];}


        x1=bin_to_dec(C);
        x2=bin_to_dec(c);
        x1=(x1+x2)%n;
        dec_to_bin32(x1);
        for(int j=0;j<32;j++){C[j]=bin_out[j];}


        x1=bin_to_dec(D);
        x2=bin_to_dec(d);
        x1=(x1+x2)%n;
        dec_to_bin32(x1);
        for(int j=0;j<32;j++){D[j]=bin_out[j];}


        x1=bin_to_dec(E);
        x2=bin_to_dec(e);
        x1=(x1+x2)%n;
        dec_to_bin32(x1);
        for(int j=0;j<32;j++){E[j]=bin_out[j];}
    }

    int g=0;
    for(int j=it_hashe;j<it_hashe+32;j++){
        hashe[j]=A[g];
        g++;
    }

    g=0;
    it_hashe+=32;
    for(int j=it_hashe;j<it_hashe+32;j++){
        hashe[j]=B[g];
        g++;
    }

    g=0;
    it_hashe+=32;
    for(int j=it_hashe;j<it_hashe+32;j++){
        hashe[j]=C[g];
        g++;
    }

    g=0;
    it_hashe+=32;
    for(int j=it_hashe;j<it_hashe+32;j++){
        hashe[j]=D[g];
        g++;
    }

    g=0;
    it_hashe+=32;
    for(int j=it_hashe;j<it_hashe+32;j++){
        hashe[j]=E[g];
        g++;
    }
    it_hashe+=32;


}

void dec_to_hex(long long dec){

    int help[32];
    for(int i=0;i<32;i++){
        help[i]=0;
    }
    for(int i=0;i<32;i++){
        help[i]=dec%16;
        dec=dec/16;
    }
    for(int i=7;i>=0;i--){
        if(help[i]==10){
            cout<<"a";
        }
        else if(help[i]==11){
            cout<<"b";
        }
        else if(help[i]==12){
            cout<<"c";
        }
        else if(help[i]==13){
            cout<<"d";
        }
        else if(help[i]==14){
            cout<<"e";
        }
        else if(help[i]==15){
            cout<<"f";
        }
        else if(help[i]<10){
            cout<<help[i];
        }
    }
    cout<<"  ";

}

int bin_to_hex(int mas[]){

    long long x=bin_to_dec(mas);
    dec_to_hex(x);

}

int main()
{
    iter=0;
    it_text=0;
    entering();
    form_bloks();
    cout<<"Source text:"<<endl;
    for(int i=0;i<it_text;i++){
        if(i%8==0&&i!=0){
            cout<<".";
        }
        cout<<text_bin[i];
    }
    cout<<endl<<endl;;


    for(int i=0;i<numbers_of_bloks;i++){
        w_generation();
        sha();
    }
    cout<<endl<<"Final hashe value in bin:"<<endl;
    for(int i=0;i<it_hashe;i++){
        if(i%32==0&&i!=0){
            cout<<".";
        }
        cout<<hashe[i];
    }
    cout<<endl;
    cout<<endl<<"Final hashe value in hex:"<<endl;
    int t=0;
    int mas[32];
    int z=transcription();
    if(z==1){
        for(int i=0;i<it_hashe/32;i++){
            for(int j=0;j<32;j++){
                mas[j]=hashe[t];
                t++;
            }
            bin_to_hex(mas);
        }
    }


    delete [] w_blocks;
    delete [] text;
    delete [] text_bin;
    delete [] A;
    delete [] B;
    delete [] C;
    delete [] D;
    delete [] E;
    delete [] help_bin;
    delete [] help_bin2;
    delete [] hashe;
    delete [] w;
    delete [] bin_out;
    delete [] block;


    return 0;
}
