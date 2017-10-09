#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX=105;
int c[MAX];
struct xy
{
    int x;
    int y;
    int c;
}dis[MAX*(MAX-1)/2];
int find(int i)
{
    while(c[i]!=i)
        i=c[i];
    return c[i];
}
void merg(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b){
        c[a]=c[b];
    }
}
bool cmp(xy a,xy b)
{
    return a.c<b.c;
}
int main()
{
    //freopen("date.in","r",stdin);
    //freopen("date.out","w",stdout);
    int n,tem,res;
    while(cin>>n&&n!=0){
        res=0;
        for(int i=1;i<=n;i++){
            c[i]=i;
        }
        for(int i=0;i<n*(n-1)/2;i++){
            scanf("%d%d%d%d",&dis[i].x,&dis[i].y,&dis[i].c,&tem);
            if(tem==1)
                merg(dis[i].x,dis[i].y);
        }
        sort(dis,dis+n*(n-1)/2,cmp);
        for(int i=0;i<n*(n-1)/2;i++){
            if(find(dis[i].x)!=find(dis[i].y)){
                res+=dis[i].c;
                merg(dis[i].x,dis[i].y);
            }
        }
        printf("%d\n",res);
    }
}
