/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1003-pro.cpp
* @Author: Pic
* @Date:   2017-07-30 20:06:39
* @Last Modified time: 2017-07-30 21:00:18
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
#include <iomanip>
using namespace std;
double res=0;
int n;double a;
bool fun(double mid)
{
	double now=mid,pre=a,nxt=0;
	for(int i=2;i<n;i++){
		nxt=now*2+2.0-pre;
		if(nxt<0){
			return 0;
		}
		pre=now;now=nxt;
	}
	res=now;
	return 1;
}
int main(){
	while(~scanf("%d%lf",&n,&a)){
		double l=0,r=a+3.0;
		res=6666666*1.0;
		double ans=0x3f3f3f3f*1.0;
		for(int i=0;i<88;i++){
			double mid=(l+r)/2;
			if(fun(mid)){
				ans=min(ans,res);
				r=mid;
			}
			else{
				l=mid;
			}
		}
		//printf("%.2lf\n",ans);
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
    return 0;
}