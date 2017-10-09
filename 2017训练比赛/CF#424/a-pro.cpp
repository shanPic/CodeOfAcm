/*
* @Author: zhans
* @Date:   2017-08-18 09:44:32
* @Last Modified by:   zhans
* @Last Modified time: 2017-08-18 21:21:47
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2000 + 30;
int per[MAXN], key[MAXN];
int vis[MAXN], vis2[MAXN];
int cnt;
int n, k, p;
bool ok(long long mid)
{
	//memset(vis,0,sizeof(vis));
	ll output = 0;
	ll now = 1;
	for (ll i = 1; i <= n; i++)
	{
		while (now <= k && abs(key[now] - per[i]) + abs(key[now] - p) > mid)
		{
			now++;
		}
		if (now <= k)
		{
			now++;
			output++;
		}
		else break;
	}
	if (output >= n)return 1;
	else return 0;
}
int main()
{
	// freopen("data.in", "r", stdin);
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &per[i]);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &key[i]);
	}
	//for(int i=0;i<k;i++) mp[i]=i;
	sort(per+1, per + n+1);
	sort(key+1, key + k+1);
	long long l = 0, r = 2e9;
	while (r - l > 1) {
		long long mid = (l + r) / 2;
		if (ok(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	if(ok(l)) r=l;
	printf("%I64d\n", r);
}