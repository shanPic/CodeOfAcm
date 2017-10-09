/*
* @FileName: D:\代码与算法\2017训练比赛\多校3\test.cpp
* @Author: Pic
* @Date:   2017-08-02 08:33:47
* @Last Modified time: 2017-08-02 08:40:14
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
int a[30],b[30];
bool cmp(int i,int j)
{
	return a[i]<a[j];
}
int main(){
	int cnt=0;
	for(int i=15;i>=0;i--) a[cnt++]=i;
	for(int i=0;i<=15;i++) b[i]=i;
	sort(b,b+16,cmp);
	for(int i=0;i<16;i++){
		cout<<b[i]<<"\t";
	}
	cout<<endl;
    return 0;
}