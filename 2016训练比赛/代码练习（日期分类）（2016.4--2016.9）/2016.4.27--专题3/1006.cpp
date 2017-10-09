#include<iostream>
#include<stdint.h>
#include<stdio.h>
using namespace std;
#define MAX(a,b) a>b?a:b;
int a[101][101];
int dp[101][101];
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int N,T;
	cin>>N;
	while(N--){
		cin>>T;
		for(int i=1;i<=T;i++){
			for(int j=1;j<=i;j++)
				cin>>a[i][j];
		}
		for(int j=1;j<=T;j++)
			dp[T][j]=a[T][j];
		for(int i=T-1;i>0;i--)
			for(int j=1;j<=i;j++){
				dp[i][j]=MAX(dp[i+1][j]+a[i][j],dp[i+1][j+1]+a[i][j]);
			}
		cout<<dp[1][1]<<endl;
	}
}