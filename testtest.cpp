/*
* @FileName: C:\Users\zhans\Desktop\chuli.cpp
* @Author: Pic
* @Created Time: 2017/9/17 17:05:48
*/
#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
 	string a,b;
	int cnt=0;
	while(cin>>a>>b){
		if(mp.find(b)==mp.end()){
			mp.insert(make_pair(b,++cnt));
		}
	}
	cout<<mp["山东农业大学"]<<endl;
	return 0;
}
