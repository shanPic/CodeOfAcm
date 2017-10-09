//平面最近点对，使用分治法
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
const double eps = 1e-6;
const int MAXN = 100010;
const double INF = 1e20;
struct Point
{
	double x, y;
};
double dist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
Point p[MAXN];
Point tmpt[MAXN];
bool cmpxy(Point a, Point b)//排序时的比较函数
{
	if (a.x != b.x)return a.x < b.x;
	else return a.y < b.y;
}
bool cmpy(Point a, Point b)//按照y值排序
{
	return a.y < b.y;
}
double Closest_Pair(int left, int right)
{
	double d = INF;

	if (left == right)return d;
	if (left + 1 == right)
		return dist(p[left], p[right]);//递归边界

	int mid = (left + right) / 2;

	double d1 = Closest_Pair(left, mid);//分治求两个点集合的最近点对
	double d2 = Closest_Pair(mid + 1, right);

	d = min(d1, d2);
	int k = 0;
	for (int i = left; i <= right; i++)
	{
		if (fabs(p[mid].x - p[i].x) <= d)
			tmpt[k++] = p[i];
	}		//tmpt为与中线距离小于等于d的点的集合
	sort(tmpt, tmpt + k, cmpy);
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k && tmpt[j].y - tmpt[i].y < d; j++)
		{
			d = min(d, dist(tmpt[i], tmpt[j]));
		}
	}//合并分治结果
	return d;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		sort(p, p + n, cmpxy);//对p进行预排序
		printf("%.2lf\n", Closest_Pair(0, n - 1) / 2);
	}
	return 0;
}