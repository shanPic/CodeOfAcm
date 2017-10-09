#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1005;

int sg[N];
int hash[21];
int f[17];//存储斐波那契数列

void fib() {
	f[1] = 1; f[2] = 2;
	for (int i = 3; i <= 16; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
}

void getsg() {
	fib();
	int i, j;
	sg[0] = 0; sg[1] = 1;
	for (i = 2; i <= N; i++) {
		for (j = 0; j <= 20; j++)    hash[j] = 0;

		for (j = 1; f[j] <= i; j++) {
			hash[sg[i - f[j]]] = 1;
		}
		for (j = 0; j <= 20; j++) {
			if (!hash[j]) {
				sg[i] = j;
				break;
			}
		}
	}
}

int main() {
	//freopen("data.in", "r", stdin);

	getsg();
	int n, m, p;
	while (~scanf("%d%d%d", &n, &m, &p)) {
		if (!n && !m && !p)    break;
		if (sg[n]^sg[m]^sg[p])
			printf("Fibo\n");
		else
			printf("Nacci\n");
	}
	return 0;
}