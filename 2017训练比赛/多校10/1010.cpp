/*
* @FileName: D:\代码与算法\2017训练比赛\多校10\1010.cpp
* @Author: Pic
* @Date:   2017-08-24 12:32:35
* @Last Modified time: 2017-08-24 16:22:20
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
 #include <climits>
#include <iostream>
const int MAXN=1000000+30;
const long long INF=1000000000100100;
using namespace std;

struct edge{
    long long to;
    long long cost;
    edge(int tv = 0, long long tc = 0):
        to(tv), cost(tc){}
};
typedef pair<long long ,int> P;
int N, R;
vector<edge> graph[MAXN];
long long dist[MAXN];     //最短距离
long long dist2[MAXN];    //次短距离
void solve(){
    for(int i=0;i<=N;i++) dist[i]=dist2[i]=INF;
    priority_queue<P, vector<P>, greater<P> > Q;
    dist[1] = 0;
    Q.push(P(0, 1));
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        //first为s->to的距离，second为edge结构体的to
        long long v = p.second;long long d = p.first;
        //当取出的值不是当前最短距离或次短距离，就舍弃他
        if(dist2[v] < d) continue;
        int rou=graph[v].size();
        for(int i = 0; i < rou; i++){
            edge &e = graph[v][i];
            long long d2 = d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                Q.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[v] < d2){
                 dist2[e.to] = d2;
                Q.push(P(dist2[e.to], e.to));

            }
        }
    }
}
void init()
{
	for(int i=0;i<=N+1;i++){
		graph[i].clear();
	}
}
int main(){
//	freopen("data.in","r",stdin);
	//cout<<1111<<endl;
    long long A, B;long long D;
    int t;
    scanf("%d",&t);
    while(t--){
		init();
		scanf("%d%d", &N, &R);
		for (int i = 0; i < R; i++) {
			scanf("%lld%lld%lld", &A, &B, &D);
			graph[A ].push_back(edge(B  , D));
			graph[B ].push_back(edge(A  , D));
		}
		solve();
		printf("%lld\n",dist2[N]);
    }
    return 0;
}
