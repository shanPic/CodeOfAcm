/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练六\1022.cpp
* @Author: Pic
* @Date:   2017-08-12 21:04:06
* @Last Modified time: 2017-08-12 22:08:48
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN = 20010;//点数
const int MAXM = 50010;//边数
struct Edge
{
	int to, next;
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN]; //Belong数组的值是1~scc(注意这里，连通分量的最小编号为1)
int Index, top;
int scc;//强连通分量的个数
bool Instack[MAXN];
int key[MAXN],door[MAXN];
void addedge(int u, int v)
{
	edge[tot].to = v ; edge[tot].next = head[u]; head[u] = tot++;
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
		}
		while ( v != u);
	}
}
void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}
bool solve(int N,int k)
{
	init();
	for(int i=0;i<N;i++){
		addedge(key[door[i*2]],door[i*2+1]);
		addedge(key[door[i*2+1]],door[i*2]);
	}
	memset(DFN, 0, sizeof(DFN));
	memset(Instack, false, sizeof(Instack));
	Index = scc = top = 0;
	for (int i = 0; i < N; i++)
		if (!DFN[i])
			Tarjan(i);
	for(int i = 0; i < k; i++){
		if (Belong[i] == Belong[key[i]])
			return false;
	}
	return true;
}
int main(){
	//freopen("data.in","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		//cout<<1111<<endl;
		if(n==0&&m==0) break;
		int x,y;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			key[x]=y;
			key[y]=x;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&door[i*2],&door[i*2+1]);
		}
		int l=0,r=m,mid;
		while(r-l>1){
			mid=(r+l)/2;
			if(solve(mid,n)){
				l=mid;
			}
			else{
				r=mid;
			}
		}
		printf("%d\n",l);
	}
    return 0;
}