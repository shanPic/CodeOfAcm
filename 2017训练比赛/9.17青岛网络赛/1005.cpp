/*
* @FileName: D:\代码与算法\2017训练比赛\9.17青岛网络赛\1005.cpp
* @Author: Pic
* @Created Time: 2017/9/17 12:05:52
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge

	int to, next, cap, flow, cost;
} edge[MAXM];
int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
	N = n;
	tol = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int cap, int cost)
{
	edge[tol].to = v;
	edge[tol].cap = cap;
	edge[tol].cost = cost;
	edge[tol].flow = 0;
	edge[tol].next = head[u];
	head[u] = tol++;
	edge[tol].to = u;
	edge[tol].cap = 0;
	edge[tol].cost = -cost;
	edge[tol].flow = 0;
	edge[tol].next = head[v];
	head[v] = tol++;
}
bool spfa(int s, int t)
{
	queue<int>q;
	for (int i = 0; i < N; i++)
	{
		dis[i] = INF;
		vis[i] = false;
		pre[i] = -1;
	}
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	while (!q.empty())
	{
		//cout<<4444<<endl;
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			
			int v = edge[i].to;
			if (edge[i].cap > edge[i].flow &&
			        dis[v] > dis[u] + edge[i].cost )
			{
				dis[v] = dis[u] + edge[i].cost;
				pre[v] = i;
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if (pre[t] == -1)return false;
	else return true;
}
//返回的是最大流， cost存的是最小费用
int minCostMaxflow(int s, int t, int &cost)
{
	int flow = 0;
	cost = 0;
	while (spfa(s, t))
	{
		cout<<33333<<endl;
		int Min = INF;
		for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
		{
			if (Min > edge[i].cap - edge[i].flow)
				Min = edge[i].cap - edge[i].flow;
		}
		for (int i = pre[t]; i != -1; i = pre[edge[i ^ 1].to])
		{
			edge[i].flow += Min;
			edge[i ^ 1].flow -= Min;
			cost += edge[i].cost * Min;
		}l
		flow += Min;
	}
	return flow;
};
char mp[13][13];
inline bool ok(int x,int y)
{
	if(x>=8||x<0||y>=8||y<0) return 0;
	if(mp[x][y]=='O') return 0;
	return 1;
}
int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
 	int t;
	scanf("%d",&t);
	while(t--){
		getchar();
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				scanf("%c",&mp[i][j]);
			}
			getchar();
		}

		int s=64*2;
		int t=s+1;
		init(t+1);
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(mp[i][j]!='O'){
					addedge(i*8+j,i*8+j+64,1,-1);
					if(mp[i][j]=='K'){
						addedge(s,i*8+j,INF,0);
					}
					else 
						addedge(i*8+j+64,t,INF,0);

					if(ok(i,j+1)){
						addedge(i*8+j+64,i*8+j+1,1,0);
						addedge(i*8+j+1+64,i*8+j,1,0);
					}
					if(ok(i+1,j)){
						addedge(i*8+j+64,(i+1)*8+j,1,0);
						addedge((i+1)*8+j+64,i*8+j,1,0);
					}
					if(ok(i+1,j+1)){
						addedge(i*8+j+64,(i+1)*8+j+1,1,0);
						addedge((i+1)*8+j+1+64,i*8+j,1,0);
					}
				}
			}
		}
	//	sap(s,t,t+1);
		int res=0;
		cout<<1111<<endl;
		minCostMaxflow(s,t,res);
		printf("%d\n",-res);
			//	memset(vis,0,sizeof(vis));
		//int res=0;
		//for(int i=0;i<tol;i++){
		//	if(edge[i].from!=s&&edge[i].to!=s&&edge[i].from!=t&&edge[i].to!=t&&edge[i].to-edge[i].from==64){
				//cout<<11111<<endl;
		//		if(edge[i].cap==0){
		//			//vis[min(edge[i].from,edge[i].to)]=1;
		//			res++;
		//		}
		//	}
		//}
		//printf("%d\n",res);
	}
	return 0;
}
