/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练三\1001.cpp
* @Author: Pic
* @Date:   2017-07-21 20:17:59
* @Last Modified time: 2017-07-21 20:30:53
*/

#include <iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=5000+30;
struct node 
{
	int l,w;
};
node a[MAXN];
int dp[MAXN];
bool cmp(node a,node b)
{
	return (a.l<b.l)||((a.l==b.l)&&(a.w<b.w));
}
int main(){
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].l,&a[i].w);
		}
		sort(a,a+n,cmp);
		int res=-1;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(a[i].w<a[j].w){
					dp[i]=max(dp[j],dp[i]);
				}
			}
			dp[i]++;
			res=max(dp[i],res);
		}
		printf("%d\n",res);
	}
    return 0;
}