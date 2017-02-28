#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "math.h"
using namespace std;

struct Model1 {
       string brand;
       string type;
       int periodicity;
       int volumeofmemory;
       int volumeofdick;
       int volumeofgraphicscard;
       int count;
       int sum;
};
typedef list<Model1> Model;
class Pricelist {
      private:
              string date;
              int otnoshenie;
			  Model spis;
			  Model1 obraz;
			  int addsum;
      public:
        Pricelist(string a,string b,int c,int d,int e,int f,int g,int h);
        void AddNote();
        void ChangeNote();
        void DelNote();
        void SearchBrand();
        void SearchMemory();
        void SearchDisk();
        void SearchVideoCard();
        void Sumadd();
		void Vibor();
		void Output();
};
Pricelist::Pricelist(string a,string b,int c,int d,int e,int f,int g,int h)
{
    obraz.brand=a;
	obraz.type=b;
	obraz.periodicity=c;
	obraz.volumeofmemory=d;
	obraz.volumeofdick=e;
	obraz.volumeofgraphicscard=f;
	obraz.count=g;
	obraz.sum=h;
	spis.push_back(obraz);
	addsum=0;
	Output();
}
void Pricelist::Output()
{
	cout<<"Модель Тип проц. Память HDD Video card Кол-во стоимость\n";
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
	{
		cout<<it->brand<<" "<<it->type<<" "<<it->periodicity<<" "<<it->volumeofmemory<<" "<<it->volumeofdick<<" "<<it->volumeofgraphicscard<<" "<<it->count<<" "<<it->sum<<"\n";

	}
}
void Pricelist::Vibor()
{
	int j;//переменная для свича
	do{
	cout<<"\n1. Добавить элемент \n2. Изменить элемент\n3. Удалить элемент\n4. Поиск по марке\n5. Поиск по памяти\n6. Поиск по HDD\n7. Поиск по видеокарте\n8. Выход\nВыберите операцию: ";
	cin>>j;
	switch (j)
	{
		case 1:{
				AddNote();
				Output();
				Sumadd();
				break;
			   }
		case 2:{
				ChangeNote();
				Output();
				Sumadd();
				break;
			   }
		case 3:{
				DelNote();
				Output();
				Sumadd();
				break;
			   }
		case 4:{
				SearchBrand();
				break;
			   }
		case 5:{
				SearchMemory();
				break;
			   }
		case 6:{
                SearchDisk();
                break;
                }
		case 7:{
                SearchVideoCard();
                break;
                }
        case 8:{
                exit (0);
                }
	}
	}while (true);
}
void Pricelist::AddNote()/*добавить*/
{
     cout << "Добавление нового объекта в прайс лист" << endl;/*добавить цепочку cout */
	 cout << "Брэнд:";
	 cin>>obraz.brand;
	 cout << "Тип процессора:";
	 cin>>obraz.type;
	 cout << "Частота процессора:";
	 cin>>obraz.periodicity;
	 cout << "Память:";
	 cin>>obraz.volumeofmemory;
	 cout << "Память HDD:";
	 cin>>obraz.volumeofdick;
	 cout << "Память видеокарты:";
	 cin>>obraz.volumeofgraphicscard;
	 cout << "Количество:";
	 cin>>obraz.count;
	 cout << "Цена:";
	 cin>>obraz.sum;
	 spis.push_back(obraz);
}
void Pricelist:: ChangeNote()
{
	cout<<"\nВведите марку продукта для изменения параметров: ";
	cin>>obraz.brand;
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
	{
		if(it->brand==obraz.brand)
		{
			cout<<"введите тип ";
			cin>>it->type;
			cout<<"введите частоту ";
			cin>>it->periodicity;
			cout<<"Введите память ";
			cin>>it->volumeofmemory;
			cout<<"введи HDD ";
			cin>>it->volumeofdick;
			cout<<"введите видео память ";
			cin>>it->volumeofgraphicscard;
			cout<<"введите кол-во ";
			cin>>it->count;
			cout<<"введите сумму ";
			cin>>it->sum;
			break;
		}
	}
}
void Pricelist::DelNote()
{
	cout<<"\nВыбирите марку элемента прайслиста который хотите удалить ";
	cin>>obraz.brand;
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
	{
		if(it->brand==obraz.brand)
		{
			spis.erase(it);
			break;
		}
	}
}
void Pricelist::SearchBrand()
{
	bool b=0;

	cout<<"введите марку для поиска ";
	cin>>obraz.brand;
	cout<<"\nМодель Тип проц. Память HDD Video card Кол-во стоимость\n";
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
		{
			if(it->brand==obraz.brand)
			{
				cout<<it->brand<<" "<<it->type<<" "<<it->periodicity<<" "<<it->volumeofmemory<<" "<<it->volumeofdick<<" "<<it->volumeofgraphicscard<<" "<<it->count<<" "<<it->sum<<"\n";
				b=1;
			}

		}
	if(!b)
	{
		cout<<"Элементов не найдено \n";
	}
}
 void Pricelist::SearchMemory()
 {
		bool b=0;
		cout<<"введите объем памяти  для поиска ";
		cin>>obraz.volumeofmemory;
		cout<<"\nМодель Тип проц. Память HDD Video card Кол-во стоимость\n";
		for (Model::iterator it=spis.begin();it!=spis.end();it++)
			{
				if(it->volumeofmemory>=obraz.volumeofmemory)
				{
					cout<<it->brand<<" "<<it->type<<" "<<it->periodicity<<" "<<it->volumeofmemory<<" "<<it->volumeofdick<<" "<<it->volumeofgraphicscard<<" "<<it->count<<" "<<it->sum<<"\n";
					b=1;
				}

			}
		if(!b)
		{
			cout<<"Элементов не найдено \n";
		}
 }
void Pricelist::SearchDisk()
 {
		bool b=0;
		cout<<"введите объем HDD  для поиска ";
		cin>>obraz.volumeofdick;
		cout<<"\nМодель Тип проц. Память HDD Video card Кол-во стоимость\n";
		for (Model::iterator it=spis.begin();it!=spis.end();it++)
			{
				if(it->volumeofdick>=obraz.volumeofdick)
				{
					cout<<it->brand<<" "<<it->type<<" "<<it->periodicity<<" "<<it->volumeofmemory<<" "<<it->volumeofdick<<" "<<it->volumeofgraphicscard<<" "<<it->count<<" "<<it->sum<<"\n";
					b=1;
				}

			}
		if(!b)
		{
			cout<<"Элементов не найдено \n";
		}
 }

 void Pricelist::SearchVideoCard()
 {
		bool b=0;
		cout<<"введите объем памяти видеокарты для поиска ";
		cin>>obraz.volumeofgraphicscard;
		cout<<"\nМодель Тип проц. Память HDD Video card Кол-во стоимость\n";
		for (Model::iterator it=spis.begin();it!=spis.end();it++)
			{
				if(it->volumeofgraphicscard>=obraz.volumeofgraphicscard)
				{
					cout<<it->brand<<" "<<it->type<<" "<<it->periodicity<<" "<<it->volumeofmemory<<" "<<it->volumeofdick<<" "<<it->volumeofgraphicscard<<" "<<it->count<<" "<<it->sum<<"\n";
					b=1;
				}

			}
		if(!b)
		{
			cout<<"Элементов не найдено \n";
		}
 }

 void Pricelist::Sumadd()
 {
	 for (Model::iterator it=spis.begin();it!=spis.end();it++)
	 {
		 addsum+=(it->count)*(it->sum);
	 }
	 cout<<"Стоимость всех компов = "<<addsum<<endl;
 }
int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"Russian");
    Pricelist P("Irbis","Amd",3,4096,750,1024,77,16789);
    P.Vibor();
    system("PAUSE");
    return EXIT_SUCCESS;
}
