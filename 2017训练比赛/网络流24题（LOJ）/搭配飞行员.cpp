/*
* @FileName: D:\代码与算法\2017训练比赛\网络流24题（LOJ）\搭配飞行员.cpp
* @Author: Pic
* @Date:   2017-08-14 13:05:02
* @Last Modified time: 2017-08-16 14:37:02
*/

#include <cstdio>  
#include <cstring>  
#include <vector>  
using namespace std;  
const int maxn=100+5;  
struct Edge{
	int to,nxt;
}edge[maxn*maxn];
int head[maxn];
int cnt;
struct Max_Match  
{  
	int n,m;//左右点集大小,点从1开始编号  
	//vector<int> g[maxn];//g[i]表示左边第i个点邻接的右边点的集合  
	bool vis[maxn];//vis[i]表示右边第i个点是否在本次match中被访问过  
	int left[maxn];//left[i]==j表右边第i个点与左边第j个点匹配,为-1表无点匹配  
  
	void init(int n,int m)  
	{  
		this->n=n;  
		this->m=m;  
		memset(left,-1,sizeof(left));  
		cnt=0;
		memset(head,-1,sizeof(head));
	}  
  	void addedge(int a,int b)
  	{
  		edge[cnt].to=b;
  		edge[cnt].nxt=head[a];
  		head[a]=cnt++;
  	}
	//判断从左u点是否可以找到一条增广路  
	bool match(int u)  
	{  
		for(int i=head[u];i!=-1;i=edge[i].nxt)  
		{  
			int v=edge[i].to;  
			if(!vis[v])  
			{  
				vis[v]=true;  
				if(left[v]==-1 || match(left[v]))//找到增广路  
				{  
					left[v]=u;  
					return true;  
				}  
			}  
		}  
		return false;  
	}  
  
	//返回当前二分图的最大匹配数  
	int solve()  
	{  
		int ans=0;//最大匹配数  
		for(int i=1;i<=n;i++)//每个左边的节点找一次增广路  
		{  
			memset(vis,0,sizeof(vis));  
			if(match(i)) ans++;//找到一条增广路,形成一个新匹配  
		}  
		return ans;  
	}  
}MM; 
int main(){
	//freopen("data.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	MM.init(m,n);
	int x,y;
	while(~scanf("%d%d",&x,&y)){
		MM.addedge(x,y);
	}
	printf("%d\n",MM.solve());
    return 0;
}