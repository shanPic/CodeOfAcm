/*
* @FileName: D:\代码与算法\2017训练比赛\2016青岛区域赛\g.cpp
* @Author: Pic
* @Created Time: 2017/10/7 12:46:48
*/
#include <bits/stdc++.h>
using namespace std;
const double INF = -1*10.0;
const int maxn=200+10;

struct Edge
{
    int from,to,cap,flow;
	double cost;
    Edge(){}
    Edge(int f,int t,int c,int fl,double co):from(f),to(t),cap(c),flow(fl),cost(co){}
};

struct MCMF
{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];     //是否在队列
    double d[maxn];        //Bellman_ford单源最短路径
    int p[maxn];        //p[i]表从s到i的最小费用路径上的最后一条弧编号
    int a[maxn];        //a[i]表示从s到i的最小残量

    //初始化
    void init(int n,int s,int t)
    {
        this->n=n, this->s=s, this->t=t;
        edges.clear();
        for(int i=0;i<n;++i) G[i].clear();
    }

    //添加一条有向边
    void AddEdge(int from,int to,int cap,double cost)
    {
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    //求一次增广路
    bool BellmanFord(int &flow, double &cost)
    {
        for(int i=0;i<n;++i) d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=1.0, a[s]=1e9+30, inq[s]=true, p[s]=0;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
			//cout<<"Q"<<endl;
            int u=Q.front(); Q.pop();
            inq[u]=false;
            for(int i=0;i<G[u].size();++i)
            {
                Edge &e=edges[G[u][i]];
				double tmp=(d[u]*e.cost);
				//tmp=-1*fabs(tmp);
                if( e.cap>e.flow && d[e.to] < tmp )
                {
                    d[e.to]=tmp;
                    p[e.to]=G[u][i];
                    a[e.to]= min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){ Q.push(e.to); inq[e.to]=true; }
                }
            }
        }
		//cout<<d[t]<<endl;
        //if(fabs(d[t]-INF)<1e-3) return false;
        if(d[t]<0) return false;
        flow += a[t];
		for(int i=0;i<a[t];i++) cost*=(d[t]);
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
    double Min_cost()
    {
        int flow=0;double cost=1.0;
		while(BellmanFord(flow,cost)) ;
        return cost;
    }
}MM;
int main()
{
//	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t; 	
   	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		MM.init(n+2,0,n+1);
		int x,y;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			if(x!=0)
				MM.AddEdge(0,i,x,1.0);
			if(y!=0)
				MM.AddEdge(i,n+1,y,1.0);
		}
		int u,v,c;double w;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%lf",&u,&v,&c,&w);
			//MM.AddEdge(u,v,c,w);
			if(c>0){
				MM.AddEdge(u,v,c-1,1.0-w);
				MM.AddEdge(u,v,1,1.0);
			}
		}
		double res=fabs(MM.Min_cost());
		//cout<<res<<endl;
		res=1.0-res;
		if(res>=1.0) res=1.0;
		printf("%.2lf\n",res);
	}	
	return 0;
}
