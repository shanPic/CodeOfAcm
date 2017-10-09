/*
* @FileName: D:\代码与算法\2017训练比赛\美团codeM初赛A轮\a.cpp
* @Author: Pic
* @Date:   2017-06-18 18:54:31
* @Last Modified time: 2017-06-25 14:38:28
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000+30;
double c[MAXN];
double d[MAXN];
int main(){
	int n;
	cin>>n;
	double v,u;
	cin>>v>>u;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	double sum=0;
	double nu=n*u;
	double n_=1;
	for(int i=1;i<=n-1;i++){
		n_*=i;
	}
	for(int i=0;i<n;i++){
		sum+=((nu /( c[i]-(n-1)*d[i] -v ) )*n_);
	}
	sum+=( (n*n*(n-1)/v) * (n_*n) );
	printf("%.3lf\n",sum/(n_*n));
    return 0;
}