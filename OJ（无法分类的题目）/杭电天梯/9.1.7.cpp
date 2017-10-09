#include <bits/stdc++.h>
using namespace std;

typedef struct Edge
{
    int beg, end;
} Edge;

Edge edge[3001];
int Sum[101] = {0};
int Map[101][101];
bool visited[101];
int prec[101][101];     // prec[x][y],用来存储第一遍第x个节点的BFS树中y节点的上一个节点
int N, M;

int BFS(int k, bool is_preprocess = true)//第二个参数表示的是否是第一遍遍历所有节点
{
    int dis[101] = {0}; //记录到根节点的距离
    memset(visited, false, sizeof(visited));
    queue<int> Q;
    visited[k] = true;
    Q.push(k);
    int cnt = 1;
    int Sum = 0;
    while (!Q.empty())
    {
        int i = Q.front(); Q.pop();
        for (int j = 1; j <= N; ++j)
        {
            if (!visited[j] && Map[i][j] > 0)
            {
                visited[j] = true;
                if (is_preprocess)
                    prec[k][j] = i; //记录前驱，只记录第一次遍历的BFS树的节点前驱，由于BFS时要对每个节点都进行一遍BFS所以需要记录n个BFS树
                dis[j] = dis[i] + 1;   //记录到根节点的距离
                Sum += dis[j];
                ++cnt;              //记录一下BFS中的节点数目，最后判断是否能够到达所有节点（cnt==N）
                Q.push(j);
            }
        }
    }
    return (cnt == N) ? Sum : -1;
}

int main()
{
    int x, y, sum ;
    while (cin >> N >> M)
    {
        memset(Sum, 0, sizeof(Sum));
        memset(Map, 0, sizeof(Map));
        memset(prec, 0, sizeof(prec));
        int i = 1;
        for ( ; i <= M; ++i)
        {
            //建树
            cin >> x >> y;
            Map[x][y]++;
            Map[y][x]++;//这样记录路径的话，可以方便的记录重边
            edge[i].beg = x;
            edge[i].end = y;
        }
        sum = 0;
        i = 1;
        for (; i <= N; ++i)
        {
            Sum[i] = BFS(i);  //需要存储每个节点的BFS树的路径和
            if (Sum[i] == -1)
                break;
            else
                sum += Sum[i];
        }
        if (i <= N)      //优化：原图为非连通图，无论删哪条边，距离恒为INF
        {
            for (int i = 0; i < M; ++i)
                puts("INF");
            continue;
        }
        for (int i = 1; i <= M; ++i)
        {
            int x = edge[i].beg;
            int y = edge[i].end;
            if (Map[x][y] > 1)           //优化：有重边，删除其中一条对全图无影响
            {
                cout << sum << endl;
            }
            else                    //删的是割边（不可能有Map[][]==0,因为前边过滤了非连通图）
            {
                int sum1 = 0, j = 1, s1;
                for (; j <= N; ++j)//遍历全部顶点，蛮力法
                {
                    if (prec[j][y] == x || prec[j][x] == y) //x-y在第j棵bfs树上，只能蛮力
                    {
                        Map[x][y] = Map[y][x] = 0;  //删边

                        s1 = BFS(j, false);
                        if (s1 == -1) //非连通，直接返回INF
                        {
                            Map[x][y] = Map[y][x] = 1;  //恢复边
                            break;                      //跳转到114行
                        }
                        sum1 += s1;
                        Map[x][y] = Map[y][x] = 1;  //恢复边
                    }
                    else
                    {
                        sum1 += Sum[j];
                    }
                }
                if (j <= N)
                {
                    puts("INF");
                    //  continue;
                }
                else
                {
                    cout << sum1 << endl;
                }
            }
        }
    }
    return 0;
}
