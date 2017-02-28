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
	cout<<"������ ��� ����. ������ HDD Video card ���-�� ���������\n";
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
	{
		cout<<it->brand<<" "<<it->type<<" "<<it->periodicity<<" "<<it->volumeofmemory<<" "<<it->volumeofdick<<" "<<it->volumeofgraphicscard<<" "<<it->count<<" "<<it->sum<<"\n";

	}
}
void Pricelist::Vibor()
{
	int j;//���������� ��� �����
	do{
	cout<<"\n1. �������� ������� \n2. �������� �������\n3. ������� �������\n4. ����� �� �����\n5. ����� �� ������\n6. ����� �� HDD\n7. ����� �� ����������\n8. �����\n�������� ��������: ";
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
void Pricelist::AddNote()/*��������*/
{
     cout << "���������� ������ ������� � ����� ����" << endl;/*�������� ������� cout */
	 cout << "�����:";
	 cin>>obraz.brand;
	 cout << "��� ����������:";
	 cin>>obraz.type;
	 cout << "������� ����������:";
	 cin>>obraz.periodicity;
	 cout << "������:";
	 cin>>obraz.volumeofmemory;
	 cout << "������ HDD:";
	 cin>>obraz.volumeofdick;
	 cout << "������ ����������:";
	 cin>>obraz.volumeofgraphicscard;
	 cout << "����������:";
	 cin>>obraz.count;
	 cout << "����:";
	 cin>>obraz.sum;
	 spis.push_back(obraz);
}
void Pricelist:: ChangeNote()
{
	cout<<"\n������� ����� �������� ��� ��������� ����������: ";
	cin>>obraz.brand;
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
	{
		if(it->brand==obraz.brand)
		{
			cout<<"������� ��� ";
			cin>>it->type;
			cout<<"������� ������� ";
			cin>>it->periodicity;
			cout<<"������� ������ ";
			cin>>it->volumeofmemory;
			cout<<"����� HDD ";
			cin>>it->volumeofdick;
			cout<<"������� ����� ������ ";
			cin>>it->volumeofgraphicscard;
			cout<<"������� ���-�� ";
			cin>>it->count;
			cout<<"������� ����� ";
			cin>>it->sum;
			break;
		}
	}
}
void Pricelist::DelNote()
{
	cout<<"\n�������� ����� �������� ���������� ������� ������ ������� ";
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

	cout<<"������� ����� ��� ������ ";
	cin>>obraz.brand;
	cout<<"\n������ ��� ����. ������ HDD Video card ���-�� ���������\n";
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
		cout<<"��������� �� ������� \n";
	}
}
 void Pricelist::SearchMemory()
 {
		bool b=0;
		cout<<"������� ����� ������  ��� ������ ";
		cin>>obraz.volumeofmemory;
		cout<<"\n������ ��� ����. ������ HDD Video card ���-�� ���������\n";
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
			cout<<"��������� �� ������� \n";
		}
 }
void Pricelist::SearchDisk()
 {
		bool b=0;
		cout<<"������� ����� HDD  ��� ������ ";
		cin>>obraz.volumeofdick;
		cout<<"\n������ ��� ����. ������ HDD Video card ���-�� ���������\n";
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
			cout<<"��������� �� ������� \n";
		}
 }

 void Pricelist::SearchVideoCard()
 {
		bool b=0;
		cout<<"������� ����� ������ ���������� ��� ������ ";
		cin>>obraz.volumeofgraphicscard;
		cout<<"\n������ ��� ����. ������ HDD Video card ���-�� ���������\n";
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
			cout<<"��������� �� ������� \n";
		}
 }

 void Pricelist::Sumadd()
 {
	 for (Model::iterator it=spis.begin();it!=spis.end();it++)
	 {
		 addsum+=(it->count)*(it->sum);
	 }
	 cout<<"��������� ���� ������ = "<<addsum<<endl;
 }
int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"Russian");
    Pricelist P("Irbis","Amd",3,4096,750,1024,77,16789);
    P.Vibor();
    system("PAUSE");
    return EXIT_SUCCESS;
}
