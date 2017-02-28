#ifndef DECIMAL_H_INCLUDED
#define DECIMAL_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "Decimal.h"

using namespace std;


class Decimal{
    private:
        unsigned sign;//0-положительное 1-отрицательно
        unsigned sz;
        unsigned char dec[100];
    public:
        void Read();
        void Display();
        friend bool operator>(const Decimal &m1, const Decimal &m2);
        friend bool operator<(const Decimal &m1, const Decimal &m2);
        friend bool operator==(const Decimal &m1, const Decimal &m2);
        friend Decimal Compare(const Decimal &m1, const Decimal &m2);
        friend int operator+(const Decimal &m1, const Decimal &m2);
        friend Decimal operator-(const Decimal &m1, const Decimal &m2);
        friend Decimal Summa(const Decimal &m1, const Decimal &m2);
        friend Decimal Subtract(const Decimal &m1, const Decimal &m2);
        friend Decimal Multiplication(const Decimal &m1, const Decimal &m2);
        friend Decimal operator !=(const Decimal &m1, const Decimal &m2);
};



#endif // DECIMAL_H_INCLUDED
