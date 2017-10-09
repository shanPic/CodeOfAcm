/*
* @FileName: D:\代码与算法\2017训练比赛\2016西欧区域赛\b-pro.cpp
* @Author: Pic
* @Created Time: 2017/10/6 15:03:34
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+30;
const int maxm=1e6+30;
int dp[maxn][2];
int vis[maxn];
struct node
{
	int flag;
	int to,nxt;
	node(){};
	node(int to,int nxt,int flag):to(to),nxt(nxt),flag(flag){};
}e[maxm*2];
int head[maxn],cnt=0;
void addedge(int from,int to,int flag){
	e[cnt].flag=flag;	
	e[cnt].to=to;
	e[cnt].nxt=head[from];
	cnt++;
}
void dfs1(int x)
{
	
}
int deg[maxn];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int n,m;
	init();
	while(~scanf("%d%d",&n,&m)){
		int x,y;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			if(vis[y]==1){
				addedge(x,y,1);
			}
			else{
				addedge(x,y,0);
				deg[y]++;
			}
		}
		int root=0;
		for(int i=1;i<=n;i++){
			
		}
			
	}	
	return 0;
}
