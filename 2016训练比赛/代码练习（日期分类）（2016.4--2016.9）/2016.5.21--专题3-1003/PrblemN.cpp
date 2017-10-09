#include<iostream>
using namespace std;
long long dp[20010];
int main(){
	dp[1]=2;
dp[2]=4;
	for(int i=3;i<20006;i++){
		dp[i]=dp[i-1]+i;
	}
	int N;
	int m;
	cin>>N;
	while(N--){
		cin>>m;
		cout<<dp[2*m]-2*m<<endl;
	}
}