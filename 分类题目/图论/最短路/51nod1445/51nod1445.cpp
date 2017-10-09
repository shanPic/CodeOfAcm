#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn=1000000+10;
struct Edge
{
	int from,to,dist,nxt;
	Edge():nxt(-1){};
	Edge(int f,int t,int d,int nxt):from(f),to(t),dist(d),nxt(nxt){}
};

struct BellmanFord
{
	int n,m;
    Edge edges[maxn];
    int G[maxn];
    int num;            //邻接表中边的条数
	bool inq[maxn];     //是否在队列中
	int d[maxn];        //s到各个点的距离
	int p[maxn];        //最短路中的上一条弧
	int cnt[maxn];      //进队次数

	void init(int n)
	{
		this->n=n;
        memset(G,-1,sizeof(G));
        num=0;
	}

	void AddEdge(int from,int to,int dist)
	{
		edges[num]=Edge(from,to,dist,G[from]);
		G[from]=num++;
	}

	bool negativeCycle(int s)
	{
	    //cout<<11111<<endl;
		queue<int> Q;
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++) d[i]=INF;
		inq[s]=true,d[s]=0,Q.push(s);	//将起点压入队列

		while(!Q.empty())
		{
			int u=Q.front(); Q.pop();
			inq[u]=false;
			for(int i=G[u];i!=-1;i=edges[i].nxt)
			{
				Edge &e=edges[i];
				if(d[e.to] > d[u]+e.dist)
				{
					d[e.to] = d[u]+e.dist;
					p[e.to] = i;
					if(!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to]=true;
						if(++cnt[e.to]>n) return true;
					}
				}
			}
		}
		return false;
	}
}BF;
int m[53][53];
int main()
{
    //freopen("data.in","r",stdin);
    int t;
    cin>>t;
    int n;
    char ch;
    while(t--){
        cin>>n;
        BF.init(n);
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ch;
                if(ch=='Y'){
                    m[i][j]=1;
                }
                else{
                    m[i][j]=0;
                }
            }
            getchar();
        }
        //for(int i=0;i<n;i++){for(int j=0;j<n;j++) cout<<m[i][j];cout<<endl;}
        for(int i=0;i<n;i++){
            int num=0;
            for(int j=0;j<n;j++){
                if(m[i][j]){
                    BF.AddEdge(i,j,num++);
                }
            }
        }
        BF.negativeCycle(0);
        if(BF.d[n-1]!=INF) cout<<BF.d[n-1]<<endl;
        else cout<<-1<<endl;
    }
}
