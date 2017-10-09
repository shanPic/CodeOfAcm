/***********************二分匹配模板**************************/
const int MAXN=1000;
int uN,vN;  //u,v数目
int g[MAXN][MAXN];//编号是0~n-1的
int linker[MAXN];//记录匹配点i的匹配点是谁
bool used[MAXN];
bool dfs(int u)//回溯看能不能通过分手来进行匹配
{
    int v;
    for(v=0;v<vN;v++)
        if(g[u][v]&&!used[v])
                  //如果有这条边，并且这条边没有用过
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))//如果这个点没有匹配过，并且能找到匹配点，那么就可以以这个边作为匹配点
            {
                linker[v]=u;//取反
                return true;
            }    
        }  
    return false;  
}    
int hungary()//返回最大匹配数
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))//如果这个点有匹配点
                          res++;
    } 
    return res;   
}
/***********************二分匹配模板**************************/