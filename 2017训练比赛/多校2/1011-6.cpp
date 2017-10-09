#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<algorithm>
#define eps 1e-8
#define MAX 1010
#define MOD 1999
using namespace std;
struct Node {
	int x, y;
	int next;
} A[MAX];
int X[MAX], Y[MAX];
int node, Hash[MOD];
void init() {
	node = 0;
	memset(Hash, -1, sizeof(Hash));
}
void insert(int x, int y) { //类似邻接表的存储方式
	int key = (x * x + y * y) % MOD;
	A[node].x = x; A[node].y = y;
	A[node].next = Hash[key];
	Hash[key] = node++;
}
bool search(int x, int y) {
	int key = (x * x + y * y) % MOD;
	for (int k = Hash[key]; k != -1; k = A[k].next) {
		if (x == A[k].x && y == A[k].y)return true;
	}
	return false;
}
int main()
{
	freopen("data.in","r",stdin);
	int N, i, j;
	while (~scanf("%d", &N)) {
		init();
		for (i = 0; i < N; ++i) {
			scanf("%d%d", &X[i], &Y[i]);
			insert(X[i], Y[i]);
		}
		int ans = 0;
		for (i = 0; i < N; ++i) { //已知正方形两点求另外两点的位置
			for (j = i + 1; j < N; ++j) {
				int x1, y1, x2, y2;
				x1 = X[i] + (Y[i] - Y[j]); y1 = Y[i] - (X[i] - X[j]);
				x2 = X[j] + (Y[i] - Y[j]); y2 = Y[j] - (X[i] - X[j]);
				if (search(x1, y1) && search(x2, y2))ans++; //存在该正方形
				x1 = X[i] - (Y[i] - Y[j]); y1 = Y[i] + (X[i] - X[j]);
				x2 = X[j] - (Y[i] - Y[j]); y2 = Y[j] + (X[i] - X[j]);
				if (search(x1, y1) && search(x2, y2))ans++;
			}
		}
		printf("%d\n", ans >> 2); //因为是按照边计算4条边所以除四
	}
	return 0;
}