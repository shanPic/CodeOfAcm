#include<bits/stdc++.h>
using namespace std;
const int N=24;
struct node
{
	int x, y, key, dist;//key为钥匙状态，dist为走过的距离
};

char mm[N][N], str[N];//mm存储地图
int flag[N][N][1 << 11], sx, sy, ans;//这里的标记数组采用了状态压缩的方法来记录钥匙
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<node> q;

void bfs()
{
	while (!q.empty()) q.pop();
	node t, nt;
	t.x = sx;
	t.y = sy;
	t.key = 0;
	t.dist = 0;
	q.push(t);
	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nt.dist = t.dist + 1;
			nt.key = t.key;
			nt.x = t.x + dx[i];
			nt.y = t.y + dy[i];
			if (mm[nt.x][nt.y] == '^' ) {
				ans = nt.dist;
				return ;
			}
			else if ('a' <= mm[nt.x][nt.y] && mm[nt.x][nt.y] <= 'z') {
				nt.key = t.key | (1 << (mm[nt.x][nt.y] - 'a'));//记录钥匙类型
			}
			if (mm[nt.x][nt.y] != '*' && flag[nt.x][nt.y][nt.key] == 0 && nt.dist < ans) {
				flag[nt.x][nt.y][nt.key] = 1;
				if ('A' <= mm[nt.x][nt.y] && mm[nt.x][nt.y] <= 'Z') {
					if ((nt.key & (1 << (mm[nt.x][nt.y] - 'A')))) //判断是否存在此类型的钥匙
						q.push(nt);
				}
				else q.push(nt);
			}
		}
	}
}

int main()
{
	int n, m, t;
	while (scanf("%d%d%d", &n, &m, &t) != EOF) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mm[i][j] = '*';
				memset(flag[i][j], 0, sizeof(flag[i][j]));
			}
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", str);
			for (int j = 1; j <= m; j++) {
				mm[i][j] = str[j - 1];
				if ('@' == mm[i][j]) sx = i, sy = j, mm[i][j] = '.';
			}
		}
		ans = t;
		bfs();
		if (ans < t) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}
