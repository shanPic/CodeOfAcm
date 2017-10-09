#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const int MAXM = 100010;
struct Edge
{
	int to, next;
	bool cut;//是否为桥的标记
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN];	//low记录了某个点能到达的最晚标号
int DFN[MAXN];	//某个点遍历到的标号
int Index, top;	//DFS的时钟
bool cut[MAXN];		//记录某个点是否是割顶
int add_block[MAXN]; //删除一个点后增加的连通块
int bridge;
void addedge(int u, int v)
{
	edge[tot].to = v; edge[tot].next = head[u]; edge[tot].cut = false;
	head[u] = tot++;
}
void Tarjan(int u, int pre,int f)
{
    //cout<<333333<<endl;
	int v;

	Low[u] = DFN[u] = ++Index;

	int son = 0;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].to;
		if (v == pre)continue;
		if (v == f) continue;
		if ( !DFN[v] )
		{
			son++;
			Tarjan(v, u,f);
			if (Low[u] > Low[v]) Low[u] = Low[v];
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

}
int solve(int N)
{
    int ori=0;
    int ans = -1;
    for(int j=0;j<N;j++){
        ori=0;
        memset(DFN,0,sizeof(DFN));
        memset(add_block,0,sizeof(add_block));
        memset(cut,false,sizeof(cut));
        Index = top = 0;
        bridge = 0;
        for(int i = 0;i< N;i++)
           if(i!=j&&!DFN[i]){
            ori++;
            Tarjan(i,i,j);
           }
        for(int i = 0;i <N;i++){
            if(i!=j)
                ans=max(ans,add_block[i]+ori);
        }
    }
    return ans;
}

int main()
{
    int n,m;
    int u,v;
    while(~scanf("%d%d",&n,&m)){
        memset(head,-1,sizeof(head));
        tot=0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        printf("%d\n",solve(n));
    }
}
