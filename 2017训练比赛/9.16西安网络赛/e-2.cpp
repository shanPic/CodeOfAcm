/*
* @FileName: D:\代码与算法\2017训练比赛\9.16西安网络赛\e-2.cpp
* @Author: Pic
* @Created Time: 2017/9/16 14:35:38
*/
#include <bits/stdc++.h>
using namespace std;

int  sum(int x)
{
	int res=0;
	while(x){
		res+=(x%10);
		x=x/10;
	}
	return res;
}
int num(int x)
{
	int res=0;
	while(x){
		res++;
		x=x/10;
	}
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
   	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int step=num(n*9);
		int bs=sum(n*9)/9;
		if((n*8)%
		
	}	
	return 0;
}
