/* * @FileName: D:\代码与算法\2017训练比赛\8.27中国海洋比赛\g.cpp
* @Author: Pic
* @Created Time: 2017/8/27 13:53:05
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=50+3;
struct edge
{
	int from,to,nxt;
	edge(){};
	edge(int _to,int _nxt):to(_to),nxt(_nxt){};
}e[2500+30];
int head[MAXN];int cnt=0;
void addedge(int from,int to)
{
	e[cnt].from=from;
	e[cnt].to=to,e[cnt].nxt=head[from];
	head[from]=cnt;
	cnt++;
}
double dp[MAXN][2];
int dfsvis[MAXN];
gl dfs(double gl,int now)
{
	if(now==N){
		dp[now][0]=dp[now][1]=gl;
		return gl;
	}
	double tmp=gl*(1.0/(double)outq[now]);
	double res0=0,res1=0;
	int flagt=0;
	int flag-0;
	for(int i=head[now];i!=-1;i=e[i].nxt){
		int v=e[i].to;
		if(!vis[v]){
			if(dfs(tmp,v)){
				res0+=dp[v][0];
				flag=1;
			}
			else{
				flagt=1;
			}
		}
	}
	if(flag) return 1;
	return 0;
}
void init()
{
	memset(outq,0,sizeof(outq));
	cnt=0;
	memset(head,-1,sizeof(head));	
}
int main()
{
//	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	 int t;
	 scanf("%d",&t);
	 int ca=0;
	 while(t--){
		 int m;
		scanf("%d%d",&N,&m);
		int x,y;
		init();
		for(int i=0;i<m;i++){
			scanf("%d%d",&x,&y);
			addedge(x,y);
			outq[x]++;	
			flag[i]=1;
		}
		tmp=0;
		memset(dfsvis,0,sizeof(dfsvis));
		dfs1(1,1);
		double ans=tmp;
		
		printf("Case #%d: %.06f\n",++ca,ans);
	 }
	return 0;
}

