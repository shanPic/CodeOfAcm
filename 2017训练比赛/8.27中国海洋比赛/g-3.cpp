//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
const int maxn=55;
int t,n,m;
double f[maxn][2];
bool vis[maxn];
vector<int>v[maxn];
void init()
{
    for(int i=1;i<=n;i++) v[i].clear();
    memset(f,0,sizeof(f));
    memset(vis,0,sizeof(vis));
    f[n][0]=1.0;f[n][1]=0.0;
}
void dfs(int x)
{
	if(x==n) return;
    int cnt=v[x].size();
    if(cnt==0) return;
    for(int i=0;i<cnt;i++){
        int y=v[x][i];
        if(vis[y]) continue;
        vis[y]=1;
        dfs(y);
    }
    double tmp=0;
    for(int i=0;i<cnt;i++){
        int y=v[x][i];
        tmp+=f[y][0];
    }
    f[x][0]=tmp*(1.0/cnt);
    for(int i=0;i<cnt;i++){
        int y=v[x][i];
        f[x][1]=max(f[x][1],(tmp-f[y][0]+f[y][1])*(1.0/cnt));
        if(cnt>1)
            f[x][1]=max(f[x][1],(tmp-f[y][0])*(1.0/(cnt-1)));
    }
    //cout<<x<<" "<<f[x][0]<<" "<<f[x][1]<<endl;
}
int main()
{
//	freopen("data.in","r",stdin);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d",&n,&m);
        init();
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
        }
        vis[1]=1;
        dfs(1);
        printf("Case #%d: ",cas);
	   cout<<fixed<<setprecision(6)<<max(f[1][0],f[1][1])<<endl;
    }
    return 0;
}
