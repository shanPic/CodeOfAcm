/*
* @FileName: D:\代码与算法\分类题目\图论\网络流\POJ2125\poj2125.cpp
* @Author: Pic
* @Created Time: 2017/10/11 19:56:57
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#define INF 1e9
using namespace std;
const int maxn=400+10;
const int inf=0x3f3f3f3f;
const int maxm=1e4;

struct Edge
{
	int from,to,nxt;
	int cap,flow;
	Edge(int from,int to,int nxt,int cap,int flow):from(from),to(to),nxt(nxt),cap(cap),flow(flow){};
	Edge(){};
};
struct
{
	int cnt=0;
	int head[maxn];
	Edge e[maxm];
	int cur[maxn];
	int dis[maxn],vis[maxn];//dis为在分层图中的层数
	void init()
	{
		memset(head,-1,sizeof(head));
		cnt=0;
	}
	void addedge(int from,int to,int cap,int flow=0)
	{
		e[cnt].from=from,e[cnt].to=to,e[cnt].cap=cap,e[cnt].flow=flow;
		e[cnt].nxt=head[from];	head[from]=cnt;
		cnt++;
		e[cnt].from=to,e[cnt].to=from,e[cnt].cap=flow,e[cnt].flow=0;
		e[cnt].nxt=head[to];	head[to]=cnt;
		cnt++;
	}
	int bfs(int s,int t)
	{
	    //memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		queue<int> q;
		q.push(s);dis[s]=0;vis[s]=1;
		while(!q.empty()){
			int x=q.front(); q.pop();
			int v;
			for(int i=head[x];i!=-1;i=e[i].nxt){
				v=e[i].to;
				if( !vis[v] && e[i].cap>e[i].flow ){
					dis[v]=dis[x]+1;
					vis[v]=1;
					q.push(v);
				}
			}
		}
		//cout<<vis[t]<<endl;
		return vis[t];

	}
	int dfs(int now,int t,int sy) //sy为剩余流量
	{
		//cout<<"dfs "<<now<<endl;
		if(now==t||sy==0) return sy;
		int f,flow=0;
		for(int i=head[now];i!=-1;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]==dis[now]+1 && (f=dfs(v,t,min(sy,e[i].cap-e[i].flow)))>0 ){
				e[i].flow+=f;
				e[i^1].cap+=f;
				//e[i^1].flow-=f;
				sy-=f;
				flow+=f;
				if(sy==0) break;
			}
		}
		return flow;
	}
	int sap(int s,int t)
	{
		int flow=0;
		while(bfs(s,t)){
            //cout<<"bfs"<<endl;
		    //for(int i=0;i<=cnt;i++) cur[i]=head[i];
			//cout<<1111<<endl;
			flow+=dfs(s,t,inf);
		}
		return flow;
	}
}MF;
int ot[maxn],in[maxn];
int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
   		for(int i=1;i<=n;i++) scanf("%d",&in[i]);
		for(int i=1;i<=n;i++) scanf("%d",&ot[i]);
		int u,v;
		MF.init();
		int s=0,t=2*n+2;
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			MF.addedge(u+n,v,inf);
		}
		for(int i=1;i<=n;i++){
            MF.addedge(i,t,in[i]);
            MF.addedge(s,i+n,ot[i]);
		}
		printf("%d\n",MF.sap(s,t));
	}
	return 0;
}
