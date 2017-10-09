/*
* @FileName: D:\代码与算法\2017训练比赛\2017CODEM\1.cpp
* @Author: Pic
* @Date:   2017-06-11 15:07:34
* @Last Modified time: 2017-06-11 16:26:22
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
const int MAXN = 1 << 20;
int a[MAXN + 30];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int flag = a[0], num = 0;
	sort(a, a + n,cmp);
	int low = 0, high = n-1;
	while (low < high) {
		int mid = low + ((high - low) >> 1);
		if (a[mid] > flag)
			low = mid+1;
		else // A[mid] >= target
			high = mid;
	}
	// int low=0;
	// for(int i=0;i<n;i++){
	// 	if(a[i]==flag){
	// 		low=i;
	// 		break;
	// 	}
	// }
	//cout<<low<<endl;
	num=n-low-1;
	//cout<<num<<endl;
	// cout<<low<<endl;
	//num=0;
	//cout<<num<<endl;
	int res=0;
	while(num){
		//cout<<1111<<endl;
		num=(num-1)/2;
		res++;
	}
	cout<<res<<endl;
	return 0;
}