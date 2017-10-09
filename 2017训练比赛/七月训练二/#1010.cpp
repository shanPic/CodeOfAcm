/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\#1010.cpp
* @Author: Pic
* @Date:   2017-07-17 21:12:17
* @Last Modified time: 2017-07-17 21:21:42
*/

#include <iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e4+30;
int cost[MAXN];
int need[MAXN];
int main(){
	//freopen("data.in","r",stdin);
	int n,s;
	while(~scanf("%d%d",&n,&s)){
		for(int i=0;i<n;i++){
			scanf("%d %d",&cost[i],&need[i]);
		}
		long long pre=0x3f3f3f3f,res=0;
		for(int i=0;i<n;i++){
			if(cost[i]>pre+s){
				pre=pre+s;
				res+=(pre*need[i]);
			}
			else{
				res+=(cost[i]*need[i]);
				pre=cost[i];
			}
		}
		printf("%lld\n",res);
	}
    return 0;
}