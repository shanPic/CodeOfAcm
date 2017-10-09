/*
* @FileName: D:\代码与算法\2017训练比赛\CF#426\a.cpp
* @Author: Pic
* @Date:   2017-08-16 09:35:08
* @Last Modified time: 2017-08-16 10:49:20
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;
const double eps=1e-4;
int main(){
	//freopen("data.in","r",stdin);
	int n;
	scanf("%d",&n);
	//cin>>n;
	for(int i=0;i<n;i++){
		long long a,b;
		//cin>>a>>b;
		scanf("%lld%lld",&a,&b);
		double yz=pow((double)a*b,1.0/3);
		//cout<<(long long)yz<<endl;
		long long tmp=(long long)(yz+0.5);
		if(a%tmp==0&&b%tmp==0&&(a*b)%tmp==0&&((a/tmp)*(b/tmp)==tmp)){
			//cout<<"Yes"<<endl;
			printf("Yes\n");
		}
		else{
			//cout<<"No"<<endl;
			printf("No\n");
		}
	}
    return 0;
}