/*
* @FileName: D:\代码与算法\POJ\poj1446\poj1446-2.cpp
* @Author: Pic
* @Date:   2017-08-17 10:23:44
* @Last Modified time: 2017-08-17 10:25:12
*/
#include <bits/stdc++.h>
using namespace std;
 
////////////////////////最大流开始//////////////////////////////////////
#define MAX_V 500 + 16
int V;                 // 顶点数
vector<int> G[MAX_V];    // 图的邻接表
int match[MAX_V];      // 所匹配的顶点
bool used[MAX_V];      // DFS中用到的访问标记
 
// 向图中增加一条连接u和v的边
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
 
// 通过DFS寻找增广路
bool dfs(int v)
{
	used[v] = true;
	for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); ++it)
	{
		int u = *it, w = match[u];
		if (w < 0 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
 
	return false;
}
 
// 求解二分图的最大匹配
int bipartite_matching()
{
	int res = 0;
	memset(match, -1, sizeof(match));
	for (int v = 0; v < V; ++v)
	{
		if (match[v] < 0)
		{
			memset(used, 0, sizeof(used));
			if (dfs(v))
			{
				++res;
			}
		}
	}
 
	return res;
}
 
void clear()
{
	for (int i = 0; i < V; ++i)
	{
		G[i].clear();
	}
}
 
///////////////////////////////最大流结束/////////////////////////////////////
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	//freopen("data.in", "r", stdin);
	freopen("data.in","r",stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &V) != EOF)
	{
		clear();
		for (int i = 0; i < V; ++i)
		{
			int v, m, u;
			scanf("%d: (%d)", &v, &m);
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &u);
				G[v].push_back(u);
			}
		}
		printf("%d\n", V - bipartite_matching());
	}
	return 0;
}