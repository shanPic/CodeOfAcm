/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练六\1021.cpp
* @Author: Pic
* @Date:   2017-08-11 20:03:33
* @Last Modified time: 2017-08-12 21:22:08
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
void addedge(int u, int v)
{
	edge[tot].to = v^1 ; edge[tot].next = head[u]; head[u] = tot++;
	edge[tot].to = u^1 ; edge[tot].next = head[v]; head[v] = tot++;
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
bool solve(int N)
{
	memset(DFN, 0, sizeof(DFN));
	memset(Instack, false, sizeof(Instack));
	Index = scc = top = 0;
	for (int i = 0; i < N; i++)
		if (!DFN[i])
			Tarjan(i);
	for(int i = 0; i < N; i+=2){
		if (Belong[i] == Belong[i^1])
			return false;
	}
	return true;
}
void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}
int main(){
	//freopen("data.in","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		init();
		int x,y,c;
		char str[33];
		for(int i=0;i<m;i++){
			scanf("%d %d %d %s",&x,&y,&c,str);
			x*=2,y*=2;
			switch(str[0]){
				case 'A':{
					if(c){
						addedge(x,y^1);addedge(x^1,y);addedge(x^1,y^1);
					}
					else{
						addedge(x,y);
					}
					break;
				}
				case 'O':{
					if(c){
						addedge(x^1,y^1);
					}
					else{
						addedge(x^1,y);addedge(x,y^1);addedge(x,y);
					}
					break;
				}
				case 'X':{
					if(c){
						addedge(x,y);addedge(x^1,y^1);
					}
					else{
						addedge(x^1,y);addedge(x,y^1);
					}
					break;
				}
			}
		}
		bool ans=solve(n*2);
		if(ans){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
    return 0;
}