#include <bits/stdc++.h>
using namespace std;
const int MAXN=400+30;
const int inf=0x3f3f3f3f;
int mp1[MAXN][MAXN],mp2[MAXN][MAXN];
int dis[MAXN][MAXN];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        mp1[u][v]=1;
    }

    memset(dis,0x3f,sizeof(dis));

    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        if(i==j) dis[i][j]=0;
        else dis[i][j]=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp1[i][j]==1) mp2[i][j]=inf; else mp2[i][j]=1;
            }
    }
    int flag=mp1[1][n];
    if(flag==1){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dis[i][j]>dis[i][k]+mp2[k][j]){
                        dis[i][j]=dis[i][k]+mp2[k][j];
                    }
                }
            }
        }
        if(mp2[1][n]==inf) printf("-1\n");
        else printf("%d\n",mp[1][n]);
    }
    else{

    }
	return 0;
}
