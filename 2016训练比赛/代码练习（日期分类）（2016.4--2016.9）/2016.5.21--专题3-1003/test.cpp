#include<iostream>
#include<stdio.h>
using namespace std;
long long dp[1005];
int main(){
	freopen("date.out","w",stdout);
	long long dpt[2005];
	dpt[1]=2;
	dpt[2]=4;
	for(int i=3;i<2000;i++){
		dpt[i]=dpt[i-1]+i;
	}
	dp[1]=2;dp[2]=7;
	for(int i=3;i<1000;i++){
		dp[i]=dp[i-1]+4*(i-1)+1;
		cout<<dpt[2*i]-2*i<<"\t"<<dp[i]<<endl;
	}
}