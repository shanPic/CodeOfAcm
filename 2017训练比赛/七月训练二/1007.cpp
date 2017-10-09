/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练二\1007.cpp
* @Author: Pic
* @Date:   2017-07-16 21:46:32
* @Last Modified time: 2017-07-17 00:28:53
*/

#include <iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=25300;
struct  node
{
	int l,r;
};
node a[MAXN];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main(){
	//freopen("data.in","r",stdin);
	int n,t;
	while(~scanf("%d%d",&n,&t)){
		int flagl=0,flagr=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].l,&a[i].r);
			if(a[i].l==1) flagl=1;
			if(a[i].r==t) flagr=1;
		}	
		if(flagl==0||flagr==0){
			printf("-1\n");
			continue;
		}
		sort(a,a+n,cmp);
		int res=0,nowres=-1,nowptr=0,l=1,ptr=0;
		bool flag=0;
		while(l<=t){
			flag=0;
			nowres=-1;nowptr=0;
			int i=0;
			for(i=ptr;a[i].l<=l;i++){
				if(a[i].r>nowres&&a[i].r>=l&&a[i].r<=t){
					flag=1;
					nowptr=i;
					nowres=a[i].r;
				}
			}
			if(!flag) break;
			l=a[nowptr].r+1;
			//cout<<a[nowptr].l<<"\t"<<a[nowptr].r<<endl;
			ptr=i;
			res++;
		}
		if(!flag){
			printf("-1\n");
		}
		else{
			printf("%d\n",res);
		}
	}
    return 0;
}
/*
8 14
1 2
1 3
2 3
2 10
3 9
5 7
8 11
11 14
正确结果应为 3
*/