/*
* @FileName: a.cpp
* @Author: Pic
* @Date:   2017-06-04 12:37:05
* @Last Modified time: 2017-06-04 13:05:01
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN=22;
long long a[MAXN];
int main(){

	long long res=1;
	a[0]=1;
	a[1]=1;
	for(int i=2;i<MAXN;i++){
		res*=i;
		a[i]=res;
	}
	int n,m;
	while(cin>>n>>m){
		cout<<a[n]/a[n-m]<<" "<<a[n]/(a[n-m]*a[m])<<"\n";
	}
    return 0;
}