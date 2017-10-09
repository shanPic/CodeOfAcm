/*
* @FileName: D:\代码与算法\2017训练比赛\9.10沈阳网络赛\1008.cpp
* @Author: Pic
* @Date:   2017-09-10 13:28:56
* @Last Modified time: 2017-09-10 13:44:57
*/
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
const int maxn=100010;
const int inf=0x3f3f3f3f;
struct Edge
{
    int from,to,cap,flow,cost;
    Edge(){}
    Edge(int f,int t,int c,int fl,int co):from(f),to(t),cap(c),flow(fl),cost(co){}
};

struct MCMF
{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];     //是否在队列
    int d[maxn];        //Bellman_ford单源最短路径
    int p[maxn];        //p[i]表从s到i的最小费用路径上的最后一条弧编号
    int a[maxn];        //a[i]表示从s到i的最小残量

    //初始化
    void init(int n,int s,int t)
    {
        this->n=n, this->s=s, this->t=t;
        edges.clear();
        for(int i=0;i<=n;++i) G[i].clear();
    }

    //添加一条有向边
    void AddEdge(int from,int to,int cap,int cost)
    {
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    //求一次增广路
    bool BellmanFord(int &flow, int &cost)
    {
        for(int i=0;i<n;++i) d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0, a[s]=INF, inq[s]=true, p[s]=0;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front(); Q.pop();
            inq[u]=false;
            for(int i=0;i<G[u].size();++i)
            {
                Edge &e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost)
                {
                    d[e.to]= d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]= min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){ Q.push(e.to); inq[e.to]=true; }
                }
            }
        }
        if(d[t]==INF) return false;
        flow +=a[t];
        cost +=a[t]*d[t];
        int u=t;
        while(u!=s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -=a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    //求出最小费用最大流
    int Min_cost()
    {
        int flow=0,cost=0;
        while(BellmanFord(flow,cost));
        return cost;
    }
}MM;
int main()
{
	freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		MM.init(n+2,0,n+1);
		int w;
		for(int i=1;i<=n;i++){
			scanf("%d",&w);
			MM.AddEdge(0,i,1,-w);
			MM.AddEdge(i,n+1,1,w);
		}
		int x,y;
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&w);
			MM.AddEdge(x,y,inf,-w);
			MM.AddEdge(y,x,inf,-w);
		}
		printf("%d\n",MM.Min_cost());
	}
}