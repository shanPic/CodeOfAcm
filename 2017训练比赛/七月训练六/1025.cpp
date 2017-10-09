/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练六\1025.cpp
* @Author: Pic
* @Date:   2017-08-07 16:16:04
* @Last Modified time: 2017-08-08 11:05:00
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN = 50000 + 30;

//调试函数
void prt(int x)
{
	for (int i = 0; i < 7; i++) printf("%d", x);
	printf("\n");
}
//存储边部分
struct Edge
{
	int b, nxt;
	Edge() {};
	Edge(int b): b(b), nxt(-1) {};
} edge[MAXN*2];
int heade[MAXN];
int cnte = 0;
void addEdge(int a, int b)
{
	edge[cnte] = Edge(b);
	edge[cnte].nxt = heade[a];
	heade[a] = cnte++;
}
void initEdge()
{
	memset(heade, -1, sizeof(heade));
	cnte = 0;
}
//并查集部分
int fa[MAXN], maxp[MAXN], minp[MAXN];
int up[MAXN], down[MAXN];
int find(int i)
{
	//prt(3);
	if (fa[i] == -1) {
		return i;
	}
	else {
		int tmp = find(fa[i]);
		up[i] = max(up[i],max(maxp[fa[i]] - minp[i], up[fa[i]]));
		down[i] = max(down[i],max(maxp[i] - minp[fa[i]], down[fa[i]]));
		//up[i] =max(maxp[fa[i]] - minp[i], up[fa[i]]);
		//down[i] = max(maxp[i] - minp[fa[i]], down[fa[i]]);
		maxp[i] = max(maxp[i], maxp[fa[i]]);
		minp[i] = min(minp[i], minp[fa[i]]);

		fa[i] = tmp;
		return fa[i];
	}
}
void merge(int a, int b) //a为下层节点，b为上层节点
{
	//prt(4);
	int faa = find(a), fab = find(b);
	if (faa != fab) {
		up[faa] = max(up[faa],max(maxp[b] - minp[faa], up[b]));
		down[faa] = max(down[faa],max(maxp[faa] - minp[b], down[b]));
		minp[faa] = min(minp[faa], minp[b]);
		maxp[faa] = max(maxp[faa], maxp[b]);
		fa[faa] = b;
	}
}
void initBC()
{
	memset(fa, -1, sizeof(fa));
	memset(up, 0, sizeof(up));
	memset(down, 0, sizeof(down));
}
//存储查询部分
vector<int> ask[MAXN];
vector<int> pos[MAXN];
//LCA部分
int vis[MAXN];
vector<int> asRoot[MAXN];
struct Res
{
	int u, v;
	int res;
} res[MAXN];
// map<int,pair<int,int> > res;
//int cntres = 0;
void LCA(int x, int faa)
{
	//prt(1);
	int y;	

	vis[x] = 1;
	int coun=ask[x].size();
	int id;
	int lca=find(x);
	for(int i=0;i<coun;i++){
		y=ask[x][i];
		id=pos[x][i];
		lca=find(y);
		if(vis[y]){
			if(id>0){
				asRoot[lca].push_back(id);
				res[id].u=x,res[id].v=y;
			}
			else{
				id=-1*id;
				asRoot[lca].push_back(id);
				res[id].u=y,res[id].v=x;
			}
		}
	}

	for (int i = heade[x]; i != -1; i = edge[i].nxt) {
		// printf("%d   %d\n",x,fa);
		//prt(5);
		y = edge[i].b;
		if (y != faa) {
			//prt(6);
			LCA(y, x);
			//merge(y, x);
			fa[y]=x;
		}
	}

	//prt(2);
	int roud = asRoot[x].size();
	int minv, minu, maxv,maxu, u, v, upu, upv, downu, downv;
	for (int i = 0; i < roud; i++) {
		id = asRoot[x][i];
		u = res[id].u, v = res[id].v;
		find(u);find(v);
		maxv=maxp[v];minu=minp[u];
		upu=up[u];downv=down[v];
		int resn = max(maxv - minu, max(upu, downv));
		res[id].res = resn;
	}
}
//int q[MAXN][MAXN];
void init(int n)
{
	initEdge();
	initBC();
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++){
			asRoot[i].clear();
			asRoot[i].reserve(33);
			ask[i].clear();
			pos[i].clear();
			ask[i].reserve(33);
			pos[i].reserve(33);
	}
}
int main() {
	//freopen("data.in", "r", stdin);
	int n;
	while (~scanf("%d", &n)) {
		init(n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &maxp[i]);
			minp[i] = maxp[i];
		}
		int x, y;
		for (int i = 0; i < n - 1 ; ++i)
		{
			scanf("%d%d", &x, &y);
			addEdge(x, y);
			addEdge(y, x);
		}
		int qn;
		scanf("%d", &qn);
		for (int i = 1; i <= qn; i++) {
			scanf("%d%d", &x, &y);
			ask[x].push_back(y);
			pos[x].push_back(i);
			ask[y].push_back(x);
			pos[y].push_back(-1*i);
		}
		//prt(heade[4]);
		LCA(1, 0);
		for(int i=1;i<=qn;i++){
			printf("%d\n",res[i].res);
		}
	}
	return 0;
}