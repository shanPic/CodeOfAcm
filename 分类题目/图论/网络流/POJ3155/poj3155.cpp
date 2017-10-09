/*
* @FileName: D:\代码与算法\acm题目\图论\网络流\POJ3155\poj3155.cpp
* @Author: Pic
* @Created Time: 2017/9/28 21:00:43
*/
// 最大密度子图的模版题，具体思路见胡伯涛的论文
#include <bits/stdc++.h>
using namespace std;
int g;
const int MAXN = 5000+30;//点数的最大值
const int MAXM = 2000010;//边数的最大值,网络流要加反向边，数组开为n*n*2不会RE
const int INF = 0x3f3f3f3f;
int U=0;
struct Edge
{
	int to, next, cap, flow;
} edge[MAXM]; //注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];//gap[x]=y :说明残留网络中dep[i]==x的个数为y
void init()
{
	tol = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0)////加边，单向图三个参数，双向图四个参数
{
	edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
	edge[tol].next = head[u]; head[u] = tol++;
	edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
	edge[tol].next = head[v]; head[v] = tol++;
}
int Q[MAXN];
void BFS(int start, int end)
{
	memset(dep, -1, sizeof(dep));
	memset(gap, 0, sizeof(gap));
	gap[0] = 1;
	int front = 0, rear = 0;
	dep[end] = 0;
	Q[rear++] = end;
	while (front != rear)
	{
		int u = Q[front++];
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dep[v] != -1)continue;
			Q[rear++] = v;
			dep[v] = dep[u] + 1;
			gap[dep[v]]++;
		}
	}
}
int S[MAXN];
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start, int end, int N)
{
	BFS(start, end);
	memcpy(cur, head, sizeof(head));
	int top = 0;
	int u = start;
	int ans = 0;
	while (dep[start] < N)
	{
		if (u == end)
		{
			int Min = INF;
			int inser;
			for (int i = 0; i < top; i++)
				if (Min > edge[S[i]].cap - edge[S[i]].flow)
				{
					Min = edge[S[i]].cap - edge[S[i]].flow;
					inser = i;
				}
			for (int i = 0; i < top; i++)
			{
				edge[S[i]].flow += Min;
				edge[S[i] ^ 1].flow -= Min;
			}
			ans += Min;
			top = inser;
			u = edge[S[top] ^ 1].to;
			continue;
		}
		bool flag = false;
		int v;
		for (int i = cur[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
			{
				flag = true;
				cur[u] = i;
				break;
			}
		}
		if (flag)
		{
			S[top++] = cur[u];
			u = v;
			continue;
		}
		int Min = N;
		for (int i = head[u]; i != -1; i = edge[i].next)
			if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
			{
				Min = dep[edge[i].to];
				cur[u] = i;
			}
		gap[dep[u]]--;
		if (!gap[dep[u]])return ans;
		dep[u] = Min + 1;
		gap[dep[u]]++;
		if (u != start)u = edge[S[--top] ^ 1].to;
	}
	return ans;
}
void chuli(int round)
{
	for(int i=0;i<round;i++){
		e[i].flow=0;
	}
	for(int i=round;i<tot;i++){
		e[i].cap=g*deg[e[i].to]
	}
}
int deg[MAXN];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int u,v;
		U=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			deg[u]++,deg[v]++;
			addedge(u,v,1,1);
			U+=2;
		}
		int round=tot;

	}
	return 0;
}
