#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=103;
int n,a[N][N],p[N],q,u,v;
int findset(int x)
{
    if(x==p[x])return x;
    return p[x]=findset(p[x]);
}
void same(int x,int y)
{
    int fx=findset(x),fy=findset(y);
    if(fx!=fy)p[fx]=p[fy];
}
struct Edge
{
    int l,r,len;
};
Edge edge[5010];
int cmp(Edge x,Edge y)
{
    return x.len<y.len;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            p[i]=i;
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(j>i)
                {
                    edge[cnt].l=i;
                    edge[cnt].r=j;
                    edge[cnt++].len=a[i][j];
                }
            }
        }
        sort(edge,edge+cnt,cmp);
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&u,&v);
            same(u,v);
        }
        int ans=0;
        for(int i=0;i<cnt;i++)
        {
            if(findset(edge[i].l)!=findset(edge[i].r))
            {
                ans+=edge[i].len;
                same(edge[i].l,edge[i].r);
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}
