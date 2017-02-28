#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

class Goods{
    protected:
        string name;//������������
        unsigned tradeprice;//�������
        unsigned retailprice;//���������
        string specification;//��������
        unsigned forwholesale;//����������� ���������� ��� ������� ����
    public:
        void GoodsRead();//������ � ����� �� �����
        void GoodsAdd();//���������� � ��
        bool GoodsSearch();//����� ����������� ������

};


class Customs: public Goods{
    protected:
        string phone;//�������
        string contactname;//���������� ����
        string address;//�����
    public:
        void CustomsRead();//������ � ����� �� �����
        void CustomsAdd();//���������� � ��
        bool CustomsSearch();//����� ����������� ����������
};

class Dealings: public Customs{
    private:
        string date;//���� ������
        string supply;//�����
        unsigned number;//����������
        string customer;//����������
        unsigned value;//����� �����
    public:
        void DealingsRead();
        void DealingsAdd();
        void MenuForCustomer();
        void MenuForAdmin();
        bool DealingsSearch();

};


#endif // SHOP_H_INCLUDED
