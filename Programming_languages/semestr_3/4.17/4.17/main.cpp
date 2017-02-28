#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
using namespace std;

double i;
struct straight{
        double A, B, C;
};

void Read(straight& E){
    cout<<"Print coefficients of straight\nA = ";
    cin>>E.A;
    cout<<"B = ";
    cin>>E.B;
    cout<<"C = ";
    cin>>E.C;
    cout<<endl<<endl;
}

void Display(straight& E){
    cout<<"Straight is \t"<<E.A<<"x+"<<E.B<<"y+"<<E.C<<endl<<endl;
}

double Calculate(const straight& s1,const straight& s2){
    double result;
    result=(s1.A*s2.B)-(s1.B*s2.A);
    return result;
}



class empty_argument{};


class empty_argument_th{
    public:
      empty_argument_th(unsigned _i){i=_i;}
      string what(){
          string a;
          if (i==1) a="Does not exist straight data\n";
          return a;
         };
      private:
      unsigned i;
};

class empty_argument_child:public straight{
      public:
      empty_argument_child(unsigned _i){i=_i;}
      string what() throw(){
          string a;
          if (i==1) a="Does not exist straight data\n";
          return a;
         };
      private:
      unsigned i;};



double throwCalculate(const straight& s1,const straight& s2)throw(){
    double result;
    result=(s1.A*s2.B)-(s1.B*s2.A);
    return result;
}


double throw2Calculate(const straight& s1,const straight& s2)throw(invalid_argument){
    if (((s1.A*s2.B)-(s1.B*s2.A))==0) throw std::invalid_argument("Does not exist straight data\n");
    double result;
    result=(s1.A*s2.B)-(s1.B*s2.A);
    return result;
    }


double personalCalculate(const straight& s1,const straight& s2)throw(empty_argument){
    if (((s1.A*s2.B)-(s1.B*s2.A))==0) throw empty_argument();
    double result;
    result=(s1.A*s2.B)-(s1.B*s2.A);
    return result;
    }


double personalTHCalculate(const straight& s1,const straight& s2)throw(empty_argument_th){
    if (((s1.A*s2.B)-(s1.B*s2.A))==0) throw empty_argument_th(1);
    double result;
    result=(s1.A*s2.B)-(s1.B*s2.A);
    return result;
    }


double personalChildCalculate(const straight& s1,const straight& s2)throw(empty_argument_child){
    if (((s1.A*s2.B)-(s1.B*s2.A))==0) throw empty_argument_child(1);
    double result;
    result=(s1.A*s2.B)-(s1.B*s2.A);
    return result;
    }


int main()
{
    setlocale(LC_ALL,"Russian");
    straight s1,s2;//
    cout<<"The 1st straight"<<endl;
    Read(s1);
    Display(s1);
    cout<<"The 2nd straight"<<endl;
    Read(s2);
    Display(s2);

    cout<<"CALCULATNG without exception:"<<endl;
    cout<< "Coefficients of check = "<<Calculate(s1,s2)<<endl<<endl;

    cout<<"CALCULATNG with throw():"<<endl;
    cout<<"Coefficients of check = "<<throwCalculate(s1,s2)<<endl<<endl;

    cout<<"CALCULATNG with standart:"<<endl;
    try{throw2Calculate(s1,s2);}
    catch(invalid_argument &a) {std::cout << a.what()<< std::endl;}

    cout<<"CALCULATNG with personal empty exception:"<<endl;
    try {personalCalculate(s1,s2);}
    catch(empty_argument &a) {std::cout << "Does not exist straight data\n"<< std::endl;}

    cout<<"CALCULATNG with personal exception:"<<endl;
    try {personalTHCalculate(s1,s2);}
    catch(empty_argument_th &a) {cout<<a.what()<<endl;}

    cout<<"CALCULATNG with personal parent-class exception:"<<endl;
    try {personalChildCalculate(s1,s2);}
    catch(empty_argument_child &a) {cout<<a.what()<<endl;}



    system("PAUSE");
    return 0;
}
