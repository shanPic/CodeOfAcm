#include<bits/stdc++.h>
using namespace std;
const int MAXN=130;
int dir1[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int dir2[4][2]={{-1,-1},{1,1},{-1,1},{1,-1}};
int m[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n;
bool DFS(int x,int y,int mol)
{
    //cout<<1111111<<endl;
    if(vis[x][y]) return 0;
    else{
        int xx,yy;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            xx=x+dir1[i][0];yy=y+dir1[i][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<n&&m[xx][yy])
                DFS(xx,yy,mol);
        }
        if(mol){
            for(int i=0;i<4;i++){
                xx=x+dir2[i][0];yy=y+dir2[i][1];
                if(xx>=0&&xx<n&&yy>=0&&yy<n&&m[xx][yy])
                    DFS(xx,yy,mol);
            }
        }
        return 1;
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    char ch;
    int t=0;
    while(~scanf("%d",&n)&&n){
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ch=getchar();
                m[i][j]=ch-'0';
            }
            getchar();
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<m[i][j];
//            }
//            cout<<endl;
//        }
        int cnt1=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]&&vis[i][j]==0){
                    //cout<<1111111<<endl;
                    //vis[i][j]=1;
                    if(DFS(i,j,0)){
                        cnt1++;
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int cnt2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]&&vis[i][j]==0){
                    //vis[i][j]=1;
                    if(DFS(i,j,1)){
                        cnt2++;
                    }
                }
            }
        }
        printf("Case %d: %d %d\n\n",++t,cnt1,cnt2);
    }

}
