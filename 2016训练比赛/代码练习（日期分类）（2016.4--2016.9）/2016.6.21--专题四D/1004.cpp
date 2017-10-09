#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAX=103;
int c[MAX];
struct xy
{
    int x;
    int y;
    int l;
}dis[MAX*(MAX-1)/2];;
bool cmp(xy a,xy b)
{
    return a.l<b.l;
}
int find(int x)
{
    while(c[x]!=x){
        x=c[x];
    }
    return x;
}
void merg(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x!=y){
        if(x>y)
            c[x]=y;
        else c[y]=x;
    }
}
int main()
{
    //freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    int n,res;
    while(cin>>n&&n!=0){
        res=0;
        for(int i=1;i<=n;i++){
            c[i]=i;
        }
        for(int i=0;i<n*(n-1)/2;i++){
            cin>>dis[i].x>>dis[i].y>>dis[i].l;
            /*if(dis[i].x>dis[i].y)
                swap(dis[i].x,dis[i].y);*/
        }
        sort(dis,dis+n*(n-1)/2,cmp);
        for(int i=0;i<n*(n-1)/2;i++){
            if(find(dis[i].x)!=find(dis[i].y)){
                res+=dis[i].l;
                merg(c[dis[i].x],c[dis[i].y]);
            }
        }
        cout<<res<<endl;
    }
}
