#include "Bankomat.h"
#include <iostream>
#include <string>
#include <math.h>
namespace Bank
{
	Bankomat::Bankomat( int N, const std::string & str, int M)
	{
		Name = str;
		Money = M;
		Number = N;
	}
	Bankomat::Bankomat ()
	{
		Name = "";
		Money = 0;
		Number = 0;
	}
	Bankomat::~Bankomat()
	{
		std::cout << "Destructor\n";
	}

	void Bankomat::add(int p)
	{
		Money+=p;
	}

	bool Bankomat::sub(int p)
	{
		if ((p > Money)||(p < Min)||(p > Max))
			return false;
		else {Money -= p; return true;}
	}
	void Bankomat::show()
	{
		std::cout << "Nomer scheta:" << Number << std::endl;
		std::cout << "Name vkladchika:" << Name << std::endl;
		std::cout << "Balans:" << Money << "$\n\n";
	}
    void Bankomat::sub2()
    {
        int p; 
        std::cout<< "Vvedite summu snatia:"<<std::endl;
        std::cin>>p;
        std::cout<<std::endl;
        if ((p > Money)||(p < Min)||(p > Max))
			std::cout << "Snytie deneg ne proizvedeno\n";
		else {Money -= p;}
    }
    void Bankomat::SetName2()
    {
        std::cout<<"vvedite name of user: ";
        std::cin>>Name;
    }
    void Bankomat::SetMoney2()
    {
        std::cout<<"vvedite summu deneg na schete: ";
        std::cin>>Money;     
    }
    void Bankomat::SetNumber2()
    {
        std::cout<<"vvedi nomer scheta: ";
        std::cin>>Number;    
    }
    void Bankomat::SetMin2()
    {
        std::cout<<"vvedite min summu snatia: ";
        std::cin>>Min;
    }
    void Bankomat::SetMax2()
    {
        std::cout<<"vvedite max summu snatia: ";
        std::cin>>Max;
    }
    void Bankomat::toString()
    {
         int m;
         m=Money;
         if(m/(10^6)!=0){
                         int k,i;
                         k=m/(10^6);
                         i=k/100;
                         std::cout<<i<<std::endl;
                         if(i=!0){
                                    switch (i){
                                             case 1: {std::cout<<"one "; break;}
                                             case 2: {std::cout<<"two "; break;}
                                             case 3: {std::cout<<"three "; break;}
                                             case 4: {std::cout<<"four "; break;}
                                             case 5: {std::cout<<"five "; break;}
                                             case 6: {std::cout<<"six "; break;}
                                             case 7: {std::cout<<"seven "; break;}
                                             case 8: {std::cout<<"eight "; break;}
                                             case 9: {std::cout<<"nine "; break;}
                                             default: std::cout<<"error ";
                                      }
                         std::cout<<"hundred ";
                         }
                         i=k/10-i*10;
                         int q;
                         q=k%10;
                         if(i=!0){
                                  switch (i){
                                         case 1: {
                                              switch (q){
                                                     case 1: {std::cout<<"eleven "; break;}
                                                     case 2: {std::cout<<"twelwe "; break;}
                                                     case 3: {std::cout<<"thirteen "; break;}
                                                     case 4: {std::cout<<"fourteen "; break;}
                                                     case 5: {std::cout<<"fifteen "; break;}
                                                     case 6: {std::cout<<"sixteen "; break;}
                                                     case 7: {std::cout<<"seventeen "; break;}
                                                     case 8: {std::cout<<"eighteen "; break;}
                                                     case 9: {std::cout<<"nineteen "; break;}
                                                     case 0: {std::cout<<"ten "; break;}
                                                     default: std::cout<<"error ";
                                              }
                                         }
                                         case 2: {std::cout<<"twenty "; break;}
                                         case 3: {std::cout<<"thirty "; break;}
                                         case 4: {std::cout<<"fourty "; break;}
                                         case 5: {std::cout<<"fifty "; break;}
                                         case 6: {std::cout<<"sixty "; break;}
                                         case 7: {std::cout<<"seventy "; break;}
                                         case 8: {std::cout<<"eighty "; break;}
                                         case 9: {std::cout<<"ninety "; break;}
                                         default: std::cout<<"error ";
                                  }
                         }
                         if((q=!0)&&(i=!1)){
                                            switch (q){
                                                     case 1: {std::cout<<"one "; break;}
                                                     case 2: {std::cout<<"two "; break;}
                                                     case 3: {std::cout<<"three "; break;}
                                                     case 4: {std::cout<<"four "; break;}
                                                     case 5: {std::cout<<"five "; break;}
                                                     case 6: {std::cout<<"six "; break;}
                                                     case 7: {std::cout<<"seven "; break;}
                                                     case 8: {std::cout<<"eight "; break;}
                                                     case 9: {std::cout<<"nine "; break;}
                                                     default: std::cout<<"error ";
                                              }
                                            
                         }
         std::cout<<"milion ";
         }
         
         
         
         
         
         
         
         
         
    }























































}        
    

