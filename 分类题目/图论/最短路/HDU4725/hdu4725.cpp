#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+30;
const int maxn=100000+30;
const int INF=0x3f3f3f3f;
struct edge
{
    int from,to,dist,nxt;
    edge(){};
    edge(int f,int t,int d,int nxt):from(f),to(t),dist(d),nxt(nxt){};
};
struct spfa
{
    int n,m;
    edge edges[MAXN];
    int head[MAXN];
    int num;
    bool inq[MAXN];
    int d[MAXN];
    int cnt[MAXN];
    void init(int n)
    {
        this->n=n;
        memset(head,-1,sizeof(head));
        num=0;
    }
    void addedge(int from,int to,int dist)
    {
        edges[num]=edge(from,to,dist,head[from]);
        head[from]=num++;
    }
    bool sss(int s)
    {
        cout<<num<<endl;
        queue<int> q;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) d[i]=INF;
        inq[s]=1;d[s]=0;q.push(s);

        while(!q.empty()){
            cout<<1111<<endl;
            int u=q.front();q.pop();
            inq[u]=0;
            for(int i=head[u];i!=-1;i=edges[i].nxt){
                cout<<2222<<"\t";
                edge &e=edges[i];
                cout<<e.to<<"\t"<<d[e.to]<<"\t"<<d[u]<<"\t"<<e.dist<<endl;
                //cout<<333333<<endl;
                if(d[e.to]>d[u]+e.dist){
                    cout<<444444<<endl;
                    d[e.to]=d[u]+e.dist;
                    if(!inq[e.to]){
                        q.push(e.to);
                        inq[e.to]=1;
                        if(++cnt[e.to]>n) return 1;
                    }
                }
            }
        }
        return false;
    }
}MM;
inline bool scan(int &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF){
        return 0;
    }
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
int a[MAXN];
int main()
{
    freopen("data.in","r",stdin);
    int t;
    //scan(t);
    scanf("%d",&t);
    int x;
    int ans;
    int cas=0;
    while(t--){
        //cout<<1111<<endl;
        int n,m,c;
        //scan(n),scan(m),scan(c);
        scanf("%d%d%d",&n,&m,&c);
        for(int i=1;i<=n;i++){
            //scan(a[i]);
            scanf("%d",&a[i]);
        }
        int ans=0;
        if(a[1]==a[n]){
            ans=2*c;
        }
        else{
            ans=abs(a[1]-a[n])*c;
        }
        int u,v,w;
        MM.init(n);
        BF.init(n);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(a[u]==a[v]){
                if(w<2*c) {
                    cout<<1111111<<endl;
                    MM.addedge(u,v,w);
                    MM.addedge(v,u,w);
                    BF.AddEdge(u,v,w);
                    BF.AddEdge(v,u,w);
                }
            }
            else{
//                cout<<2222222<<endl;
//                cout<<u<<"\t"<<v<<"\t"<<w<<endl;
                MM.addedge(u,v,w);
                MM.addedge(v,u,w);
                BF.AddEdge(u,v,w);
                BF.AddEdge(v,u,w);
            }
        }
        MM.sss(1);
        BF.negativeCycle(1);
        for(int i=1;i<=n;i++) {
            cout<<MM.d[i]<<"\t"<<BF.d[i]<<endl;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}
