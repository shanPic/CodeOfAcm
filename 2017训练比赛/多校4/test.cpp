/*
* @FileName: D:\代码与算法\2017训练比赛\多校4\test.cpp
* @Author: Pic
* @Date:   2017-08-03 13:30:24
* @Last Modified time: 2017-08-03 16:23:45
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
#include <cmath>
using namespace std;
int main(){
	long long cnt=0;
	long long ro=1;
	for(int i=1;i<13;i++){
		cnt=0;
		ro*=48;
		for(long long j=1;j<=ro;j++){
				if((ro%j)==0) cnt++;
	    }
	    cout<<ro<<"\t"<<cnt<<endl;
    }
	cout<<cnt<<endl;
    return 0;
}