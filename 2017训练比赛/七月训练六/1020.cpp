/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练六\1020.cpp
* @Author: Pic
* @Date:   2017-08-11 09:50:29
* @Last Modified time: 2017-08-11 21:18:57
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
/*
* Tarjan算法
* 复杂度O(N+M)
*/
const int MAXN = 200;//点数
const int MAXM = 50300;//边数
struct Edge
{
	int from,to, next;
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN]; //Belong数组的值是1~scc
int Index, top;
int scc;//强连通分量的个数
bool Instack[MAXN];
//int num[MAXN];//各个强连通分量包含点的个数，数组编号1~scc
//num数组不一定需要，结合实际情况
void addedge(int u, int v)
{
	edge[tot].from=u; edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
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
	for (int i = 1; i <= N; i++)
		if (!DFN[i])
			Tarjan(i);
}
int dout[MAXN],din[MAXN];
void sd()
{
	int x,y;
	for(int i=0;i<tot;++i){
		x=edge[i].from;y=edge[i].to;
		if(Belong[x]!=Belong[y]){
		//cout<<i<<"\t"<<Belong[x]<<"\t"<<Belong[y]<<endl;
			dout[Belong[x]]++;
			din[Belong[y]]++;
		}
	}
}
void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
	memset(din,0,sizeof(din));
	memset(dout,0,sizeof(dout));
}
int main() {
	//freopen("data.in","r",stdin);
	int n;
	//char str[MAXN*3];
	while(~scanf("%d",&n)){
		init();
		int x;
		for(int i=1;i<=n;i++){
			while(~scanf("%d",&x)&&x){
				addedge(i,x);
			}
		}
		solve(n);
		if(scc==1){
			printf("1\n0\n");
			continue;
		}
		sd();
		int ares=0,bres=0;
		for(int i=1;i<=scc;i++){
			if(din[i]==0){
				ares++;
			}
			if(dout[i]==0){
				bres++;
			}
		}
		bres=max(ares,bres);
		printf("%d\n%d\n",ares,bres);
	}
	return 0;
}