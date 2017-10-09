#include<bits/stdc++.h>
using namespace std;
const int MAXN = 53000+30;
const int MAXM = 100010;
struct Edge
{
	int to, next;
	bool cut;//是否为桥的标记
} edge[MAXM];

int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值是1~block
int Index,top;
int block;//边双连通块数
bool Instack[MAXN];
int bridge;//桥的数目

void addedge(int u, int v)
{
	edge[tot].to = v; edge[tot].next = head[u]; edge[tot].cut = false;
	head[u] = tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if(v == pre )continue;
        if( !DFN[v] )
        {
            Tarjan(v,u);
            if( Low[u] > Low[v] )Low[u] = Low[v];
            if(Low[v] > DFN[u])
            {
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
        }
        else if( Instack[v] && Low[u] > DFN[v] )
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        block++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = block;
        }
        while( v!=u );
    }
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void solve()
{
	//初始化操作
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    Index = top = block = 0;
    memset(Belong,0,sizeof(Belong));
	memset(head,-1,sizeof(head)); tot=0;
    Index = top = 0;
    bridge = 0;
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        addedge(u,v);
        addedge(v,u);
    }
    for(int i = 1;i <= n;i++)
       if(!DFN[i])
          Tarjan(i,i);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        if(Belong[u]==Belong[v]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    solve();
}
