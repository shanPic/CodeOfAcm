#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<iomanip>
#define INF 0x7ffffff
#define MAXN 1600
using namespace std;
const double eps=1e-10;
const double PI=acos(-1);
int vis[MAXN];
int G[MAXN][MAXN];
int liner[MAXN];
int n,m;
struct node
{
    int p,flag;
}mn[MAXN];
int dfs(int x)
{
		for(int i=0;i<m;i++){
			if(G[x][i]&&!vis[i]){
				vis[i]=1;
				if(liner[i]==-1||dfs(liner[i])){
					liner[i]=x;
					return 1;
				}
			}
		}
		return 0;
}
int zuida()
{
	memset(liner,-1,sizeof(liner));
	int res=0;
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) res++;
	}
	return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    #endif
    int t;
    int x,xn,y;
    int flag;  //1Îª×ó£¬-1ÎªÓÒ
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
    	//cout<<"--------------"<<endl<<n<<endl<<m<<endl<<"---------"<<endl;
        cout<<zuida()<<endl;
    }
}
