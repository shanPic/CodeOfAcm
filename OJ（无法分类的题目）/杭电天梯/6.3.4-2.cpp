#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int MAXN=130;
int g[MAXN][MAXN];
int liner[MAXN];
int vis[MAXN];
int n;
int DFS(int x)
{
	for(int i=1;i<=n;i++){
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
	int t;
	cin>>t;
	int m;
	int x,y;
	while(t--){
        memset(g,0,sizeof(g));
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			g[x][y]=1;
		}
		cout<<n-huger()<<endl;
	}
}
