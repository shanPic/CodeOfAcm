/*
* @FileName: D:\代码与算法\acm题目\图论\最短路\Poj3463\poj3463.cpp
* @Author: Pic
* @Created Time: 2017/8/29 21:24:44
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=1000+30;
const int maxm=10000+30;
struct edge
{
	int to,w;
	int nxt;
	edge(){};
	edge(int _to,int _w,int _nxt):to(_to),w(_w),nxt(_nxt){};
}e[maxm];
int head[maxn],cnt=0;
void addedge(int from,int to,int w)
{
	e[cnt]=edge(to,w,head[from]);
	head[from]=cnt++;	
}
int dis[maxn][2],dp[maxn][2];
int vis[maxn];
void dj(int s)
{
	typedef pair<int,int> p;
	priority_queue<p> q;
	q.push(make_pair(0,s));
	dis[s][0]=0;
	dp[s][0]=1;
	dp[s][1]=1;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		int len,v;
		for(int i=head[u];i!=-1;i=e[i].nxt){
			len=e[i].w;
			v=e[i].to;
			int tmp=dis[u][0]+len;
			int tmpcnt=dp[u][0];
			if(dis[v][0]>tmp){
				swap(tmp,dis[v][0]);
				swap(tmpcnt,dp[v][0]);
				q.push(make_pair(-dis[v][0],v));
			}
			else if(dis[v][0]==tmp){
				dp[v][0]+=tmpcnt;
			}
			if(dis[v][1]>tmp){
				dis[v][1]=tmp;
				dp[v][1]=tmpcnt;
			//	q.push(make_pair(-dis[v][1],v));
			}
			else if(dis[v][1]==tmp){
				dp[v][1]+=tmpcnt;
			}
			if(dis[v][1]>dis[u][1]+len){
				dis[v][1]=dis[u][1]+len;
				dp[v][1]=dp[u][1];
			//	q.push(make_pair(-dis[v][1],v));
			}
			else if(dis[v][1]==dis[u][1]+len){
				dp[v][1]+=dp[u][1];
			}
		}	
	}	
}
void init()
{
	memset(head,-1,sizeof(head));
	cnt=0;
	memset(dis,0x3f,sizeof(dis));
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
}
int main()
{
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
 
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		int a,b,l;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&l);
			addedge(a,b,l);	
		}
		int s,f;
		scanf("%d%d",&s,&f);
		dj(s);
		if(dis[f][1]-dis[f][0]==1)
			printf("%d\n",dp[f][1]+dp[f][0]);
		else{
			printf("%d\n",dp[f][0]);
		}
	}
	return 0;
}
/*
3
5 8
1 2 3
1 3 2
1 4 5
2 3 1
2 5 3
3 4 2
3 5 4
4 5 3
1 5
5 6
2 3 1
3 2 1
3 1 10
4 5 2
5 2 7
5 2 7
4 1
5 6
1 2 4
1 3 2
1 4 4
3 2 3
4 2 1
2 5 10
1 5
*/
/*
 * 3
 * 2
 * 3
 */
