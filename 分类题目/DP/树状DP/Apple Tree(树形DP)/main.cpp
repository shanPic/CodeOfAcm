/****************
*D:\ACM学习\树状DP
使用了邻接表来建树
具体实现见

****************/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct node
{
    int u,v,val,next;
} tree[505];

int dp[205][405][2],head[205],val[205];
int len,n,k;

void add(int u,int v)
{
    tree[len].u = u;
    tree[len].v = v;
    tree[len].next = head[u];
    head[u] = len++;
}//添加树的一个节点,类似于邻接表的实现

void dfs(int root,int mark)
{
    int i,j,t,son;
    for(i = head[root]; i!=-1; i = tree[i].next)
    {
        son = tree[i].v;//见#20
        if(son == mark)
            continue;//见#67
        dfs(son,root);//深搜,将所有节点都搜索一遍
        for(j = k; j>=1; j--)
        {
            for(t = 1; t<=j; t++)
            {
                dp[root][j][0]=max(dp[root][j][0],dp[root][j-t][1]+dp[son][t-1][0]);
                dp[root][j][0]=max(dp[root][j][0],dp[root][j-t][0]+dp[son][t-2][1]);
                dp[root][j][1]=max(dp[root][j][1],dp[root][j-t][1]+dp[son][t-2][1]);//背包
            }
        }
    }
}

int main()
{
    int i,j,a,b;
    while(~scanf("%d%d",&n,&k))
    {
        memset(dp,0,sizeof(dp));
        memset(head,-1,sizeof(head));
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&val[i]);
            for(j = 0; j<=k; j++)
                dp[i][j][0] = dp[i][j][1] = val[i];
        }
        len = 0;
        for(i = 1; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);//?
        }
        dfs(1,0);
        printf("%d\n",max(dp[1][k][0],dp[1][k][1]));
    }

    return 0;
}
