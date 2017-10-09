/*
* @FileName: D:\代码与算法\2017训练比赛\CF#426\b.cpp
* @Author: Pic
* @Date:   2017-08-16 10:37:54
* @Last Modified time: 2017-08-16 11:16:25
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN=35000+30;
int a[MAXN],pre[MAXN],last[MAXN];
int dp[MAXN][50+3];
int res[MAXN][50+3];
void print(int n)
{
	for(int i=1;i<=n;i++){
		cout<<dp[i][1]<<"\t";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<res[i][1]<<"\t";
	}
	cout<<endl;
}
int main(){
	//freopen("data.in","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
	//while(~scanf("%d%d",&n,&k)){
		memset(last,-1,sizeof(last));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			pre[i]=last[a[i]];
			last[a[i]]=i;
		}
		// for(int i=1;i<=n;i++) cout<<pre[i]<<"\t";
		// 	cout<<endl;
		for(int i=1;i<=n;i++){
			int rou=min(i,k);
			int tmp=0;
			for(int j=1;j<=rou;j++){
				if(dp[i-1][j]>pre[i]){
					tmp=res[i-1][j]+1;
				}
				else{
					tmp=res[i-1][j];
				}
				if(tmp>res[i-1][j-1]+1){
					res[i][j]=tmp;
					dp[i][j]=dp[i-1][j];
				}
				else{
					res[i][j]=res[i-1][j-1]+1;
					dp[i][j]=i;
				}
			}
		}
		//print(n);
		printf("%d\n",res[n][k]);
	//}
    return 0;
}