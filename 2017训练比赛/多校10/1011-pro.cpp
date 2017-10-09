/*
* @FileName: D:\代码与算法\2017训练比赛\多校10\1011-pro.cpp
* @Author: Pic
* @Date:   2017-08-24 16:25:58
* @Last Modified time: 2017-08-24 16:48:25
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int maxn = 100000 + 30;
const int MAXN=maxn;
const long long INF = LLONG_MAX-50;

struct Node {
    int v, flag;
    long long c;
    Node (int _v = 0, long long _c = 0, int _flag = 0) : v(_v), c(_c), flag(_flag) {}
    bool operator < (const Node &rhs) const {
        return c > rhs.c;
    }
};

struct Edge {
    int v;
    long long cost;
    Edge (int _v = 0, long long _cost = 0) : v(_v), cost(_cost) {}
};

vector<Edge>E[maxn];
bool vis[maxn][2];
long long dist[maxn][2];
int path1[MAXN],path2[MAXN];
long long pathval[MAXN];
long long pathval2[MAXN];

void Dijkstra(int n, int s) {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    priority_queue<Node>que;
    dist[s][0] = 0;
    que.push(Node(s, 0, 0));
    while (!que.empty()) {
        Node tep = que.top(); que.pop();
        int u = tep.v;
        int flag = tep.flag;
        if (vis[u][flag]) continue;
        vis[u][flag] = true;
        for (int i = 0; i < (int)E[u].size(); i++) {
            int v = E[u][i].v;
            long long cost = E[u][i].cost;
            if (!vis[v][0] && dist[v][0] > dist[u][flag] + cost) {
                dist[v][1] = dist[v][0];
                dist[v][0] = dist[u][flag] + cost;
                path2[v]=path1[v];
                pathval2[v]=pathval[v];
                path1[v]=u;
                pathval[v]=cost;
                que.push(Node(v, dist[v][0], 0));
                que.push(Node(v, dist[v][1], 1));
            } else if (!vis[v][1] && dist[v][1] > dist[u][flag] + cost) {
                dist[v][1] = dist[u][flag] + cost;
                path1[v]=u;
                pathval[v]=cost;
                que.push(Node(v, dist[v][1], 1));
            }
        }
    }
}

void addedge(int u, int v, int w) {
    E[u].push_back(Edge(v, w));
}

int main() {
    //freopen("data.in", "r", stdin);
    int t;
    scanf("%d",&t);
	while (t--) {
		int n, m, u, v;long long w;
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) E[i].clear();
		for (int i=0;i<m; i++) {
			scanf("%d%d%lld", &u,&v, &w);
			addedge(u, v, w);
		}
		memset(path1,-1,sizeof(path1));
		 memset(path2,-1,sizeof(path2));
		 pathval[0]=pathval[1]=INF;
		 pathval[0]=pathval2[1]=INF;
		Dijkstra(n, 1);
		if(dist[n][1]>=INF||dist[n][1]<=-1*INF){
			//cout<<dist[N-1]<<"\t"<<dist2[N-1]<<endl;
			long long res=pathval[n];
			int i=path1[n];
			while(i!=-1){
				res=min(res,pathval[i]);
				i=path1[i];
			}
			i=path2[n];
			while(i!=-1){
				res=min(res,pathval2[i]);
				i=path2[i];
			}
			for(int i=2;i<n;i++){
				res=min(res,dist[i][0]);
			}
			printf("%lld\n",dist[n][0]+2*res);
			continue;
		 }
		printf("%lld\n", dist[n][1]);
	}
    return 0;
}