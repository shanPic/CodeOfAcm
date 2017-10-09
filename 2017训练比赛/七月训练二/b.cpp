/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\b.cpp
* @Author: Pic
* @Date:   2017-07-15 21:00:40
* @Last Modified time: 2017-07-16 00:20:29
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 20 + 3;
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ok;
int h, w;
int gx, gy;
int res;
void dfs(int x, int y, int cnt)
{
	//cout<<1111111<<endl;
	if (cnt > 10) {
		return;
	}
	if (x == gx && y == gy) {
		ok = 1;
		res = min(res, cnt);
		return;
	}
	int tmpx, tmpy;
	for (int i = 0; i < 4; i++) {
		int num=0;
		tmpx = x + dir[i][0], tmpy = y + dir[i][1];
		while (tmpx >= 0 && tmpx < w && tmpy >= 0 && tmpy < h && mp[tmpx][tmpy] == 0) {
			num++;
			if(cnt+1<=10)
			if (tmpx == gx && tmpy == gy) {
				ok = 1;
				res = min(res, cnt + 1);
				return;
			}
			tmpx += dir[i][0], tmpy += dir[i][1];
		}
		if (!vis[tmpx][tmpy]) {
			if(!(tmpx >= 0 && tmpx < w && tmpy >= 0 && tmpy < h )) continue;
			if(!num) continue;
			vis[tmpx-dir[i][0]][tmpy-dir[i][1]] = 1;
			if (mp[tmpx][tmpy]) {
				mp[tmpx][tmpy] = 0;
				dfs(tmpx-dir[i][0], tmpy-dir[i][1], cnt + 1);
				mp[tmpx][tmpy] = 1;
			}
			vis[tmpx-dir[i][0]][tmpy-dir[i][1]] = 0;
		}
	}
}
int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int bx, by;
	while ((~scanf("%d%d", &w, &h)) && w != 0 && h != 0) {
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf("%d", &mp[i][j]);
				if (mp[i][j] == 2) {
					bx = i, by = j;
					mp[i][j] = 0;
				}
				else if (mp[i][j] == 3) {
					gx = i, gy = j;
					mp[i][j] = 0;
				}
			}
		}
		res = 0x3f3f3f3f;
		ok = 0;
		memset(vis, 0, sizeof(vis));
		dfs(bx, by, 0);
		if (ok) {
			printf("%d\n", res);
		}
		else {
			printf("-1\n");
		}
	}
	//system("pause");
	return 0;
}
