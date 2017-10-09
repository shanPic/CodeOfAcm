/*
* @FileName: D:\代码与算法\2017训练比赛\9.23北京网络赛\1004-2.cpp
* @Author: Pic
* @Created Time: 2017/9/23 12:55:58
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1000+30;
struct edge{
	int to,nxt;
}e[maxn*3];
int head[maxn],tot;
void init()
{
	memset(head,-1,sizeof(head));
	tot=0;
}
void addedge(int from,int to)
{
	e[tot].to=to;
	e[tot].nxt=head[from];
	head[from]=tot++;
}
int mp[maxn][maxn];
int vis[maxn][maxn];
void dfs(int begin,int now,int d)
{
	vis[now]=1;dis[begin][now]=d;
	int v;
	for(int i=head[now];i!=-1;i=head[now].nxt){
		v=e[i].to;
		if(!vis[v]){
			dfs(begin,v,d+1);
		}
	}
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(dis,0,sizeof(dis));
		int x,y;
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			//	dis[x][y]=dis[y][x]=1;
			adddedge(x,y);addedge(y,x);
		}	
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			dfs(i,i,0);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){

			}
		}
	}	 
	return 0;
}
