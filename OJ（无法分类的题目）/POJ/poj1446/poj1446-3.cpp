/*
* @FileName: D:\代码与算法\POJ\poj1446\poj1446-3.cpp
* @Author: Pic
* @Date:   2017-08-17 10:25:54
* @Last Modified time: 2017-08-17 10:34:41
*/

#include<cstdio>  
#include<cstring>  
#include<vector> 
#include<iostream> 
using namespace std;  
const int maxn=100+5;  
  
struct Max_Match  
{  
	int n,m;//左右点集大小,点从1开始编号  
	vector<int> g[maxn];//g[i]表示左边第i个点邻接的右边点的集合  
	bool vis[maxn];//vis[i]表示右边第i个点是否在本次match中被访问过  
	int left[maxn];//left[i]==j表右边第i个点与左边第j个点匹配,为-1表无点匹配  
  
	void init(int n,int m)  
	{  
		this->n=n;  
		this->m=m;  
		for(int i=1;i<=n;i++) g[i].clear();  
		memset(left,-1,sizeof(left));  
	}  
  
	//判断从左u点是否可以找到一条增广路  
	bool match(int u)  
	{  
		for(int i=0;i<g[u].size();i++)  
		{  
			int v=g[u][i];  
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
int main()
{
	int n,m,c;
	freopen("data.in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
    	MM.init(n,n);
        m=n;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d: (%d)",&x,&y);
            x++;
            for(int j=0;j<y;j++)
            {
            	scanf("%d",&c);
                //、、int c=read();
                //e[x].push_back(c);
                c++;
                MM.g[x].push_back(c);
            }
        }
        int ans=MM.solve();
        cout<<ans<<endl;
        printf("%d\n",n*2-ans);
    }

}