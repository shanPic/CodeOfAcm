/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练三\1002-pro.cpp
* @Author: Pic
* @Date:   2017-07-21 21:40:00
* @Last Modified time: 2017-07-22 13:38:37
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 5000+30;//点数的最大值
const int MAXM = 2000010;//边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge
{
	int to, next, cap, flow;
} edge[MAXM]; //注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];
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
int sap(int start, int end, int N)//输入参数：起点、终点、点的总数
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
int ma[MAXN],mi[MAXN];
int spf[MAXN],cnt[MAXN];
int main()  
{  
	//freopen("data.in","r",stdin);
	int c,l;
	while(~scanf("%d%d",&c,&l)){
		//DC.init(l+c+2,1,l+c+2); //初始化，参数分别为：点的个数，源点标号，汇点标号
		init();
		for(int j=1;j<=c;j++){
			scanf("%d%d",&mi[j],&ma[j]);
		}
		for(int i=1;i<=l;i++){
			scanf("%d%d",&spf[i],&cnt[i]);
		}
		for(int i=1;i<=l;i++){
			addedge(0,i,cnt[i]);
			for(int j=1;j<=c;j++){
				if(mi[j]<=spf[i]&&ma[j]>=spf[i]){
					addedge(i,j+l,1);
				}
			}
		}
		for(int j=1;j<=c;j++){
			//DC.AddEdge(j+l+1,l+c+2,1);
			addedge(j+l,l+c+1,1);
		}
		//printf("%d\n",DC.Maxflow());  
		printf("%d\n",sap(0,l+c+1,l+c+2));
	}
	return 0;  
}  