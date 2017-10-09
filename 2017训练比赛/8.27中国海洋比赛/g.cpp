/* * @FileName: D:\代码与算法\2017训练比赛\8.27中国海洋比赛\g.cpp
* @Author: Pic
* @Created Time: 2017/8/27 13:53:05
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=50+3;
struct edge
{
	int from,to,nxt;
	edge(){};
	edge(int _to,int _nxt):to(_to),nxt(_nxt){};
}e[2500+30];
int head[MAXN];int cnt=0; 
void addedge(int from,int to)
{
	e[cnt].from=from;
	e[cnt].to=to,e[cnt].nxt=head[from];
	head[from]=cnt;
	cnt++;
}
double dis[MAXN];
int N;
int flag[MAXN],outq[MAXN];
int vis[MAXN];
double tmp=0;
void dj()
{
	typedef pair<double,int> p;
	priority_queue<p> q;
    for(int i=0;i<=N;i++) dis[i]=0;	
	memset(vis,0,sizeof(vis));
	q.push(make_pair(1.0,1));
	dis[1]=1;
	int v;
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(!vis[now]){
			vis[now]=1;
			for(int i=head[now];i!=-1;i=e[i].nxt){
				if(flag[i]==1){
					v=e[i].to;
					double dist=dis[now]*(1.0/(double)outq[now]);
					if(dist>dis[v]){
						dis[v]=dist;
						q.push(make_pair(dis[v],v));
					}
					if(v==N){
						tmp+=dist;
					}
				}
			}
		}
	}
}
void init()
{
	memset(outq,0,sizeof(outq));
	cnt=0;
	memset(head,-1,sizeof(head));	
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	 int t;
	 scanf("%d",&t);
	 int ca=0;
	 while(t--){
		 int m;
		scanf("%d%d",&N,&m);
		int x,y;
		init();
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			addedge(x,y);
			outq[x]++;	
			flag[i]=1;
		}
		tmp=0;
		dj();
		double ans=tmp;
		for(int i=0;i<m;i++){
			outq[e[i].from]--;
			flag[i]=0;
			tmp=0;
			dj();
			ans=max(ans,tmp);
			outq[e[i].from]++;
			flag[i]=1;
		}
		printf("Case #%d: %.06f\n",++ca,ans);
	 }
	return 0;
}
