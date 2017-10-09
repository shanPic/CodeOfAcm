/*
* @FileName: D:\代码与算法\tem2.cpp
* @Author: Pic
* @Created Time: 2017/8/28 22:26:29
*/
#include <bits/stdc++.h>
using namespace std;
map<string,int> v;
int main()
{
	//freopen("rank.txt","r",stdin);
	ifstream in;
	in.open("rank.txt");
	string a,b;
	int cnt=1;
	while(1){
		in>>a>>b;
		if(a=="1") break;
		if(v.find(b)==v.end()){
			v.insert(make_pair(b,cnt));
			cnt++;
			cout<<cnt<<endl;
		}
	}
	string name="山东农业大学";
	cout<<(v.find(name)==v.end())<<endl;
	cout<<v[name]<<endl;
}
