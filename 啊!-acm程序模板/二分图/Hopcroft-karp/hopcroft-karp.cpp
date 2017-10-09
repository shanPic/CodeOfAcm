/* *********************************************
http://www.cnblogs.com/kuangbin/archive/2012/08/26/2657446.html
二分图匹配（Hopcroft-Carp的算法）。

初始化：g[][]邻接矩阵，全部初始化为0

调用：res=MaxMatch();  Nx,Ny要初始化！！！分别代表二分图左右两部分的点个数

时间复杂大为 O(V^0.5 E)



适用于数据较大的二分匹配

需要ｑｕｅｕｅ头文件

********************************************** */

const int MAXN=3000;
const int INF=1<<28;
int g[MAXN][MAXN],Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];
bool searchP()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0;i<Nx;i++)
        if(Mx[i]==-1)
        {
            Q.push(i);
            dx[i]=0;
        }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        if(dx[u]>dis)  break;
        for(int v=0;v<Ny;v++)
            if(g[u][v]&&dy[v]==-1)
            {
                dy[v]=dx[u]+1;
                if(My[v]==-1)  dis=dy[v];
                else
                {
                    dx[My[v]]=dy[v]+1;
                    Q.push(My[v]);
                }
            }
    }
    return dis!=INF;
}
bool DFS(int u)
{
    for(int v=0;v<Ny;v++)
       if(!vst[v]&&g[u][v]&&dy[v]==dx[u]+1)
       {
           vst[v]=1;
           if(My[v]!=-1&&dy[v]==dis) continue;
           if(My[v]==-1||DFS(My[v]))
           {
               My[v]=u;
               Mx[u]=v;
               return 1;
           }
       }
    return 0;
}
int MaxMatch()
{
    int res=0;
    memset(Mx,-1,sizeof(Mx));
    memset(My,-1,sizeof(My));
    while(searchP())
    {
        memset(vst,0,sizeof(vst));
        for(int i=0;i<Nx;i++)
          if(Mx[i]==-1&&DFS(i))  res++;
    }
    return res;
}

//**************************************************************************/
