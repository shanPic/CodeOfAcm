/*
* @FileName: D:\代码与算法\2017训练比赛\多校5\1006.cpp
* @Author: Pic
* @Date:   2017-08-08 12:43:46
* @Last Modified time: 2017-08-08 13:11:26
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,m;
		//scanf("%d%d",&n,&m);
		cin>>n>>m;
		long long up=n*(n-1)/2;
		if(m>=up){
			//printf("%d\n",up*2);
			cout<<up*2<<endl;
		}
		else if(m>=n-1){
			//printf("%d\n",(up+up-m)*2);
			long long ans=(up+up-m)*2LL;
			cout<<ans<<endl;
		}
		else{
			long long ans=(up+up-n+1LL+(n-1LL-m)*(n-1)*(m+1))*2LL;
			//long long ans=
			cout<<ans<<endl;
		}
	}
    return 0;
}