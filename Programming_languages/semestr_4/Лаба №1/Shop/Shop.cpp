#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Shop.h"
#include <string>

using namespace std;



//����� GOODS

void Goods::GoodsRead(){
    ifstream gdsout("Goods.txt");
    cout<<"\n������ �� ������:(������������ - ������� ���� - ��������� ���� - �������� - ������� ������� ����)"<<endl;
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
    cout<<"\n���������� ������:"<<endl;

    cout<<"������������: ";
    cin>>name;
    gdsin<<name<<" ";

    cout<<"������� ����: ";
    cin>>tradeprice;
    gdsin<<tradeprice<<" ";

    cout<<"��������� ����: ";
    cin>>retailprice;
    gdsin<<retailprice<<" ";

    cout<<"��������(��� ��������): ";
    cin>>specification;
    gdsin<<specification<<" ";

    cout<<"���������� ������ ��� ��������� ������� ����: ";
    cin>>forwholesale;
    gdsin<<forwholesale<<"\n";
    gdsin.close();
}


bool Goods::GoodsSearch(){
    string Gforsearch;//��������� ���������� ��� ������
    ifstream gdsout("Goods.txt");
    cout<<"\n������� ������������ ������(�� ����������): ";
    cin>>Gforsearch;
    while(gdsout!=NULL){
        gdsout>>name;
        gdsout>>tradeprice;
        gdsout>>retailprice;
        gdsout>>specification;
        gdsout>>forwholesale;
        if(name==Gforsearch){
            cout<<"\n������������ �����: "<<name<<" - "<<tradeprice<<" - "<<retailprice<<" - "<<specification<<" - "<<forwholesale<<endl;
            gdsout.close();
            return true;
        }
    }
    cout<<"\n������� ������ ��� � �������!"<<endl;
    gdsout.close();
    return false;
}





//����� Customs



void Customs::CustomsRead(){
    ifstream ctsout("Customs.txt");
    cout<<"\n����������:(������� - ���������� ���� - �����)"<<endl;
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
    cout<<"\n���������� ����������:"<<endl;

    cout<<"�������(10 ����: 8����������): ";
    cin>>phone;
    ctsin<<phone<<" ";

    cout<<"���������� ����(�������): ";
    cin>>contactname;
    ctsin<<contactname<<" ";

    cout<<"�����(������: �����,�����-���/��������(��� ��������)): ";
    cin>>address;
    ctsin<<address<<"\n";
    ctsin.close();
}


bool Customs::CustomsSearch(){
    string Cforsearch;//��������� ���������� ��� ������
    ifstream ctsout("Customs.txt");
    cout<<"\n������� ���������� ����: ";
    cin>>Cforsearch;
    while(ctsout!=NULL){
        ctsout>>phone;
        ctsout>>contactname;
        ctsout>>address;
        if(contactname==Cforsearch){
            cout<<"\n������������ ����������: "<<contactname<<" - "<<phone<<" - "<<address<<endl;
            ctsout.close();
            return true;
        }
    }
    cout<<"\n������� ������� ��� � ���� ������!"<<endl;
    ctsout.close();
    return false;
}




//����� Dealings

int dealingscount=0;//���������� ��� ���������� �����������


void Dealings::DealingsRead(){
    ifstream dlsout("Dealings.txt");
    cout<<"\n������:(���� ������ - ����� - ���������� - ���������� - ����� �����)"<<endl;
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
    cout<<"\n���������� ������:"<<endl;
    cout<<"����(dd.mm.yy): ";
    cin>>date;
    dlsin<<date<<" ";

    supply=name;
    dlsin<<supply<<" ";

    cout<<"����������: ";
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
    int i;//���������� ��� �����
	do{
        cout<<"\n���� ����������\n1. ����������� ������� �������\n2. ����� �����\n3. �������� ����������\n4. ������� �������\n5. ����� ��� �������������\n6. �����\n�������� ��������: ";
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
                cout<<"������� ������: ";
                cin>>password;
                if(password==12345){
                    MenuForAdmin();
                }
                else{
                    cout<<"\n������ �� �����!"<<endl;
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
    int j;//���������� ��� �����
	do{
        cout<<"\n���� ��������������\n1. ����������� ������� �������\n2. �������� �����\n3. ����� �����\n4. ����������� ���� �����������\n5. ����� ����������\n6. ����������� ��� ������\n7. ����� ������\n8. ������� � ���� ����������\n9. �����\n�������� ��������: ";
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
    string D1forsearch, D2forsearch;//��������� ���������� ��� ������
    ifstream dlsout("Dealings.txt");
    cout<<"\n������� ���������� ����: ";
    cin>>D1forsearch;
    cout<<"\n������� �����: ";
    cin>>D2forsearch;
    while(dlsout!=NULL){
        dlsout>>date;
        dlsout>>supply;
        dlsout>>number;
        dlsout>>customer;
        dlsout>>value;
        if((customer==D1forsearch)&&(supply==D2forsearch)){
            cout<<"\n������������ ������: "<<date<<" - "<<supply<<" - "<<number<<" - "<<customer<<" - "<<value<<endl;
            dlsout.close();
            return true;
        }
    }
    cout<<"\n������ ������ �� ����������!"<<endl;
    dlsout.close();
    return true;
}
