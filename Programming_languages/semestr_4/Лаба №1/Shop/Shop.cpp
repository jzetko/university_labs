#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Shop.h"
#include <string>

using namespace std;



//КЛАСС GOODS

void Goods::GoodsRead(){
    ifstream gdsout("Goods.txt");
    cout<<"\nТовары на складе:(Наименование - Оптовая цена - Розничная цена - Описание - Признак потовой цены)"<<endl;
    while(gdsout!=NULL){
        gdsout>>name;
        gdsout>>tradeprice;
        gdsout>>retailprice;
        gdsout>>specification;
        gdsout>>forwholesale;
        if(gdsout==NULL){
            break;
        }
        cout<<name<<" - "<<tradeprice<<" - "<<retailprice<<" - "<<specification<<" - "<<forwholesale<<endl;
    }
    gdsout.close();
}


void Goods::GoodsAdd(){
    ofstream gdsin;
    gdsin.open("Goods.txt",ios::app);
    cout<<"\nДобавление товара:"<<endl;

    cout<<"Наименование: ";
    cin>>name;
    gdsin<<name<<" ";

    cout<<"Оптовая цена: ";
    cin>>tradeprice;
    gdsin<<tradeprice<<" ";

    cout<<"Розничная цена: ";
    cin>>retailprice;
    gdsin<<retailprice<<" ";

    cout<<"Описание(Без пробелов): ";
    cin>>specification;
    gdsin<<specification<<" ";

    cout<<"Количество товара для получения оптовой цены: ";
    cin>>forwholesale;
    gdsin<<forwholesale<<"\n";
    gdsin.close();
}


bool Goods::GoodsSearch(){
    string Gforsearch;//временная переменная для поиска
    ifstream gdsout("Goods.txt");
    cout<<"\nВведите наименование товара(На английском): ";
    cin>>Gforsearch;
    while(gdsout!=NULL){
        gdsout>>name;
        gdsout>>tradeprice;
        gdsout>>retailprice;
        gdsout>>specification;
        gdsout>>forwholesale;
        if(name==Gforsearch){
            cout<<"\nИнтересующий товар: "<<name<<" - "<<tradeprice<<" - "<<retailprice<<" - "<<specification<<" - "<<forwholesale<<endl;
            gdsout.close();
            return true;
        }
    }
    cout<<"\nДанного товара нет в наличии!"<<endl;
    gdsout.close();
    return false;
}





//КЛАСС Customs



void Customs::CustomsRead(){
    ifstream ctsout("Customs.txt");
    cout<<"\nПокупатели:(Телефон - Контактное лицо - Адрес)"<<endl;
    while(ctsout!=NULL){
        ctsout>>phone;
        ctsout>>contactname;
        ctsout>>address;
        if(ctsout==NULL){
            break;
        }
        cout<<phone<<" - "<<contactname<<" - "<<address<<endl;
    }
    ctsout.close();
}


void Customs::CustomsAdd(){
    ofstream ctsin;
    ctsin.open("Customs.txt",ios::app);
    cout<<"\nДобавление покупателя:"<<endl;

    cout<<"Телефон(10 цифр: 8ХХХХХХХХХХ): ";
    cin>>phone;
    ctsin<<phone<<" ";

    cout<<"Контактное лицо(Фамилия): ";
    cin>>contactname;
    ctsin<<contactname<<" ";

    cout<<"Адрес(Формат: Город,Адрес-дом/квартира(без пробелов)): ";
    cin>>address;
    ctsin<<address<<"\n";
    ctsin.close();
}


bool Customs::CustomsSearch(){
    string Cforsearch;//временная переменная для поиска
    ifstream ctsout("Customs.txt");
    cout<<"\nВведите контактное лицо: ";
    cin>>Cforsearch;
    while(ctsout!=NULL){
        ctsout>>phone;
        ctsout>>contactname;
        ctsout>>address;
        if(contactname==Cforsearch){
            cout<<"\nИнтересующий покупатель: "<<contactname<<" - "<<phone<<" - "<<address<<endl;
            ctsout.close();
            return true;
        }
    }
    cout<<"\nДанного клиента нет в базе данных!"<<endl;
    ctsout.close();
    return false;
}




//КЛАСС Dealings

int dealingscount=0;//переменная для количества покупателей


void Dealings::DealingsRead(){
    ifstream dlsout("Dealings.txt");
    cout<<"\nСделки:(Дата сделки - Товар - Количество - Покупатель - Общая сумма)"<<endl;
    while(dlsout!=NULL){
        dlsout>>date;
        dlsout>>supply;
        dlsout>>number;
        dlsout>>customer;
        dlsout>>value;
        if(dlsout==NULL){
            break;
        }
        cout<<date<<" - "<<supply<<" - "<<number<<" - "<<customer<<" - "<<value<<endl;
    }
    dlsout.close();
}


void Dealings::DealingsAdd(){
if(GoodsSearch()==false){
    MenuForCustomer();
    }
if(CustomsSearch()==false){
    MenuForCustomer();
    }
    ofstream dlsin;
    dlsin.open("Dealings.txt",ios::app);
    cout<<"\nДобавление сделки:"<<endl;
    cout<<"Дата(dd.mm.yy): ";
    cin>>date;
    dlsin<<date<<" ";

    supply=name;
    dlsin<<supply<<" ";

    cout<<"Количество: ";
    cin>>number;
    dlsin<<number<<" ";

    customer=contactname;
    dlsin<<customer<<" ";

    if(number>=forwholesale){
        value=tradeprice*number;
    }
    else{
        value=retailprice*number;
    }
    dlsin<<value<<"\n";
    dlsin.close();
}


void Dealings::MenuForCustomer(){
    int i;//переменная для свича
	do{
        cout<<"\nМеню покупателя\n1. Просмотреть каталог товаров\n2. Найти товар\n3. Добавить покупателя\n4. Сделать покупку\n5. Войти как администратор\n6. Выход\nВыберите операцию: ";
        cin>>i;
        switch (i){
            case 1:{
                GoodsRead();
                break;
            }
            case 2:{
                GoodsSearch();
                break;
            }
            case 3:{
                CustomsAdd();
                break;
            }
            case 4:{
                DealingsAdd();
                break;
            }
            case 5:{
                unsigned password;
                cout<<"Введите пароль: ";
                cin>>password;
                if(password==12345){
                    MenuForAdmin();
                }
                else{
                    cout<<"\nПароль не верен!"<<endl;
                    MenuForCustomer();
                }
                break;
            }
            case 6:{
                exit (0);
            }
        }
	}while (true);
}


void Dealings::MenuForAdmin(){
    int j;//переменная для свича
	do{
        cout<<"\nМеню администратора\n1. Просмотреть каталог товаров\n2. Добавить товар\n3. Найти товар\n4. Просмотреть всех покупателей\n5. Найти покупателя\n6. Просмотреть все сделки\n7. Поиск сделки\n8. Перейти в меню покупателя\n9. Выход\nВыберите операцию: ";
        cin>>j;
        switch (j){
            case 1:{
                GoodsRead();
                break;
            }
            case 2:{
                GoodsAdd();
                break;
            }
            case 3:{
                CustomsSearch();
                break;
            }
            case 4:{
                CustomsRead();
                break;
            }
            case 5:{
                CustomsSearch();
                break;
            }
            case 6:{
                DealingsRead();
                break;
            }
            case 7:{
                DealingsSearch();
                break;
            }
            case 8:{
                MenuForCustomer();
                break;
            }
            case 9:{
                exit (0);
            }
        }
	}while (true);
}

bool Dealings::DealingsSearch(){
    string D1forsearch, D2forsearch;//временные переменная для поиска
    ifstream dlsout("Dealings.txt");
    cout<<"\nВведите контактное лицо: ";
    cin>>D1forsearch;
    cout<<"\nВведите товар: ";
    cin>>D2forsearch;
    while(dlsout!=NULL){
        dlsout>>date;
        dlsout>>supply;
        dlsout>>number;
        dlsout>>customer;
        dlsout>>value;
        if((customer==D1forsearch)&&(supply==D2forsearch)){
            cout<<"\nИнтересующая сделка: "<<date<<" - "<<supply<<" - "<<number<<" - "<<customer<<" - "<<value<<endl;
            dlsout.close();
            return true;
        }
    }
    cout<<"\nДанной сделки не существует!"<<endl;
    dlsout.close();
    return true;
}
