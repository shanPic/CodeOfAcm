#include<iostream>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;
#define INF 1e9
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
    int num;            //�ڽӱ��бߵ�����
	bool inq[maxn];     //�Ƿ��ڶ�����
	int d[maxn];        //s��������ľ���
	int p[maxn];        //���·�е���һ����
	int cnt[maxn];      //���Ӵ���

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
		queue<int> Q;
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++) d[i]=INF;
		inq[s]=true,d[s]=0,Q.push(s);	//�����ѹ�����

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
int main()
{
    int n,m;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        BF.init(n);//nΪ��ĸ���

        while(m--) {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            u--,v--;
            BF.AddEdge(u,v,d);
        }
        BF.negativeCycle(0);

        long long ans=0;
        for(int i=1; i<n; i++)
            printf("%I64d\n",BF.d[i]);
    }
    return 0;
}
