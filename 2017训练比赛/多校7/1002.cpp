/*
* @FileName: D:\代码与算法\2017训练比赛\多校7\1002.cpp
* @Author: Pic
* @Date:   2017-08-15 14:01:47
* @Last Modified time: 2017-08-15 16:15:36
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
long long logk(long long k, long long m)
{
	return (long long)floor(log2(m) / log2(k));
}
int main() {
	freopen("data.out","w",stdout);
	//int t;
	//scanf("%d",&t);
	//cin>>t;
	//while(t--){
	cout<<logk(2,3)<<endl;
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			long long m = i, k = j;
			//scanf("%lld%lld",&m,&k);
			//cin>>m>>k;
			if (k != 1) {
				long long res = m + logk(k, m);
				cout << res << " ";
			}
			else {
				long long res = 0;
				switch (m % 4) {
				case 1: res = 1; break;
				case 2: res = m + 1; break;
				case 3: res = 0; break;
				case 4: res = m; break;
				}
				cout << res << " ";
			}
		}
		cout<<endl;
	}
	//}
	return 0;
}