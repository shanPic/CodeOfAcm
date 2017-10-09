#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int M = 1e5 + 10;
int MN;
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
	for (; i <= MN; i += lowbit(i)){
		a[i].sum += v;
	}
}
void updateZero(int i, int v)
{
	for (; i <= MN; i += lowbit(i)){
		a[i].zero += v;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int n, k;
	int buf;
	char ch;
	int l, r;
	while (cin >> MN>> k){
		memset(a, 0, sizeof(a));
		for (int i = 1; i <=MN; i++){
			//scanf("%d", &buf);
			cin>>buf;
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
			//scanf("%c %d %d", &ch, &l, &r);
			cin >> ch >> l >> r;
			if (ch == 'C'){
				if (a[l].flag1 == 1 && r != 0){
					//cout << 1111111111111 << endl;
					updateZero(l, -1);
				}
				else if (a[l].flag1 == 0 && r == 0){
					//cout << 22222222222222 << endl;
					updateZero(l, 1);
				}
				else if (a[l].flag2 == 0 && r<0){
					//cout << 333333333333 << endl;
					updateNeg(l, 1);
				}
				else if (a[l].falg2 == 1 && r>0){
					//cout << 444444444444444 << endl;
					updateNeg(l, -1);
				}
			}
			else{
				int rr = getsum(r);
				int ll = getsum(l-1);
				if (getzero(r) - getzero(l-1))
					cout << '0';
				else if ((rr-ll) % 2/*||(rr==ll&&rr!=0&&ll!=0)*/){
					cout << '-' ;
				}
				else cout << '+' ;
			}
		}
		cout << endl;
	}
}
