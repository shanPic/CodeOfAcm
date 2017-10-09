/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\1014.cpp
* @Author: Pic
* @Date:   2017-07-18 01:08:33
* @Last Modified time: 2017-07-18 01:30:31
*/

#include <cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+30;
struct  node
{
	int d,t;
};
node a[MAXN];
bool cmp(node a,node b)
{
	return ((a.d*1.0)/(a.t*1.0))>((b.d*1.0)/(b.t*1.0));
}
int main(){
	//freopen("data.in","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].t,&a[i].d);
		}
		sort(a,a+n,cmp);
		long long tot=0;
		long long res=0;
		for(int i=0;i<n;i++){
			res+=(a[i].d*tot);
			tot+=(a[i].t*2);
		}
		printf("%lld\n",res);
	}
    return 0;
}