/*
* @FileName: D:\代码与算法\2017训练比赛\8.27中国海洋比赛\i.cpp
* @Author: Pic
* @Created Time: 2017/8/27 12:14:23
*/
#include <bits/stdc++.h>
using namespace std;

int jg(int x){
	int tmp=0;
	while(x!=0){
		tmp=x%10;
		x=x/10;
		if(tmp==4) return 0;	
	}
	return 1;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int t;
   	scanf("%d",&t);
	int ca=0;
	int n;
	while(t--){
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(jg(i)){
				cnt++;
			}
		}
		printf("Case #%d: %d\n",++ca,cnt);
	}
	return 0;
}
