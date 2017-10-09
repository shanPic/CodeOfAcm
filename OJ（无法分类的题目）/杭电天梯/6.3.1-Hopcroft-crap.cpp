#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
//#define INF 0x7ffffff
//#define MAXN 1600
using namespace std;
const double eps=1e-10;
const double PI=acos(-1);
const int MAXN=1600;
//int vis[MAXN];
//int liner[MAXN];
int n,m;
struct node
{
    int p,flag;
}mn[MAXN];
/* *********************************************

二分图匹配（Hopcroft-Carp的算法）。
初始化：g[][]邻接矩阵
调用：res=MaxMatch();  
Nx,Ny要初始化！！！
时间复杂大为 O(V^0.5 E)
适用于数据较大的二分匹配
需要ｑｕｅｕｅ头文件

********************************************** */
/************************************************/
const int INF=1<<28;
int G[MAXN][MAXN],Mx[MAXN],My[MAXN],Nx,Ny;
int dx[MAXN],dy[MAXN],dis;
bool vst[MAXN];
bool searchP()
{
    queue<int>Q;
    dis=INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=0; i<Nx; i++)
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
        for(int v=0; v<Ny; v++)
            if(G[u][v]&&dy[v]==-1)
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
    for(int v=0; v<Ny; v++)
        if(!vst[v]&&G[u][v]&&dy[v]==dx[u]+1)
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
        for(int i=0; i<Nx; i++)
            if(Mx[i]==-1&&DFS(i))  res++;
    }
    return res;
}

//**************************************************************************/
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    #endif
    int t;
    int x,xn,y;
    int flag;  //1为左，-1为右
    while(cin>>t){
    	n=m=0;
    	memset(G,0,sizeof(G));
    	memset(mn,0,sizeof(mn));
    	flag=0;
        for(int i=0;i<t;i++){
            scanf("%d:(%d)",&x,&xn);
            if(mn[x].p!=0){
                if(mn[x].p==-1) flag=1;
                else flag=-1;
            }
            else{
                mn[x].p=1;flag=-1;mn[x].flag=n++;
            }
            for(int j=0;j<xn;j++){
                scanf("%d",&y);
                mn[y].p=flag;
                if(flag==1){
                    mn[y].p=flag;
                    mn[y].flag=n;
                    G[n][mn[x].flag]=1;
                    n++;
                }
                else{
                    mn[y].p=flag;
                    mn[y].flag=m;
                    G[mn[x].flag][m]=1;
                    m++;
                }
            }
        }
        Nx=n;Ny=m;
    	//cout<<"--------------"<<endl<<n<<endl<<m<<endl<<"---------"<<endl;
        cout<<MaxMatch()<<endl;
    }
}
