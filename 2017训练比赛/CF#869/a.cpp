/*
* @FileName: D:\代码与算法\2017训练比赛\CF#869\a.cpp
* @Author: Pic
* @Created Time: 2017/10/6 21:36:36
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+30;
int has[maxn];
int an[2000+30],bn[2000+30];
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	int n;
	memset(has,0,sizeof(has));
   	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&an[i]);
		has[an[i]]++;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&bn[i]);
		has[bn[i]]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int tmp=(an[i]^bn[j]);
			if(tmp>=maxn) continue;
			if(has[tmp]!=0){
				cnt++;
			}
		}
	}
	if(cnt%2==0){
		printf("Karen\n");
	}
	else{
		printf("Koyomi\n");
	}
	return 0;
}
