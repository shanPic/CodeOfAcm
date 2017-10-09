#include<iostream>
#include<queue>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXNm 11000
#define MAXNn 110
#define INF 0x7ffffff
int n,m;
struct node
{
	int x,y,v,nxt;
}e[MAXNm];
int head[MAXNn];
int now=0;
void addedge(int x,int y,int v)
{
	e[now].x=x;e[now].y=y;e[now].v=v;
	e[now].nxt=head[x];
	head[x]=now++;
}
int vis[MAXNn];
int d[MAXNn];
int G[MAXNn][MAXNn];
void SPAF()
{
	queue<int> q;
	int tmp;
	q.push(0);
	vis[0]=1;
	d[0]=0;
	while(!q.empty()){
        //cout<<5555555<<endl;
		tmp=q.front();
		q.pop();
		vis[tmp]=0;
		for(int i=head[tmp];i!=-1;i=e[i].nxt){
			int xx=e[i].y;
			if(d[xx]>d[tmp]+e[i].v){
				d[xx]=d[tmp]+e[i].v;
                if(vis[xx]==0){
                    q.push(xx);
                    vis[xx]=1;
                }
			}
		}
	}
	//cout<<666666<<endl;
}
void dij()
{
	d[0]=0;
	for(int i=1;i<=n;i++){
		d[i]=min(G[0][i],G[i][0]);
	}
	vis[0]=1;
    for(int i=0;i<n;i++){
		int m=INF;
		int res=-1;
		for(int i=1;i<=n;i++){
			if(vis[i]==0&&d[i]<m){
				m=d[i];
				res=i;
			}
		}
		if(res==-1) continue;
		vis[res]=1;
		for(int i=1;i<=n;i++){
			if(d[res]+G[res][i]<d[i]){
				d[i]=d[res]+G[res][i];
			}
		}
	}
}
int cost[MAXNn];
int dp[105000];
int sum;
void zero_one_pack()
{
	for(int i=0;i<=sum;i++){
		dp[i]=INF;
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=cost[i];j--){
			if(dp[j]>dp[j-cost[i]]+d[i]){
				dp[j]=dp[j-cost[i]]+d[i];
			}
		}
	}
}
void init()
{
	for(int i=0;i<=n;i++){
		vis[i]=0;
	}
	for(int i=0;i<=n;i++){
		d[i]=INF;
	}
}
int main()
{
    //freopen("data.in","r",stdin);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int a,b,v;
		memset(head,-1,sizeof(head));
		memset(G,0x3f3f3f3f,sizeof(G));
		for(int i=0;i<m;i++){
			cin>>a>>b>>v;
			G[a][b]=G[b][a]=v;
		}
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>cost[i];
			sum+=cost[i];
		}
		init();
		//SPAF();
		dij();
		zero_one_pack();
		int ss=sum/2+1;
		int res=INF;
		for(int i=ss;i<=sum;i++){
            res=min(res,dp[i]);
		}
		if(res==INF) cout<<"impossible"<<endl;
		else cout<<res<<endl;
	}
	return 0;
}
