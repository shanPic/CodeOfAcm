/*
* @FileName: D:\代码与算法\2017训练比赛\七月训练六\1009.cpp
* @Author: Pic
* @Date:   2017-08-06 16:23:25
* @Last Modified time: 2017-08-06 16:24:19
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
long long eular(long long n)
{
	long long ans = n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans -= ans / i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)ans -= ans / n;
	return ans;
}
int main(){
	long long n;
	while(cin>>n&&n){
		cout<<eular(n)<<"\n";
	}
    return 0;
}