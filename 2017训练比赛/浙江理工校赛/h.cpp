# include <iostream>
# include <cstdio>
# include <cstring>
# include <algorithm>
# include <vector>
# include <cmath>
# include <cstdlib>
# define INF 0x3f3f3f3f
# define LL long long
using namespace std;

const int maxn = 5003;
int h[maxn], v[maxn];
int mx[maxn][16];
int n, q;

void rmq_init()
{
	int i, j, t;
	for (j = 1; j <= n; j++) mx[j][0] = h[j];
	int m = floor(log((double)n) / log(2.0));
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++)
		{
			t = j + (1 << (i - 1));
			if (t <= n) mx[j][i] = max(mx[j][i - 1], mx[t][i - 1]);
			else mx[j][i] = mx[j][i - 1];
		}
	}
}

int rmq(int l, int r)
{
	int m = floor(log((double)(r - l + 1)) / log(2.0));
	int a = max(mx[l][m], mx[r - (1 << m) + 1][m]);
	return a;
}

int main()
{
	int t, k;
	scanf("%d", &t);
	while (t--)
	{
		memset(mx, 0, sizeof(mx));
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &h[i]);
		rmq_init();
		for (int i = 1; i <= n; ++i)
			scanf("%d", &v[i]);	//V[i]存储快乐值
		int l = 1, r = 1, sum = h[1], tot = v[1], ans = v[1], imax = 0; //sum为前缀和，tot为总快乐值，sum储存当前尺取的总花费
		while (r <= n) //写的比较丑。尺取法
		{
			ans = max(ans , tot);
			if (r == n)
				break;
			if (r + 1 <= n && sum + h[r + 1] - rmq(l, r + 1) <= k)
			{
				++r;
				tot += v[r];
				sum = sum + h[r];
				ans = max(ans, tot);
			}
			else
			{
				sum -= h[l];
				tot -= v[l];
				++l;
				while ( l < r && sum - rmq(l, r) > k)
				{
					sum -= h[l];
					tot -= v[l];
					++l;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}