/*
* @FileName: D:\代码与算法\2017训练比赛\多校9\test.cpp
* @Author: Pic
* @Date:   2017-08-22 15:49:33
* @Last Modified time: 2017-08-22 16:23:26
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("data.out","w",stdout);
	cout<<1<<endl;
	for(int i=0;i<2500;i++) cout<<'a';
	cout<<endl;
	for(int i=0;i<2500;i++){
		if(i%2){
			cout<<'*';
		}
		else{
			cout<<'a';
		}
	}
	cout<<endl;
}