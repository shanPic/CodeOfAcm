#include<cstdio>
#include<iostream>
#include<stdlib.h>
#define INF 0x7ffffff
#define MAXN 200010
using namespace std;
const double eps=1e-10;
struct node
{
    int x;
    int value;
    int next;
};
node e[60000];int st[1505];     //存储图原始数据，使用的是邻接表形式（数组模拟）
int visited[1505];              //标记节点加入至队列中的个数
int dis[1505];                  //存储路程
int qu[1000];                //使用数组模拟队列
int main()
{
    int n,m,u,v,w,start,en,h,r,cur;
    freopen("data.in","r",stdin);
    //freopen("c.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0; i<=1500; i++)
        {
            visited[i]=0;
            dis[i]=-1;//!
            st[i]=-1;
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d\n",&u,&v,&w);
            e[i].x=v;
            e[i].value=w;
            e[i].next=st[u];
            st[u]=i;
        }
        //scanf("%d%d",&start,&en);
        start=m;
        visited[start]=1;
        dis[start]=0;
        h=0;
        r=1;
        qu[r]=start;
        while(h!=r)
        {
            h=(h+1)%1000;       //防止数组越界
            cur=qu[h];
            int tmp=st[cur];
            visited[cur]=0;
            while(tmp!=-1)
            {
                if (dis[e[tmp].x]>dis[cur]+e[tmp].value||dis[e[tmp].x]==-1)
                {
                    dis[e[tmp].x]=dis[cur]+e[tmp].value;//松弛操作
                    if(visited[e[tmp].x]==0)
                    {
                        visited[e[tmp].x]=1;
                        r=(r+1)%1000;       //防止数组越界
                        qu [r]=e[tmp].x;
                    }
                }
                tmp=e[tmp].next;        //使用的是数组模拟的邻接表
            }
        }
        printf("%d\n",dis[en]);
    }
}
