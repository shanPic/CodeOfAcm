/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\#1008.cpp
* @Author: Pic
* @Date:   2017-07-17 01:05:29
* @Last Modified time: 2017-07-23 21:31:59
*/

#include <iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1000+30;
struct node
{
	double x,y;
};
node a[MAXN];
int cnt=0;
int n,d;
void getseg(int x,int y)
{
	(double)x;(double)y;
	if(y<=d){
		double mo=sqrt(d*d-y*y);
		a[cnt].y=x+mo;
		a[cnt++].x=x-mo;
	}
}
bool cmp(node a,node b)
{
	return (a.y<b.y)||(a.y==b.y&&a.x>b.y);
}
bool vis[MAXN];
int main(){
	//freopen("data.in","r",stdin);
	int t=0;
	while(~scanf("%d%d",&n,&d)&&n&&d){
		int x,y;
		cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			getseg(x,y);
		}
		//for(int i=0;i<cnt;i++) cout<<a[i].x<<"\t"<<a[i].y<<"\n";
		if(cnt<n){
			printf("Case %d: -1\n",++t);
			continue;
		}
		sort(a,a+cnt,cmp);
		int res=0;
		memset(vis,0,sizeof(vis));
		double now=0;
		for(int i=0;i<cnt;i++){
			if(!vis[i]){
				res++;
				vis[i]=1;
				now=a[i].y;
				for(int j=i+1;j<cnt;j++){
					if(a[j].x<=now&&a[j].y>=now){
						vis[j]=1;
					}
				}
			}
		}
		printf("Case %d: %d\n",++t,res);
	}
    return 0;
}