#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10005;
const int mod = 1e9;
int n, m;
struct Node {
    int u, v, w, next;
}node[maxn * 100];
int dis[maxn], pre[maxn], visited[maxn];
int head[maxn], num;
void init() {
    memset(visited, 0, sizeof(visited));
    memset(head, -1, sizeof(head));
    memset(dis, -1, sizeof(dis));
    memset(pre, 1000, sizeof(pre));
    num = 0;
}

inline void add(int u, int v, int w) {
    node[num].next = head[u];
    node[num].u = u;
    node[num].v = v;
    node[num].w = w;
    head[u] = num++;
}

int spfa() {
    int u, v, w;
    queue<int> que;
    que.push(0);
    visited[0] = 1;
    dis[0] = 0;
    while (!que.empty()) {
        u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = node[i].next) {
            v = node[i].v;
            w = node[i].w;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!visited[v]) {
                    visited[v] = 1;
                    que.push(v);
                    pre[v] = w;
                }
            }
        }
        visited[u] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dis[i]);
    }
    return ans;
}

int main() {
        //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d%d", &n, &m);
        
        if (n == 1) {
            printf("%d\n", 0);
            continue;
        }
        
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
        }
        for (int i = 1; i <= n; ++i) {
            add(0, i, 0);
        }
        printf("%d\n", spfa());
    }
}