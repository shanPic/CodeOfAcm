/*
* @FileName: D:\代码与算法\2017训练比赛\多校3\1005-pro.cpp
* @Author: Pic
* @Date:   2017-08-01 12:32:00
* @Last Modified time: 2017-08-01 21:59:26
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN=1e6+30;
struct  node
{
	int b,c,nxt;	
	node(){};
	node(int b,int c,int nx):b(b),c(c),nxt(nx){};
};
node e[MAXN*2];
int cnt=0;
int head[MAXN];
void addedge(int a,int b,int c)
{
	e[cnt]=node(b,c,head[a]);
	head[a]=cnt;
	cnt++;
}
void init(int n)
{
    cnt=0;
    //memset(head,-1,sizeof(head));
    for(int i=0;i<=n;i++){
        head[i]=-1;
    }
}
int pre[MAXN];
int sz[MAXN];
void dfs(int now,int fa,int dist)
{
	//cout<<1111<<endl;
	sz[now]=0;
    int b,c;
    for(int i=head[now];i!=-1;i=e[i].nxt){
        b=e[i].b,c=e[i].c;
        if(b==fa) continue;
        dfs(b,now,c);
        pre[b]=c;
        sz[now]+=sz[b];
    }
    sz[now]++;
}
int main(){
   // freopen("data.in","r",stdin);
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        init(n);
        int a,b,c;
        LL res=0;
        for(int i=0;i<n-1;i++){
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
       // for(int i=0;i<=n;i++) sz[i]=0;
        pre[0]=0;
        dfs(1,0,0);
        for(int i=1;i<=n;i++){
 			res += 1LL * pre[i] * min(sz[i],k);
        }
        cout<<res<<"\n";
    }
    return 0;
}