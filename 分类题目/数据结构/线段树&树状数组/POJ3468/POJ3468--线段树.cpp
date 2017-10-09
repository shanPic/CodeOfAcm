#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int M = 4*100010;
long long sumv[M];//线段树sum数组
long long add[M];
long long  x, y;//全局变量,update与query时使用
long long  addval;
long long  _sum;
//*********************//
void update(int id, int l, int r)
{
	long long m = l + (r - l) / 2;
	if (x <= l&&y >= r){
		add[id] += addval;
	}
	else{
		if (x <= m) update(2 * id, l, m);
		if (y>m) update(2 * id + 1, m+1, r);
	}
	sumv[id]=0;//!!!!!!!!!注意此步骤
    if (l<r){
		sumv[id] = sumv[2 * id] + sumv[2 * id + 1];
	}
	sumv[id] += add[id] * (r - l + 1);
}
void query(int id, int l, int r, long long addv)
{
	long long  m = l + (r - l) / 2;
	if (x <= l&&y >= r){
		_sum += sumv[id] + addv*(r - l + 1);
	}
	else{
        //addv += add[id];
		if (x <= m){
			query(2 * id, l, m, addv+add[id]);
		}
		if (y>m) query(2 * id + 1, m+1, r, addv+add[id]);
	}
}
int main()
{
	//freopen("data.in", "r", stdin);
	//freopen("data.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	long long  n, q;
	while (cin >> n >> q){
		memset(sumv, 0, sizeof(sumv));
		memset(add, 0, sizeof(add));
		for (int i = 1; i <= n; i++){
			cin >> addval;
			x = i;
			y = i;
			update(1, 1, n);
		}
		string ch;
		for (int i = 0; i<q; i++){
			cin >> ch;
			if (ch == "Q"){
				_sum = 0;
				cin >> x >> y;
				query(1, 1, n, 0);
				cout << _sum << endl;
			}
			if (ch == "C"){
				cin >> x >> y >> addval;
				update(1, 1, n);

			}
		}
	}
}
