/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1008.cpp
* @Author: Pic
* @Date:   2017-07-31 21:45:59
* @Last Modified time: 2017-08-02 10:19:04
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int INF=0x3f3f3f3f;
int a[25];
//反转，只不过开头的翻转两个的情况需要处理一下，可以枚举一下翻第一个与不翻第一个
int main(){
	for(int i=0;i < 20;i++){
		scanf("%d",&a[i]);
	}
	int b[25];
	for(int i=0;i<22;i++) b[i]=a[i];
	int res=0,res1=0,res2=0;
	for(int i=0;i<19;i++){
		if(a[i]%2){
			res1++;
			a[i+1]++,a[i+2]++;
		}
	}
	if(a[19]%2) res1=INF;
	b[0]++,b[1]++; res2++;
	for(int i=0;i<19;i++){
		if(b[i]%2){
			res2++;
			b[i+1]++, b[i+2]++;
		}
	}
	if(b[19]%2) res2=INF;
	res=min(res1,res2);
	cout<<res<<"\n";
    return 0;
}