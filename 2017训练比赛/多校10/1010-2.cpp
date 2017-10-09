/*
* @FileName: D:\代码与算法\2017训练比赛\多校10\1010-2.cpp
* @Author: Pic
* @Date:   2017-08-24 12:44:51
* @Last Modified time: 2017-08-24 12:52:11
*/
#include<iostream>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
#define INF 1e9
const int maxn=100000+10;
struct Edge
{
	int from,to,dist,nxt;
	Edge():nxt(-1){};
	Edge(int f,int t,int d,int nxt):from(f),to(t),dist(d),nxt(nxt){}
};

struct BellmanFord
{
	int n,m;
    Edge edges[maxn];
    int G[maxn];
    int num;            //邻接表中边的条数
	bool inq[maxn];     //是否在队列中
	int d1[maxn];        //s到各个点的距离
	int d2[maxn];
	int p[maxn];        //最短路中的上一条弧
	int cnt[maxn];      //进队次数

	void init(int n)
	{
		this->n=n;
        memset(G,-1,sizeof(G));
        num=0;
	}

	void AddEdge(int from,int to,int dist)
	{
		edges[num]=Edge(from,to,dist,G[from]);
		G[from]=num++;
	}

	bool negativeCycle(int s)
	{
		queue<int> Q;
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++) d[i]=INF; //注意是0到n-1 还是1到n 要根据情况变化
		inq[s]=true,d[s]=0,Q.push(s);	//将起点压入队列

		while(!Q.empty())
		{
			int u=Q.front(); Q.pop();
			inq[u]=false;
			for(int i=G[u];i!=-1;i=edges[i].nxt)
			{
				Edge &e=edges[i];
				if(d1[e.to] > d1[u]+e.dist)
				{
					d2[e.to]=d1[e.to];
					d1[e.to] = d1[u]+e.dist;
					p[e.to] = i;
					if(!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to]=true;
						if(++cnt[e.to]>n) return true;
					}
				}
				else if(d1[e.to]>d1[u]+e.dist){
					d2[e.to]=d1[u]+e.dist;
					
				}
			}
		}
		return false;
	}
}BF;
int main()
{
    int n,m;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        BF.init(n);//n为点的个数

        while(m--) {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            u--,v--;
            BF.AddEdge(u,v,d);
            BF.AddEdge(v,u,d);
        }
        BF.negativeCycle(0);

        long long ans=0;
        for(int i=1; i<n; i++)
            printf("%I64d\n",BF.d[i]);
    }
    return 0;
}