/*
* @FileName: D:\代码与算法\2017训练比赛\多校5\1008.cpp
* @Author: Pic
* @Date:   2017-08-08 16:20:52
* @Last Modified time: 2017-08-10 12:02:03
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN=1e4+30;
typedef long long ll;
ll B[80],A[80];
ll c[MAXN];
int n,m;
int search(int b)
{
	for(int i=b;i<=m;i++){
		if(B[i]!=0) return i;
	}
	return -1;
}
int main(){
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		for(int i=0;i<=m;i++){
			scanf("%lld",&B[i]);
		}
		if(n==1){
			printf("%d\n",m);
			continue;
		}
		B[0]=0;
		int now=0;
		for(int i=0;i<n;i++){
			ll x=search(now);
			now=x;
			A[i]=x;
			//C[x]++;
			for(int i=1;i<=m-x;i++){
				if(c[i]){
					c[i+x]+=c[i];
				}
			}
			c[x]++;
			for(int i=1;i<=m;i++){
				if(c[i]>=B[i]){
					B[i]=0;
				}
			}
		}
		printf("%d",A[0]);
		for(int i=1;i<n;i++){
			printf(" %lld",A[i]);
		}
		printf("\n");
	}
    return 0;
}