//dijkstra算法
//维护两个集合
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#define INF 99999
#define MAXN 110
using namespace std;
const double eps=1e-10;
const double PI=acos(-1);
int G[MAXN][MAXN];
int dis[MAXN];
int n,m;
void dijkstra()
{
    bool s[MAXN];
    memset(s,0,sizeof(s));
//    memset(dis,-1,sizeof(dis));
    for(int i=2;i<=n;i++){
        dis[i]=min(G[i][1],G[1][i]);
    }
    int tmp=INF;
    int flag=0;
    for(int k=0;k<n;k++){
        tmp=INF;
        flag=0;
        for(int i=2;i<=n;i++ ){
            if(s[i]==0&&dis[i]<tmp){
                tmp=dis[i];
                flag=i;
            }
        }
        s[flag]=1;
        for(int i=1;i<=n;i++){
            if(i!=flag&&s[i]==0){
                dis[i]=min(dis[flag]+G[flag][i],dis[i]);
            }
        }
        if(s[n])
            return;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int x,y;
    int tmp;
    while(cin>>n>>m){
        //memset(G,-1,sizeof(G));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                G[i][j]=INF;
            }
        }
        if(n==0&&m==0)
            break;
        for(int i=0;i<m;i++){
        cin>>x>>y>>tmp;
        //>>G[x][y];
        if(tmp<G[x][y])
            G[x][y]=G[y][x]=tmp;
        }
        dijkstra();
        if(dis[n]==-1)
            cout<<0<<endl;
        else
        cout<<dis[n]<<endl;
    }
}
