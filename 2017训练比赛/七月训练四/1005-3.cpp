/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1005-3.cpp
* @Author: Pic
* @Date:   2017-07-30 19:55:03
* @Last Modified time: 2017-07-30 20:06:30
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
int main(){
	int ansl,ansr,ans;
	int n,k;
	while(~scanf("%d%d",&n,&k)&&n&&k){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		pre[0].i=0,pre[0].sum=0;
		for(int i=1;i<=n;i++){
			pre[i].i=i;
			pre[i].sum=pre[i-1].sum+a[i];
		}
		for(int i=0;i<k;i++){
			int t;
			scanf("%d",&t);
			int l=0,r=0,sum=0;
			ansl=ansr=0;ans=0x3f3f3f3f;
			while(1){
				while(r<n&&sum<t){
					r++;
					sum=pre[r].sum-pre[l].sum;
					if(abs(t-sum)<abs())
				}
			}
		}

	}
    return 0;
}