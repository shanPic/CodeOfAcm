#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000030;
int fa[MAXN];
int n,m;
void init()
{

}
int fid(int x)
{
    if(fa[x]==0) return x;
    int tmp=find(f[x]);
    f[x]=tmp;
    return tmp;
}
void bing(int x,int y)
{
    int a=fid(x),b=fid(y);
    if(a==0){
        fa[x]=b;
    }
    else if(b==0){
        fa[y]=a;
    }
    else{
        fa[x]=b;
    }
}
int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++){
        scanf("%d%d",&x,&y);

    }
}
