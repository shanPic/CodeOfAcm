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
int node[MAXN];
int n,m;
int dfs(int x)
{
	for(int i=0;i<m;i++){
		for(int i=0;i<m;i++){
			if(G[x][i]&&!vis[i]){
				vis[i]=1;
				if(liner[i]==-1||dfs(liner[i])){
					liner[i]=x;
					return 1;
				}
			}
		}
	}
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
/*    std::ios::sync_with_stdio(false);
    std::cin.tie(0);*/
    int t;
    int x,xn,y;
    int flag;  //Îª×ó£¬rÎªÓÒ 
    while(cin>>t){
    	n=m=0;
    	memset(node,0,sizeof(node));
    	flag=0;
    	for(int i=0;i<t;i++){
    		scanf("%d:(%d)",&x,&xn);
    		if(node[x]!=0) {
    			if(node[x]==-1) {flag=1;int &tmp=n;}
    			else {flag=-1; int &tmp=m;}
    		}
    		else{
    			node[x]=1; flag=-1; int &tmp=m;
    		}
    		for(int j=0;j<xn;j++){
    			scanf("%d",&y);
    			node[y]=flag;
    			tmp++;
    		}
    		cout<<zuida()<<endl;
    	}
    }
}
