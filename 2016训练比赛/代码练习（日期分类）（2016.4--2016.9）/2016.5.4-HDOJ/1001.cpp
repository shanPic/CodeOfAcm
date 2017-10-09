#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
//int a[10010];
int dp_last,dp,tem,a;
int main(){
	//freopen("date.in","r",stdin);
	//freopen("date.out","w",stdout);
	int N,m,temp,b_tem=1,e_tem=1,b=1,e=1,ca=0;
	cin>>N;
	temp=N-1;
	while(N--){
		cin>>m;
		scanf("%d",&a);
		b=1;
		e=1;
		b_tem=1;
		e_tem=1;
		dp=a;
		tem=dp;
		for(int i=2;i<=m;i++){
			scanf("%d",&a);
			if(dp+a>=a){
				dp=dp+a;
				e_tem=i;
			}
			else{
				dp=a;
				b_tem=i,e_tem=i;
			}
			if(tem<=dp){
				tem=dp;
				b=b_tem;
				e=e_tem;
			}
		}
		/*jilu *e=&dp[1+m];
		jilu *b=&dp[1];
		sort(b,e);*/
		//cout<<dp[i].
		if(temp==N);
			else
		printf("\n");
		/*cout<<"Case 1:"<<endl;
		cout<<tem<<" "<<b<<" "<<e<<endl;*/
	printf("Case %d:\n%d %d %d\n",++ca,tem,b,e);
	}
}
