#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int N;//количество человек


int Gnome_sort(int m, int *mas, int *num){//Гномья сортировка
    int i=0;
    int j=1;
    int save1;//Для чисел
    int save2;//Для номера
    while(i<m-1){
        if(mas[i]>=mas[i+1]){
            if(i<j){
                i=j;
            }
            else{
                i++;
                j=i+1;
            }
        }
        else{
            save1=mas[i+1];
            mas[i+1]=mas[i];
            mas[i]=save1;

            save2=num[i+1];
            num[i+1]=num[i];
            num[i]=save2;


            if(i!=0){
                i--;
            }
            else{
                i=j;
            }
        }
    }
    return num[0];
}

int Print(int m, int *mas){//вывод массива на экран
    cout<<endl;
    for(size_t count=0;count<m;count++){
        cout<<mas[count]<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"Введите количество человек: ";
    cin>>N;
    int *A=new int[N];
    int *B=new int[N];
    for(size_t count=0;count<N;count++){
        B[count]=count+1;
    }
    int forswitch;
    cout<<"Выберете способ заполения чисел:\n1.Рандомно\n2.С клавиатуры\n";
    cin>>forswitch;
    switch(forswitch){
        case 1:{
            for(size_t count=0;count<N;count++){
                A[count]=rand()%N;
            }
            break;
        }
        case 2:{
            cout<<"Введите числа Ai:"<<endl;
            for(size_t count=0;count<N;count++){
                cin>>A[count];
            }
            break;
        }
    }
    for(size_t count=0;count<N;count++){
        if(A[count]>=N){
            cout<<"Знакомства установить невозможно, по причине людей, имеющих знакомств больше количества самого народа"<<endl;
                delete []A;
                delete []B;
                A=NULL;
                B=NULL;
                system("PAUSE");
                return 0;
        }
    }
    cout<<"Исходный массив:";
    Print(N,A);
    Gnome_sort(N,A,B);
    cout<<"Массив после сортировки(невозрастающий):";
    Print(N,A);
    int maxcontact[N];//массив, содержащий номера людей с максимальным количеством знакомств
    int counterofmaxcontact=0;//счетчик людей с максимальным количеством знакомств
    for(size_t count=0;count<N;count++){
        if(A[count]==(N-1)){
            maxcontact[counterofmaxcontact]=count+1;
            counterofmaxcontact++;
        }
    }
    while(A[0]!=0){
        for(size_t count=0;count<A[0];count++){
            if(A[count+1]<=0){
                cout<<"Знакомства установить невозможно без дополнительных знакомств\nДля выполнения условия задачи необходимо "<<B[0]<<" го человека познакомить с "<<A[0]-count<<" человеком(людьми)"<<endl;
                if(counterofmaxcontact!=0){
                    cout<<", кроме: ";
                    for(size_t count=0;count<counterofmaxcontact;count++){
                        cout<<maxcontact[count]<<" ";
                    }
                    cout<<endl;
                }
                delete []A;
                delete []B;
                A=NULL;
                B=NULL;
                system("PAUSE");
                return 0;
            }
            else{
                A[count+1]--;
            }
        }
        A[0]=0;
        Gnome_sort(N,A,B);
    }
    cout<<"Знакомство состоялось без дополнительных знакомств!"<<endl;
    delete []A;
    delete []B;
    A=NULL;
    B=NULL;
    system("PAUSE");
    return 0;
}
