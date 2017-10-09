/*
* @Author: zhans
* @Date:   2017-05-23 13:41:23
* @Last Modified by:   zhans
* @Last Modified time: 2017-05-23 13:46:01
*/

#include <bits/stdc++.h>

using namespace std;
const int MAXN=100000;
int data[MAXN];
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int x;
	int cnt=0;
	while(cin>>x){
		//cout<<x<<endl;
		data[cnt++]=x;
	}
	sort(data,data+cnt);
	for(int i=0;i<cnt;i++){
		cout<<data[i]<<"\t";
	}
	cout<<endl;
    return 0;
}