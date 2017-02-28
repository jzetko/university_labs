#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;




struct Probability{
    string name;//название элемента
    double P;//вероятность появления
    char binary[10];//бинарный код элемента
    int number_of_bits;//счетик кол-ва бит, отведенных под кодирование символа
};

struct Substraction{
    int into_one;//кол-во элементов в левое поддерево
    double summa;//сумма разностей разбиения
};

int numbers;//количество элементов
vector <Probability> main_vector;
Probability model;
Substraction newmodel;

void Shennon(vector<Probability> &v){

    if(v.size()==1){//если обрабатывается только один вектор, то выходим из рекурсии
        return;
    }

    vector <Probability> left,right;//левые и правые поддеревья
    vector <Substraction> for_recursion;//для нахождения оптимального разбиения

    vector <Probability>::iterator it,it_left,it_right;
    vector <Substraction>::iterator it_round;

    int size_of_vector=v.size();
    for(int i=1;i<size_of_vector;i++){//находим оптимальное разбиение таблицы символов на 2 части
        for(it=v.begin();it<v.begin()+i;it++){
            left.push_back(*it);
        }
        for(it;it!=v.end();it++){
            right.push_back(*it);
        }
        double sum1=0;
        double sum2=0;
        for(it_left=left.begin();it_left!=left.end();it_left++){
            sum1=sum1+it_left->P;
        }
        for(it_right=right.begin();it_right!=right.end();it_right++){
            sum2=sum2+it_right->P;
        }
        newmodel.into_one=i;
        newmodel.summa=abs(sum1-sum2);
        for_recursion.push_back(newmodel);

        left.clear();
        right.clear();
    }


    double minimum=10000;
    int number_of_the_best_result;

    for(it_round=for_recursion.begin();it_round!=for_recursion.end();it_round++){//продолжение нахождения потимального разбиения
        if((it_round->summa)<minimum){
            number_of_the_best_result=it_round->into_one;
            minimum=it_round->summa;
        }
    }

    for_recursion.clear();

    for(it=v.begin();it<v.begin()+number_of_the_best_result;it++){//распределяем эл-ты в левое и правое поддеревья
        left.push_back(*it);
    }

    for(it;it!=v.end();it++){
        right.push_back(*it);
    }

    for(it_left=left.begin();it_left!=left.end();it_left++){//присвоение 0 и 1 поддеревьям
        for(it=main_vector.begin();it!=main_vector.end();it++){
            if(it_left->name==it->name){
                it->binary[it->number_of_bits]='0';
                it->number_of_bits++;
            }
        }
    }
    for(it_right=right.begin();it_right!=right.end();it_right++){
        for(it=main_vector.begin();it!=main_vector.end();it++){
            if(it_right->name==it->name){
                it->binary[it->number_of_bits]='1';
                it->number_of_bits++;
            }
        }
    }


    Shennon(left);
    Shennon(right);
    left.clear();
    right.clear();
}

class cmp{//сортировка веторов по частоте
public:
    bool operator() (const Probability &a, const Probability &b) {
        return a.P>b.P;
    }
} compare;


void sorting_by_P(){

    sort(main_vector.begin(), main_vector.end(), compare);

}


int main()
{

    cout<<"Print the number of elements: ";
    cin>>numbers;
    string for_adding_name;
    double for_adding_p;

    for(int i=0;i<numbers;i++){
        cout<<"Enter the "<<i+1<<" name: ";
        cin>>for_adding_name;
        cout<<"Enter the "<<i+1<<" probability: ";
        cin>>for_adding_p;
        model.name=for_adding_name;
        model.P=for_adding_p;
        model.number_of_bits=0;
        main_vector.push_back(model);
    }

    double sum_test=0;
    vector <Probability>::iterator it;
    for(it=main_vector.begin();it!=main_vector.end();it++){
        sum_test+=it->P;
    }
    cout<<"Total probability="<<sum_test<<endl;

    if(sum_test<0.95||sum_test>1){
        cout<<endl<<"Total probability is wrong!!!"<<endl;
        system("PAUSE");
        return 0;
    }

    sorting_by_P();
    if(main_vector.size()==1){
        main_vector[0].binary[0]='0';
    }
    else{
            Shennon(main_vector);
    }


    cout<<endl<<"Name - Binary digit"<<endl;
    for(it=main_vector.begin();it!=main_vector.end();it++){
        cout<<it->name<<" - "<<it->binary<<endl;
    }

    int min_bin=ceil(log2(numbers));
    cout<<endl<<"Min numbers of bits to coding one symbol without algorithm="<<min_bin<<endl;

    double bin_after_algorithm=0;
    for(it=main_vector.begin();it!=main_vector.end();it++){
        bin_after_algorithm+=(it->number_of_bits)*(it->P);
    }
    cout<<"Numbers of bits to coding one symbol after using algorithm="<<bin_after_algorithm<<endl<<endl;

    main_vector.clear();

    return 0;
}
