/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\1015.cpp
* @Author: Pic
* @Date:   2017-07-18 01:38:29
* @Last Modified time: 2017-07-18 01:46:57
*/

#include <cstdio>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
const int MAXN=350+30;
long long num[MAXN][MAXN];
long long  dp[MAXN][MAXN];
int main(){
	//freopen("data.in","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				scanf("%lld",&num[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+num[i][j];
			}
		}
		long long res=-1;
		for(int i=1;i<=n;i++){
			res=max(res,dp[n][i]);
		}
		printf("%lld\n",res);
	}
    return 0;
}