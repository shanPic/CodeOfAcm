#include<iostream>
#include<stdint.h>
#include<stdio.h>
using namespace std;
#define MAX(a,b) a>b?a:b;
int a[100010];
int dp[100010];
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int N,max,case2=0,b,e,temb,teme;
	cin>>N;
	while(N--){
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		dp[0]=a[0];
		b=0,e=0;
		temb=0;teme=0;
		max=INT32_MIN;
		dp[0]=a[0];
		for(int i=0;i<m;i++)
			if((dp[i-1]+a[i])>max){
				dp[i]=dp[i-1]+a[i];
				max=dp[i];
				e++;
			}
			else {
				dp[i]=a[i];

			}


	}
}