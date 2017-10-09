//POJ 3468 区间add，区间查询
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//每当有add加到i节点上，直接更新i节点的sum.
//也就是说如果要查询区间[1,n]的sum值，直接sum[1]即可,不用再去考虑1的addv[1]值.
const int MAXN=100000+100;
typedef long long LL;
#define lson i*2,l,m
#define rson i*2+1,m+1,r
LL sum[MAXN*4];
LL addv[MAXN*4];
void PushDown(int i,int num)
{
    if(addv[i])
    {
        sum[i*2] +=addv[i]*(num-(num/2));
        sum[i*2+1] +=addv[i]*(num/2);
        addv[i*2] +=addv[i];
        addv[i*2+1]+=addv[i];
        addv[i]=0;
    }
}
void PushUp(int i)
{
    sum[i]=sum[i*2]+sum[i*2+1];
}
void build(int i,int l,int r)
{
    addv[i]=0;
    if(l==r)
    {
        scanf("%I64d",&sum[i]);
        return ;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    PushUp(i);
}
void update(int ql,int qr,int add,int i,int l,int r)
{
    if(ql<=l&&r<=qr)
    {
        addv[i]+=add;
        sum[i] += (LL)add*(r-l+1);
        return ;
    }
    PushDown(i,r-l+1);
    int m=(l+r)/2;
    if(ql<=m) update(ql,qr,add,lson);
    if(m<qr) update(ql,qr,add,rson);
    PushUp(i);
}
LL query(int ql,int qr,int i,int l,int r)
{
    if(ql<=l&&r<=qr)
    {
        return sum[i];
    }
    PushDown(i,r-l+1);
    int m=(l+r)/2;
    LL res=0;
    if(ql<=m) res+=query(ql,qr,lson);
    if(m<qr) res+=query(ql,qr,rson);
    return res;
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)==2&&n&&q)
    {
        build(1,1,n);
        while(q--)
        {
            char str[10];
            scanf("%s",str);
            int x,y,z;
            if(str[0]=='Q')
            {
                scanf("%d%d",&x,&y);
                printf("%I64d\n",query(x,y,1,1,n));
            }
            else
            {
                scanf("%d%d%d",&x,&y,&z);
                update(x,y,z,1,1,n);
            }
        }
    }
    return 0;
}
