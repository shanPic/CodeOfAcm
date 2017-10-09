#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#define INF 0x7ffffff
#define MAXN 200010
using namespace std;
const double eps=1e-10;
int res[1000];
    int n;
bool vis[10];
int cas;
void dfs(int step)
{
    if(step>n){
        cout<<++cas<<endl;
        for(int i=1;i<=n;i++){
            cout<<res[i];
        }
        cout<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                vis[i]=1;
                res[step]=i;
                dfs(step+1);
                vis[i]=0;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(cin>>n){
        cas=0;
        memset(vis,0,sizeof(vis));
        dfs(1);
    }
}
