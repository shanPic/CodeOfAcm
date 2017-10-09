/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1001.cpp
* @Author: Pic
* @Date:   2017-07-27 10:58:04
* @Last Modified time: 2017-07-30 10:18:37
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN = 100000 + 30;
struct  node
{
	long long cost;
	int  aid;
	bool operator < (const node &b)const
	{
		return aid < b.aid;
	}
};
node a[MAXN];
int N, n, c;
long long f;
long long cal(int n,int k)
{
	priority_queue<node> q1;
	long long sum1=0;
	for (int i = 1; i <= n; i++) {
		q1.push(a[i]);
		sum1 += a[i].aid;
	}
	for (int i = n + 1; i < k ; i++) {
		if (a[i].aid < (q1.top().aid)) {
			sum1 -= (q1.top().aid);
			sum1 += a[i].aid;
			q1.push(a[i]);
		}
	}
	return sum1;
}
bool cmp(node a,node b)
{
	return a.cost<b.cost;
}
int main() {
	//freopen("data.in","r",stdin);
	while (~scanf("%d%d%lld", &N, &c, &f)) {
		for (int i = 1; i <= c; i++)
			scanf("%lld%d", &a[i].cost, &a[i].aid);
		n = N / 2;
		if(n==0){
			long long res=-1;
			long long ans=-1;
			for(int i=1;i<=c;i++){
				if(a[i].aid<=f){
					//res=max(res,(long long)a[i].aid);
					if(a[i].aid>=res){
						res=a[i].aid;
						ans=a[i].cost;
					}
				}
			}
			//printf("%lld\n",ans);
			cout<<ans<<"\n";
			continue;
		}
		sort(a+1,a+c+1,cmp);
		priority_queue<node> q2;
		long long sum1 = 0, sum2 = 0;
		for (int i = c; i > c - n; i--) {
			q2.push(a[i]);
			sum2+=a[i].aid;
		}
		long long res=-1;
		for (int i = c - n; i >n; i--) {
			sum1=cal(n,i);
			//cout<<sum1<<"\t"<<sum2<<endl;
			if(sum1+sum2+a[i].aid<=f){
				res=a[i].cost;
				break;
			}
			if(((q2.top().aid)>a[i].aid)){
				sum2-=(q2.top().aid);
				sum2+=a[i].aid;
			}
		}
		// for(int i=1;i<=c;i++){
		// 	cout<<a[i].cost<<"\t"<<a[i].aid<<endl;
		// }
		// cout<<res<<endl;
		//printf("%lld\n",res);
		cout<<res<<"\n";
	}
	return 0;
}