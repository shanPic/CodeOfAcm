/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练三\1004.cpp
* @Author: Pic
* @Date:   2017-07-22 16:35:27
* @Last Modified time: 2017-07-22 16:54:39
*/

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=1001+30;
struct node
{
	int x,y;
};
node a[MAXN];
int fa[MAXN];
int fin(int x)
{
	if(fa[x]==-1) return x;
	else{
		fa[x]=fin(fa[x]);
		return fa[x];
	}
}
void uion(int x,int y)
{
	int fx=fin(x),fy=fin(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
	return;
}
bool ok[MAXN];
int main(){
	//freopen("data.in","r",stdin);
	int n,d;
	memset(fa,-1,sizeof(fa));
	memset(ok,0,sizeof(ok));
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	getchar();
	char ch;
	int x,y,fx,fy;
	while(~scanf("%c",&ch)){
		if(ch=='O'){
			scanf("%d",&x);
			x--;
			// cout<<"O"<<" "<<x<<endl;
			ok[x]=1;
			for(int i=0;i<n;i++){
				if(i!=x)
				if(sqrt((double)(a[i].x-a[x].x)*(a[i].x-a[x].x)+(a[i].y-a[x].y)*(a[i].y-a[x].y))<=d&&ok[i]){
					uion(i,x);
				}
			}
		}
		else if(ch=='S'){
			scanf("%d%d",&x,&y);x--,y--;
			// cout<<"S"<<" "<<x<<" "<<y<<endl;
			fx=fin(x),fy=fin(y);
			if(fx==fy){
				printf("SUCCESS\n");
			}
			else{
				printf("FAIL\n");
			}
		}
		getchar();
	}
	// cout<<"-----------"<<endl;
	// for(int i=0;i<n;i++){
	// 	cout<<fin(i)<<endl;
	// }
    return 0;
}