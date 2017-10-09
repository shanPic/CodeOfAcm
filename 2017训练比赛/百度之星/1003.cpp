/*
* @FileName: D:\代码与算法\2017训练比赛\百度之星\1003.cpp
* @Author: Pic
* @Date:   2017-08-05 17:14:04
* @Last Modified time: 2017-08-05 19:48:21
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
struct node
{
	int k,p;
}mo[1000+30];
int a[100000+30],b[100000+30];
int dp[1000+3][10+3];
int main(){
	//freopen("data.in","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int maxb=-1;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i],&b[i]);
			maxb=max(b[i],maxb);
		}
		int flag=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&mo[i].k,&mo[i].p);
			if(mo[i].p>maxb) flag=1;
		}
		if(!flag) {
			cout<<-1<<endl;
			continue;
		}
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<=10;i++) dp[0][i]=0;

		//背包过程
		for(int k=0;k<m;k++)
		for(int i=1;i<=1000;i++){
			for(int j=0;j<=10;j++){
				
				if(mo[k].p<=j){
					continue;
				}
				else{
					if((mo[k].p-j)>i){
						dp[i][j]=min(dp[i][j],mo[k].k);
					}
					else{
						dp[i][j]=min(dp[i][j],dp[i-mo[k].p+j][j]+mo[k].k);
					}
				}
				
			}
		}
		long long res=0;
		for(int i=0;i<n;i++){
			res+=((long long)dp[a[i]][b[i]]);
		}
		//printf("%lld\n",res);
		cout<<res<<endl;
	}
    return 0;
}