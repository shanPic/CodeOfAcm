/*
* @FileName: D:\代码与算法\2017训练比赛\CF#869\b.cpp
* @Author: Pic
* @Created Time: 2017/10/6 22:00:52
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	long long a,b;
   	scanf("%I64d%I64d",&a,&b);
	long long c=b-a;
	if(c>=10){
		printf("0\n");
	}	
	else{
		int res=1;
		for(int i=0;i<c;i++){
			a++;
			res=(res*(a%10))%10;
		}
		res=res%10;
		printf("%d\n",res);
	}
	return 0;
}
