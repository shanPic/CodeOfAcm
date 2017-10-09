/*
* @FileName: b-real.cpp
* @Author: Pic
* @Date:   2017-06-04 13:48:05
* @Last Modified time: 2017-06-04 14:23:45
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=100000+3;
int pre[MAXN];
int main(){

	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int x;
		int res=0;
		pre[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			pre[i]=pre[i-1]+x;
		}
		int de,re,nu;
		for(int i=0;i<m;i++){
			scanf("%d %d %d",&de,&re,&nu);
			res+=((pre[de]-pre[re-1])*nu);
		}
		printf("%d\n",res+pre[n]);
	}

    return 0;
}