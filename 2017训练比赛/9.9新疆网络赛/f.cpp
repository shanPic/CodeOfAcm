/*
* @FileName: D:\代码与算法\2017训练比赛\9.9新疆网络赛\f.cpp
* @Author: Pic
* @Created Time: 2017/9/9 12:11:47
*/
#include <bits/stdc++.h>
using namespace std;
/*
* 有向图的强连通分量的Tarjan算法
* 复杂度O(N+M)
*/
const int MAXN = 10500;//点数
const int MAXM = 100500;//边数
struct Edge
{
	int from;
	int to, next;
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN]; //Belong数组的值是1~scc(注意这里，连通分量的最小编号为1)
int degin[MAXN],degout[MAXN];
int Index, top;
int scc;//强连通分量的个数
bool Instack[MAXN];
//int num[MAXN];//各个强连通分量包含点的个数，数组编号1~scc
//num数组不一定需要，结合实际情况
void addedge(int u, int v)
{
	edge[tot].from=u;
	edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
}
void Tarjan(int u)
{
	int v;
	Low[u] = DFN[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = true;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].to;
		if ( !DFN[v] )
		{
			Tarjan(v);
			if ( Low[u] > Low[v] )Low[u] = Low[v];
		}
		else if (Instack[v] && Low[u] > DFN[v])
			Low[u] = DFN[v];
	}
	if (Low[u] == DFN[u])
	{
		scc++;
		do
		{
			v = Stack[--top];
			Instack[v] = false;
			Belong[v] = scc;
			//num[scc]++;
		}
		while ( v != u);
	}
}
void solve(int N)
{
	memset(DFN, 0, sizeof(DFN));
	memset(Instack, false, sizeof(Instack));
	//memset(num, 0, sizeof(num));
	Index = scc = top = 0;
	for (int i = 1; i <= N; i++)	//注意，此模版点的标号是从1开始的
		if (!DFN[i])
			Tarjan(i);
}
void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t; 
	scanf("%d",&t);
	while(t--){
		init();
		int n,m;
		int u,v;
		scanf("%d%d",&n,&m);
		if(n<=1){
			printf("0\n");
			continue;
		}
		for(int	i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}
		solve(n);
		if(scc==1){
			printf("0\n");
			continue;
		}
		memset(degin,0,sizeof(degin));
		memset(degout,0,sizeof(degout));
		for(int i=0;i<tot;i++){
			u=edge[i].from;v=edge[i].to;
			if(Belong[u]!=Belong[v]){
				degout[Belong[u]]++;
				degin[Belong[v]]++;
			}
		}
		int numin=0,numout=0;
		for(int i=1;i<=scc;i++){
			if(degout[i]==0){
				numout++;
			}
			if(degin[i]==0){
				numin++;
			}
		}
		printf("%d\n",max(numout,numin));
	}
	return 0;
}
