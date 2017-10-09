/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练三\1003.cpp
* @Author: Pic
* @Date:   2017-07-22 13:38:47
* @Last Modified time: 2017-07-22 15:15:58
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN=1e5+30;
struct node
{
	int s,aid;
};
node a[MAXN];
node b[MAXN];
bool cmp1(node a,node b)
{
	return (a.s>b.s)||((a.s==b.s)&&(a.aid<b.aid));
}
bool cmp2(node a,node b)
{
	return (a.aid<b.aid)||((a.aid==b.aid)&&(a.s>b.s));
}
int n,c,f;
bool ok(int mid)
{
	sort(b,b+mid,cmp2);
	sort(b+mid+1,b+c,cmp2);
	//int i=f/2;
	int tot=a[mid].aid;
	for(int i=0;i<n/2;i++){
		tot+=b[i].aid;
	}
	for(int i=mid+1;i<mid+1+n/2;i++){
		tot+=b[i].aid;
	}
	return tot<=f;
}
int main(){
	//freopen("data.in","r",stdin);
	while(~scanf("%d%d%d",&n,&c,&f)){
		for(int i=0;i<c;i++){
			scanf("%d%d",&a[i].s,&a[i].aid);
		}
		sort(a,a+c,cmp1);
		int i=n/2;
		int res=0;
		for(;i<c-n/2;i++){
			memcpy(b,a,sizeof(a));
			if(ok(i)){
				res=i;
				break;
			}
		}
		printf("%d\n",a[res].s);
	}
    return 0;
}