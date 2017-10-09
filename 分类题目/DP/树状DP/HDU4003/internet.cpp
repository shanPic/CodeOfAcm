#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 10010;

namespace Adj {
    int size, head[MAXN];
    struct Node{
        int v, next, w;
    }E[MAXN*2];
    inline void initAdj() {
        size = 0;
        memset(head, -1, sizeof(head));
    }
    inline void addEdge(int u, int v, int w) {
        E[size].v = v;
        E[size].w = w;
        E[size].next = head[u];
        head[u] = size++;
    }
}
using namespace Adj;
//////////////////////////////
vector<int>adj[MAXN];
int f[MAXN][12];
bool vis[MAXN];
int n, m, k;

void dfs(int u) {
    vis[u] = true;
    for (int e = head[u]; e != -1; e = E[e].next) {
        int v = E[e].v;
        int w = E[e].w;
        if (vis[v]) continue;
        dfs(v);
        for (int i = k; i >= 1; --i) {
            for (int j = 1; j <= i; ++j)
                f[u][i] = max(f[u][i], f[u][i-j] + f[v][j] + 2*w - j*w);
        }
    }
}

int main(){

    while (~scanf("%d%d%d", &n, &m, &k)) {

        initAdj();
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            sum += w;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        dfs(m);
        printf("%d\n", sum * 2 - f[m][k]);
    }
    return 0;
}
