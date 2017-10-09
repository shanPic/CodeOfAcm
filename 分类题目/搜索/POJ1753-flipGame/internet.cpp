#include"stdio.h"
#include"iostream"
#include"queue"
#include<string.h>
using namespace std;
#define N 65536
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int change[16];
int visit[N];
struct node    // 用优先队列，一般队列也能过
{
    int state,step;
    friend bool operator<(node a,node b)
    {
        return a.step>b.step;
    }
};
void inti()        //若提前求出16个操作状态存入数组可以省去该函数
{
    int i,j,x,y,t,temp,k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            temp=0;
            temp^=(1<<((3-i)*4+3-j));
            for(t=0;t<4;t++)
            {
                x=dir[t][0]+i;
                y=dir[t][1]+j;
                if(x<0||y<0||x>3||y>3)
                    continue;
                temp^=(1<<((3-x)*4+3-y));
            }
            change[k++]=temp;
        }
    }
}
int bfs(int t)
{
    freopen("data.in","r",stdin);
    int i;
    memset(visit,0,sizeof(visit));
    priority_queue<node>q;
    node cur,next;
    cur.state=t;
    cur.step=0;
    q.push(cur);
    visit[t]=1;
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        if(cur.state==0||cur.state==N-1)
            return cur.step;
        for(i=0;i<16;i++)
        {
            next.state=cur.state^change[i];
            next.step=cur.step+1;
            if(!visit[next.state])
            {
                q.push(next);
                visit[next.state]=1;
            }
        }
    }
    return -1;
}
int main()
{
    int i,j,t,ans;
    inti();
    char chess[5][5];
    while(scanf("%s",chess[0])!=-1)
    {
        for(i=1;i<4;i++)
            scanf("%s",chess[i]);
        t=0;
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                if(chess[i][j]=='b')
                    t^=1<<((3-i)*4+3-j); //此处把异或改为加也行。加是指
            }
        ans=bfs(t);
        if(ans==-1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
