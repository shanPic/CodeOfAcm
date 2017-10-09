/*
* @FileName: D:\代码与算法\2017训练比赛\8.27中国海洋比赛\f.cpp
* @Author: Pic
* @Created Time: 2017/8/27 12:49:07
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
    scanf("%d",&t);
	int ca=0;
	while(t--){
		int n;
		scanf("%d",&n);
		if(n%2==0){
			printf("Case #%d:\n-1\n",++ca);
			continue;
		}	
		else{
			printf("Case #%d:\n",++ca);
			int year=2*n+1;
			printf("%d",n);
			int now=n+1;
			for(int i=1;i<n;i++){	
				now+=2;
				printf(" %d",year-now+1);
				year++;
			}
			printf("\n");
		}
	}	
	return 0;
}
