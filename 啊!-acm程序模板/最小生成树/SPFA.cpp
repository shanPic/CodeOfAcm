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
