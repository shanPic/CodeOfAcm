/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\1013.cpp
* @Author: Pic
* @Date:   2017-07-18 21:18:53
* @Last Modified time: 2017-07-18 21:39:24
*/

#include <cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;
const int MAXN=130;
double a[MAXN];
int main(){
	//freopen("data.in","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%lf",&a[i]);
		}
		//sort(a,a+n);
		int i=n;
		while(i>1){
			sort(a,a+i);
			double tmp=2*sqrt(a[i-1]*a[i-2]);
			a[i-2]=tmp;
			i--;
		}
		//printf("%.3lf\n",a[0]);
		cout<<fixed<<setprecision(3)<<a[0]<<"\n";
	}
	return 0;
}