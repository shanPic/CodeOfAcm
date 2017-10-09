/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1005-pro.cpp
* @Author: Pic
* @Date:   2017-07-30 18:54:29
* @Last Modified time: 2017-07-30 19:13:00
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN=1e5+30;
int a[MAXN];
struct node 
{
	int i,sum;
}pre[MAXN];
bool cmp(node a,node b)
{
	return a.sum<b.sum;
}
int resl=0,resr=0,ressum=0;
int getsum(int t,int l,int r)
{
	int sum=pre[r].sum-pre[l].sum;
	if()
}
int main(){
	int n,k;
	while(~sanf("%d%d",&n,&k)&&n&&k){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		pre[0].i=0,pre[0].sum=0;
		for(int i=1;i<=n;i++){
			pre[i].sum=pre[i-1].sum+a[i];
		}
		sort(pre,pre+n+1,cmp);
		int l=0,r=0,sum=0;
		for(;;){
			while(r<n&&sum<t){
				t++;
				getsum(t,l,r);
			}
		}
	}
    return 0;
}