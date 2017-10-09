/*
* @FileName: D:\代码与算法\2017训练比赛\多校2\1006-test.cpp
* @Author: Pic
* @Date:   2017-07-27 12:23:36
* @Last Modified time: 2017-07-28 10:50:15
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000;
long long a[MAXN];
int main(){
	int m=8000;
	int n=4;
	a[1]=a[2]=1;
	for(int i=3;i<=m;i++){
		a[i]=a[i-1]+a[i-2]*2;
	}
	long long tmp=0;
	for(int i=1;i<=40;i++){
		tmp=0;
		for(int j=1;j<=m-i*n;j++){
			tmp=0;
			for(int k=j;k<=n+j-1;k++){
				tmp+=a[k];
			}
			a[j]=tmp;
		}
		printf("%d:\t%lld\n",i+1,a[1]);
	}

    return 0;
}