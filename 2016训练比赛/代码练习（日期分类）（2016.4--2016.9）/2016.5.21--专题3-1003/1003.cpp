#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
inline int MAX(int a, int b){
	return a > b ? a : b;
}
int a[1010];
int dp[1010];
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int N, maxs,maxr,flag=0;
	while (cin >> N&&N != 0){
		for (int i = 0; i<N; i++){
			cin >> a[i];
		}
		dp[0] = a[0];
		maxr=a[0];
		for (int k = 1; k<N; k++){
			for (int l = 0; l<k; l++){
				flag=0;
				if (a[k]>a[l]){
					maxs = -1000000;
					flag=1;
					maxs = MAX(maxs, dp[l] + a[k]);
				}
			}
			if(flag){
				dp[k] = maxs;
				if(dp[k]>maxr)
					maxr=dp[k];
			}
		}
		//sort(a,a+N);
		/*for(int i=0;i<N;i++){
			cout<<dp[i]<<endl;
		}*/
		cout<<maxr<<endl;
	}
}