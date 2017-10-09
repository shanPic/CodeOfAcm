#include<bits/stdc++.h>
using namespace std;
const int MAXN=600+30;
const int MAXNE=250000+30;
const int INF=0x3f3f3f3f;
int d[MAXN];
int w[MAXN];
int cost[MAXN];
bool vis[MAXN];
int n;
struct edge
{
    int to;
    int w;
    int nxt;
    edge():nxt(-1){};
    edge(int to2,int w2,int nxt2):to(to2),w(w2),nxt(nxt2){};
}e[MAXNE] ;
int head[MAXN];
int tot;
void addedge(int b,int to,int w)
{
    e[tot]=edge(to,w,head[b]);
    head[b]=tot++;
}
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
struct node{
    int d,u;
    node(){};
    node(int _d,int _u):d(_d),u(_u){};
    bool operator<(const node &o)const
    {
        if(d>o.d)
            return true;
        else if(d==o.d){
            return w[d]>=w[o.d];
        }
    }
};
void dj(int s)
{
    memset(vis,0,sizeof(vis));
    memset(w,0,sizeof(w));
    w[s]=cost[s];
    for(int i=0;i<n;i++) d[i]=INF;
    d[s]=0;
    priority_queue<node> q;
    q.push(node(0,s));
    node tmp;
    while(!q.empty()){
        tmp=q.top();
        q.pop();
        int u=tmp.u;
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].nxt){
            int v=e[i].to;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                w[v]=w[u]+cost[v];
                q.push(node(d[v],v));
            }
            else if(d[v]==d[u]+e[i].w){
                if(w[v]<w[u]+cost[v]){
                    w[v]=w[u]+cost[v];
                }
            }
        }
    }
}
int main()
{
    //freopen("data.in","r",stdin);
    int m,s,e;
    cin>>n>>m>>s>>e;
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    int u,v,c;
    init();
    for(int i=0;i<m;i++){
        cin>>u>>v>>c;
        addedge(u,v,c);
        addedge(v,u,c);
    }
    dj(s);
    cout<<d[e]<<" "<<w[e]<<endl;
}
