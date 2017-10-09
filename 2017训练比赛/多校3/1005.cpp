/*
* @FileName: D:\代码与算法\2017训练比赛\多校3\1005.cpp
* @Author: Pic
* @Date:   2017-08-01 12:32:00
* @Last Modified time: 2017-08-01 15:33:38
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+30;
typedef long long LL;
struct  node
{
	int b,c,nxt;	
	node(){};
	node(int b,int c,int nx):b(b),c(c),nxt(nx){};
};
node e[MAXN*2];
int cnt=0;
int head[MAXN];
void addedge(int a,int b,int c)
{
	e[cnt]=node(b,c,head[a]);
	head[a]=cnt;
	cnt++;
}
void init(int n)
{
	cnt=0;
	//memset(head,-1,sizeof(head));
	for(int i=0;i<=n;i++){
		head[i]=-1;
	}
}
int dis[MAXN];
struct qnode
{
	int i,dis,dep;
	qnode(){};
	qnode(int i,int dis,int dep):i(i),dis(dis),dep(dep){};
	bool operator<(const qnode &b) const
	{
		//return dis>b.dis;
		if(dep>b.dep) return 1;
		else if(dep==b.dep){
			return dis>b.dis;
		}
		return 0;
	}
};
void bfs(LL &res,int n,int k)
{
	priority_queue<qnode> q;
	//queue<qnode> q;
	q.push(qnode(1,0,0));
	int a,b,c;
	int num=-1;
	while(!q.empty()){
		qnode now=q.top(); 
		//qnode now=q.front();
		q.pop();
		num++;
		if(num>k) return;
		res+=now.dis;
		a=now.i;
		dis[a]=now.dis;
		for(int i=head[a];i!=-1;i=e[i].nxt){
			b=e[i].b,c=e[i].c;
			if(dis[b]!=0||b==1) {
				res-=c;
				continue;
			}
			q.push(qnode(b,dis[a]+c,now.dep+1));
		}
	}
}
int main(){
	freopen("data.in","r",stdin);
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		init(n);
		if(n==k) k--;
		int a,b,c;
		LL res=0;
		for(int i=0;i<n-1;i++){
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
			addedge(b,a,c);
			res+=c;
		}
		for(int i=0;i<=n;i++) dis[i]=0;
		//dfs(1,0,0);
		//sort(dis+2,dis+n+1);
		bfs(res,n,k);
		cout<<res<<"\n";
	}
    return 0;
}