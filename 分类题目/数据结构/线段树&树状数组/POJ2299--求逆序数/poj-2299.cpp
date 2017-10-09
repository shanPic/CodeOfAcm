#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
const int M=500010;
int MN;
int e[M];
int k;
struct node
{
    int val;
    int pos;
}a[M];
int lowbit(int x)
{
    return x&(-x);
}
void update(int i,int v)
{
    for(;i<=MN;i+=lowbit(i)){
        e[i]+=v;
    }
}
int getsum(int i)
{
    int res=0;
    for(;i>0;i-=lowbit(i)){
        res+=e[i];
    }
    return res;
}
bool cmp1(node a,node b)
{
    return a.val<b.val;
}
bool cmp2(node a,node b)
{
    return a.pos<b.pos;
}
void init()
{
    sort(a+1,a+k+1,cmp1);
    for(int i=1;i<=k;i++)
        a[i].val=i;
    sort(a+1,a+k+1,cmp2);
    memset(e,0,sizeof(e));
    MN=k;
}
int main()
{
    //freopen("data.in","r",stdin);
    long long  res;
    while(cin>>k&&k!=0){
        res=0;
        for(int i=1;i<=k;i++){
            cin>>a[i].val;
            a[i].pos=i;
        }
        init();
        for(int i=1;i<=k;i++){
            update(a[i].val,1);
            res+=(i-getsum(a[i].val));
        }
        cout<<res<<endl;
    }
}
