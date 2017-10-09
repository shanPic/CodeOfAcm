/*
* @FileName: a.cpp
* @Author: Pic
* @Date:   2017-06-03 19:12:16
* @Last Modified time: 2017-06-03 19:24:51
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=100+3;
int a[MAXN];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){

	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	if(n==0){
		cout<<0<<endl;
		return 0;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(m==0){
		cout<<"Impossible"<<endl;
		return 0;
	}
	sort(a,a+m,cmp);
	int sum=1;
	int res=0;
	int flag=0;
	for(int i=0;i<m;i++){
		sum--;
		sum+=a[i];
		if(sum>=n){
			res=i+1;
			flag=1;
			break;
		}
	}
	if(sum>=n) flag=1;
	if(flag)
		cout<<res<<endl;
	else cout<<"Impossible"<<endl;
    return 0;
}