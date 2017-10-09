/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\#1009.cpp
* @Author: Pic
* @Date:   2017-07-17 20:31:16
* @Last Modified time: 2017-07-23 21:31:59
*/

#include <iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=50000+30;
struct  node
{
	int l,r;
	int id;
	bool operator < (const node a) const
	{
		return (a.r<r)||((a.r==r)&&(a.l<l));
	}
};
bool cmp(node a,node b)
{
	return (a.l<b.l)||(a.l==b.l&&a.r<b.r);
}
node cow[MAXN];
int belong[MAXN];
int main(){
	//freopen("data.in","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		int l,r;
		for(int i=0;i<n;i++){
			scanf("%d%d",&l,&r);
			cow[i].l=l,cow[i].r=r,cow[i].id=i;
		}
		int cnt=1;
		sort(cow,cow+n,cmp);
		priority_queue<node> q;
		q.push(cow[0]);
		belong[cow[0].id]=cnt;
		for(int i=1;i<n;i++){
			if(!q.empty()&&q.top().r<cow[i].l){
				belong[cow[i].id]=belong[q.top().id];
				q.pop();q.push(cow[i]);
			}	
			else{
				belong[cow[i].id]=++cnt;
				q.push(cow[i]);
			}
		}
		printf("%d\n",cnt);
		for(int i=0;i<n;i++){
			printf("%d\n",belong[i]);
		}
	}
    return 0;
}