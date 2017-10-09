/*
* @FileName: D:\代码与算法\2017训练比赛\9.10沈阳网络赛\1008-pro.cpp
* @Author: Pic
* @Date:   2017-09-10 13:46:54
* @Last Modified time: 2017-09-10 14:17:26
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef long long LL;

const int maxN = 100000 + 30;
const int maxM = maxN * 2;

struct edge
{
	int to;
	int next;
	int cap;
	int cost;
} e[maxM];

int head[maxN], tot;
int d[maxN], pre[maxN], path[maxN];
bool vis[maxN];

void init()
{
	memset(head, -1, sizeof(head));
	tot = 0;
}

void addedge(int s, int t, int cap, int cost)
{
	e[tot].to = t; e[tot].cap = cap; e[tot].cost = cost; e[tot].next = head[s]; head[s] = tot++;
	e[tot].to = s; e[tot].cap = 0; e[tot].cost = -cost; e[tot].next = head[t]; head[t] = tot++;
}

int spfa(int s, int t)
{
	memset(d, -INF, sizeof(d));
	//memset(pre, -1, sizeof(pre));
	//memset(path, -1, sizeof(path));
	pre[s]=-1;
	memset(vis, false, sizeof(vis));
	int res = d[0];
	d[s] = 0;
	vis[s] = true;
	queue<int>q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].next)
		{
			int v = e[i].to;
			if (d[v] < d[u] + e[i].cost && e[i].cap > 0)
			{
				d[v] = d[u] + e[i].cost;
				pre[v] = u;
				path[v] = i;
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return d[t] != res;
}

void MCMF(int s, int t, int &cost)
{
	cost = 0;
	while (spfa(s, t))
	{
		int minn = INF;
		for (int i = t; i != s && ~i; i = pre[i])
			minn = min(minn, e[path[i]].cap);
		for (int i = t; i != s && ~i; i = pre[i])
		{
			e[path[i]].cap -= minn;
			e[path[i] ^ 1].cap += minn;
		}
		if (d[t] < 0)
			break;
		cost += minn * d[t];
	}
}

int main()
{
	//freopen("data.in", "r", stdin);
	int n, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		init();
		int s = 0, t = n + 1, cost;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &cost);
			addedge(s, i, 1, -cost);
			addedge(i, t, 1, cost);
		}
		for (int i = 1; i < n; i++) {
			int u, v, k;
			scanf("%d%d%d", &u, &v, &k);
			addedge(u, v, INF, -k);
			addedge(v, u, INF, -k);
		}
		cost = 0;
		MCMF(s, t, cost);
		printf("%d\n", cost);
	}
	return 0;
}