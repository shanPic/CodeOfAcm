/*
* @FileName: D:\代码与算法\2017训练比赛\多校8\1008-pro.cpp
* @Author: Pic
* @Date:   2017-08-17 20:52:59
* @Last Modified time: 2017-08-17 21:10:50
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000+30;
int a[MAXN];
int main()
{
	//freopen("data.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int sumL=0,sumN=0,sumD=0;
		getchar();
		char ch;
		for(int i=0;i<n;i++){
			ch=getchar();
			getchar();
			if(ch=='L'){
				sumL+=a[i];
			}
			else if(ch=='D'){
				sumD+=a[i];
			}
			else if(ch=='N'){
				sumN+=a[i];
			}
		}
		if(k<=sumL+sumN&&k>=-1*(sumN+sumD)){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
}