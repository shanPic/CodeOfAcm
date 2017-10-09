/*
* @FileName: D:\代码与算法\2017训练比赛\CF#371\a.cpp
* @Author: Pic
* @Date:   2017-06-27 10:17:16
* @Last Modified time: 2017-06-27 10:54:54
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	long long res=0;
	int l,r;
	if(l2<=r1&&r2>=l1){
		if(r2>r1){
			if(l1>=l2){
				res=r1-l1+1;
				l=l1,r=r1;
			}
			else{
				res=r1-l2+1;
				l=l2,r=r1;
			}
		}
		else{
			if(l1>=l2){
				res=r2-l1+1;
				l=l1,r=r2;
			}
			else{
				res=r2-l2+1;
				l=l2,r=r2;
			}
		}
	}
	if(k<=r&&k>=l){
		res--;
	}
	cout<<res<<endl;
    return 0;
}