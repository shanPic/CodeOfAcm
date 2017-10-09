#include<bits/stdc++.h>
using namespace std;
const int MAXN=5300;
int dp[MAXN][18];
int a[MAXN];
int h[MAXN];
int n;
void st()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		dp[i][0]=a[i];
	}
	for(int i=1;i<log2(n)+1;i++){//循环边界？
		//cout<<333333<<endl;
		for(int j=0;j<n;j++){
			//cout<<44444<<endl;
			dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
		}
	}
}
int ask(int i,int j)
{
	int l=log2(j-i+1);
	return max(dp[i][l],dp[j-(1<<l)+1][l]);
}
int main()
{
	//freopen("data.in","r",stdin);
	int t;
	cin>>t;
	int k;
	while(t--){
		//cout<<111111<<endl;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		st();

		//尺取法
		int l=0,r=0,sumc=a[0],sumh=h[0],ans=h[0];
		while(1){
			while(r+1<n&&sumc+a[r+1]-ask(l,r+1)<=k){
				r++;
				sumc+=a[r];
				sumh+=h[r];
				ans=max(sumh,ans);
			}
			//if(sumc+a[r+1]-ask(l,r+1)<=k) break;
			sumc-=a[l];
			sumh-=h[l];
			l++;
			while(l<r&&sumc-ask(l,r)>k){
				sumc-=a[l];
				sumh-=h[l];
				l++;
			}
			if(r==n-1) break;
		}
/*		cout<<sumc<<"\t"<<sumh<<endl;
		cout<<l<<"\t"<<r<<endl; */
		cout<<ans<<endl;
	}
}