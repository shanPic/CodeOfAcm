/*
* @FileName: D:\代码与算法\2017训练比赛\百度之星初赛\1001.cpp
* @Author: Pic
* @Date:   2017-08-12 14:06:06
* @Last Modified time: 2017-08-12 15:11:03
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		//scanf("%d",&n);
		cin>>n;
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		long long x=n-1,res=0;
		long long i=x;
		i=sqrt(i);
		for(long long j=1;j<=i+1;j++){
			if(x%j==0) res++;
		}
		//printf("%d\n",res+1);
		if(x%i==0) res--;
		cout<<res+1<<endl;
	}
    return 0;
}