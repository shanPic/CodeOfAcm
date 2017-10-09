#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
int find(string &a,char flag,string::iterator &last){
	string::iterator itstr=last+1;
	for(;itstr!=a.end();itstr++)
		if(*itstr==flag){
			last=itstr;
			return 1;
		}
	for(itstr=a.begin();itstr!=last;itstr++){
		if(*itstr==flag){
			last=itstr;
		return 2;
	}
	}
	return 0;
}
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	string X,Z;
	//int dp[10000];
	int sum,tem;
	string::iterator head;
	while(cin>>X>>Z){
		tem=Z.size();
		int dp[tem];
		head=X.begin();
		tem=0;
		sum=1;
		string::iterator itstr=Z.begin();
		for(string::iterator a=X.begin();a!=X.end();a++){
			if(*itstr==*a){
				dp[0]=1;
				head=a;
				tem=1;
				break;
			}
		}
		if(tem==0)
			dp[0]=0;
		//dp[0]=1;
		//dp[0]=0;
		for(++itstr;itstr!=Z.end();itstr++,sum++){
			tem=find(X,*itstr,head);
			//cout<<tem<<endl;
			switch(tem){
			case 1:	dp[sum]=dp[sum-1]+1;break;
			case 0: dp[sum]=0;break;
			case 2: dp[sum]=1;break;
			}
			
		}
		//for(int i=0;i<sum;i++)cout<<dp[i]<<"\t";cout<<endl;
		sort(dp,dp+sum);
		cout<<dp[sum-1]<<endl;
	}
}




