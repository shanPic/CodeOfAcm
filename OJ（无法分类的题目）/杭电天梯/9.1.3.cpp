#include<bits/stdc++.h>
using namespace std;
cosnt int MAXN=1005;
int dp[MAXN][MAXN];
int n,m,k,s;
int c[MAXN];
int v[MAXN];
void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<k;i++){
		for(int j=0;j<=m;j++){
			for(int kk=1;kk<=s;kk++){
				dp[j][kk]=max(dp[j-c[i]][kk-1]+v[i],dp[j][kk]);
			}
		}
	}
}
int main()
{
	while(cin>>n>>m>>k>>s){
		for(int i=0;i<k;i++){
			cin>>v[i]>>c[i];
		}
		solve();
		int res=-1;
		bool flag=0;
		for(int i=1;i<=s;i++){
			for(int j=0;j<=m;j++){
				if(dp[])
			}
		}
	}
}