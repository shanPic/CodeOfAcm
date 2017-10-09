/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1012.cpp
* @Author: Pic
* @Date:   2017-08-04 15:53:57
* @Last Modified time: 2017-08-04 21:30:25
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN=1e3+30;
const LL INF=0x80808080;
LL a[MAXN];
struct node
{
	int x,y;	
};
LL hs[MAXN*MAXN];
node co[MAXN*MAXN];
int n;
int cnt=0;
bool seach(LL x)
{
	for(int i=0;i<n;i++){
		if(a[i]==x) continue;
		LL flag=x-a[i];
		int id=lower_bound(hs,hs+cnt,flag)-hs;
		while(hs[id]==flag){
			if(((LL)min(co[id].x,co[id].y))!=min(a[i],x)&&((LL)max(co[id].x,co[id].y))!=max(a[i],x)){
				return 1;
			}
			id++;
		}
	}
	return 0;
}
int main(){
	//freopen("data.in","r",stdin);
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		cnt=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				co[cnt].x=a[i],co[cnt].y=a[j];	
				hs[cnt++]=a[i]+a[j];
			}
		}
		sort(hs,hs+cnt);
		LL res=-1*INF;
		for(int i=n-1;i>=0;i--){
			if(seach(a[i])){
				res=a[i];
				break;
			}
		}
		if(res!=(-1*INF)){
			printf("%lld\n",res);
		}
		else{
			printf("no solution\n");
		}
	}
    return 0;
}