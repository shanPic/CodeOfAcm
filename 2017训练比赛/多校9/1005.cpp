/*
* @FileName: D:\代码与算法\2017训练比赛\多校9\1005.cpp
* @Author: Pic
* @Date:   2017-08-22 12:08:29
* @Last Modified time: 2017-08-22 12:58:30
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20010;//点数
const int MAXM = 50010;//边数
struct Edge
{
	int from;
	int to, next;
} edge[MAXM];
int head[MAXN], tot;
int Low[MAXN], DFN[MAXN], Stack[MAXN], Belong[MAXN]; //Belong数组的值是1~scc(注意这里，连通分量的最小编号为1)
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
vector<int> mp[2010];
int inq[MAXN],outq[MAXN];
void solve(int N)
{
	memset(DFN, 0, sizeof(DFN));
	memset(Instack, false, sizeof(Instack));
	memset(Belong,-1,sizeof(Belong));
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
bool topo()
{	
	queue<int> q;
	for(int i=1;i<=scc;i++){
		if(inq[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		if(q.size()>1){
			return 0;
		}
		int now=q.front();q.pop();
		int rou=mp[now].size();
		int y;
		for(int i=0;i<rou;i++){
			y=mp[now][i];
			inq[y]--;
			if(inq[y]==0){
				q.push(y);
			}
		}
	}
	return 1;
}
int main()
{
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		int x,y;
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		solve(n);
		for(int i=0;i<=scc;i++){
			mp[i].clear();
			mp[i].reserve(50);
		}
		memset(inq,0,sizeof(inq));
		memset(outq,0,sizeof(outq));
		// for(int i=1;i<=n;i++) cout<<Belong[i]<<"\t";
		// 	cout<<endl;
		for (int i = 0; i < tot; i++) {
			x = edge[i].from, y = edge[i].to;
			if(Belong[x]!=Belong[y]){
				mp[Belong[x]].push_back(Belong[y]);
				inq[Belong[y]]++;
				outq[Belong[x]]++;
			}
		}
		int flag=1;
		if(scc!=1){
			for(int i=1;i<=scc;i++){
				//cout<<inq[i]<<"\t"<<outq[i]<<endl;
				if(inq[i]==0&&outq[i]==0){
					flag=0;
					break;
				}
			}
		}
		if(!flag){
			printf("Light my fire!\n");
			continue;
		}
		if(topo()){
			printf("I love you my love and our love save us!\n");
		}
		else{
			printf("Light my fire!\n");
		}
	}
}	