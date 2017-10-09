/*
* @FileName: D:\代码与算法\2017训练比赛\多校1\1006.cpp
* @Author: Pic
* @Date:   2017-07-25 14:20:12
* @Last Modified time: 2017-07-25 16:05:59
*/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int MAXN=100000+30;
const int mod=1e9+7;
int xh1[MAXN],xh2[MAXN];
int a[MAXN],b[MAXN];
int cnt1,cnt2;
int n,m;
int vis[MAXN];
void fun(int x[],int n,int xh[],int &cnt)
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		if(!vis[i]){
			//vis[i]=1;
			int now=i,res=0;
			while(!vis[now]){
				res++;
				vis[now]=1;
				now=x[now];
			}
			xh[cnt++]=res;
		}
	}
}
int main(){
	freopen("data.in","r",stdin);
	int t=0;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&b[i]);
		}
		cnt1=0;cnt2=0;
		fun(a,n,xh1,cnt1);
		//cout<<cnt1<<endl;
		fun(b,m,xh2,cnt2);
		//cout<<cnt2<<endl;
		int res=1;
		int tmp=0;
		// for(int i=0;i<cnt1;i++) cout<<xh1[i]<<"\t";
		// 	cout<<endl;
		// for(int i=0;i<cnt2;i++) cout<<xh2[i]<<"\t";
		// 	cout<<endl;
		for(int i=0;i<cnt1;i++){
			tmp=0;
			for(int j=0;j<cnt2;j++){
				if(xh1[i]>=xh2[j]){
					tmp+=xh2[j];
				}
			}
			//cout<<endl<<tmp<<endl;
			// if(tmp!=0)
			res=((res%mod)*(tmp%mod))%mod;
		}
		printf("Case #%d: %d\n",++t,res%mod);
	}
    return 0;
}