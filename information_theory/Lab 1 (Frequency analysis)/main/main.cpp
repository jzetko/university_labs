#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct freq{
    char letter;//исходная буква
    int frequency;//частота
    char newletter;//буква по статистике(не нужна в 1ом векторе)
};

class cmp{//для сортировки
public:
    bool operator() (const freq &a, const freq &b) {
        return a.frequency>b.frequency;
    }
} compare;

freq model;//создаем объект структуры
vector <freq> vect;//создаем вектор структуры(надо 2)

void show_encryption_key(){//фича

    cout<<"\n\noriginal letter - letter for encoding\n";
    cout<<"a - p\nb - q\nc -d\nd - w\ne - z\nf - h\ng - m\nh - k\ni - a\nj - o\nk - t\nl - y\nm - c\nn - v\no - e\np - x\nq - u\nr - l\ns - j\nt - i\nu - f\nv - g\nw - b\nx - n\ny - s\nz - r\n";

}

void show_decryption_key(){//фича

    cout<<"\n\nletter from encryption text - letter for change\n";
    vector <freq>::iterator it;
    for(it=vect.begin();it!=vect.end();it++){
        cout<<it->letter<<" - "<<it->newletter<<endl;
    }

}

void sum_difference(){//фича
    ifstream encryption_text("encrypt_text.txt");
    ifstream decryption_text("decrypt_text.txt");
    char mas1[5839];
    char mas2[5839];
    encryption_text.getline(mas1, 5839);
    decryption_text.getline(mas2, 5839);
    encryption_text.close();
    decryption_text.close();

    int count=0;
    for(int i=0;i<5839;i++){
        if(mas1[i]!=mas2[i])
            count++;
    }

    cout<<"The number of different letters: "<<count<<" from 5839 letters"<<endl;

}

void forming_alphabet(){//создание вектора с алфавитом(надо 2 одинаковых)

    model.letter='a';
    model.frequency=0;
    vect.push_back(model);

    model.letter='b';
    model.frequency=0;
    vect.push_back(model);

    model.letter='c';
    model.frequency=0;
    vect.push_back(model);

    model.letter='d';
    model.frequency=0;
    vect.push_back(model);

    model.letter='e';
    model.frequency=0;
    vect.push_back(model);

    model.letter='f';
    model.frequency=0;
    vect.push_back(model);

    model.letter='g';
    model.frequency=0;
    vect.push_back(model);

    model.letter='h';
    model.frequency=0;
    vect.push_back(model);

    model.letter='i';
    model.frequency=0;
    vect.push_back(model);

    model.letter='j';
    model.frequency=0;
    vect.push_back(model);

    model.letter='k';
    model.frequency=0;
    vect.push_back(model);

    model.letter='l';
    model.frequency=0;
    vect.push_back(model);

    model.letter='m';
    model.frequency=0;
    vect.push_back(model);

    model.letter='n';
    model.frequency=0;
    vect.push_back(model);

    model.letter='o';
    model.frequency=0;
    vect.push_back(model);

    model.letter='p';
    model.frequency=0;
    vect.push_back(model);

    model.letter='q';
    model.frequency=0;
    vect.push_back(model);

    model.letter='r';
    model.frequency=0;
    vect.push_back(model);

    model.letter='s';
    model.frequency=0;
    vect.push_back(model);

    model.letter='t';
    model.frequency=0;
    vect.push_back(model);

    model.letter='u';
    model.frequency=0;
    vect.push_back(model);

    model.letter='v';
    model.frequency=0;
    vect.push_back(model);

    model.letter='w';
    model.frequency=0;
    vect.push_back(model);

    model.letter='x';
    model.frequency=0;
    vect.push_back(model);

    model.letter='y';
    model.frequency=0;
    vect.push_back(model);

    model.letter='z';
    model.frequency=0;
    vect.push_back(model);

}

void frequency_count(){//подсчет частоты букв в тексте

    forming_alphabet();
    ifstream text("encrypt_text.txt");
    char mas[5839];
    text.getline(mas, 5839);
    text.close();

    for(int i=0;i<5839;i++){
        vector <freq>::iterator it;
        for(it=vect.begin();it!=vect.end();it++){
            if(it->letter==mas[i]){
                it->frequency++;
            }
        }

    }

}

void sorting_by_frequency(){

    sort(vect.begin(), vect.end(), compare);

}

void adding_letters_from_statistics(){//нахуй не надо

    sorting_by_frequency();

    vect[0].newletter='e';
    vect[1].newletter='t';
    vect[2].newletter='a';
    vect[3].newletter='o';
    vect[4].newletter='i';
    vect[5].newletter='n';
    vect[6].newletter='s';
    vect[7].newletter='h';
    vect[8].newletter='r';
    vect[9].newletter='d';
    vect[10].newletter='l';
    vect[11].newletter='c';
    vect[12].newletter='u';
    vect[13].newletter='m';
    vect[14].newletter='w';
    vect[15].newletter='f';
    vect[16].newletter='g';
    vect[17].newletter='y';
    vect[18].newletter='p';
    vect[19].newletter='b';
    vect[20].newletter='v';
    vect[21].newletter='k';
    vect[22].newletter='j';
    vect[23].newletter='x';
    vect[24].newletter='q';
    vect[25].newletter='z';

}

void decryption(){

    frequency_count();
    adding_letters_from_statistics();

    ifstream encryption_text("encrypt_text.txt");
    char mas[5839];
    encryption_text.getline(mas, 5839);
    encryption_text.close();

    ofstream decryption_text;
    decryption_text.open("decrypt_text.txt");
    for(int i=0;i<5839;i++){
        vector <freq>::iterator it;
        for(it=vect.begin();it!=vect.end();it++){
            if(it->letter==mas[i]){
                decryption_text<<it->newletter;
            }
        }
        if(mas[i]==' ')
            decryption_text<<' ';
    }
    decryption_text.close();

}



void encryption(){
    ifstream text("text.txt");
    char mas[5839];
    text.getline(mas, 5839);
    text.close();
    ofstream encryption_text;
    encryption_text.open("encrypt_text.txt");
    for(int i=0;i<5839;i++){
        if(mas[i]=='a'){encryption_text<<'p';}
        if(mas[i]=='b'){encryption_text<<'q';}
        if(mas[i]=='c'){encryption_text<<'d';}
        if(mas[i]=='d'){encryption_text<<'w';}
        if(mas[i]=='e'){encryption_text<<'z';}
        if(mas[i]=='f'){encryption_text<<'h';}
        if(mas[i]=='g'){encryption_text<<'m';}
        if(mas[i]=='h'){encryption_text<<'k';}
        if(mas[i]=='i'){encryption_text<<'a';}
        if(mas[i]=='j'){encryption_text<<'o';}
        if(mas[i]=='k'){encryption_text<<'t';}
        if(mas[i]=='l'){encryption_text<<'y';}
        if(mas[i]=='m'){encryption_text<<'c';}
        if(mas[i]=='n'){encryption_text<<'v';}
        if(mas[i]=='o'){encryption_text<<'e';}
        if(mas[i]=='p'){encryption_text<<'x';}
        if(mas[i]=='q'){encryption_text<<'u';}
        if(mas[i]=='r'){encryption_text<<'l';}
        if(mas[i]=='s'){encryption_text<<'j';}
        if(mas[i]=='t'){encryption_text<<'i';}
        if(mas[i]=='u'){encryption_text<<'f';}
        if(mas[i]=='v'){encryption_text<<'g';}
        if(mas[i]=='w'){encryption_text<<'b';}
        if(mas[i]=='x'){encryption_text<<'n';}
        if(mas[i]=='y'){encryption_text<<'s';}
        if(mas[i]=='z'){encryption_text<<'r';}
        if(mas[i]==' '){encryption_text<<' ';}
    }
    encryption_text.close();
}

void Menu(){
    cout<<"Welcome to encryption/decryption program!!!\n\n";

    encryption();
    cout<<"Encryption is complete!\n\n";

    decryption();
    cout<<"Decryption is complete!\n\nOpen files with matching names to view the result!\n\nAdvanced functions:\n";

    int j;
	do{
        cout<<"1. Show encryption key\n2. Show decryption key\n3. The number of different letters in encryption and decryption files\n4. Exit\nChoose the operation: ";
        cin>>j;
        switch (j){
            case 1:{
				show_encryption_key();
				break;
            }
            case 2:{
				show_decryption_key();
				break;
            }
            case 3:{
				sum_difference();
				break;
            }
            case 4:{
                exit (0);
            }
        }
	}while (true);

}





int main()
{
    Menu();
    vect.clear();
    system("Pause");
    return 0;
}
