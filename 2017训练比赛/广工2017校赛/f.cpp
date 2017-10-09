#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define M 100100
using namespace std;
struct abcd {
	int to, next;
} table[M << 1];
int head[M], tot;
int n, m, a[M], fa[M], dpt[M];
int stack[60], top;
void Add(int x, int y)
{
	table[++tot].to = y;
	table[tot].next = head[x];
	head[x] = tot;
}
void DFS(int x)
{
	int i;
	dpt[x] = dpt[fa[x]] + 1;
	for (i = head[x]; i; i = table[i].next)
		if (table[i].to != fa[x])
		{
			fa[table[i].to] = x;
			DFS(table[i].to);
		}
}
bool Check(int x, int y)
{
	top = 0;
	if (dpt[x] < dpt[y])
		swap(x, y);
	while (dpt[x] > dpt[y])
	{
		stack[++top] = a[x];
		if (top >= 47) return true;
		x = fa[x];
	}
	while (x != y)
	{
		stack[++top] = a[x];
		stack[++top] = a[y];
		if (top >= 47) return true;
		x = fa[x]; y = fa[y];
	}
	stack[++top] = a[x];
	if (top >= 47) return true;
	sort(stack + 1, stack + top + 1);
	for (int i = 3; i <= top; i++)
		if (stack[i] - stack[i - 1] < stack[i - 2])
			return true;
	return false;
}
int main()
{
	int i, x, y, p;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		Add(x, y); Add(y, x);
	}
	DFS(1);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &p, &x, &y);
		if (!p)
			puts(Check(x, y) ? "Y" : "N");
		else
			a[x] = y;
	}
	return 0;
}