#include "Bankomat.h"
#include <iostream>
#include <conio.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
	using Bank::Bankomat;
	Bankomat a,b;
	a.SetName("Vlad");
	a.SetMoney(1000);
	a.SetNumber(1256478);
	a.SetMin(100);
	a.SetMax(2000);
	a.show();
	a.add(200);
	a.show();
	a.add(345);
	a.show();
	if(!a.sub(1000))
	{
		cout << "Snytie deneg ne proizvedeno\n";
	}

	a.show();
	if(!a.sub(99))
	{
		cout << "Snytie deneg ne proizvedeno\n";
	}
	a.show();
	
	//b.SetName2();
	b.SetMoney2();
	//b.SetNumber2();
	//b.SetMin2();
	//b.SetMax2();
	b.show();
	//b.sub2();
    //b.show();
    b.toString();
    
    
    
    _getch();
	return 0;
	
	
}
