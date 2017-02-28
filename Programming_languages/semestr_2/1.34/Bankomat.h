#ifndef BANKOMAT_CLASS
#define BANKOMAT_CLASS
#include <string>
namespace Bank
{
	class Bankomat
	{
		private:
			unsigned int Number;
			std::string Name;
			int Money;
			int Min;
			int Max;
		public:
			Bankomat (int N, const std::string & str, int M); 
			Bankomat ();
			~Bankomat();
			void SetMoney (int p){Money = p;}
			void SetNumber (int n){Number = n;}
			void SetName (const std::string & str){Name = str;}
			void SetMin (int l){Min = l;}
			void SetMax (int h){Max = h;}

			void add (int p);
			bool sub (int p);
			void show ();
			void sub2 ();
			void SetName2();
			void SetMoney2();
			void SetNumber2();
			void SetMin2();
			void SetMax2();
			void toString();
			
			
    };
	
}
#endif

