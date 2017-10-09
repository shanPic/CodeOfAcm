//HDU 1026
//光搜 + 优先队列，需要记录路径
#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;
const int MAXN = 110;
struct node
{
    int x, y;
    int time;
    friend bool operator<(node a, node b) //time小的优先级高
    {
        return a.time > b.time;
    }
};
priority_queue<node>que; //优先队列
struct cmap
{
    int nx, ny; //记录前驱，用来记录路径
    char c;
} map[MAXN][MAXN]; //记录map
int n, m;
int fight[MAXN][MAXN], mark[MAXN][MAXN];
int bfs()//从目标点开始搜索，搜索到起点。记录搜索的前驱，就记录下路径了
{
    int k;
    int dir[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
    node now, next;
    while (!que.empty())  que.pop();//初始化
    now.x = n - 1; now.y = m - 1;
    if (map[now.x][now.y].c >= '1' && map[now.x][now.y].c <= '9')
    {
        now.time = map[n - 1][m - 1].c - '0';
        fight[now.x][now.y] = map[now.x][now.y].c - '0';
    }
    else  now.time = 0;

    que.push(now);
    while (!que.empty())
    {
        now = que.top();
        que.pop();
        if (now.x == 0 && now.y == 0)  return now.time;
        for (k = 0; k < 4; k++)
        {
            next.x = now.x + dir[k][0];
            next.y = now.y + dir[k][1];
            if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m &&
                    !mark[next.x][next.y] && map[next.x][next.y].c != 'X')
            {
                if (map[next.x][next.y].c >= '1' && map[next.x][next.y].c <= '9')
                {
                    next.time = now.time + map[next.x][next.y].c - '0' + 1;
                    fight[next.x][next.y] = map[next.x][next.y].c - '0';

                }
                else next.time = now.time + 1;
                que.push(next);
                map[next.x][next.y].nx = now.x;
                map[next.x][next.y].ny = now.y;
                mark[next.x][next.y] = 1;
            }
        }
    }
    return -1;
}
int main()
{
    int i, j, flag, x, y, tx, ty, sec;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                scanf(" %c", &map[i][j].c); //前面一个空格很关键
                mark[i][j] = fight[i][j] = 0;
            }
        mark[n - 1][m - 1] = 1;
        flag = bfs();
        if (flag != -1)
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n", flag);
            sec = 1, x = y = 0;
            while (sec != flag + 1)
            {
                printf("%ds:(%d,%d)->(%d,%d)\n", sec++, x, y, map[x][y].nx, map[x][y].ny);
                for (i = 0; i < fight[map[x][y].nx][map[x][y].ny]; i++)
                    printf("%ds:FIGHT AT (%d,%d)\n", sec++, map[x][y].nx, map[x][y].ny);
                tx = map[x][y].nx;
                ty = map[x][y].ny;
                x = tx; y = ty;
            }

        }
        else
            printf("God please help our poor hero.\n");
        printf("FINISH\n");


    }
    return 0;
}