#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int N;//���������� �������


int Gnome_sort(int m, int *mas, int *num){//������ ����������
    int i=0;
    int j=1;
    int save1;//��� �����
    int save2;//��� ������
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

int Print(int m, int *mas){//����� ������� �� �����
    cout<<endl;
    for(size_t count=0;count<m;count++){
        cout<<mas[count]<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    cout<<"������� ���������� �������: ";
    cin>>N;
    int *A=new int[N];
    int *B=new int[N];
    for(size_t count=0;count<N;count++){
        B[count]=count+1;
    }
    int forswitch;
    cout<<"�������� ������ ��������� �����:\n1.��������\n2.� ����������\n";
    cin>>forswitch;
    switch(forswitch){
        case 1:{
            for(size_t count=0;count<N;count++){
                A[count]=rand()%N;
            }
            break;
        }
        case 2:{
            cout<<"������� ����� Ai:"<<endl;
            for(size_t count=0;count<N;count++){
                cin>>A[count];
            }
            break;
        }
    }
    for(size_t count=0;count<N;count++){
        if(A[count]>=N){
            cout<<"���������� ���������� ����������, �� ������� �����, ������� ��������� ������ ���������� ������ ������"<<endl;
                delete []A;
                delete []B;
                A=NULL;
                B=NULL;
                system("PAUSE");
                return 0;
        }
    }
    cout<<"�������� ������:";
    Print(N,A);
    Gnome_sort(N,A,B);
    cout<<"������ ����� ����������(��������������):";
    Print(N,A);
    int maxcontact[N];//������, ���������� ������ ����� � ������������ ����������� ���������
    int counterofmaxcontact=0;//������� ����� � ������������ ����������� ���������
    for(size_t count=0;count<N;count++){
        if(A[count]==(N-1)){
            maxcontact[counterofmaxcontact]=count+1;
            counterofmaxcontact++;
        }
    }
    while(A[0]!=0){
        for(size_t count=0;count<A[0];count++){
            if(A[count+1]<=0){
                cout<<"���������� ���������� ���������� ��� �������������� ���������\n��� ���������� ������� ������ ���������� "<<B[0]<<" �� �������� ����������� � "<<A[0]-count<<" ���������(������)"<<endl;
                if(counterofmaxcontact!=0){
                    cout<<", �����: ";
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
    cout<<"���������� ���������� ��� �������������� ���������!"<<endl;
    delete []A;
    delete []B;
    A=NULL;
    B=NULL;
    system("PAUSE");
    return 0;
}
