/*
* @FileName: D:\代码与算法\acm题目\图论\最短路\distance\main.cpp
* @Author: Pic
* @Created Time: 2017/8/26 17:20:33
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+30;
const int inf= 1e9+1e8;
int per[MAXN];
struct edge{
	int to,dist;
	int nxt;
	edge(int _to,int _dist,int _nxt):to(_to),dist(_dist),nxt(_nxt){}
	edge(){};
}e[MAXN*4+30];
int head[MAXN];
int cnt=0;
void addedge(int from,int to,int dist)
{
	e[cnt]=edge(to,dist,head[from]);
	head[from]=cnt;
	cnt++;
}
int color[MAXN];
int ans=inf;
int dis[MAXN];
int vis[MAXN];
int pcnt=0;
int use[MAXN];
void dj()
{
	memset(vis,0,sizeof(vis));
	typedef pair<int,int> p;
	priority_queue<p> q;
	for(int i=0;i<pcnt;i++){
		dis[per[i]]=0;
		q.push(p(0,per[i]));
	}
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(!vis[now]){
			vis[now]=1;
			for(int i=head[now];i!=-1;i=e[i].nxt){
				int len=e[i].dist;
				int v=e[i].to;
				if(color[now]!=color[v]&&color[v]!=-1){
					ans=min(ans,dis[now]+dis[v]+len);
				}
				if(dis[v]>dis[now]+len){
					dis[v]=dis[now]+len;
					color[v]=color[now];
					q.push(p(-dis[v],v));
				}
			}
		}
	}	
}
int main()
{
//	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,k,l;
   	scanf("%d%d%d",&n,&k,&l); 
	for(int i=0;i<n;i++){
		scanf("%d",&per[i]);
		pcnt++;
	}	
	int x,y,w;
	for(int i=0;i<l;i++){
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		addedge(y,x,w);
	}
	ans=inf;
	memset(use,0,sizeof(use));
	memset(color,-1,sizeof(color));
	for(int i=0;i<pcnt;i++){
		color[per[i]]=i;
		if(use[per[i]]){
			ans=0;
		}
		use[per[i]]=1;
	}	
	memset(dis,0x3f,sizeof(dis));
	dj();
	printf("%d\n",ans*3);
	return 0;
}


