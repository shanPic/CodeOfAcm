#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX_N 100000 + 16
int a[MAX_N];
pair<int, int> accumulation[MAX_N];	// sum <-> index
 
// 更新答案
int get_sum(int& result, const int& l, const int& r, const int& t, int& from, int& to)
{
	if (l >= r)
	{
		return -1*0x3f3f3f3f;	// 不合法，终止
	}
	int sum = accumulation[r].first - accumulation[l].first;
	if (abs(t - sum) < abs(t - result))	// 顺便记录一下可能的答案
	{
		result = sum;
		from = min(accumulation[l].second, accumulation[r].second);
		to = max(accumulation[l].second, accumulation[r].second);
	}
	return sum;
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif
	int n, k;
	while (cin >> n >> k && n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		accumulation[0] = make_pair(0, 0);	// 多留一个，待会儿免得下标跟答案对不上
		for (int i = 0; i < n; ++i)
		{
			accumulation[i + 1] = make_pair(accumulation[i].first + a[i], i + 1);
		}
		sort(accumulation, accumulation + n + 1);
		while (k--)
		{
			int t;
			cin >> t;
			// 输入结束
			int l = 0, r = 0, sum = 0x80808080, from, to, result = 0x80808080;
			for (;;)
			{
				while (r < n && sum < t)
				{
					sum = get_sum(result, l, ++r, t, from, to);	// ++r 头部前进
				}
				if (sum < t)
				{
					break;
				}
 
				sum = get_sum(result, ++l, r, t, from, to);	// ++l 尾部前进
			}
			cout << result << ' ' << from + 1 << ' ' << to << endl;
		}
	}
	return 0;
}