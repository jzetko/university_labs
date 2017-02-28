#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node{

    string name;
    double P;
    Node *parent;
    char code[15];
    char symbol;
};

Node newNode;
vector <Node> main_vector,tree_vector,our_selections;//1-������ ������� �������� ��� ���� � �����, 2-������ ��� ������ � ��� � ��������, 3-������ �������� ������ �������� ��������
int numbers;
double bin_after_algorithm=0;

class cmp{//���������� ������� �� �������
public:
    bool operator() (const Node &a, const Node &b) {
        return a.P>b.P;
    }
} compare;


void sorting_by_P(vector <Node> &v1){//����� ���������� ������ ������� �� �������

    sort(v1.begin(), v1.end(), compare);

}


void Huffman(vector <Node> &v){

    if(v.size()==1){
        return;
    }
    sorting_by_P(v);//��������� ��� ������(�������) ��� ������ ��������
    vector <Node>::iterator it,it_tree;
    //for(it=v.begin();it!=v.end();it++){
    //    cout<<it->name<<" - "<<it->P<<endl;
    //}
    Node *newNode=new Node;//������� ����� ���� � �������� ��� ����������� ����
    it=v.end()-1;
    newNode->name=it->name+"+"+(it-1)->name;
    newNode->P=it->P+(it-1)->P;
    newNode->parent=0;
    for(it_tree=main_vector.begin();it_tree!=main_vector.end();it_tree++){
        if(it_tree->name==it->name){
            it_tree->parent=newNode;//�������� ����� ��������� ������ �� ������ ������������ ����
            it_tree->symbol='0';
        }
    }
    it--;
    for(it_tree=main_vector.begin();it_tree!=main_vector.end();it_tree++){
        if(it_tree->name==it->name){
            it_tree->parent=newNode;//�������� ����� ��������� ������ �� ������ ������������ ����
            it_tree->symbol='1';
        }
    }
    main_vector.push_back(*newNode);//�������� � �������� ������
    v.pop_back();//
    v.pop_back();//
    v.push_back(*newNode);//������� ���� 2 �������� ������� � ������ �� �� ����� ���� ������������� ��



    Huffman(v);//�������� ���� ����������

}


void Output(vector <Node> &v){

    vector <Node>::iterator it,it_tree,it_help;
    for(it=our_selections.begin();it!=our_selections.end();it++){
        int count=0;
        for(it_tree=main_vector.begin();it_tree!=main_vector.end();it_tree++){
            if(it->name==it_tree->name){
                while(it_tree->parent!=0){
                    it->code[count]=it_tree->symbol;//���������� ������ � ��� ������ ��-�� � ������ ������ ��� ������� ���������
                    count++;
                    Node *newNode=it_tree->parent;
                    for(it_help=main_vector.begin();it_help!=main_vector.end();it_help++){
                        if(newNode->name==it_help->name){
                            it_tree=it_help;//�������� �� ������������ �������
                        }
                    }
                }
            }
        }
    }
    for(it=our_selections.begin();it!=our_selections.end();it++){
        int count=0;
        while(it->code[count]!='\0'){
            count++;
        }
        bin_after_algorithm+=count*(it->P);//������� ���-�� ��� �� 1 �������
        cout<<it->name<<" - ";
        for(count-1;count>=0;count--){
            cout<<it->code[count];//������ �� ����� ������������ ���������� ���
        }
        cout<<endl;
    }

}



int main()
{

    cout<<"Print the number of elements: ";
    cin>>numbers;
    string for_adding_name;
    double for_adding_p;


    for(int i=0;i<numbers;i++){//��������� ������� ������ ��������
        cout<<"Enter the "<<i+1<<" name: ";
        cin>>for_adding_name;
        cout<<"Enter the "<<i+1<<" probability: ";
        cin>>for_adding_p;
        newNode.name=for_adding_name;
        newNode.P=for_adding_p;
        newNode.parent=0;
        main_vector.push_back(newNode);
        tree_vector.push_back(newNode);
        our_selections.push_back(newNode);
    }

    vector <Node>::iterator it;
    double sum_test=0;
    for(it=main_vector.begin();it!=main_vector.end();it++){
        sum_test+=it->P;
    }
    cout<<"Total probability="<<sum_test<<endl;


    if(sum_test<0.95||sum_test>1){//�������� �� ������������ ��������� ������
        cout<<endl<<"Total probability is wrong!!!"<<endl;
        system("PAUSE");
        return 0;
    }

    if(main_vector.size()==1){//���� ����� ���������
        main_vector[0].code[0]='0';
    }
    else{
        Huffman(tree_vector);
        Output(main_vector);
    }


    int min_bin=ceil(log2(numbers));
    cout<<endl<<"Min numbers of bits to coding one symbol without algorithm="<<min_bin<<endl;
    cout<<"Numbers of bits to coding one symbol after using algorithm="<<bin_after_algorithm<<endl<<endl;

    main_vector.clear();
    our_selections.clear();
    tree_vector.clear();

    return 0;

}
