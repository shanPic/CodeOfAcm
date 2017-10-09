/*
* @FileName: D:\代码与算法\2017训练比赛\10.9--wannafly模拟赛3\d.cpp
* @Author: Pic
* @Date:   2017-10-09 21:11:12
* @Last Modified time: 2017-10-09 21:17:27
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=500+30;
int deg[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		deg[u]++;
		deg[v]++;
	}
	sort(deg+1,deg+n+1,cmp);
	if(deg[1]>4){
		printf("NotValid\n");
	}
	else{
		if(deg[1]==2||deg[1]==1){
			printf("I\n");
		}
		else if(deg[1]==4&&(deg[2]==1||deg[2]==2)){
			printf("X\n");
		}
		else if(deg[1]==3&&(deg[2]==1||deg[2]==2)){
			printf("Y\n");
		}
		else{
			printf("NotValid\n");
		}
	}
}
