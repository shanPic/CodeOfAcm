/*
* @FileName: D:\代码与算法\2017训练比赛\多校4\1009.cpp
* @Author: Pic
* @Date:   2017-08-03 12:15:29
* @Last Modified time: 2017-08-03 12:17:50
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x;
		int odd=0,even=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			if(x%2){
				odd++;
			}
			else{
				even++;
			}
		}
		if(odd>even){
			printf("2 1\n");
		}
		else{
			printf("2 0\n");
		}
	}
    return 0;
}