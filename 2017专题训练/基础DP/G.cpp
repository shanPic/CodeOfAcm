/*
dp[i][j]表示的是在i点j时刻最多可以接到的馅饼
m[i][j]表示的是在i点j时刻落下多少馅饼
状态转移方程为：
dp[i][j]=max(dp[i-1][j-1],dp[i+1][j-1],dp[i][j-1])+m[i][j];
需要注意的还有，因为开始时位于点5，所以在5秒内不能到达所有位置
可以运用滚动数组进行空间优化
为了方便处理是否能到达的问题，从最后的时间向前进行dp
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int dp[15][MAXN];
int m[15][MAXN];
int max(int a, int b, int c)
{
	int ret = b;
	if (a > b)
	{
		ret = a;
	}

	if (ret < c)
	{
		ret = c;
	}
	return ret;
}
int main()
{
	//freopen("data.in","r",stdin);
	int n;
	int x, t;
	int maxt;
	while (cin >> n)
	{
		if (!n) break;
		memset(dp, 0, sizeof(dp));
		memset(m, 0, sizeof(m));
		maxt = -1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &t);
			m[x + 1][t]++;
			maxt = max(maxt, t);
		}
		for (int i = maxt; i >= 0; i--)
		{
			for (int j = 1; j <= 11; j++)
			{
				dp[j][i] = max(dp[j - 1][i + 1], dp[j + 1][i + 1], dp[j][i + 1]) + m[j][i];
				//dp[j][i]=max(dp[j][i],dp[j][i+1])+m[j][i];
			}
		}
		cout << dp[6][0] << endl;
	}
	return 0;
}
