/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1006.cpp
* @Author: Pic
* @Date:   2017-07-31 08:39:34
* @Last Modified time: 2017-07-31 20:17:36
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int MAXN=10000+30;
int p[MAXN+3];
void getPrime()
{
	memset(p, 0, sizeof(p));
	for (int i = 2; i <= MAXN; i++)
	{
		if (!p[i])p[++p[0]] = i;
		for (int j = 1; j <= p[0] && p[j] <= MAXN / i; j++)
		{
			p[p[j]*i] = 1;
			if (i % p[j] == 0) break;
		}
	}
}
int solve(int n)
{
	int res=0;
	int l=1,r=1,sum=0;
	for(;;){
		while(p[r]<=n&&sum<n){
			sum+=p[r];
			r++;
			if(sum==n) res++;
		}
		if(sum<n) break;
		sum-=p[l];
		l++;
		if(sum==n) res++;
		//if(l>r) break;
	}
	return res;
}
int main()
{
	//freopen("data.in","r",stdin);
	getPrime();
	int n;
	while(~scanf("%d",&n)&&n){
		//cout<<"n is "<<n<<endl;
		printf("%d\n",solve(n));
	}
}