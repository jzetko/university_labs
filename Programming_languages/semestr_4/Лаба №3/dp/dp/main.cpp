#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

const int maxN=210;
const long long inf=(long long)1e10;

long long width,n;
pair<long long,long long>blocks[maxN];

struct item{
	long long lastHeight,lastLen,result;
	item(){}
	item(long long a,long long b,long long c){
		lastHeight=a;
		lastLen=b;
		result=c;
	}
};

item dp[maxN][maxN];
int prev[maxN][maxN];
vector<int> ans;

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
		if (blocks[i].first==0||blocks[i].second==0){
			cout << "No solution";
			return 0;
		}
	}
    str.close();

    clock_t start,end;
    double elapsed;
    start=clock();

	for(int i=0;i<maxN;i++){
		for(int j=0;j<maxN;j++){
			dp[i][j]=item(0,0,inf);
		}
	}

	dp[1][1]=item(blocks[0].second, blocks[0].first, blocks[0].second);
	for(int i=1;i<n;i++){
		for(int j=1;j<=i;j++){
			long long newHeight=max(dp[i][j].lastHeight, blocks[i].second);
			long long newResult=dp[i][j].result-dp[i][j].lastHeight+newHeight;
			long long newLen=dp[i][j].lastLen+blocks[i].first;
			if(newLen<=width&&dp[i+1][j+1].result>newResult){
				dp[i+1][j+1]=item(newHeight, newLen, newResult);
				prev[i+1][j+1]=j;
			}
			if(dp[i+1][1].result>dp[i][j].result+blocks[i].second){
				dp[i+1][1]=item(blocks[i].second, blocks[i].first, dp[i][j].result+blocks[i].second);
				prev[i+1][1]=j;
			}
		}
	}

	int ansInd=1;
	for(int i=1; i<=n;i++){
		if(dp[n][i].result<dp[n][ansInd].result)
			ansInd=i;
	}

	int curr=ansInd;
	int cnt=0;
	for(int i=n;i>0;i--){
		cnt++;
		if(curr==1){
			ans.push_back(cnt);
			cnt=0;
		}
		curr=prev[i][curr];
	}

	cout<<"Total height="<<dp[n][ansInd].result<<endl;
	cout<<"Numbers of strings="<<ans.size()<<endl<<"Partition by rows:"<<endl;
	for (int i=ans.size()-1;i>=0;i--){
		cout<<ans[i]<<endl;
	}
	end=clock();
    elapsed=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<endl<<endl<<"Execution time="<<elapsed<<" ces"<<endl;

	return 0;
}
