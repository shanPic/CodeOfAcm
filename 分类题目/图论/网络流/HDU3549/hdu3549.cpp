#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
const int maxn=15+5;//֮ǰ����ֻд10+5,һֱTLE,���Ǳ���

struct Edge
{
	Edge(){}
	Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){}
	int from,to,cap,flow;
};

struct Dinic
{
	int n,m,s,t;            //�����,����(��������),Դ��������
	vector<Edge> edges;     //�߱� edges[e]��edges[e^1]��Ϊ����
	vector<int> G[maxn];    //�ڽӱ�,G[i][j]��ʾ���i�ĵ�j������e�����е����
	bool vis[maxn];         //BFSʹ��,���һ���ڵ��Ƿ񱻱�����
	int d[maxn];            //d[i]������s��i��ľ���(���)
	int cur[maxn];          //cur[i]��ǰ������i�ڵ�ĵ�cur[i]����

	void init(int n,int s,int t)
	{
		this->n=n,this->s=s,this->t=t;
		for(int i=1;i<=n;i++) {
            G[i].clear();
            G[i].reserve(n*n);
		}
		edges.clear();
		edges.reserve(n*n);
	}

	void AddEdge(int from,int to,int cap)//capΪ�ߵ����������������
	{
		edges.push_back( Edge(from,to,cap,0) );
		edges.push_back( Edge(to,from,0,0) );
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	bool BFS()
	{
		memset(vis,0,sizeof(vis));
		queue<int> Q;//��������ڵ��ŵ�
		Q.push(s);
		d[s]=0;
		vis[s]=true;
		while(!Q.empty())
		{
			int x=Q.front(); Q.pop();
			for(int i=0; i<G[x].size(); i++)
			{
				Edge& e=edges[G[x][i]];
				if(!vis[e.to] && e.cap>e.flow)
				{
					vis[e.to]=true;
					d[e.to] = d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	//a��ʾ��s��xĿǰΪֹ���л�����С����
	//flow��ʾ��x��t����С����
	int DFS(int x,int a)
	{
		if(x==t || a==0)return a;
		int flow=0,f;//flow������¼��x��t����С����
		for(int& i=cur[x]; i<G[x].size(); i++)
		{
			Edge& e=edges[G[x][i]];
			if(d[x]+1==d[e.to] && (f=DFS( e.to,min(a,e.cap-e.flow) ) )>0 )
			{
				e.flow +=f;
				edges[G[x][i]^1].flow -=f;
				flow += f;
				a -= f;
				if(a==0) break;
			}
		}
		return flow;
	}

	int Maxflow()
	{
		int flow=0;
		while(BFS())
		{
			memset(cur,0,sizeof(cur));
			flow += DFS(s,INF);
		}
		return flow;
	}
}DC;
int main()
{
    int t,n,m;
    scanf("%d",&t);
    int cnt=0;
    while(t--){
        scanf("%d%d",&n,&m);
        DC.init(n,1,n);
        int b,e,c;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&b,&e,&c);
            DC.AddEdge(b,e,c);
        }
        printf("Case %d: %d\n",++cnt,DC.Maxflow());
    }
}
