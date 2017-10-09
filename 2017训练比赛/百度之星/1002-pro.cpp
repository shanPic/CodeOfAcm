/*
* @FileName: D:\代码与算法\2017训练比赛\百度之星\1002-pro.cpp
* @Author: Pic
* @Date:   2017-08-06 09:31:11
* @Last Modified time: 2017-08-06 09:34:31
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
int sum[3000+30];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(sum,0,sizeof(sum));
		int u,v,w;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);
			if(u!=v){
				sum[u]+=w;
				sum[v]+=w;
			}
		}
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			ans=min(ans,sum[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}