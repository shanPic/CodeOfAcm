#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int MAXN=110;
int n,m,k;
int g[MAXN][MAXN];
int liner[MAXN];
int vis[MAXN];
struct node
{
	int x,y;
}chess[10010];
int DFS(int x)
{
	for(int i=1;i<=m;i++){
		if(!vis[i]&&g[x][i]){
			vis[i]=1;
			if(liner[i]==-1||DFS(liner[i])){
				liner[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int huger()
{
	int res=0;
	memset(liner,-1,sizeof(liner));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(DFS(i)) res++;
	}
	return res;
}
int main()
{
	//freopen("data.in","r",stdin);
	int res;
	int x,y;
	int ans;
	int cas=0;
	while(cin>>n>>m>>k){
		ans=0;
		memset(g,0,sizeof(g));
		for(int i=0;i<k;i++){
			cin>>x>>y;
			chess[i].x=x;
			chess[i].y=y;
			g[x][y]=1;
		}
		res=huger();
		for(int i=0;i<k;i++){
			x=chess[i].x;
			y=chess[i].y;
			g[x][y]=0;
			if(huger()!=res) ans++;
            g[x][y]=1;
		}
		//cout<<ans<<endl;
		printf("Board %d have %d important blanks for %d chessmen.\n",++cas,ans,res);
	}
}
