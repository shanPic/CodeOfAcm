/*
* @FileName: D:\代码与算法\2017训练比赛\CF#369\b.cpp
* @Author: Pic
* @Date:   2017-06-11 17:05:07
* @Last Modified time: 2017-06-11 19:30:15
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN=500+30;
int a[MAXN][MAXN];
int main(){

	int n;
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			//sum+=a[i][j];
			if(a[i][j]==0) x=i,y=j;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i!=x){
			for(int j=1;j<=n;j++){
				sum+=a[i][j];
			}
			break;
		}
	}
	int sum2=0;
	for(int i=1;i<=n;i++){
		sum2+=a[x][i];
	}
	int res=sum-sum2;
	a[x][y]=res;
	int flag=0;
	int sum3=0;
	for(int i=1;i<=n;i++){
		sum3+=a[i][y];
	}
	int sum4=0;
	for(int i=1;i<=n;i++){
		sum4+=a[i][n-i+1];
	}
	int sum5=0;
	for(int i=1;i<=n;i++){
		sum5+=a[i][i];
	}
	if(sum==sum3&&sum3==sum4&&sum4==sum5){
		flag=1;
	}
	if (flag) {
		if (res > 0)
			printf("%d\n", sum - sum2);
		else printf("-1\n");
	}
	else{
		printf("-1\n");
	}
    return 0;
}