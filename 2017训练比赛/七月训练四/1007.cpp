/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1007.cpp
* @Author: Pic
* @Date:   2017-07-31 20:48:40
* @Last Modified time: 2017-07-31 21:26:48
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
typedef __int64 LL;
using namespace std;
const int MAXN = 1e7 + 30;
// LL m[MAXN + 1];
struct node
{
	LL l, r;
} res[1000000+3];
int cnt = 0;
void out(int i)
{
	cout<<"flag"<<i<<endl;
}
void solve(LL n)
{
	//out(2);
	LL l = 1, r = 1;
	LL sum = 0;
	for (;;) {
		//out(3);
		while (r*r <= n && sum < n) {
			sum += r*r;
			r++;
			if (sum == n) {
				res[cnt].l = l, res[cnt++].r = r-1;
			}
		}
		if(sum<n) break;
		sum -= l*l;
		l++;
		if (sum == n) {
			res[cnt].l = l, res[cnt++].r = r-1;
		}
	}
}
int main() {
	// for (int i = 0; i < MAXN; i++) {
	// 	m[i] = i * i;
	// }
	LL n;
	while (~scanf("%lld", &n)) {
		cnt = 0;
		solve(n);
		printf("%d\n", cnt);
		LL l, r;
		//out(1);
		for (int i = 0; i < cnt; i++) {
			l = res[i].l, r = res[i].r;
			//printf("%lld ", r - l + 1);
			cout<< r-l+1 <<" ";
			for (LL j = l; j <= r; j++) {
				//printf("%lld ", j);
				cout<<j<<" ";
			}
			//printf("\n");
			cout<<"\n";
		}
	}
	return 0;
}