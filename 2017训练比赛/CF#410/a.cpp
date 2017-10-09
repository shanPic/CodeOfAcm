/*
* @FileName: D:\代码与算法\2017训练比赛\CF#410\a.cpp
* @Author: Pic
* @Date:   2017-06-11 11:56:04
* @Last Modified time: 2017-06-11 14:35:54
*/

#include <bits/stdc++.h>
using namespace std;

bool ok(string str)
{
	int i=0,j=str.size()-1;
	int num=0;
	while(i<j){
		if(str[i]!=str[j]) num++;
		i++;j--;
	}
	if(num==0) return 1;
	else return 0;
}
int main(){
	string str;
	cin>>str;
	int cnt=str.size();
	int i=0,j=cnt-1;
	//cout<<i<<"\t"<<j<<endl;
	if(cnt==1){
		cout<<"YES"<<endl;
		return 0;
	}
	int num=0;
	while(i<j){
		if(str[i]!=str[j]){
			num++;
		}
		i++;j--;
	}
	//cout<<num<<endl;
	//cout<<str<<endl;aa
	//cout<<num<<endl;
	if(cnt%2==1&&(num==0||num==1)){
		cout<<"YES"<<endl;
		return 0;
	}
	if(num!=1) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
    return 0;
}