/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\1011.cpp
* @Author: Pic
* @Date:   2017-08-03 21:08:51
* @Last Modified time: 2017-08-04 15:48:11
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;
const int MAXN=35+3;
const LL INF=0x80808080;
int n;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		pair<LL,int> res{a[0],1};
		int one=n/2,tow=n-one;
		map<LL,pair<int,int> > mp;
		for(int i=0;i<(1<<one);i++){
			LL tmp=0;
			int num=0,now=i,id=0;
			while(now){
				if(now&1) num++;
				tmp+=a[id];
				id++;
				now=(now>>1);
			}
			if(mp.find(tmp)==mp.end()){
				mp.insert(make_pair(tmp,make_pair(num,1)));
			}
			else{
				mp[tmp].second++;
			}
		}
	}
    return 0;
}