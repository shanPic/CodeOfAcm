/*
* @FileName: D:\代码与算法\2017训练比赛\网络流24题（LOJ）\太空飞行计划.cpp
* @Author: Pic
* @Date:   2017-08-14 15:08:19
* @Last Modified time: 2017-08-14 16:18:20
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000+30;//点数的最大值
const int MAXM = 2000010;//边数的最大值,网络流要加反向边，数组开为n*n*2不会RE
const int INF = 0x3f3f3f3f;
struct Edge
{
	int to, next, cap, flow;
} edge[MAXM]; //注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], cur[MAXN];
void init()
{
	tol = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0)////加边，单向图三个参数，双向图四个参数
{
	edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
	edge[tol].next = head[u]; head[u] = tol++;
	edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
	edge[tol].next = head[v]; head[v] = tol++;
}
int Q[MAXN];
void BFS(int start, int end)
{
	memset(dep, -1, sizeof(dep));
	memset(gap, 0, sizeof(gap));
	gap[0] = 1;
	int front = 0, rear = 0;
	dep[end] = 0;
	Q[rear++] = end;
	while (front != rear)
	{
		int u = Q[front++];
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dep[v] != -1)continue;
			Q[rear++] = v;
			dep[v] = dep[u] + 1;
			gap[dep[v]]++;
		}
	}
}
int S[MAXN];
//输入参数：起点、终点、点的总数
//点的编号没有影响，只要输入点的总数
int sap(int start, int end, int N)
{
	BFS(start, end);
	memcpy(cur, head, sizeof(head));
	int top = 0;
	int u = start;
	int ans = 0;
	while (dep[start] < N)
	{
		if (u == end)
		{
			int Min = INF;
			int inser;
			for (int i = 0; i < top; i++)
				if (Min > edge[S[i]].cap - edge[S[i]].flow)
				{
					Min = edge[S[i]].cap - edge[S[i]].flow;
					inser = i;
				}
			for (int i = 0; i < top; i++)
			{
				edge[S[i]].flow += Min;
				edge[S[i] ^ 1].flow -= Min;
			}
			ans += Min;
			top = inser;
			u = edge[S[top] ^ 1].to;
			continue;
		}
		bool flag = false;
		int v;
		for (int i = cur[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].to;
			if (edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u])
			{
				flag = true;
				cur[u] = i;
				break;
			}
		}
		if (flag)
		{
			S[top++] = cur[u];
			u = v;
			continue;
		}
		int Min = N;
		for (int i = head[u]; i != -1; i = edge[i].next)
			if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
			{
				Min = dep[edge[i].to];
				cur[u] = i;
			}
		gap[dep[u]]--;
		if (!gap[dep[u]])return ans;
		dep[u] = Min + 1;
		gap[dep[u]]++;
		if (u != start)u = edge[S[--top] ^ 1].to;
	}
	return ans;
}
set<int> sy,yq;
int m,n;
int vis[MAXN];
void dfs(int x,int fa)
{
	//cout<<"flag"<<endl;
	vis[x]=1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int v=edge[i].to;
		if(v!=fa&&vis[v]==0){
			if(edge[i].cap>edge[i].flow){
				if(v<=m) sy.insert(v);
				else yq.insert(v-m);
				dfs(v,x);
			}
		}
	}
}
int main(){
	//freopen("data.in","r",stdin);
	init();
	//scanf("%d%d",&m,&n);
	cin>>m>>n;
	string str;
	int sum=0;
	getchar();
	for(int i=1;i<=m;i++){
		getline(cin,str);
		//cout<<str<<endl;
		stringstream sstr(str);
		int x,y;
		sstr>>x;
		//cout<<x<<endl;
		addedge(0,i,x);
		sum+=x;
		while(sstr>>y){
			addedge(i,y+m,INF);
		}
	}
	int w;
	for(int i=1+m;i<=n+m;i++){
		cin>>w;
		addedge(i,m+n+1,w);
	}
	int res=sap(0,m+n+1,m+n+2);
	//cout<<res<<endl;
	res=sum-res;
	dfs(0,0);
	for(auto ite=sy.begin();ite!=sy.end();ite++){
		cout<<*ite<<" ";
	}
	cout<<endl;
	for(auto ite=yq.begin();ite!=yq.end();ite++){
		cout<<*ite<<" ";
	}
	cout<<endl;
	cout<<res<<endl;
    return 0;
}