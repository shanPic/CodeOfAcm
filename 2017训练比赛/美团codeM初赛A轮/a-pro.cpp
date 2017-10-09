/*
* @FileName: D:\代码与算法\2017训练比赛\美团codeM初赛A轮\a-pro.cpp
* @Author: Pic
* @Date:   2017-06-18 18:54:31
* @Last Modified time: 2017-06-18 19:55:08
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=1300+30;
long double c[MAXN];
long double d[MAXN];
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
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			sum+= (nu /( c[i]-(j-1)*d[i] -v ) );
		}
	}
	//sum*=n_;
	//sum+=( (n*n*(n-1)/v) * (n_*n) );
	//printf("%.3lf\n",sum/(n_*n)+0.0005);
	cout<<fixed<<setprecision(3)<<sum/n<<"\n";
	//cout<<sum/(n*n_)<<endl;
    return 0;
}