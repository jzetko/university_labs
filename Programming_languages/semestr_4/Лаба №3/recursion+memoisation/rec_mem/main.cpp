#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

const int maxN=210;
const long long inf=1e10;

long long width,n;
pair<long long,long long> blocks[maxN];
long long ans[maxN], save[maxN];
vector<long long> realAns;

int solve(int a){
	if(a==0)
		return 0;
	if(save[a]!=-1)
		return save[a];
	long long bestRes=inf;
	long long bestInd=-1;
	long long currMax=0;
	long long sumLen=0;
	for(int i=a-1;i>=0;i--){
		currMax=max(currMax, blocks[i].second);
		sumLen+=blocks[i].first;
		if(sumLen>width)
			break;
		long long res=solve(i)+currMax;
		if(res<bestRes){
			bestRes=res;
			bestInd=i;
		}
	}
	ans[a]=a-bestInd;
	save[a]=bestRes;
	return bestRes;
}

int main()
{
	clock_t start,end;
    double elapsed;
    start=clock();

    ifstream str("test.txt");
    str>>width;
    str>>n;
    if(n<5||n>=200){
        cout<<"Error of numbers of blocks!"<<endl;
        return 0;
    }
	//cin >> width >> n;

	for(int i=0;i<n;i++){
		//cin >> blocks[i].first >> blocks[i].second;
		str>>blocks[i].first;
		str>>blocks[i].second;
		if (blocks[i].first > width){
			cout << "No solution";
			return 0;
		}
		if (blocks[i].first==0||blocks[i].second==0){
			cout << "No solution";
			return 0;
		}
	}
    str.close();


	for(int i=0;i<maxN;i++){
    	save[i] = -1;
    }

	cout<<"Total height="<<solve(n)<<endl;

    int curr=n;
    while(curr!=0){
    	realAns.push_back(ans[curr]);
    	curr-=ans[curr];
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
