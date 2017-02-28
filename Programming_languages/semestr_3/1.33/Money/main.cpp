#include <iostream>
#include <cstdlib>
#include <string>
#include "math.h"
using namespace std;

class Money{
    private:
        int kop[4];
        int rub[9];
        double sum;
    public:
        void GetSum();
        friend Money Slogenie(const Money &m1,const Money &m2);//Вот дружественные фнкции которые берут в качестве аргумента объекты класса
        friend Money Raznost(const Money &m1,const Money &m2);//Сами же функции описаны ниже, работаются как Объект.поле ничего сложного, под себя подгонишь и норм
        friend Money Del1(const Money &m1,const Money &m2);
        friend Money Del2(const Money &m2,const Money &m1);
        friend Money Delonnum1(const Money &m1);
        friend Money Delonnum2(const Money &m2);
        friend Money Umn1(const Money &m1);
        friend Money Umn2(const Money &m2);
        friend Money Sravnenie(const Money &m1, const Money &m2);
        friend Money Menu();
};

void Money::GetSum(){
sum=0;
cout<<"Последовательно введите количество купюр достоинставми 1, 2, 5, 10, 50, 100, 500, 1000, 5000 рублей"<<endl;
for (int i=0; i<9;i++){
    cin>>rub[i];
}
cout<<"Последовательно введите количество монет достоинствами 1, 5, 10, 50 копеек"<<endl;
for (int j=0;j<4;j++){
    cin>>kop[j];
}
sum=(rub[0])+(2*rub[1])+(5*rub[2])+(10*rub[3])+(50*rub[4])+(100*rub[5])+(500*rub[6])+(1000*rub[7])+(5000*rub[8])+(0.01*kop[0])+(0.05*kop[1])+(0.1*kop[2])+(0.5*kop[3]);
cout<<"Сумма равна="<<sum<<endl<<endl<<endl;
}

Money Slogenie(const Money &m1,const Money &m2){
double sl=0;
sl=m1.sum+m2.sum;
cout<<"Результат сложения равен="<<sl<<endl<<endl;
}

Money Raznost(const Money &m1,const Money &m2){
double rz=0;
if (m1.sum>=m2.sum){
    rz=m1.sum-m2.sum;
}
else{
     rz=m2.sum-m1.sum;
}
cout<<"Результат вычитания равен="<<rz<<endl<<endl;
}


Money Del1(const Money &m1,const Money &m2){
double dlt1=m1.sum/m2.sum;
cout<<"Результат Деления 1ой суммы на 2ую равен="<<dlt1<<endl<<endl;
}

Money Del2(const Money &m2,const Money &m1){
double dlt2=m2.sum/m1.sum;
cout<<"Результат Деления 2ой суммы на 1ую равен="<<dlt2<<endl<<endl;
}

Money Delonnum1(const Money &m1){
double num1,dt1;
cout<<"Введите на какое число вы хотите разделить 1 сумму:";
cin>>num1;
dt1=m1.sum/num1;
cout<<"Результат деления 1 суммы на "<<num1<<" = "<<dt1<<endl<<endl;
}

Money Delonnum2(const Money &m2){
double num2,dt2;
cout<<"Введите на какое число вы хотите разделить 2 сумму:";
cin>>num2;
dt2=m2.sum/num2;
cout<<"Результат деления 2 суммы на "<<num2<<" = "<<dt2<<endl<<endl;
}

Money Umn1(const Money &m1){
double ch1,umg1;
cout<<"Введите на какое число вы хотите умножить 1 сумму:";
cin>>ch1;
umg1=m1.sum*ch1;
cout<<"Результат умножения 1 суммы на "<<ch1<<" = "<<umg1<<endl<<endl;
}

Money Umn2(const Money &m2){
double ch2,umg2;
cout<<"Введите на какое число вы хотите умножить 2 сумму:";
cin>>ch2;
umg2=m2.sum*ch2;
cout<<"Результат умножения 2 суммы на "<<ch2<<" = "<<umg2<<endl<<endl;
}


Money Sravnenie(const Money &m1, const Money &m2){
if(m1.sum>m2.sum)
    cout<<"1 сумма > 2 суммы";
if(m1.sum<m2.sum)
    cout<<"1 сумма < 2 суммы";
if(m1.sum==m2.sum)
    cout<<"суммы равны";
cout<<endl;
}

Money Menu(const Money &m1, const Money &m2){
int j;
do{
    cout<<"\n1. Сложить \n2. Вычесть\n3. Разделить 1ую на 2ую\n4. Разделить 2ую на 1ую\n5. Разделить 1 сумму на число\n6. Разделить 2 сумму на число\n7. Умножить 1ую сумму на число\n8. Умножить 2ую сумму на число\n9.Сравнить суммы\n10.Выйти из программы\nВыберите операцию: ";
	cin>>j;
	cout<<endl;
	switch (j)
	{
		case 1:{
				Slogenie(m1,m2);
				break;
			   }
		case 2:{
				Raznost(m1,m2);
				break;
			   }
		case 3:{
				Del1(m1,m2);
				break;
			   }
		case 4:{
				Del2(m2,m1);
				break;
			   }
		case 5:{
				Delonnum1(m1);
				break;
			   }
		case 6:{
                Delonnum2(m2);
                break;
                }
		case 7:{
                Umn1(m1);
                break;
                }
        case 8:{
                Umn2(m2);
                break;
                }
        case 9:{
                Sravnenie(m1,m2);
                break;
                }
        case 10:{
                exit (0);
                }
	}
	}while (true);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Russian");
    Money m1,m2;
    m1.GetSum();
    m2.GetSum();
    Menu(m1,m2);
    system ("PAUSE");
    return 0;
}
