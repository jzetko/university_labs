#ifndef SUMMA_CLASS
#define SUMMA_CLASS

#include <string>

using namespace std;

class summa {
    public:
        summa(int _kop[4], int _rub[9])         {
int t;
for (t=0;t<4;t++){
    kop[t]=_kop[t];}
for (t=0;t<9;t++){
    rub[t]=_rub[t];}
}

        double GiveSumma();
        friend summa Slogenie(const summa &s1,const summa &s2); 
        friend summa GiveNominals(const double &chis); 
        friend bool Sravnenie(summa &s1,summa &s2);
        friend summa Raznost(summa &s1, summa &s2);
        friend double Delenie(summa &s1, summa &s2);
        friend summa Del(summa &s1, double &a);
        friend summa Umn(summa &s1, double &a);
    private:
        int kop[4];
        int rub[9];
};



#endif
