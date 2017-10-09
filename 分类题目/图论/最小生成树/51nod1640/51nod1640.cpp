#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+30;
const int MAXM=2*MAXN+30;
int f[MAXN];
struct edge
{
    int u,v;
    long long w;
}e[MAXM];
int tot;
void addedge(int v,int u,int w)
{
    e[tot].v=v;
    e[tot].u=u;
    e[tot].w=w;
    tot++;
}
int fin(int x)
{
    if(f[x]==-1)
        return x;
    else{
        f[x]=fin(f[x]);
        return f[x];
    }
}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
long long kru(int n)
{
    memset(f,-1,sizeof(f));
    sort(e,e+tot,cmp);
    long long num=0,ans=0;
    int u,v,w;
    int i;
    for(i=0;i<tot;i++){
        u=e[i].u,v=e[i].v,w=e[i].w;
        int t1=fin(u);
        int t2=fin(v);
        if(t1!=t2){
            num++;
            f[t2]=t1;
        }
        if(num==n-1) break;
    }
    num=0;
    memset(f,-1,sizeof(f));
    while(e[i].w==e[i+1].w){
        i++;
    }
    for(;i>=0;i--){
        u=e[i].u,v=e[i].v,w=e[i].w;
        int t1=fin(u);
        int t2=fin(v);
        if(t1!=t2){
            num++;
            ans+=w;
            f[t2]=t1;
        }
        if(num==n-1) break;
    }
    if(num<n-1) return -1;
    else return ans;
}
int main()
{
    //freopen("data.in","r",stdin);
    int n,m;
    int a,b;
    long long v;
    tot=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%lld",&a,&b,&v);
        addedge(a,b,v);
    }
    //printf("%lld\n",kru(n));
    cout<<kru(n)<<endl;
}
