/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1005.cpp
* @Author: Pic
* @Date:   2017-07-30 14:53:58
* @Last Modified time: 2017-07-30 20:53:18
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 30;
const int INF=0x3f3f3f3f;
struct res {
	int l, r;
	int sum;
};
int n, k;
int t;
int a[MAXN];
struct node
{
	int i;
	int sum;
} pre[MAXN];
res ans;
long long getsum(int t, int l, int r)
{
	if (l >= r) return -1 * 0x3f3f3f3f;
	int sum = pre[r].sum - pre[l].sum;
	if (abs(t - sum) < abs(t - ans.sum)) {
		ans.l = min(pre[l].i, pre[r].i);
		ans.r = max(pre[l].i, pre[r].i);
		ans.sum = sum;
	}
	return sum;
}
void  cal(int t)
{
	int l = 0, r = 0, sum = -1;
	ans.l = 0, ans.r = 0, ans.sum = -1*INF;
	for (;;) {
		while (r < n && sum < t) {
			r++;
			sum = getsum(t, l, r);
		}
		if (sum < t) {
			break;
		}
		l++;
		sum = getsum(t, l, r);
	}
	getsum(t, l, r);

}
bool cmp(node a, node b)
{
	return a.sum < b.sum;
}
int main() {
	freopen("data.in", "r", stdin);
	while (~scanf("%d%d", &n, &k) && n && k) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		pre[0].sum = 0; pre[0].i = 0;
		for (int i = 0; i < n; i++) {
			pre[i + 1].i = i + 1;
			pre[i + 1].sum = pre[i].sum + a[i];
		}
		sort(pre, pre + n + 1, cmp);
		for (int i = 0; i < k; i++) {
			//ans.l=1,ans.r=n;
			scanf("%d", &t);
			cal(t);
			cout << abs(ans.sum) << " " << ans.l + 1 << " " << ans.r << "\n";
		}
	}
	return 0;
}
