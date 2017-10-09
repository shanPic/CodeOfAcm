#include<iostream>
#include<queue>
#include<string.h>
#include<cstdio>
#define INF 0x7ffffff
using namespace std;
const int MAXN=20000;
int d[MAXN];
int vis[MAXN];
int sz[MAXN];
struct node
{
    int x,y,v,nxt;
}bf[MAXN];
int head[MAXN];
int coun=0;
void addedge(int x,int y,int v)
{
    bf[coun].x=x, bf[coun].y=y, bf[coun].v=v;
    bf[coun].nxt=head[x];
    head[x]=coun;
        ++coun;
}
int m,n;
void spfa(int s)
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        if(i!=s) d[i]=INF;
        else d[i]=0;
    }
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        vis[now]=0;
        for(int i=head[now];i!=-1;i=bf[i].nxt){
            int xx=bf[i].y;
            if(d[xx]>d[now]+bf[i].v){
                d[xx]=d[now]+bf[i].v;
                if(vis[xx]==0) {q.push(xx);}
            }
        }
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    while(cin>>n>>m){
        memset(head,-1,sizeof(head));
        memset(bf,-1,sizeof(bf));
        int a,b,v,s,e;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&v);
            addedge(a,b,v);
            addedge(b,a,v);
        }
        scanf("%d%d",&s,&e);
        spfa(s);
        if(d[e]==INF)
            cout<<-1<<endl;
        else cout<<d[e]<<endl;
    }
}
