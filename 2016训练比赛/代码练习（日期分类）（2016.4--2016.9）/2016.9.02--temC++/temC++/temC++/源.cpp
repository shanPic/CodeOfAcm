#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int M = 1e5 + 10;
#define flag1 falg1
#define flag2 falg2
struct node
{
	int sum;//存储负数的个数
	int zero;//存储之前0的个数
	bool flag1;//标记此下标下是否为0,若为0,即flag=1
	bool flag2;
}a[M];
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int i)
{
	int sum = 0;
	for (; i>0; i -= lowbit(i)){
		sum += a[i].sum;
	}
	return sum;
}
int getzero(int i)
{
	int sum = 0;
	for (; i>0; i -= lowbit(i)){
		sum += a[i].zero;
	}
	return sum;
}
void updateNeg(int i, int v)
{
	for (; i <= M; i += lowbit(i)){
		a[i].sum += v;
	}
}
void updateZero(int i, int v)
{
	for (; i <= M; i += lowbit(i)){
		a[i].zero += v;
	}
}
int main()
{
	freopen("data.in", "r", stdin);
	int n, k;
	int buf;
	char ch;
	int l, r;
	while (cin >> n >> k){
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++){
			scanf("%d", &buf);
			if (buf<0){
				updateNeg(i, 1);
				a[i].falg2 = 1;
			}
			else if (buf == 0){
				updateZero(i, 1);
				a[i].flag1 = 1;
			}
		}
		for (int i = 1; i <= k; i++){
			scanf("%c%d%d", &ch, &l, &r);
			if (ch == 'C'){
				if (a[l].flag1 == 1 && r != 0){
					updateZero(l, -1);
				}
				else if (a[l].flag1 == 0 && r == 0){
					updateZero(l, 1);
				}
				else if (a[l].flag2 == 0 && r<0){
					updateNeg(l, 1);
				}
				else if (a[l].falg2 == 1 && r>0){
					updateNeg(l, -1);
				}
			}
			else{
				if (getzero(r) - getzero(l))
					cout << '0';
				else if ((getsum(r) - getsum(l)) % 2)
					cout << '-';
				else cout << '+';
			}
		}
	}
	cin >> ch;
}
																						