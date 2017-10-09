/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练三\#1003-pro.cpp
* @Author: Pic
* @Date:   2017-07-22 15:22:03
* @Last Modified time: 2017-07-22 16:45:16
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 2e5 + 30;
struct node
{
	int s, aid, l, r;
};
node a[MAXN];
int tmp[MAXN];
bool cmp1(node a, node b)
{
	return (a.s < b.s) || ((a.s == b.s) && (a.aid > b.aid));
}
int n, c, f;
int main() {
	//freopen("data.in", "r", stdin);
	while (~scanf("%d%d%d", &n, &c, &f)) {
		for (int i = 0; i < c; i++) {
			scanf("%d%d", &a[i].s, &a[i].aid);
		}
		sort(a, a + c, cmp1);
		int tot = 0;
		int flag = -1;
		int res = -1;
		if (n > 1) {
			priority_queue<int> q;
			int i=0;
			for (i = 0; i < n / 2; i++) {
				q.push(a[i].aid);
				tot += a[i].aid;
			}
			for (; i < c - n / 2; i++) {
				flag = q.top();
				if (a[i].aid < flag) {
					a[i].l = tot;
					q.pop();
					tot -= flag;
					q.push(a[i].aid);
					tot += a[i].aid;
				}
				else {
					a[i].l = tot;
				}
			}
			while (!q.empty()) q.pop();
			tot = 0;
			i = c-1;
			for (; i >= c - n / 2; i--) {
				q.push(a[i].aid);
				tot += a[i].aid;
			}
			for (; i >= n / 2; i--) {
				flag = q.top();
				if (a[i].aid < flag) {
					a[i].r = tot;
					q.pop();
					tot -= flag;
					q.push(a[i].aid);
					tot += a[i].aid;
				}
				else {
					a[i].r = tot;
				}
				if (a[i].l + a[i].r+a[i].aid <= f) {
					res = i;
					break;
				}
			}
		}
		else{
			res=c-1;
		}
		if(res==-1){
			printf("-1\n");
		}
		else
			printf("%d\n", a[res].s);
	}
	return 0;

}