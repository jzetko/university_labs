#include <iostream>
#include <cstdlib>
#include <cmath>


//��������� ������ ������� ���������� ������ �������, ��� � �� ����� ��� ����� ������ ���������� ��������� � ������������� ��������

using namespace std;

int main()
{
    int A,B,C,D;
    cout<<"Enter A: ";
    cin>>A;
    cout<<"Enter B: ";
    cin>>B;
    cout<<"Enter C: ";
    cin>>C;
    cout<<"Enter D: ";
    cin>>D;


    int counter=1;
    for(int i=-10000;i<10000;i++){
        if((A*pow(i,3)+B*pow(i,2)+C*i+D==0)&&(D%i==0)){
            cout<<"X"<<counter<<"="<<i<<endl;
            counter++;
        }
    }


    return 0;
}
