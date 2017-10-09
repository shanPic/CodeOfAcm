/*
* @FileName: D:\代码与算法\2017训练比赛\9.10沈阳网络赛\1008-3.cpp
* @Author: Pic
* @Date:   2017-09-10 14:09:12
* @Last Modified time: 2017-09-10 14:55:06
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;

typedef pair<int, int>P;//first保存最短距离，second保存顶点的编号
namespace IO{
    const int BUFFSIZE=20<<20;//<<10kb <<20MB
    char Buf[BUFFSIZE+1],*buf=Buf;
    size_t lastlen=0;
    void init(){lastlen=fread(Buf,1,BUFFSIZE,stdin);}
    template<class T>
    void read1(T& res){
        for(res=0;*buf<'0'||*buf>'9';buf++);
        while(*buf>='0'&&*buf<='9'){res=res*10+(*buf-'0');buf++;}
    }
    template<class T>
    void read2(T& res){
        int sgn=1;
        for(res=0;*buf<'0'||*buf>'9';buf++)if(*buf=='-')sgn=-1;
        while(*buf>='0'&&*buf<='9')res=res*10+(*buf-'0'),buf++;
        res=res*sgn;
    }

    template<class T>
    bool read3(T& res){
        for(res=0;*buf<'0'||*buf>'9';buf++);
        if(buf-Buf>=lastlen) return 0;
        while(*buf>='0'&&*buf<='9'){res=res*10+(*buf-'0');buf++;}
        return 1;
    }
    void readstring(char *c){
        for(;*buf=='\n'||*buf=='\t'||*buf==' ';buf++);
        while(((*buf!='\n')&&(*buf!='\t')&&(*buf!=' '))){*(c++)=*(buf++);}
        *c=0;
    }
}
struct Edge
{
	int to, cap, cost, rev;//终点，容量（指残量网络中的），费用，反向边编号
	Edge(int t, int c, int cc, int r) : to(t), cap(c), cost(cc), rev(r) {}
};
#define N 100030
#define INF 100000000
int V;//顶点数
vector<Edge>G[N];//图的邻接表
int h[N];//顶点的势
int dist[N];//最短距离
int prevv[N];//最短路中的父结点
int preve[N];//最短路中的父边

void addedge(int from, int to, int cap, int cost)
{
	G[from].push_back(Edge( to, cap, cost, G[to].size()));
	G[to].push_back(Edge( from, 0, -cost, G[from].size() - 1 ));
}
void init(int n)
{
	for(int i=0;i<=n+2;i++){
		G[i].clear();
	}
}
int MCMF(int s, int t, int f)//返回最小费用
{
	int res = 0;
	fill(h, h + V, 0);
	while (f > 0) //f>0时还需要继续增广
	{
		//cout<<"one zg"<<endl;
		priority_queue<P, vector<P>, greater<P> >q;
		fill(dist, dist + V, INF);//距离初始化为INF
		dist[s] = 0;
		q.push(P(0, s));
		while (!q.empty())
		{
			P p = q.top(); q.pop();
			int v = p.second;
			if (dist[v] < p.first)continue; //p.first是v入队列时候的值，dist[v]是目前的值，如果目前的更优，扔掉旧值
			for (int i = 0; i < G[v].size(); i++)
			{
				Edge&e = G[v][i];
				if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) //松弛操作
				{
					dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
					prevv[e.to] = v;//更新父结点
					preve[e.to] = i;//更新父边编号
					q.push(P(dist[e.to], e.to));
				}
			}
		}
		if (dist[t] == INF)//如果dist[t]还是初始时候的INF，那么说明s-t不连通，不能再增广了
			return -1;
		for (int j = 0; j < V; j++) //更新h
			h[j] += dist[j];
		int d = f;
		for (int x = t; x != s; x = prevv[x])
			d = min(d, G[prevv[x]][preve[x]].cap);//从t出发沿着最短路返回s找可改进量
		f -= d;
		res += d * h[t]; //h[t]表示最短距离的同时，也代表了这条最短路上的费用之和，乘以流量d即可得到本次增广所需的费用
		for (int x = t; x != s; x = prevv[x])
		{
			Edge&e = G[prevv[x]][preve[x]];
			e.cap -= d;//修改残量值
			G[x][e.rev].cap += d;
		}
	}
	return res;
}

int main()
{
    //freopen("data.in", "r", stdin);
    //cout<<2222<<endl;
    IO::init();
    //cout<<11111<<endl;
    int n, t;
    //scanf("%d", &t);
    IO::read1(t);
    //cout<<t<<endl;
    //cout<<1111<<endl;
    while (t--)
    {
        //scanf("%d", &n);
        IO::read1(n);
        //cout<<n<<endl;
        init(n);
        V=n+2;
        int s = 0, t = n + 1, cost;
        for (int i = 1; i <= n; i++)
        {
        	//cout<<2222<<endl;
            //scanf("%d", &cost);
            IO::read1(cost);
            addedge(s, i, 1, cost);
            addedge(i, t, 1, -cost);
        }
        for (int i = 1; i < n; i++) {
            int u, v, k;
            //scanf("%d%d%d", &u, &v, &k);
            IO::read1(u);
            IO::read1(v);
            IO::read1(k);
            addedge(u, v, INF, k);
            addedge(v, u, INF, k);
        }
        //cost = 0;
        
        printf("%d\n", -MCMF(s, t, 1));
        //IO::
    }
    return 0;
}