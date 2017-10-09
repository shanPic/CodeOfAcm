#include<bits/stdc++.h>
using namespace std;
char *girl="girl";
char *cat="cat";
//string girl="girl";
//string cat="cat";
const int MAXN=1000+30;
char m[MAXN][MAXN];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int gn,cn;
int n,mm;
bool vis[MAXN][MAXN];
void dfs1(int x,int y,int num)
{
    if(num>=3){
        int a,b;
        for(int i=0;i<4;i++){
            a=x+dir[i][0];b=y+dir[i][1];
            if((a>=0&&a<n)&&(b>=0&&b<mm)&&(m[a][b]==girl[num])&&vis[a][b]==0){
                gn++;
            }
        }
        return;
    }
    int a,b;
    for(int i=0;i<4;i++){
        a=x+dir[i][0];b=y+dir[i][1];
        if((a>=0&&a<n)&&(b>=0&&b<mm)&&(m[a][b]==girl[num])&&vis[a][b]==0){
            vis[a][b]=1;
            dfs1(a,b,num+1);
            vis[a][b]=0;
        }
    }
}
void dfs2(int x,int y,int num)
{
    if(num>=2){
        int a,b;
        for(int i=0;i<4;i++){
            a=x+dir[i][0];b=y+dir[i][1];
            if((a>=0&&a<n)&&(b>=0&&b<mm)&&(m[a][b]==cat[num])&&vis[a][b]==0){
                cn++;
            }
        }
        return;
    }
    int a,b;
    for(int i=0;i<4;i++){
        a=x+dir[i][0];b=y+dir[i][1];
        if((a>=0&&a<n)&&(b>=0&&b<mm)&&(m[a][b]==cat[num])&&vis[a][b]==0){
            vis[a][b]=1;
            dfs2(a,b,num+1);
            vis[a][b]=0;
        }
    }
}
int main()
{
    freopen("data.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d\n",&n,&mm);
        //getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<mm;j++){
                m[i][j]=getchar();
            }
            getchar();
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<mm;j++){
//                cout<<m[i][j];
//            }
//            cout<<endl;
//        }
        gn=cn=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<mm;j++){
                if(m[i][j]=='g'){
                    memset(vis,0,sizeof(vis));
                    dfs1(i,j,1);
                }
                else if(m[i][j]=='c'){
                    memset(vis,0,sizeof(vis));
                    dfs2(i,j,1);
                }
            }
        }
        printf("%d %d\n",gn,cn);
    }
}
