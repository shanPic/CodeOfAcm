/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练一\S.cpp
* @Author: Pic
* @Date:   2017-07-06 20:10:48
* @Last Modified time: 2017-07-06 21:46:01
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 30;
int n;
int nxt[MAXN];
char a[MAXN];
void kmp_pre()
{
	int i, j;
	j = nxt[0] = -1;
	i = 0;
	while (i < n)
	{
		while (-1 != j && a[i] != a[j])
			j = nxt[j];
		nxt[++i] = ++j;
	}
}
bool vis[MAXN];
const int MOD = 10007;
int sum[MAXN];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int res = 0;
		scanf("%d\n%s", &n, a);
		memset(sum, 0, sizeof(sum));
		kmp_pre();
		for (int i = 2; i <= n; i++) {
			if (nxt[i] != 0) {
				sum[i] = 1;
				sum[i]+=sum[nxt[i]];
			}
		}
		// for (int i = 1; i <= n; i++)
		// {
		// 	cout << sum[i] << "\t";
		// }
		// cout << endl;
		int aa, b;
		res++;
		for (int i = 2; i <= n; i++) {
			res++;
			if (nxt[i] != -1 && nxt[i] != 0) {
				//cout << i << "\t" << nxt[i] << endl;
				res += sum[i];
				res = res % MOD;
			}
			//cout << res << endl;
		}
		printf("%d\n", (res) % MOD);
	}
	return 0;
}