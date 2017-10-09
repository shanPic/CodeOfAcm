//此标程采用数组模拟队列实现SPFA
//默认无负圈
#include<cstdio>
using namespace std;
struct node
{
    int x;
    int value;
    int next;
};
node e[60000];int st[1505];;      //存储图原始数据，使用的是邻接表形式（数组模拟）
int visited[1505];//标记节点加入至队列中的个数
int dis[1505];  //存储路程
int queue[1000];//使用数组模拟队列
int main()
{
    int n,m,u,v,w,start,h,r,cur;
//    freopen("c.in","r",stdin);
//    freopen("c.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1; i<=1500; i++)
        {
            visited[i]=0;
            dis[i]=-1;
            st[i]=-1;
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d\n",&u,&v,&w);
            e[i].x=v;
            e[i].value=w;
            e[i].next=st[u];
            st[u]=i;
        }
        start=1;
        visited[start]=1;
        dis[start]=0;
        h=0;
        r=1;
        queue[r]=start;
        while(h!=r)
        {
            h=(h+1)%1000;       //防止数组越界
            cur=queue[h];
            int tmp=st[cur];
            visited[cur]=0;
            while(tmp!=-1)
            {
                if (dis[e[tmp].x]<dis[cur]+e[tmp].value)
                {
                    dis[e[tmp].x]=dis[cur]+e[tmp].value;//松弛操作
                    if(visited[e[tmp].x]==0)
                    {
                        visited[e[tmp].x]=1;
                        r=(r+1)%1000;       //防止数组越界
                        queue[r]=e[tmp].x;
                    }
                }
                tmp=e[tmp].next;        //使用的是数组模拟的邻接表
            }
        }
        printf("%d\n",dis[n]);
    }
    return 0;
}
