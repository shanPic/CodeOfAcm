#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
#define MAXN 220
int n,m,k;
int vis[MAXN];
int liner[MAXN];
int G[MAXN][MAXN];
int dfs(int x)
{
	for(int i=0;i<m;i++){
		if(G[x][i]&&!vis[i]){
			vis[i]=1;
			if(liner[i]==-1||dfs(liner[i])){
				liner[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int zuida()
{
	int res=0;
	memset(liner,-1,sizeof(liner));
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) res++;
	}
	return res;
}
int main()
{
	//freopen("data.in","r",stdin);
	int p,x,y;
	while(cin>>n){
		if(n==0) break;
		cin>>m>>k;
		memset(G,0,sizeof(G));
		for(int i=0;i<k;i++){
			cin>>p>>x>>y;
			if(x!=0&&y!=0)
			G[x][y]=1;
		}
		cout<<zuida()<<endl;
	}
}
