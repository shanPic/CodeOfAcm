/*
* @FileName: D:\代码与算法\BZOJ\1003\1003-pro.cpp
* @Author: Pic
* @Date:   2017-08-18 20:47:51
* @Last Modified time: 2017-08-19 11:55:29
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=100+30;
int inq[MAXN];
int mp[MAXN];
int dis[MAXN];
struct edge
{
	int to,nxt;
	int w;
}es[MAXN*MAXN*2];
int head[MAXN];
int cnt=0;
void init()
{
	memset(head,-1,sizeof(head));
	cnt=0;
}
void addedge(int from,int to,int w)
{
	es[cnt].to=to,es[cnt].w=w;
	es[cnt].nxt=head[from];
	head[from]=cnt;
	cnt++;
}
int spfa(int s,int t)
{
	memset(inq,0,sizeof(inq));memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(s);
	dis[s]=0;
	inq[s]=1;
	while(!q.empty()){
		//cout<<1111111<<endl;
		int now=q.front();q.pop();
		inq[now]=0;
		for(int i=head[now];i!=-1;i=es[i].nxt){
			//cout<<2222<<endl;
			edge &e=es[i];
			if(!mp[e.to]&&dis[now]+e.w<dis[e.to]){
				dis[e.to]=dis[now]+e.w;
				if(!inq[e.to]){
					q.push(e.to);
					inq[e.to]=1;
				}
			}
		}
	}
	return dis[t];
}
int can[MAXN][MAXN];
int dist[MAXN][MAXN];
int dp[MAXN];
int main()
{
	// freopen("data.in","r",stdin);
	int n,m,k,e;
	while(~scanf("%d%d%d%d",&n,&m,&k,&e)){
		init();
		int a,b,c;
		for(int i=0;i<e;i++){
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
			addedge(b,a,c);
		}
		int d;
		scanf("%d",&d);
		memset(can,0,sizeof(can));
		for(int i=0;i<d;i++){
			scanf("%d%d%d",&c,&a,&b);
			for(int j=a;j<=b;j++){
				can[c][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){

				memset(mp,0,sizeof(mp));
				for(int l=1;l<=m;l++)
				for(int k=i;k<=j;k++){
					mp[l]=mp[l]|can[l][k];
				}

				dist[i][j]=spfa(1,m);
				//cout<<dist[i][j]<<"\t"; 
			}
			//cout<<endl;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(dist[i][j]<0x3f3f3f3f){
					dist[i][j]*=(j-i+1);
				}
			}
		}
		memset(dp,0x3f,sizeof(dp));
		// for(int i=1;i<=n;++i) {
		// 	dp[i]=dist[1][i];
		// }
		dp[1]=dist[1][1];
		dp[0]=0;
		//cout<<dp[1]<<endl;
		for(int i=2;i<=n;i++){
			dp[i]=dist[1][i];
			for(int j=1;j<i;j++){
				dp[i]=min(dp[i],dp[j]+dist[j+1][i]+k);
			}
		}
		printf("%d\n",dp[n]);
	}
}