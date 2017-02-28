#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <stdexcept>
#include <cmath>
using namespace std;

class empty_argument_th{
    public:
      empty_argument_th(unsigned _i){i=_i;}
      string what(){
          string a;
          if (i==1) a="One or more forms are NULL!\n";
          return a;
         };
      private:
      unsigned i;
};

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
		void Menu();
		void Output();
};
Pricelist::Pricelist(string a,string b,int c,int d,int e,int f,int g,int h)
{
    try{
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
    catch(exception &a){
        std::cout << a.what()<< std::endl;
    }
}
void Pricelist::Output()
{
	cout<<"Model Type Proc Memory HDD Videocard Number Price\n";
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
	{
		cout<<it->brand<<" "<<it->type<<" "<<it->periodicity<<" "<<it->volumeofmemory<<" "<<it->volumeofdick<<" "<<it->volumeofgraphicscard<<" "<<it->count<<" "<<it->sum<<"\n";

	}
}
void Pricelist::Menu()
{
	int j;//переменная для свича
	do{
	cout<<"\n1. Add \n2. Change\n3. Delete\n4. Search on mark\n5. Search on memory of computer\n6. Search on HDD\n7. Search on memory of videocard\n8. Exit\nChoose the operation: ";
	cin>>j;
	switch (j)
	{
		case 1:{
				try{
				    AddNote();
				}
				catch(empty_argument_th &a) {cout<<a.what()<<endl;}
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
     try{
         cout << "Adding new object in Pricelist" << endl;/*добавить цепочку cout */
        cout << "Brand:";
        cin>>obraz.brand;
        cout << "Type of proc:";
        cin>>obraz.type;
        cout << "Frequency:";
        cin>>obraz.periodicity;
        cout << "Memory of computer:";
        cin>>obraz.volumeofmemory;
        cout << "Memory of HDD:";
        cin>>obraz.volumeofdick;
        cout << "Memory of videocard:";
        cin>>obraz.volumeofgraphicscard;
        cout << "Number:";
        cin>>obraz.count;
        cout << "Price:";
        cin>>obraz.sum;
        spis.push_back(obraz);
        cout<<endl<<endl;
        if(obraz.brand==""||obraz.type==""||obraz.periodicity==0||obraz.volumeofmemory==0||obraz.volumeofdick==0||obraz.volumeofgraphicscard==0||obraz.count==0||obraz.sum){
            throw empty_argument_th(1);
        }
}
void Pricelist:: ChangeNote()
{
	cout<<"\nChoose the mark for change parametrs: ";
	cin>>obraz.brand;
	for (Model::iterator it=spis.begin();it!=spis.end();it++)
	{
		if(it->brand==obraz.brand)
		{
			cout<<"Print type of processor ";
			cin>>it->type;
			cout<<"Print frequency ";
			cin>>it->periodicity;
			cout<<"Print memory of computer ";
			cin>>it->volumeofmemory;
			cout<<"Print HDD ";
			cin>>it->volumeofdick;
			cout<<"Print memory of videocard ";
			cin>>it->volumeofgraphicscard;
			cout<<"Print the number ";
			cin>>it->count;
			cout<<"Print price ";
			cin>>it->sum;
			break;
		}
	}
}
void Pricelist::DelNote()
{
	cout<<"\nChoose the mark for delete ";
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

	cout<<"Print the mark for search ";
	cin>>obraz.brand;
	cout<<"\nModel Type Proc Memory HDD Videocard Number Price\n";
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
		cout<<"Computers are not found \n";
	}
}
 void Pricelist::SearchMemory()
 {
		bool b=0;
		cout<<"Print the memory of computer for search ";
		cin>>obraz.volumeofmemory;
		cout<<"\nModel Type Proc Memory HDD Videocard Number Price\n";
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
			cout<<"Computers are not found \n";
		}
 }
void Pricelist::SearchDisk()
 {
		bool b=0;
		cout<<"Print HDD for search ";
		cin>>obraz.volumeofdick;
		cout<<"\nModel Type Proc Memory HDD Videocard Number Price\n";
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
			cout<<"Computers are not found \n";
		}
 }

 void Pricelist::SearchVideoCard()
 {
		bool b=0;
		cout<<"Print the memory of videocard for search ";
		cin>>obraz.volumeofgraphicscard;
		cout<<"\nModel Type Proc Memory HDD Videocard Number Price\n";
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
			cout<<"Computers are not found \n";
		}
 }

 void Pricelist::Sumadd()
 {
	 for (Model::iterator it=spis.begin();it!=spis.end();it++)
	 {
		 addsum+=(it->count)*(it->sum);
	 }
	 cout<<"Summe of price on all computers = "<<addsum<<endl;
 }
int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"Russian");

        Pricelist P("Irbis","Amd",3,4096,750,1024,77,16789);
        P.Menu();



    system("PAUSE");
    return EXIT_SUCCESS;
}
