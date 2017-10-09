#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int M = 1e6;
const int inf = 0x3f3f3f3f;
int val[M], qmax[M], qmin[M];
int n, k;
int head1, tail1, head2, tail2;
void Min()
{
	for (int i = 0; i<k; i++){
		while (head1 <= tail1&&val[qmin[tail1]] >= val[i])
			tail1--;
		tail1++;
		qmin[tail1] = i;
	}
	for (int i = k; i<n; i++){
		while (head1 <= tail1&&val[qmin[tail1]] >= val[i])
			tail1--;
		tail1++;
		qmin[tail1] = i;
		while (head1 <= tail1&&qmin[head1]<i - k)
			head1++;
		printf("%d ", val[qmin[head1]]);
	}
	cout << endl;
}
void Max()
{
	for (int i = 0; i<k; i++){
		while (head2 <= tail2&&val[qmax[tail2]] <= val[i])
			tail2--;
		tail2++;
		qmax[tail2] = i;
	}
	for (int i = k; i<n; i++){
		while (head2 <= tail2&&val[qmax[tail2]] <= val[i])
			tail2--;
		tail2++;
		qmax[tail2] = i;
		while (head2 <= tail2&&qmax[head2]<i - k)
			head2++;
		printf("%d ", val[qmax[head2]]);
	}
	cout << endl;
}
int main()
{
	freopen("data.in", "r", stdin);
	while (cin >> n >> k){
		for (int i = 0; i<n + 10; i++){
			qmin[i] = 0;
			qmax[i] = 0;
		}
		for (int i = 0; i<n; i++){
			scanf("%d ", &val[i]);
		}
		head1 = head2 = 0;
		tail1 = tail2 = 1;
		Min();
		Max();
	}
	getchar();
}
