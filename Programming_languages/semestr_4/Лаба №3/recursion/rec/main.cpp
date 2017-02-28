#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

const int maxN = 210;
const long long inf = 1e10;

long long width,n;
pair<long long, long long> blocks[maxN];
vector<long long> realAns;

pair<long long,long long> solve(int a){
	if(a==0)
		return make_pair(0,0);
	long long bestRes=inf;
	long long bestInd=-1;
	long long currMax=0;
	long long sumLen=0;
	for(int i=a-1;i>=0;i--){
		currMax=max(currMax, blocks[i].second);
		sumLen+=blocks[i].first;
		if(sumLen>width)
			break;
		long long res=solve(i).first+currMax;
		if(res<bestRes){
			bestRes=res;
			bestInd=i;
		}
	}
	return make_pair(bestRes, a-bestInd);
}

int main()
{

    ifstream str("test.txt");
    str>>width;
    str>>n;
    //cin>>width>>n;
    if(n<5||n>=200){
        cout<<"Error of numbers of blocks!"<<endl;
        return 0;
    }

	for(int i=0;i<n;i++){
		//cin>>blocks[i].first>>blocks[i].second;
		str>>blocks[i].first;
		str>>blocks[i].second;
		if (blocks[i].first > width){
			cout << "No solution";
			return 0;
		}
	}
    str.close();

    clock_t start,end;
    double elapsed;
    start=clock();

	cout<<"Total weight="<<solve(n).first<<endl;

    int curr=n;
    while(curr!=0){
    	realAns.push_back(solve(curr).second);
    	curr-=solve(curr).second;
    }

    cout<<"Numbers of strings="<<realAns.size()<<endl<<"Partition by rows:"<<endl;
    for(int i=realAns.size()-1;i>=0;i--){
    	cout<<realAns[i]<<endl;
    }
    end=clock();
    elapsed=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<endl<<endl<<"Execution time="<<elapsed<<" ces"<<endl;

	return 0;
}

