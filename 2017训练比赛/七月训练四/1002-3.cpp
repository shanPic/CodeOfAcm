/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1002-3.cpp
* @Author: Pic
* @Date:   2017-07-24 21:07:16
* @Last Modified time: 2017-07-24 22:31:49
*/
//二分答案mid，当原边权小于等于mid新边权为0，否则新边权为1.
//求最短路，若小于等于k说明满足条件。
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN = 1000+30;
const int MAXM = MAXN*MAXN;
#define INF 1e9
struct HeapNode {//Dijkstra算法用到的优先队列的节点
    int d,u;
    HeapNode(){};
    HeapNode(int d,int u):d(d),u(u){}
    bool operator < (const HeapNode &rhs)const
    {
        return d > rhs.d;
    }
};
struct Edge
{
	int from,to,dist;
	int nxt;
	Edge():nxt(-1){};
	Edge(int a,int b,int d,int nx):from(a),to(b),dist(d),nxt(nx){};
}edge[MAXM];
int cnt=0;
int head[MAXN];
void addedge(int x,int y,int d)
{
	edge[cnt]=Edge(x,y,d,head[x]);
	head[x]=cnt++;
}
int d[MAXN];
void init(int n)
{
	for(int i=0;i<=n;i++) head[i]=-1;
	cnt=0;
}
bool done[MAXN];
int n,p,k;
int dj(int s,int x)
{
	memset(d,0x3f,sizeof(d));d[s]=0;
	for(int i=1;i<=n;i++){done[i]=0;}
	priority_queue<HeapNode> q;
	q.push(HeapNode(0,s));
	HeapNode tmp;
	while(!q.empty()){
		tmp=q.top();q.pop();
		//int now=head[tmp.u];
		//if(d[tmp.u]<tmp.d) continue;
		if(done[tmp.u]) continue;
		done[tmp.u]=1;
		int u=tmp.u;
		// while(now!=-1){
		// 	//cout<<11111<<endl;
		// 	int mod=0;
		// 	Edge &e=edge[now];
		// 	if(e.dist >= x){
		// 		mod=1;
		// 	}
		// 	if(d[e.to]>d[tmp.u]+mod){
		// 		d[e.to]=d[tmp.u]-mod;
		// 		q.push(HeapNode(d[e.to],e.to));
		// 	}
		// 	now=edge[now].nxt;
		// }
		int mod=0;
		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			mod=0;
			Edge &e = edge[i];
			if(e.dist >= x) mod=1;
			if (d[e.to] > d[u] + mod)
			{
				d[e.to] = d[u] + mod;
				q.push(HeapNode(d[e.to],e.to));
			}
		}
	}
	return d[n];
}
int main(){
	freopen("data.in","r",stdin);
	while(~scanf("%d%d%d",&n,&p,&k)){
		init(n);
		int x,y,d;
		int maxl=-1;
		for(int i=0;i<p;i++){
			scanf("%d%d%d",&x,&y,&d);
			addedge(x,y,d);
			addedge(y,x,d);
			maxl=max(d,maxl);
		}
		int l=0,r=maxl+2;
		while(r-l>1){
			int mid=l+((r-l)>>1);
			if(dj(1,mid) <= k){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		if(r>=maxl){
			printf("-1\n");
		}
		else{
			printf("%d\n",l);
		}
	}
    return 0;
}