/*
* @FileName: D:\代码与算法\2017训练比赛\9.10沈阳网络赛\1008-4.cpp
* @Author: Pic
* @Date:   2017-09-10 14:18:16
* @Last Modified time: 2017-09-10 14:49:27
*/
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

typedef long long LL;

const int maxN = 100000 + 30;
const int maxM = maxN * 2;

struct edge
{
    int to;
    int next;
    int cap;
    int cost;
} e[maxM];

int head[maxN], tot;
int d[maxN], pre[maxN], path[maxN];
bool vis[maxN];
namespace IO{
    const int BUFFSIZE=20<<20;//<<10kb <<20MB
    char Buf[BUFFSIZE+1],*buf=Buf;
    size_t lastlen=0;
    void init(){lastlen=fread(Buf,1,BUFFSIZE,stdin);}
    template<class T>
    void read1(T& res){
        for(res=0;*buf<'0'||*buf>'9';buf++);
        while(*buf>='0'&&*buf<='9'){res=res*10+(*buf-'0');buf++;}
    }
    template<class T>
    void read2(T& res){
        int sgn=1;
        for(res=0;*buf<'0'||*buf>'9';buf++)if(*buf=='-')sgn=-1;
        while(*buf>='0'&&*buf<='9')res=res*10+(*buf-'0'),buf++;
        res=res*sgn;
    }

    template<class T>
    bool read3(T& res){
        for(res=0;*buf<'0'||*buf>'9';buf++);
        if(buf-Buf>=lastlen) return 0;
        while(*buf>='0'&&*buf<='9'){res=res*10+(*buf-'0');buf++;}
        return 1;
    }
    void readstring(char *c){
        for(;*buf=='\n'||*buf=='\t'||*buf==' ';buf++);
        while(((*buf!='\n')&&(*buf!='\t')&&(*buf!=' '))){*(c++)=*(buf++);}
        *c=0;
    }
}

void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addedge(int s, int t, int cap, int cost)
{
    e[tot].to = t; e[tot].cap = cap; e[tot].cost = cost; e[tot].next = head[s]; head[s] = tot++;
    e[tot].to = s; e[tot].cap = 0; e[tot].cost = -cost; e[tot].next = head[t]; head[t] = tot++;
}
int que[maxN], ptr;
int spfa(int s, int t)
{
    memset(d, -INF, sizeof(d));
    //memset(pre, -1, sizeof(pre));
    //memset(path, -1, sizeof(path));
    pre[s]=-1;
    memset(vis, false, sizeof(vis));
    int res = d[0];
    d[s] = 0;
    vis[s] = true;
    ptr = 0;
    que[ptr++] = s;
    while (ptr)
    {
        int u = que[--ptr];
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if (d[v] < d[u] + e[i].cost && e[i].cap > 0)
            {
                d[v] = d[u] + e[i].cost;
                pre[v] = u;
                path[v] = i;
                if (!vis[v])
                {
                    vis[v] = true;
                    que[ptr++] = v;
                }
            }
        }
        vis[u] = false;
    }
    return d[t] != res;
}

void MCMF(int s, int t, int &cost)
{
	cost = 0;
    while (spfa(s, t))
    {
        int minn = INF;
        for (int i = t; i != s && i != -1; i = pre[i])
            minn = min(minn, e[path[i]].cap);
        for (int i = t; i != s && i != -1; i = pre[i])
        {
            e[path[i]].cap -= minn;
            e[path[i] ^ 1].cap += minn;
        }
        if (d[t] < 0)
            break;
        cost += minn * d[t];
    }
}

int main()
{
    //freopen("data.in", "r", stdin);
    //cout<<2222<<endl;
    IO::init();
    //cout<<11111<<endl;
    int n, t;
    //scanf("%d", &t);
    IO::read1(t);
    //cout<<t<<endl;
    while (t--)
    {
        //scanf("%d", &n);
        IO::read1(n);
        //cout<<n<<endl;
        init();
        int s = 0, t = n + 1, cost;
        for (int i = 1; i <= n; i++)
        {
            //scanf("%d", &cost);
            IO::read1(cost);
            addedge(s, i, 1, -cost);
            addedge(i, t, 1, cost);
        }
        for (int i = 1; i < n; i++) {
            int u, v, k;
            //scanf("%d%d%d", &u, &v, &k);
            IO::read1(u);
            IO::read1(v);
            IO::read1(k);
            addedge(u, v, INF, -k);
            addedge(v, u, INF, -k);
        }
        cost = 0;
        MCMF(s, t, cost);
        printf("%d\n", cost);
        //IO::
    }
    return 0;
}