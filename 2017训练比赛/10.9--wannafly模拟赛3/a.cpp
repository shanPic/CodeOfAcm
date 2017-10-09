/*
* @FileName: D:\代码与算法\2017训练比赛\10.9--wannafly模拟赛3\a.cpp
* @Author: Pic
* @Date:   2017-10-09 21:02:56
* @Last Modified time: 2017-10-09 21:05:25
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+30;
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int res=-1;
	for(int i=n-1;i>=0;i--){
		if(a[i]+i>res){
			res=a[i]+i;
		}
	}
	printf("%d\n",res);
}	