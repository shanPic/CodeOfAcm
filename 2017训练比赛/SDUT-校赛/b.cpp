/*
* @FileName: b.cpp
* @Author: Pic
* @Date:   2017-06-04 13:13:01
* @Last Modified time: 2017-06-04 13:16:11
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m)
	{
		cout<<n/__gcd(n,m)<<"\n";
	}
    return 0;
}