/*
* @FileName: D:\代码与算法\acm题目\图论\桥-割点-边或点双联通分量-强连通分量\bzoj1015\bzoj1015.cpp
* @Author: Pic
* @Created Time: 2017/9/8 17:02:38
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const int MAXM = 100010;
struct Edge
{
	int to, next;
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN];	//low记录了某个点能到达的最晚标号
int DFN[MAXN];	//某个点遍历到的标号
//int Stack[MAXN];
int Index, top;	//DFS的时钟
//bool Instack[MAXN];
bool cut[MAXN];		//记录某个点是否是割顶
int add_block[MAXN]; //删除一个点后增加的连通块
//int bridge;
void addedge(int u, int v)
{
	edge[tot].to = v; edge[tot].next = head[u]; //edge[tot].cut = false;
	head[u] = tot++;
}
void Tarjan(int u, int pre,int preEdge)
{
	int v;

	Low[u] = DFN[u] = ++Index;

	//Stack[top++] = u;
	//Instack[u] = true;

	int son = 0;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].to;
		if (v == pre)continue;
		if((i^1)==preEdge) continue;
		if ( !DFN[v] )
		{
			son++;
			Tarjan(v, u, i);
			if (Low[u] > Low[v])Low[u] = Low[v];
			//割点
			//一个顶点u是割点，当且仅当满足(1)或(2) (1) u为树根，且u有多于一个子树。
			//(2) u不为树根，且满足存在(u,v)为树枝边(或称父子边，
			//即u为v在搜索树中的父亲)，使得DFS(u)<=Low(v)
			if (u != pre && Low[v] >= DFN[u]) //不是树根
			{
				cut[u] = true;
				add_block[u]++;
			}
		}
		else if ( Low[u] > DFN[v])	//!!!
			Low[u] = DFN[v];
	}
	//树根，分支数大于1
	if (u == pre && son > 1)cut[u] = true;
	if (u == pre)add_block[u] = son - 1;

	//Instack[u] = false;
	//top--;

}
int solve(int N)
{
	//初始化操作
    memset(DFN,0,sizeof(DFN));
    memset(add_block,0,sizeof(add_block));
    memset(cut,false,sizeof(cut));
    Index = top = 0;
    int ans = 0;
    for(int i = 0;i < N;i++)
		if(!DFN[i]){
			Tarjan(i,i,-1);
			ans++;
		}
	return ans;
    //printf("%d\n",ans);
}
int main()
{
	freopen("data.in","r",stdin);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int u,v;
			memset(head,-1,sizeof(head)); tot=0;
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);	
		}
		int ans=solve(n);
		int k;
		scanf("%d",&k);
		int x;
		for(int i=0;i<k;i++){
			scanf("%d",&x);
			cout<<add_block[x]<<endl;
			ans=ans+add_block[x];

			printf("%d\n",ans);
		}

	}
}
