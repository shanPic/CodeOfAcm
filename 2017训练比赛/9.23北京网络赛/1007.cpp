/*
* @FileName: D:\代码与算法\2017训练比赛\9.23北京网络赛\1007.cpp
* @Author: Pic
* @Created Time: 2017/9/23 14:58:21
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int m,n;
	freopen("data.in","r",stdin);
	while(~scanf("%d%d",&m,&n)){
		if(m>n) swap(m,n);
		m--,n--;
		int g=__gcd(m,n);
		int x=n/g,y=m/g;
		cout<<"x is "<<x<<endl;
		int tot=m*x+1;
		int sum=0;
		int tmp=x/2;
		sum+=((tmp-1)*tmp);
		if(tmp*2!=x){
			sum+=(tmp);
		}
		//if(x==m+1) sum++;
		printf("%d\n",tot-sum*2);
	}
	return 0;
}
