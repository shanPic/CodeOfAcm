/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1002-pro.cpp
* @Author: Pic
* @Date:   2017-07-24 17:27:33
* @Last Modified time: 2017-07-24 21:52:59
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include<queue>
using namespace std;
const int maxn = 1000+30;
#define INF 1e9

struct HeapNode //Dijkstra算法用到的优先队列的节点
{
    int d,u;
    HeapNode(int d,int u):d(d),u(u){}
    bool operator < (const HeapNode &rhs)const
    {
        return d > rhs.d;
    }
};

struct Edge     //边
{
    int from,to,dist;
    Edge(int f,int t,int d):from(f),to(t),dist(d){}
};

int mid=0;
struct Dijkstra
{
    int n,m;            //点数和边数,编号都从0开始
    vector<Edge> edges; //边列表
    vector<int> G[maxn];//每个节点出发的边编号(从0开始编号)
    bool done[maxn];    //是否已永久标号
    int d[maxn];        //s到各个点的距离
    int p[maxn];        //p[i]为从起点s到i的最短路中的最后一条边的编号
    int cnt[maxn];

    void init(int n)
    {
        this->n=n;
        for(int i=0;i<=n;i++){//清空邻接表
			G[i].clear();
			G[i].reserve(n*n);
		}
        edges.clear();  //清空边列表
		edges.reserve(n*n);
    }
    void init2(){
        for(int i=0;i<=n;i++) d[i]=INF;
        memset(p,-1,sizeof(p));
    	cnt[1]=cnt[0]=0;
    }
    void AddEdge(int from,int to,int dist)
    {//如果是无向图，每条无向边调用两次AddEdge
        edges.push_back(Edge(from,to,dist) );
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s)//求s到所有点的距离
    {
        priority_queue<HeapNode> Q;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push(HeapNode(0,s));

        while(!Q.empty())
        {
            HeapNode x=Q.top(); Q.pop();
            int u=x.u;
            if(done[u]) continue;
            done[u]= true;

            for(int i=0;i<G[u].size();i++)
            {
                Edge& e= edges[G[u][i]];
                if( d[e.to]> d[u]+e.dist)
                {
                	if(e.dist>=mid) cnt[e.to]=cnt[u]+1;
                    d[e.to] = d[u]+e.dist;
                    p[e.to] = G[u][i];
                    Q.push(HeapNode(d[e.to],e.to) );
                }
            }
        }
    }
}DJ;
int n,p,k;
int main()
{
	//freopen("data.in","r",stdin);
	while(~scanf("%d%d%d",&n,&p,&k)){
		DJ.init(n+1);
		//n--;
		int x,y,l;
		int minl=INF,maxl=-1;
		for(int i=0;i<p;i++){
			scanf("%d%d%d",&x,&y,&l);
			minl=min(l,minl),maxl=max(l,maxl);
		}
		l=minl;int r=maxl+2;
		 
			mid=(l+r)/2;
			DJ.init2();
			DJ.dijkstra(1);
			if(DJ.cnt[n]>k){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		if(l>maxl) printf("-1\n");
		else printf("%d\n",l);

	}
    return 0;
}