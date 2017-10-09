/*
* @FileName: D:\代码与算法\2017训练比赛\多校1\1001.cpp
* @Author: Pic
* @Date:   2017-07-25 11:34:10
* @Last Modified time: 2017-07-25 12:18:13
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	unsigned  long long n;
	int res;
	int t=0;
	while(cin>>n){
		//if(n==63) printf("Case #%d: %d\n",++t,res-1);
		cout<<((long long)1<<n)<<endl;
		n=(((long long)1<<n)-1);
		cout<<n<<endl;
		res=0;
		while(n){
			n/=10;
			res++;
		}
		//cout<<res<<endl;
		printf("Case #%d: %d\n",++t,res-1);
	}
    return 0;
}