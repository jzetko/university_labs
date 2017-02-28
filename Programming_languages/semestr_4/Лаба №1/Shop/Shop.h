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
        string name;//наименование
        unsigned tradeprice;//оптовая
        unsigned retailprice;//розничная
        string specification;//описание
        unsigned forwholesale;//необходимое количество для оптовой цены
    public:
        void GoodsRead();//Чтение и вывод на экран
        void GoodsAdd();//Добавление в БД
        bool GoodsSearch();//Поиск конкретного товара

};


class Customs: public Goods{
    protected:
        string phone;//телефон
        string contactname;//контактное лицо
        string address;//адрес
    public:
        void CustomsRead();//Чтение и вывод на экран
        void CustomsAdd();//Добавление в БД
        bool CustomsSearch();//Поиск конкретного покупателя
};

class Dealings: public Customs{
    private:
        string date;//дата сделки
        string supply;//товар
        unsigned number;//количество
        string customer;//покупатель
        unsigned value;//общая сумма
    public:
        void DealingsRead();
        void DealingsAdd();
        void MenuForCustomer();
        void MenuForAdmin();
        bool DealingsSearch();

};


#endif // SHOP_H_INCLUDED
