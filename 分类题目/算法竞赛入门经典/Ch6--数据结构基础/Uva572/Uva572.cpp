#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=101;
bool mapp[MAXN][MAXN];
bool vis[MAXN][MAXN];
void dfs(int x,int y)
{
    vis[x][y]=1;
    if(x>=m||y>=n||x<0||y<0)
        return;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++){
            if(i!=0||j!=0)
                if(mapp[x+i][y+j]&&vis[x+i][y+j]==0)
                    dfs(x+i,y+j);
        }
}
int main()
{
    //freopen("data.in","r",stdin);
    int res;
    char tem;
    while(scanf("%d%d",&m,&n)){
        if(m==0&&n==0)
            break;

        res=0;
        memset(vis,0,sizeof(vis));
        getchar();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%c",&tem);
                if(tem=='*')
                    mapp[i][j]=0;
                else if(tem=='@')
                    mapp[i][j]=1;
            }
            getchar();
        }
////////
//for(int i=0;i<m;i++)
//{
//    for(int j=0;j<n;j++)
//        if(mapp[i][j]==0)
//            cout<<"*";
//        else cout<<"@";
//    cout<<endl;
//}
//////
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(vis[i][j]==0&&mapp[i][j]){
                    res++;
                    dfs(i,j);/////
                }
            }
        printf("%d\n",res);
    }
}
