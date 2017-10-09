/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练四\test.cpp
* @Author: Pic
* @Date:   2017-07-29 21:31:42
* @Last Modified time: 2017-07-31 20:47:52
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

int main(){
	long long x;
	for(long long i=1;;i++){
		x=i*i;
		if(x>=1e14){
			cout<<x<<endl;
			cout<<i<<endl;
			break;
		}
	}
    return 0;
}