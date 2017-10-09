/*
* @FileName: D:\代码与算法\2017训练比赛\网络流24题（LOJ）\test.cpp
* @Author: Pic
* @Date:   2017-08-14 15:24:13
* @Last Modified time: 2017-08-14 15:30:42
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("data.in","r",stdin);
	//char str[99];
	string str;
	//gets(str);
	int x;
	// while(~sscanf(str,"%d",&x)){
	// 	cout<<x<<endl;
	// }
	getline(cin,str);
	stringstream sstr(str);
	while(sstr>>x){
		cout<<x<<endl;
	}
    return 0;
}